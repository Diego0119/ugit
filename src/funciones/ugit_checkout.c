#include "../definicion_funciones/funciones.h"

int ugit_checkout(char *prompt, Branch *branches, int *branches_count)
{
    char *branch_name = prompt + 14;
    // *initial_prompt = branch_name;
    // printf("nuevo prompt inicial: %s\n", initial_prompt);
    for (int i = 0; i < *branches_count; i++)
    {
        if (strcmp(branch_name, branches[i].nombre_rama) == 0)
        {
            printf("El nombre coincide con alguna rama: %s\n", branches[i].nombre_rama);
            return 1;
        }
    }
    printf("No existe una rama con ese nombre\n");
    return 0;
}
