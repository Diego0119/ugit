#include "../definicion_funciones/funciones.h"
/**
 * @file flow_control.c
 * @brief Implementación de la función de control de flujo para la interacción del usuario con uGit.
 *
 * Este archivo contiene la implementación de la función `flow_control`, que permite al usuario
 * interactuar con el sistema de control de versiones uGit a través de una interfaz de línea de comandos.
 * La función lee comandos del usuario, los interpreta y ejecuta las funciones correspondientes según
 * el comando ingresado. También maneja la inicialización del repositorio, la creación de ramas,
 * la adición de archivos, y la realización de commits, entre otros.
 *
 * @version 0.1
 * @date 2024-09-17
 */

void flow_control(void)
{
    char prompt[MAX_INPUT_SIZE];
    Branch branches[MAX_BRANCHES];

    int files_count = 0;
    int modificacion_flag = 0;
    int repositorio_flag = 0;
    char branch_name[MAX_INPUT_SIZE];
    strcpy(branch_name, "main");
    char initial_prompt[MAX_INPUT_SIZE];
    char *user_name;
    strcpy(initial_prompt, "Shell>");

    while (strcmp(prompt, "exit") != 0)
    {
        printf("%s", initial_prompt);
        if (fgets(prompt, sizeof(prompt), stdin) == NULL)
        {
            printf("Comando desconocido\n");
            return;
        }
        size_t len = strlen(prompt);
        if (len > 0 && prompt[len - 1] == '\n')
        {
            prompt[len - 1] = '\0';
        }

        if (strcmp(prompt, "ugit init") == 0)
        {
            user_name = ugit_init(branches, initial_prompt, &repositorio_flag);
        }
        else if (strcmp(prompt, "ugit --version") == 0)
        {
            ugit_version();
        }
        else if (strncmp(prompt, "vi", 2) == 0)
        {
            manejar_archivos(prompt, branches, branch_name, &files_count, &modificacion_flag);
        }
        else if (strncmp(prompt, "ugit add", 8) == 0)
        {
            if (repositorio_flag == 1)
            {
                ugit_add(prompt, branches, branch_name, &modificacion_flag);
            }
            else
            {
                printf("No hay un repositorio inicializado.\n");
            }
        }
        else if (strncmp(prompt, "ugit commit", 11) == 0)
        {
            if (repositorio_flag == 1)
            {
                ugit_commit(prompt, branch_name, branches, &modificacion_flag);
            }
            else
            {
                printf("No hay un repositorio inicializado.\n");
            }
        }
        else if (strncmp(prompt, "ugit log", 8) == 0)
        {
            if (repositorio_flag == 1)
            {
                ugit_log(branches, branch_name, user_name);
            }
            else
            {
                printf("No hay un log de commits, debido a que no se ha inicializado ningun repositorio.\n");
            }
        }
        else if (strncmp(prompt, "ugit branch", 11) == 0)
        {
            if (repositorio_flag == 1)
            {
                ugit_branch(prompt, branches);
            }
            else
            {
                printf("Para poder crear una rama se debe primero inicializar un repositorio.\n");
            }
        }
        else if (strncmp(prompt, "ugit checkout", 13) == 0)
        {
            if (repositorio_flag == 1)
            {
                *branch_name = *(prompt + 14);
                branches[hash(branch_name)] = ugit_checkout(prompt, branches, initial_prompt);
            }
            else
            {
                printf("No existe esa rama, debido a que no hay un repositorio inicializado.\n");
            }
        }
        else if (strncmp(prompt, "ugit help", 9) == 0)
        {
            commands_prompt();
        }
        else
        {
            printf("Comando desconocido\n");
        }
    }
}
