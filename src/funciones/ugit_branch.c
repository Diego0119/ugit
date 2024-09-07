#include "../definicion_funciones/funciones.h"

void ugit_branch(char *prompt, Branch *branches, int *branches_count)
{
    char *branch_name = prompt + 12;
    strncpy(branches[*branches_count].nombre_rama, branch_name, MAX_INPUT_SIZE - 1);
    branches[*branches_count].nombre_rama[MAX_INPUT_SIZE - 1] = '\0';
    (*branches_count)++;
    printf("Nombre de la rama creada: %s\n", branches[*branches_count - 1].nombre_rama);
}
