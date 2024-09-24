#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_version.c
 * @brief Proporciona la versión del sistema de control de versiones uGit.
 * @authors Diego Sanhueza y Manuel Gonzalez
 * Este archivo contiene la implementación de la función `ugit_version`, que imprime la versión actual del sistema
 * de control de versiones `uGit` en la salida estándar.
 *
 * @version 1.0.0
 * @date 2024-09-17
 */

/**
 * @brief Imprime la versión actual del sistema de control de versiones uGit.
 *
 * La función `ugit_version` muestra en la consola la versión actual del software `uGit`. Esto es útil para verificar
 * qué versión del sistema se está utilizando y puede ser especialmente relevante durante el desarrollo y mantenimiento
 * del software.
 *
 * @return No devuelve ningún valor. La función imprime la versión en la salida estándar.
 *
 * @code
 * void ugit_version(void)
 * {
 *     printf("ugit version 1.0.0\n");
 * }
 * @endcode
 *
 * @details Al llamar a esta función, se imprimirá un mensaje que incluye el número de versión del sistema de control
 *          de versiones `uGit`. La salida es un simple mensaje de texto con el formato `ugit version X.X.X`, donde
 *          `X.X.X` representa la versión actual del software.
 */
void ugit_version(void)
{
    printf("ugit version 1.0.0\n");
}
