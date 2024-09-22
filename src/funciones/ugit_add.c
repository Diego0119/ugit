#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_add.c
 * @brief Permite añadir un archivo al área de "staging" de uGit.
 *
 * Esta función maneja la adición de archivos al área de "staging" en el sistema de control
 * de versiones uGit. Dependiendo del comando proporcionado, la función puede añadir un archivo
 * específico al área de "staging" o añadir todos los archivos si se usa el comando correspondiente.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Añade un archivo al área de "staging" o maneja el comando para añadir todos los archivos.
 *
 * La función `ugit_add` procesa un comando para añadir archivos al área de "staging". Si el archivo
 * especificado en el comando está presente en la estructura de datos de commits, el archivo se marca
 * como añadido. También maneja el caso especial donde el comando solicita añadir todos los archivos.
 *
 * @param prompt Cadena de caracteres que contiene el comando, incluyendo el nombre del archivo a añadir.
 * @param branches Array de estructuras `Branch` que representa el estado actual de las ramas y commits.
 * @param branch_name Nombre de la rama actual, utilizado para calcular el hash y determinar el commit correspondiente.
 * @param modificacion_flag Puntero a un entero que indica si hay modificaciones activas (1) o si todo está en "staging" (0).
 *
 /**
 * @brief Añade un archivo al área de "staging" o maneja el comando para añadir todos los archivos.
 *
 * La función `ugit_add` procesa un comando para añadir archivos al área de "staging". Si el archivo
 * especificado en el comando está presente en la estructura de datos de commits, el archivo se marca
 * como añadido. También maneja el caso especial donde el comando solicita añadir todos los archivos.
 *
 * @param prompt Cadena de caracteres que contiene el comando, incluyendo el nombre del archivo a añadir.
 * @param branches Array de estructuras `Branch` que representa el estado actual de las ramas y commits.
 * @param branch_name Nombre de la rama actual, utilizado para calcular el hash y determinar el commit correspondiente.
 * @param modificacion_flag Puntero a un entero que indica si hay modificaciones activas (1) o si todo está en "staging" (0).
 *
 * @code
 * void ugit_add(char *prompt, Branch *branches, char *branch_name, int *modificacion_flag)
 * {
 *     char *filename = prompt + 9;
 *     int commit_count = branches[hash(branch_name)].commit_count;
 *
 *     if (strncmp(branches[hash(branch_name)].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME) == 0)
 *     {
 *         if (strcmp(filename, ".") == 0)
 *         {
 *             printf("Todos los archivos fueron añadidos\n");
 *             *modificacion_flag = 0;
 *         }
 *         else if (strlen(filename) > 0)
 *         {
 *             printf("El archivo '%s' fue añadido.\n", filename);
 *             *modificacion_flag = 0;
 *         }
 *         else
 *         {
 *             printf("No se proporcionó ningun archivo.\n");
 *         }
 *     }
 *     else
 *     {
 *         printf("El archivo '%s' no existe\n", filename);
 *     }
 * }
 * @endcode
 *
 * @details La función:
 * - Extrae el nombre del archivo del comando proporcionado.
 * - Verifica si el archivo existe en el área de "staging".
 * - Si el archivo existe, actualiza el flag de modificaciones para indicar que los cambios han sido añadidos.
 * - Si el archivo no existe, muestra un mensaje de error.
 * - Si el comando es para añadir todos los archivos (especificado como "."), marca todos los archivos como añadidos.
 *
 * @note La función asume que el nombre del archivo está en una posición fija dentro del comando (`prompt + 9`).
 *
 */
void ugit_add(char *prompt, Branch *branches, char *branch_name, int *modificacion_flag)
{
    char *filename = prompt + 9;
    int commit_count = branches[hash(branch_name)].commit_count;

    if (strncmp(branches[hash(branch_name)].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME) == 0)
    {
        if (strcmp(filename, ".") == 0)
        {
            printf("Todos los archivos fueron añadidos\n");
            *modificacion_flag = 0;
        }
        else if (strlen(filename) > 0)
        {
            printf("El archivo '%s' fue añadido.\n", filename);
            *modificacion_flag = 0;
        }
        else
        {
            printf("No se proporcionó ningun archivo.\n");
        }
    }
    else
    {
        printf("El archivo '%s' no existe\n", filename);
    }
}
