#include "../definicion_funciones/funciones.h"
/**
 * @file ugit_log.c
 * @authors Diego Sanhueza y Manuel Gonzalez
 * @brief Permite visualizar el historial de commits realizados en una rama específica.
 * Esta función muestra el historial de commits realizados en la rama actual del sistema de control de versiones `uGit`.
 * Imprime detalles de cada commit, incluyendo el autor, el hash del commit y la descripción asociada.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Muestra el historial de commits de una rama.
 *
 * La función `ugit_log` imprime el historial de commits de la rama especificada. Muestra información sobre cada commit,
 * incluyendo el autor (nombre del usuario), el hash del commit y la descripción del commit.
 *
 * @param branches Estructura de datos que contiene todas las ramas del repositorio. La función accede a la rama
 *                 especificada por `branch_name` para obtener el historial de commits.
 * @param branch_name Cadena de caracteres que representa el nombre de la rama actual para la cual se desea ver
 *                    el historial de commits. La función utiliza este nombre para buscar los commits en la estructura
 *                    de datos.
 * @param user_name Cadena de caracteres que representa el nombre del autor de los commits. Este nombre se imprime
 *                  junto con los detalles de cada commit.
 *
 * @return No devuelve ningún valor. La función imprime el historial de commits en la salida estándar.
 *
 * @code
 * void ugit_log(Branch *branches, char *branch_name, char *user_name)
 * {
 *     int commit_count = branches[hash(branch_name)].commit_count;
 *     printf("----------------------------------------------------\n");
 *     if (commit_count > 0)
 *     {
 *         for (int i = 0; i < commit_count; i++)
 *         {
 *             printf("Author: %s\n", user_name);
 *             printf("Commit: %ld\n", branches[hash(branch_name)].commit[i].commit_hash);
 *             printf("Descripcion: %s\n", branches[hash(branch_name)].commit[i].descripcion_commit);
 *             printf("----------------------------------------------------\n");
 *         }
 *     }
 *     else
 *     {
 *         printf("No hay commits\n");
 *         return;
 *     }
 * }
 * @endcode
 *
 * @details La función realiza las siguientes operaciones:
 * - Obtiene el número total de commits en la rama especificada utilizando el contador de commits en la estructura
 *   de datos `branches`.
 * - Imprime una línea separadora para mejorar la legibilidad de la salida.
 * - Si hay commits disponibles (`commit_count > 0`), itera a través de cada commit e imprime:
 *   - El nombre del autor del commit (`user_name`).
 *   - El hash del commit.
 *   - La descripción del commit.
 *   - Una línea separadora después de cada commit para facilitar la lectura.
 * - Si no hay commits disponibles, imprime un mensaje indicando que no hay commits.
 *
 * @note Solo se mostraran los logs de la rama en la cual se haga el `ugit log`.
 */
void ugit_log(Branch *branches, char *branch_name, char *user_name)
{
    int commit_count = branches[hash(branch_name)].commit_count;
    printf("----------------------------------------------------\n");
    if (commit_count > 0)
    {
        for (int i = 0; i < commit_count; i++)
        {
            printf("Author: %s\n", user_name);
            printf("Commit: %ld\n", branches[hash(branch_name)].commit[i].commit_hash);
            printf("Descripcion: %s\n", branches[hash(branch_name)].commit[i].descripcion_commit);
            printf("----------------------------------------------------\n");
        }
    }
    else
    {
        printf("No hay commits\n");
        return;
    }
}
