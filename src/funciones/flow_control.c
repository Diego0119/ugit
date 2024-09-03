#include "../definicion_funciones/funciones.h"

void flow_control(void)
{
    char prompt[MAX_INPUT_SIZE];
    Commit *commits;
    int commit_count = 0;

    while (strcmp(prompt, "exit") != 0)
    {
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
            ugit_init();
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
            commits = ugit_commit(prompt, commit_count);
        }
        else if (strncmp(prompt, "ugit log", 8) == 0)
        {
            ugit_log(commits, commit_count);
        }
    }
}
