#include "../definicion_funciones/funciones.h"

Commit ugit_commit(char *prompt, int commit_count)
{
    char *commit_message = prompt + 11;
    Commit commit[MAX_COMMITS];
    strcpy(commit[commit_count].descripcion_commit, commit_message);
    commit[commit_count].commit_hash = 123;
    return *commit;
}