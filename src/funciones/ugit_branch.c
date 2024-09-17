#include "../definicion_funciones/funciones.h"
/**
 * @file ugit_branch.c
 * @brief Esta funcion permite crear nuevas ramas
 *
 * @param prompt se le debe pasar el prompt, que sera el nombre de la nueva rama que se desea
 * @param branches se le debe pasar la estructura de datos actual
 * @return retornara el nombre de la nueva rama
 */
char ugit_branch(char *prompt, Branch *branches)
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

    strncpy(branches[hash(branch_name)].nombre_rama, branch_name, MAX_INPUT_SIZE - 1);
    branches[hash(branch_name)].nombre_rama[MAX_INPUT_SIZE - 1] = '\0';
    branches[hash(branch_name)].commit_count = 0;
    return *branch_name;
}
