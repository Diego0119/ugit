#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_branch.c
 * @brief Permite crear nuevas ramas en el sistema de control de versiones.
 *
 * Esta función se encarga de crear una nueva rama en el sistema, utilizando el nombre proporcionado en
 * el comando `prompt`. Si el nombre de la rama es vacío, se muestra un mensaje de error. La nueva rama
 * se inicializa con un contador de commits en cero.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Crea una nueva rama en el sistema de control de versiones.
 *
 * La función `ugit_branch` agrega una nueva rama a la estructura de datos `branches`. La función verifica
 * si el nombre de la rama es "main", y si no, toma el nombre de la rama del comando `prompt`. Si el nombre
 * de la rama es vacío, se muestra un mensaje de error y la función termina.
 *
 * @param prompt Cadena de caracteres que contiene el comando para crear una nueva rama. El nombre de la rama
 *               se extrae de esta cadena. Si el nombre de la rama es vacío, se muestra un mensaje de error.
 * @param branches Estructura de datos que contiene todas las ramas y commits. La nueva rama se agrega a esta
 *                 estructura.
 *
 * @return No retorna ningún valor. La nueva rama se agrega directamente a la estructura `branches`.
 *
 * @details La función:
 * - Compara el nombre de la rama con "main" y, si coincide, usa "main" como nombre de la rama.
 * - Si el nombre de la rama no es "main", extrae el nombre de la rama del comando `prompt` y verifica que no esté vacío.
 * - Usa `strncpy` para copiar el nombre de la nueva rama en la estructura de datos `branches`.
 * - Inicializa el contador de commits de la nueva rama en cero.
 *
 * @note La función asume que el nombre de la rama comienza en la posición `prompt + 12` para comandos distintos
 *       a "main". Asegúrese de que los comandos sean válidos y correctamente formateados.
 */
void ugit_branch(char *prompt, Branch *branches)
{
    char *branch_name;
    if (strcmp(prompt, "main") == 0)
    {
        branch_name = "main";
    }
    else
    {
        branch_name = prompt + 12;
        if (strcmp(branch_name, "") == 0)
        {
            printf("El nombre de la rama no puede ser vacio\n");
            return;
        }
    }

    strncpy(branches[hash(branch_name)].nombre_rama, branch_name, MAX_INPUT_SIZE - 1);
    branches[hash(branch_name)].nombre_rama[MAX_INPUT_SIZE - 1] = '\0';
    branches[hash(branch_name)].commit_count = 0;
}
