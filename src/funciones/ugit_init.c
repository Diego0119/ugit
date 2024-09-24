#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_init.c
 * @authors Diego Sanhueza y Manuel Gonzalez
 * @brief Permite inicializar el repositorio del sistema de control de versiones.
 * Esta función se encarga de inicializar un nuevo repositorio para el sistema de control de versiones `uGit`.
 * Si el repositorio no ha sido inicializado previamente, solicita el nombre del usuario y configura la rama principal
 * (`main`) junto con el prompt inicial. También establece la bandera de repositorio como inicializada.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Inicializa el repositorio del sistema `uGit`.
 *
 * La función `ugit_init` configura el repositorio inicial del sistema de control de versiones `uGit`. Si el
 * repositorio no ha sido inicializado previamente, solicita el nombre del usuario y crea la rama principal
 * (`main`). También ajusta el prompt inicial y marca el repositorio como inicializado.
 *
 * @param branches Estructura de datos que contiene todas las ramas del repositorio. La función inicializa la
 *                 rama principal (`main`) en esta estructura.
 * @param initial_prompt Cadena de caracteres que representa el prompt inicial del sistema `uGit`. La función
 *                       actualiza este prompt para reflejar la rama principal (`main`) después de la inicialización.
 * @param repositorio_flag Bandera que indica si el repositorio ha sido inicializado. La función verifica este
 *                         flag para evitar la inicialización repetida del repositorio.
 *
 * @return Cadena de caracteres que contiene el nombre del usuario ingresado. Retorna `NULL` si el repositorio ya
 *         ha sido inicializado previamente.
 * @code
 * char *ugit_init(Branch *branches, char *initial_prompt, int *repositorio_flag)
 * {
 *     if (*repositorio_flag == 0)
 *     {
 *         char *user_name = (char *)malloc(256 * sizeof(char));
 *         if (user_name == NULL)
 *         {
 *             printf("Error al asignar memoria para el nombre del usuario.\n");
 *             exit(1);
 *         }
 *
 *         printf("Ingrese su nombre: ");
 *         fgets(user_name, 256, stdin);
 *
 *         size_t len = strlen(user_name);
 *         if (len > 0 && user_name[len - 1] == '\n')
 *         {
 *             user_name[len - 1] = '\0';
 *         }
 *
 *         printf("Repositorio de uGit inicializado\n");
 *         ugit_branch("main", branches);
 *         ugit_branch_control("main", initial_prompt);
 *         *repositorio_flag = 1;
 *
 *         return user_name;
 *     }
 *     else
 *     {
 *         printf("Ya hay un repositorio inicializado\n");
 *         return NULL;
 *     }
 * }
 * @endcode
 *
 * @details La función realiza las siguientes operaciones:
 * - Verifica si el repositorio ha sido inicializado previamente usando la bandera `repositorio_flag`.
 * - Si el repositorio no está inicializado (`repositorio_flag == 0`), solicita el nombre del usuario y lo almacena
 *   en la variable `user_name`.
 * - Elimina el salto de línea final del nombre del usuario, si existe.
 * - Imprime un mensaje indicando que el repositorio ha sido inicializado.
 * - Llama a la función `ugit_branch` para crear la rama principal (`main`).
 * - Llama a la función `ugit_branch_control` para ajustar el prompt inicial al de la rama principal (`main`).
 * - Establece la bandera `repositorio_flag` a 1 para indicar que el repositorio ha sido inicializado.
 * - Retorna el nombre del usuario ingresado.
 * - Si el repositorio ya ha sido inicializado, imprime un mensaje y retorna `NULL`.
 *
 * @note Asegúrese de que el nombre del usuario ingresado no exceda el límite de caracteres. La función
 *       utiliza `fgets` para leer la entrada del usuario y maneja el posible salto de línea al final de la cadena.
 */
char *ugit_init(Branch *branches, char *initial_prompt, int *repositorio_flag)
{
    if (*repositorio_flag == 0)
    {
        char *user_name = (char *)malloc(256 * sizeof(char));
        if (user_name == NULL)
        {
            printf("Error al asignar memoria para el nombre del usuario.\n");
            exit(1);
        }

        printf("Ingrese su nombre: ");
        fgets(user_name, 256, stdin);

        size_t len = strlen(user_name);
        if (len > 0 && user_name[len - 1] == '\n')
        {
            user_name[len - 1] = '\0';
        }

        printf("Repositorio de uGit inicializado\n");
        ugit_branch("main", branches);
        ugit_branch_control("main", initial_prompt);
        *repositorio_flag = 1;

        return user_name;
    }
    else
    {
        printf("Ya hay un repositorio inicializado\n");
        return NULL;
    }
}
