#include "../definicion_funciones/funciones.h"

static int hashes_entregados[MAX_COMMITS];
static int count = 0;

/**
 * @file generar_hash.c
 * @brief Implementación de la función de generación de hash única.
 *
 * Este archivo contiene la implementación de la función `generar_hash`,
 * que calcula un valor de hash único basado en una cadena de entrada.
 * Se asegura que el hash sea único dentro de un rango limitado de valores
 * utilizando un algoritmo de ajuste si ocurre una colisión.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Genera un hash único para una cadena de entrada.
 *
 * La función `generar_hash` toma una cadena como entrada y calcula un valor
 * de hash sumando los valores ASCII de los caracteres de la cadena y
 * utilizando la operación módulo para limitar el valor del hash. Si el hash
 * calculado ya ha sido entregado anteriormente, la función ajusta el valor
 * hasta que encuentra un hash único dentro del rango permitido (0-99).
 *
 * @param prompt Cadena de caracteres de la cual se calculará el hash.
 *
 * @code
 * static int hashes_entregados[MAX_COMMITS];
 * static int count = 0;
 *
 * int generar_hash(char *prompt)
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
 *     int unique = 0;
 *     while (!unique)
 *     {
 *         unique = 1;
 *
 *         for (int i = 0; i < count; i++)
 *         {
 *             if (hashes_entregados[i] == hash)
 *             {
 *                 hash = (hash + 1) % 100;
 *                 unique = 0;
 *                 break;
 *             }
 *         }
 *     }
 *
 *     hashes_entregados[count] = hash;
 *     count++;
 *
 *     return hash;
 * }
 * @endcode
 *
 * @return Un valor de hash único basado en la entrada proporcionada.
 *
 * @note La función garantiza que el hash sea único comparándolo con los
 * valores previamente generados y almacenados en `hashes_entregados[]`.
 */

int generar_hash(char *prompt)
{
    int temp_hash = 0;
    int hash = 0;
    int aux;

    while ((aux = *prompt++))
    {
        temp_hash += aux;
    }

    hash = temp_hash % 100;

    int unique = 0;
    while (!unique)
    {
        unique = 1;

        for (int i = 0; i < count; i++)
        {
            if (hashes_entregados[i] == hash)
            {
                hash = (hash + 1) % 100;
                unique = 0;
                break;
            }
        }
    }

    hashes_entregados[count] = hash;
    count++;

    return hash;
}
