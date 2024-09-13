#include "../definicion_funciones/funciones.h"

void ugit_add(char *prompt, Branch *branches, char *branch_name, int *modificacion_flag)
{
    char *filename = prompt + 9;
    int commit_count = branches[hash(branch_name)].commit_count;

    if (strncmp(branches[hash(branch_name)].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME) == 0)
    {
        if (strcmp(filename, ".") == 0)
        {
            printf("Todos los archivos fueron añadidos\n");
            *modificacion_flag = 0;
        }
        else if (strlen(filename) > 0)
        {
            printf("El archivo '%s' fue añadido.\n", filename);
            *modificacion_flag = 0;
        }
        else
        {
            printf("No se proporcionó ningun archivo.\n");
        }
    }
    else
    {
        printf("El archivo %s no existe\n", filename);
    }
}
