#include "../definicion_funciones/funciones.h"
/**
 * @file ugit_log.c
 * @brief Esta funcion permite ver el log de commits realizados en la rama
 *
 * @param branches se le debe pasar la estructura de datos actual de la rama
 * @param branch_name se le debe pasar el nombre de la rama actual para obtener el hash y buscarlo
 */

void ugit_log(Branch *branches, char *branch_name)
{
    int commit_count = branches[hash(branch_name)].commit_count;
    printf("----------------------------------------------------\n");
    if (commit_count > 0)
    {
        for (int i = 0; i < commit_count; i++)
        {
            printf("Author: Diego Sanhueza\n");
            printf("Commit: %ld\n", branches[hash(branch_name)].commit[i].commit_hash);
            printf("Descripcion: %s\n", branches[hash(branch_name)].commit[i].descripcion_commit);
            printf("----------------------------------------------------\n");
        }
    }
    else
    {
        printf("No hay commits\n");
        return;
    }
}
