#include "../definicion_funciones/funciones.h"

unsigned long hash(char *str)
{
    long hash = 0;
    int aux;
    while ((aux = *str++))
    {
        hash += aux; // ocupa el valor en la tabla ascii
    }

    return hash;
}