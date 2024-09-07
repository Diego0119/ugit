#include "../definicion_funciones/funciones.h"

void flow_control(void)
{
    char prompt[MAX_INPUT_SIZE];
    Commit commits[MAX_COMMITS];
    Branch branches[MAX_BRANCHES];
    int commit_count = 0;
    int branches_count = 0;
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
                ugit_init();
                strcpy(initial_prompt, "ugit(main) ");
                // initial_prompt = "ugit(main) ";
                repositorio_flag++;
            }
            else
            {
                printf("El repositorio ya fue inicializado\n");
            }
        }
        else if (strcmp(prompt, "ugit --version") == 0)
        {
            ugit_version();
        }
        else if (strncmp(prompt, "ugit add", 8) == 0)
        {
            ugit_add(prompt);
        }
        else if (strncmp(prompt, "ugit commit", 11) == 0)
        {
            commit_count++;
            ugit_commit(commits, prompt, commit_count);
        }
        else if (strncmp(prompt, "ugit log", 8) == 0)
        {
            ugit_log(commits, commit_count);
        }
        else if (strncmp(prompt, "ugit branch", 11) == 0)
        {
            ugit_branch(prompt, branches, &branches_count);
        }
        else if (strncmp(prompt, "ugit checkout", 13) == 0)
        {
            if (ugit_checkout(prompt, branches, &branches_count))
            {
                ugit_branch_control(prompt, initial_prompt);
            }
        }
        else
        {
            printf("Comando desconocido\n");
        }
    }
}
