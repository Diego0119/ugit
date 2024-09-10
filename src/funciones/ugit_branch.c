#include "../definicion_funciones/funciones.h"

char ugit_branch(char *prompt, Branch *branches, int *branches_count)
{
    char *branch_name;
    if (strcmp(prompt, "main") == 0)
    {
        branch_name = "main";
    }
    else
    {
        branch_name = prompt + 12;
        if (strcmp(branch_name, "") == 0)
        {
            printf("El nombre de la rama no puede ser vacio\n");
            return *branch_name;
        }
    }
    // genera el indice de la rama segun el nombre
    strncpy(branches[hash(branch_name)].nombre_rama, branch_name, MAX_INPUT_SIZE - 1);
    branches[hash(branch_name)].nombre_rama[MAX_INPUT_SIZE - 1] = '\0';
    (*branches_count)++;
    branches[hash(branch_name)].commit_count = 0;
    // printf("Nombre de la rama creada: %s\n", branches[*branches_count - 1].nombre_rama);
    return *branch_name;
}
