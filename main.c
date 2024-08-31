#include "src/definicion_funciones/funciones.h"
#define MAX_INPUT_SIZE 100
#include <string.h>

int main(void)
{
    char prompt[MAX_INPUT_SIZE];

    while (strcmp(prompt, "exit") != 0)
    {
        if (fgets(prompt, sizeof(prompt), stdin) == NULL)
        {
            printf("Comando desconocido\n");
            return 1;
        }
        size_t len = strlen(prompt);
        if (len > 0 && prompt[len - 1] == '\n')
        {
            prompt[len - 1] = '\0';
        }
        if (strcmp(prompt, "ugit init") == 0)
        {
            ugit_init();
        }
        if (strcmp(prompt, "ugit --version") == 0)
        {
            ugit_version();
        }
    }
    return 0;
}
