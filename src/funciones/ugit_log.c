#include "../definicion_funciones/funciones.h"

void ugit_log(Commit *commit, int commit_count)
{
    printf("entro a ugit_log");
    for (int i = 0; i < commit_count; i++)
    {
        printf("%ld\n", commit->commit_hash);
        printf("%s\n", commit->descripcion_commit);
    }
}
