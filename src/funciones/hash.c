#include "../definicion_funciones/funciones.h"

static int hashes_entregados[MAX_COMMITS];
static int count = 0;

/**
 * @file hash.c
 * @brief Implementación de la función de hashing para el sistema uGit.
 *
 * Este archivo contiene la implementación de la función `hash`, que calcula un valor de hash
 * para un string dado. El valor de hash se utiliza para identificar de manera única elementos
 * como commits en el sistema de control de versiones uGit.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Calcula un valor de hash para una cadena de caracteres.
 *
 * La función `hash` toma una cadena de caracteres como entrada y calcula un valor de hash
 * utilizando la suma de los valores ASCII de los caracteres de la cadena, seguida de una
 * operación de módulo para limitar el rango del hash.
 *
 * @param prompt Cadena de caracteres para la cual se calculará el valor de hash.
 * @return Un valor de hash único basado en la entrada proporcionada.
 *
 * @code
 * int hash(char *prompt)
 * {
 *     int temp_hash = 0;
 *     int hash = 0;
 *     int aux;
 *
 *     while ((aux = *prompt++))
 *     {
 *         temp_hash += aux;
 *     }
 *
 *     hash = temp_hash % 100;
 *
 *     hashes_entregados[count] = hash;
 *     count++;
 *
 *     for (int i = 0; i < count; i++)
 *     {
 *         if (hashes_entregados[i] == hash)
 *         {
 *             return hash + 1;
 *         }
 *     }
 *
 *     return hash;
 * }
 * @endcode
 *
 * @note La función da el hash respectivo dependiendo del prompt.
 *
 */
int hash(char *prompt)
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
