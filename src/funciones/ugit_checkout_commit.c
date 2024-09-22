#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_checkout_commit.c
 * @brief Permite realizar el checkout de un commit específico en una rama.
 *
 * Esta función permite al usuario cambiar al commit especificado en una rama determinada.
 * Se busca el commit en la rama basándose en el hash del commit proporcionado como cadena
 * de caracteres y se compara con los commits almacenados en la rama.

 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @param rama_hash El hash de la rama en la que se buscará el commit.
 * @param branches Arreglo de estructuras `Branch` que contiene información de todas las ramas y sus commits.
 * @param commit_hash Cadena de caracteres que contiene el hash del commit que se desea buscar y hacer checkout.
 *
 * @return Retorna 1 si el commit se encuentra en la rama y se realiza el cambio exitosamente,
 *         de lo contrario, retorna 0 si no se encuentra el commit con el hash especificado.
 *
 * @code
 * int ugit_checkout_commit(int rama_hash, Branch *branches, char *commit_hash)
 * {
 *     int hash_long = strtol(commit_hash, NULL, 10);
 *
 *     for (int i = 0; i < branches[rama_hash].commit_count; i++)
 *     {
 *         if (branches[rama_hash].commit[i].commit_hash == hash_long)
 *         {
 *             printf("Cambio al commit %ld en la rama %s.\n", hash_long, branches[rama_hash].nombre_rama);
 *             return 1;
 *         }
 *     }
 *
 *     printf("No se encontró un commit con el hash %ld en la rama.\n", hash_long);
 *     return 0;
 * }
 * @endcode
 *
 * @details La función realiza las siguientes operaciones:
 * - Convierte el hash del commit de cadena a número entero usando `strtol`.
 * - Itera a través de los commits en la rama correspondiente y compara el hash convertido con los hashes almacenados.
 * - Si encuentra el commit correspondiente, imprime un mensaje indicando el cambio de commit y retorna 1.
 * - Si no se encuentra el commit, muestra un mensaje de error y retorna 0.
 *
 * @note La conversión de la cadena `commit_hash` a número entero puede fallar si la entrada no es válida.
 */
int ugit_checkout_commit(int rama_hash, Branch *branches, char *commit_hash)
{
    int hash_long = strtol(commit_hash, NULL, 10);

    for (int i = 0; i < branches[rama_hash].commit_count; i++)
    {
        if (branches[rama_hash].commit[i].commit_hash == hash_long)
        {
            printf("Cambio al commit %ld en la rama %s.\n", hash_long, branches[rama_hash].nombre_rama);
            return 1;
        }
    }

    printf("No se encontró un commit con el hash %ld en la rama.\n", hash_long);
    return 0;
}
