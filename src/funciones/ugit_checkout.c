#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_checkout.c
 * @authors Diego Sanhueza y Manuel Gonzalez
 * @brief Permite cambiar de una rama a otra en el sistema de control de versiones.
 * Esta función cambia la rama actual a la rama especificada en el comando `prompt`. Si la rama existe,
 * actualiza el prompt actual para reflejar el cambio. Si la rama no existe, muestra un mensaje de error.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Cambia la rama actual a la rama especificada en el comando `prompt`.
 *
 * La función `ugit_checkout` verifica si la rama especificada existe en la estructura de datos `branches`.
 * Si existe, actualiza el `initial_prompt` para reflejar la nueva rama y retorna la estructura de datos de
 * la rama seleccionada. Si la rama no existe, muestra un mensaje de error y retorna la estructura de datos
 * de la rama actual.
 *
 * @param prompt Cadena de caracteres que contiene el nombre de la rama a la que se desea cambiar. El nombre de
 *               la rama se extrae del comando `prompt`, comenzando desde el índice 14.
 * @param branches Estructura de datos que contiene todas las ramas. La función busca en esta estructura para
 *                 verificar si la rama especificada existe.
 * @param initial_prompt Cadena de caracteres que representa el prompt actual de la shell. Este prompt se
 *                       actualiza para reflejar el nombre de la nueva rama si la rama existe.
 *
 * @param actual_branch_name Nombre de la rama en la que esta actualmente el usuario.
 *
 * @return Retorna la estructura de datos de la rama a la cual se cambió. Si la rama no existe, retorna la
 *         estructura de datos de la rama actual.
 *
 * @code
 * Branch ugit_checkout(char *prompt, Branch *branches, char *initial_prompt, char *actual_branch_name)
 * {
 *     char *branch_or_hash = prompt + 14;
 *
 *     if (isdigit(branch_or_hash[0]))
 *     {
 *         if (ugit_checkout_commit(hash(actual_branch_name), branches, branch_or_hash) == 1)
 *         {
 *             snprintf(initial_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_or_hash);
 *         }
 *         return branches[hash(actual_branch_name)];
 *     }
 *
 *     if (strcmp(branch_or_hash, branches[hash(branch_or_hash)].nombre_rama) == 0)
 *     {
 *         if (strcmp(prompt, "main") == 0)
 *         {
 *             branch_or_hash = "main";
 *         }
 *         else if (strcmp(branch_or_hash, "") == 0)
 *         {
 *             printf("No existe una rama con ese nombre\n");
 *             return branches[hash(actual_branch_name)];
 *         }
 *         else
 *         {
 *             branch_or_hash = prompt + 14;
 *         }
 *         snprintf(initial_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_or_hash);
 *         return branches[hash(branch_or_hash)];
 *     }
 *
 *     printf("No existe una rama con ese nombre\n");
 *     return branches[hash(actual_branch_name)];
 * }
 * @endcode
 *
 * @details La función realiza las siguientes operaciones:
 * - Extrae el nombre de la rama del comando `prompt` (comenzando en `prompt + 14`).
 * - Compara el nombre de la rama extraído con las ramas existentes en la estructura de datos `branches`.
 * - Si el nombre de la rama coincide con una rama existente, actualiza `initial_prompt` con el nuevo nombre
 *   de la rama y retorna la estructura de datos correspondiente a esa rama.
 * - Si el nombre de la rama no coincide con ninguna rama existente, muestra un mensaje de error y retorna
 *   la estructura de datos de la rama actual.
 *
 * @note Se debe asegurar que la rama o el commit exista, en el caso de que no exista
 *       saldra un mensaje de error.
 */
Branch ugit_checkout(char *prompt, Branch *branches, char *initial_prompt, char *actual_branch_name)
{
    char *branch_or_hash = prompt + 14;

    if (isdigit(branch_or_hash[0]))
    {
        if (ugit_checkout_commit(hash(actual_branch_name), branches, branch_or_hash) == 1)
        {
            snprintf(initial_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_or_hash);
        }
        return branches[hash(actual_branch_name)];
    }

    if (strcmp(branch_or_hash, branches[hash(branch_or_hash)].nombre_rama) == 0)
    {
        if (strcmp(prompt, "main") == 0)
        {
            branch_or_hash = "main";
        }
        else if (strcmp(branch_or_hash, "") == 0)
        {
            printf("No existe una rama con ese nombre\n");
            return branches[hash(actual_branch_name)];
        }
        else
        {
            branch_or_hash = prompt + 14;
        }
        snprintf(initial_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_or_hash);
        return branches[hash(branch_or_hash)];
    }

    printf("No existe una rama con ese nombre\n");
    return branches[hash(actual_branch_name)];
}
