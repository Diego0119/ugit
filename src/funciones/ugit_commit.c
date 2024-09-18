#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_commit.c
 * @brief Permite realizar un commit para manejar el historial de versiones en el sistema de control de versiones.
 *
 * Esta función realiza un commit en la rama actual del sistema de control de versiones. Un commit registra
 * los cambios en el historial de versiones con un mensaje descriptivo. La función verifica que se hayan añadido
 * archivos y que el mensaje de commit no esté vacío antes de proceder con el commit.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Realiza un commit para manejar el historial de versiones.
 *
 * La función `ugit_commit` agrega un nuevo commit al historial de versiones en la rama especificada. Verifica
 * que se hayan añadido archivos y que el mensaje de commit no esté vacío antes de proceder. Si todo es correcto,
 * se actualiza el historial de commits de la rama actual y se restablece la bandera de modificaciones.
 *
 * @param prompt Cadena de caracteres que contiene el mensaje del commit. El mensaje se extrae del comando `prompt`,
 *               comenzando desde el índice 11.
 * @param branch_name Cadena de caracteres que representa el nombre de la rama en la que se realiza el commit.
 * @param branches Estructura de datos que contiene todas las ramas y sus respectivos historiales de commits.
 *                 La función actualiza el historial de commits de la rama especificada.
 * @param modificacion_flag Bandera que indica si hay cambios no añadidos. La función verifica esta bandera para
 *                          asegurarse de que todos los cambios se hayan añadido antes de realizar el commit.
 *
 * @return No retorna ningún valor.
 *
 * @details La función realiza las siguientes operaciones:
 * - Extrae el mensaje del commit del comando `prompt` (comenzando en `prompt + 11`).
 * - Verifica si hay archivos añadidos y si el mensaje del commit no está vacío.
 * - Verifica si la bandera de modificaciones está activada (indicando que hay cambios no añadidos).
 * - Si todas las condiciones son correctas, actualiza el historial de commits de la rama actual con el mensaje
 *   del commit y el hash generado para el commit.
 * - Incrementa el contador de commits en la rama actual y restablece la bandera de modificaciones a 0.
 *
 * @note Asegúrese de que el comando `prompt` esté correctamente formateado y contenga el mensaje del commit en la
 *       posición correcta (a partir de `prompt + 11`).
 */
void ugit_commit(char *prompt, char *branch_name, Branch *branches, int *modificacion_flag)
{
    char *commit_message = prompt + 11;
    int commit_count = branches[hash(branch_name)].commit_count;
    if (strcmp(branches[hash(branch_name)].commit[commit_count].archivos_agregados, "") == 0)
    {
        printf("No se puede hacer un commit sin añadir archivos\n");
    }
    else if (strcmp(commit_message, "") == 0)
    {
        printf("No se puede hacer un commit sin descripcion\n");
    }
    else if (*modificacion_flag == 1)
    {
        printf("Hay cambios que no se han añadido\n");
    }
    else
    {
        strncpy(branches[hash(branch_name)].commit[commit_count].descripcion_commit, commit_message, MAX_INPUT_SIZE - 1);
        branches[hash(branch_name)].commit[commit_count].descripcion_commit[MAX_INPUT_SIZE - 1] = '\0';
        branches[hash(branch_name)].commit[commit_count].commit_hash = hash(prompt);
        branches[hash(branch_name)].commit_count++;
        *modificacion_flag = 0;
    }
}
