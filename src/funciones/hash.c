#include "../definicion_funciones/funciones.h"

static int hashes_entregados[MAX_COMMITS];

static int count = 0;
/**
 * @file hash.h
 * @brief Esta funcion permite realizar un hasheo dado un string
 *
 * @param prompt este parametro permite obtener un hash dependiendo de las palabras
 * @return retornara un numero el cual sera el hash dado un prompt
 */
unsigned long hash(char *prompt)
{
    int temp_hash = 0;
    int hash = 0;
    int aux;
    while ((aux = *prompt++))
    {
        temp_hash += aux;
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
    }

    return hash;
}
