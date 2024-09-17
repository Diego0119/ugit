#include "../definicion_funciones/funciones.h"
/**
 *
 * @file flow_control.c
 * @brief Esta funcion permite al usuario interactuar con ugit
 *
 *
 */
void flow_control(void)
{
    char prompt[MAX_INPUT_SIZE];
    Branch *branches = (Branch *)malloc(1000 * sizeof(Branch));
    if (branches == NULL)
    {
        printf("Error al asignar memoria para las ramas\n");
        exit(1);
    }

    int files_count = 0;
    int modificacion_flag = 0;
    int repositorio_flag = 0;
    char branch_name[MAX_INPUT_SIZE];
    strcpy(branch_name, "main");
    char initial_prompt[MAX_INPUT_SIZE];
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
            ugit_init(branches, initial_prompt, &repositorio_flag);
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
                ugit_log(branches, branch_name);
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
                *branch_name = ugit_branch(prompt, branches);
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
    free(branches);
}
