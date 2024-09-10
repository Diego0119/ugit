#include "../definicion_funciones/funciones.h"

unsigned long hash(char *str)
{
    int hash = 0;
    int aux;
    while ((aux = *str++))
    {
        hash += aux; // ocupa el valor en la tabla ascii
    }
    // printf("%d\n", hash % 100);
    return hash % 100;
}
