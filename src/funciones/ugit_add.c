#include "../definicion_funciones/funciones.h"

void ugit_add(char *prompt, Branch *branches, int *branches_count)
{
    // aca debo hacer que cuando termine el git add
    // lea el nombre del "archivo" para despues diga que
    // ese archivo fue añadido
    char *filename = prompt + 9;

    strcpy(branches[*branches_count].commit->archivos_agregado, filename);
    printf("Nombre del archivo agregado en la estructura Branch\n");
    printf("%s\n", branches[*branches_count].commit->archivos_agregado);
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
        printf("no se proporcionó ningun archivo.\n");
    }
}
