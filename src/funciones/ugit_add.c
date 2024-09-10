#include "../definicion_funciones/funciones.h"

void ugit_add(char *prompt, Branch *branches, char *branch_name)
{
    char *filename = prompt + 9;
    int commit_count = branches[hash(branch_name)].commit_count;
    strcpy(branches[hash(branch_name)].commit[commit_count].archivos_agregado, filename);

    if (strcmp(filename, ".") == 0)
    {
        printf("Todos los archivos fueron añadidos\n");
    }
    else if (strlen(filename) > 0)
    {
        printf("El archivo '%s' fue añadido.\n", filename);
    }
    else
    {
        printf("No se proporcionó ningun archivo.\n");
    }
}
