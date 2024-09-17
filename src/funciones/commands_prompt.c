#include "../definicion_funciones/funciones.h"

/**
 * @file commands_prompt.c
 * @brief Esta funcion permite mostrar los comandos disponibles
 *@code
 *  void commands_prompt(void)
 *{
 *
 *   printf("Comandos disponibles:\n");
 *   printf("  init        - Inicializa un nuevo repositorio.\n");
 *   printf("  add <file>  - Añade un archivo al área de preparación.\n");
 *   printf("  commit <msg> - Realiza un commit con el mensaje especificado.\n");
 *   printf("  log         - Muestra el historial de commits.\n");
 *   printf("  branch <name> - Crea una nueva rama con el nombre especificado.\n");
 *   printf("  checkout <name> - Cambia a la rama especificada.\n");
 *   printf("  --version        - Muestra la version de ugit.\n");
 *   printf("  help        - Muestra esta ayuda.\n");
 * }
 *@endcode
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
    printf("  --version        - Muestra la version de ugit.\n");
    printf("  vi <nombre_archivo>       - Puedes crear archivos con vi.\n");
    printf("  help        - Muestra esta ayuda.\n");
}
