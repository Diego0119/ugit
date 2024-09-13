#include "../definicion_funciones/funciones.h"

void ugit_commit(char *prompt, char *branch_name, Branch *branches, int *modificacion_flag)
{

    char *commit_message = prompt + 11;
    int commit_count = branches[hash(branch_name)].commit_count;
    if (strcmp(branches[hash(branch_name)].commit[commit_count].archivos_agregados, "") == 0)
    {
        printf("No se puede hacer un commit sin añadir archivos\n");
    }
    else if (strcmp(commit_message, "") == 0)
    {
        printf("No se puede hacer un commit sin descripcion\n");
    }
    else if (*modificacion_flag == 1)
    {
        printf("Hay cambios que no se han añadido\n");
    }
    else
    {
        strncpy(branches[hash(branch_name)].commit[commit_count].descripcion_commit, commit_message, MAX_INPUT_SIZE - 1);
        branches[hash(branch_name)].commit[commit_count].descripcion_commit[MAX_INPUT_SIZE - 1] = '\0';
        branches[hash(branch_name)].commit[commit_count].commit_hash = hash(prompt);
        branches[hash(branch_name)].commit_count++;
        *modificacion_flag = 0;
    }
}
