#include "../definicion_funciones/funciones.h"

void ugit_log(Commit *commit, int commit_count)
{
    // entra pero aun no puede acceder correctamente a la informacion
    for (int numero_commit = 0; numero_commit < commit_count; numero_commit++)
    {
        printf("Author: Diego Sanhueza\n");
        printf("Commit: %ld\n", commit[numero_commit].commit_hash);
        printf("Descripcion: %s\n", commit[numero_commit].descripcion_commit);
        printf("----------------------------------------------------\n");
    }
}
