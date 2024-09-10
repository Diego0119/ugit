#include "../definicion_funciones/funciones.h"

void ugit_log(Branch *branches, int commit_count, char *branch_name)
{
    commit_count = branches[hash(branch_name)].commit_count;
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
