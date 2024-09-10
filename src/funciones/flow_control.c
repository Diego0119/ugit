#include "../definicion_funciones/funciones.h"

void flow_control(void)
{
    char prompt[MAX_INPUT_SIZE];
    Commit commits[MAX_COMMITS];
    Branch branches[MAX_BRANCHES];
    int commit_count = 0;
    int branches_count = 0;
    char branch_name[MAX_INPUT_SIZE];
    strcpy(branch_name, "main");
    int repositorio_flag = 0;
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
        // aca puedo definir un arreglo de comandos soportados,
        // de modo que si no es ninguno de los comandos desconocidos diga que hay un error
        if (strcmp(prompt, "ugit init") == 0)
        {
            if (repositorio_flag == 0)
            {
                ugit_init(branches, &branches_count, initial_prompt);
                // strcpy(initial_prompt, "ugit(main) ");
                // initial_prompt = "ugit(main) ";
                repositorio_flag++;
            }
            else
            {
                printf("El repositorio ya fue inicializado.\n");
            }
        }
        else if (strcmp(prompt, "ugit --version") == 0)
        {
            ugit_version();
        }
        else if (strncmp(prompt, "ugit add", 8) == 0)
        {
            if (repositorio_flag == 1)
            {
                ugit_add(prompt, branches, branch_name);
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
                // commit_count++;
                ugit_commit(commits, prompt, branch_name, branches);
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
                ugit_log(branches, commit_count, branch_name);
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
                *branch_name = ugit_branch(prompt, branches, &branches_count);
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
                if (ugit_checkout(prompt, branches))
                {
                    ugit_branch_control(prompt, initial_prompt);
                }
            }
            else
            {
                printf("No existe esa rama, debido a que no hay un repositorio inicializado.\n");
            }
        }
        else
        {
            printf("Comando desconocido\n");
        }
    }
}
