#include "../definicion_funciones/funciones.h"

void ugit_commit(Commit *commits, char *prompt, int commit_count)
{
    // hay que verificar en el caso que de 2 prompts sean iguales, en ese caso
    // se generarian hashes iguales y habria colision
    char *commit_message = prompt + 11;
    strncpy(commits[commit_count - 1].descripcion_commit, commit_message, MAX_INPUT_SIZE - 1);
    commits[commit_count - 1].descripcion_commit[MAX_INPUT_SIZE - 1] = '\0';
    commits[commit_count - 1].commit_hash = hash(prompt);
}
