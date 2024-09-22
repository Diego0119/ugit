#include "../definicion_funciones/funciones.h"

/**
 * @file commands_prompt.c
 * @brief Implementación de la función que muestra los comandos disponibles para uGit.
 *
 * Este archivo contiene la implementación de la función `commands_prompt`, que imprime
 * una lista de comandos disponibles en el sistema de control de versiones uGit.
 * Los comandos incluyen operaciones básicas como inicializar un repositorio, añadir archivos,
 * realizar commits, y cambiar entre ramas.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Muestra los comandos disponibles para uGit.
 *
 * Esta función imprime una lista de comandos que el usuario puede utilizar en uGit,
 * junto con una breve descripción de lo que hace cada comando. Es útil para proporcionar
 * ayuda rápida al usuario sobre cómo utilizar las funciones básicas del sistema de control
 * de versiones.
 *
 * Comandos disponibles:
 * - `init`        - Inicializa un nuevo repositorio.
 * - `add <file>`  - Añade un archivo al área de preparación.
 * - `commit <msg>` - Realiza un commit con el mensaje especificado.
 * - `log`         - Muestra el historial de commits.
 * - `branch <name>` - Crea una nueva rama con el nombre especificado.
 * - `checkout <name>` - Cambia a la rama especificada.
 * - `--version`   - Muestra la versión de uGit.
 * - `vi <nombre_archivo>` - Permite crear archivos con el editor vi.
 * - `help`        - Muestra esta ayuda.
 *
 * * @code
 * void commands_prompt(void)
 * {
 *     printf("Comandos disponibles:\n");
 *     printf("  init        - Inicializa un nuevo repositorio.\n");
 *     printf("  add <file>  - Añade un archivo al área de preparación.\n");
 *     printf("  commit <msg> - Realiza un commit con el mensaje especificado.\n");
 *     printf("  log         - Muestra el historial de commits.\n");
 *     printf("  branch <name> - Crea una nueva rama con el nombre especificado.\n");
 *     printf("  checkout <name> - Cambia a la rama especificada.\n");
 *     printf("  --version        - Muestra la versión de uGit.\n");
 *     printf("  vi <nombre_archivo>       - Puedes crear archivos con vi.\n");
 *     printf("  help        - Muestra esta ayuda.\n");
 * }
 * @endcode
 */
void commands_prompt(void)
{
    printf("Comandos disponibles:\n");
    printf("  init        - Inicializa un nuevo repositorio.\n");
    printf("  add <file>  - Añade un archivo al área de preparación.\n");
    printf("  commit <msg> - Realiza un commit con el mensaje especificado.\n");
    printf("  log         - Muestra el historial de commits.\n");
    printf("  branch <name> - Crea una nueva rama con el nombre especificado.\n");
    printf("  checkout <name> - Cambia a la rama especificada.\n");
    printf("  --version        - Muestra la versión de uGit.\n");
    printf("  vi <nombre_archivo>       - Puedes crear archivos con vi.\n");
    printf("  help        - Muestra esta ayuda.\n");
}
