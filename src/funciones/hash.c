#include "../definicion_funciones/funciones.h"

unsigned long hash(char *str)
{
    int hashes_entregados[MAX_COMMITS];
    int count = 0;
    int temp_hash = 0;
    int hash = 0;
    int aux;
    while ((aux = *str++))
    {
        temp_hash += aux; // ocupa el valor en la tabla ascii
    }
    hash = temp_hash % 100;
    hashes_entregados[count] = hash;
    count++;

    for (int i = 0; i < count; i++)
    {
        if (hashes_entregados[i] == hash)
        {
            return hash + 1;
        }
        return hash;
    }
}