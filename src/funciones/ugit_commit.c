#include "../definicion_funciones/funciones.h"

void ugit_commit(Commit *commits, char *prompt, char *branch_name, Branch *branches)
{
    char *commit_message = prompt + 11;
    int commit_count = branches[hash(branch_name)].commit_count;
    if (strcmp(branches[hash(branch_name)].commit[commit_count].archivos_agregado, " ") == 0)
    {
        printf("No se puede hacer un commit sin añadir archivos\n");
    }
    else
    {
        strncpy(branches[hash(branch_name)].commit[commit_count].descripcion_commit, commit_message, MAX_INPUT_SIZE - 1);
        branches[hash(branch_name)].commit[commit_count].descripcion_commit[MAX_INPUT_SIZE - 1] = '\0';
        branches[hash(branch_name)].commit[commit_count].commit_hash = hash(prompt);
        branches[hash(branch_name)].commit_count++;
    }
}
