#include "../definicion_funciones/funciones.h"

void ugit_add(char *prompt)
{
    // aca debo hacer que cuando termine el git add
    // lea el nombre del "archivo" para despues diga que
    // ese archivo fue añadido
    char *filename = prompt + 9;
    if (strlen(filename) > 0)
    {
        printf("El archivo '%s' fue añadido.\n", filename);
    }
    else
    {
        printf("no se proporcionó ningun archivo.\n");
    }
}
