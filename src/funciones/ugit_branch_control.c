#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_branch_control.c
 * @brief Permite cambiar el prompt de la shell basado en la rama actual.
 *
 * Esta función actualiza el prompt de la shell para reflejar la rama en la que se encuentra el usuario.
 * El prompt se ajusta para mostrar el nombre de la rama actual como parte del texto del prompt.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Cambia el prompt de la shell para reflejar la rama actual.
 *
 * La función `ugit_branch_control` actualiza el prompt de la shell (`actual_prompt`) para incluir
 * el nombre de la rama actual. Si el comando `prompt` es "main", el prompt se establece con el nombre
 * de la rama principal "main". Para otros nombres de ramas, se extrae el nombre de la rama del comando `prompt`.
 *
 * @param prompt Cadena de caracteres que contiene el comando actual. Si el comando es "main", el prompt
 *               se configura para mostrar "main". De lo contrario, se extrae el nombre de la rama del comando.
 * @param actual_prompt Cadena de caracteres donde se almacenará el nuevo texto del prompt de la shell.
 *
 * @details La función:
 * - Compara el comando `prompt` con el nombre de la rama principal "main".
 * - Si el comando es "main", el nombre de la rama se establece como "main".
 * - Si el comando es otro, se extrae el nombre de la rama del comando `prompt`.
 * - Actualiza el `actual_prompt` con el formato "ugit(nombre_rama) ".
 *
 * @note La función asume que el nombre de la rama está en una posición fija dentro del comando (`prompt + 14`)
 *       para comandos distintos a "main". Asegúrese de que los comandos sean válidos y estén correctamente formateados.
 */
void ugit_branch_control(char *prompt, char *actual_prompt)
{
    char *branch_name;
    if (strcmp(prompt, "main") == 0)
    {
        branch_name = "main";
    }
    else
    {
        branch_name = prompt + 14;
    }
    snprintf(actual_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_name);
}
