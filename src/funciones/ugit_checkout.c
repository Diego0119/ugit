#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_checkout.c
 * @brief Esta funcion permite cambiar de una rama a otra
 *
 *
 * @param prompt se le debe pasar el nombre de la rama a la cual se desea ir
 * @param branches se le debe pasar la estrucutra de datos actual de la rama
 * @param initial_prompt se le debe el prompt actual para poder cambiarlo por el nuevo en el caso que la rama exista
 * @return retornara la estructura de datos de la rama a la cual se cambio
 */

Branch ugit_checkout(char *prompt, Branch *branches, char *initial_prompt)
{
    char *branch_name = prompt + 14;

    if (strcmp(branch_name, branches[hash(branch_name)].nombre_rama) == 0)
    {
        if (strcmp(prompt, "main") == 0)
        {
            branch_name = "main";
        }
        else if (strcmp(branch_name, "") == 0)
        {
            printf("No existe una rama con ese nombre\n");
            return *branches;
        }
        else
        {
            branch_name = prompt + 14;
        }
        snprintf(initial_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_name);
        return branches[hash(branch_name)];
    }

    printf("No existe una rama con ese nombre\n");

    return branches[hash(branch_name)];
}
