#include "../definicion_funciones/funciones.h";

Commit ugit_commit(char *prompt)
{
    char *commit_message = prompt + 11;
    Commit commit;
    strcpy(commit.descripcion_commit, commit_message);
    commit.commit_hash = 123;
    return commit;
}