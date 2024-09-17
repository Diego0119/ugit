#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_init.c
 * @brief Esta funcion permite inicializar el repositorio
 * @code
 * void ugit_init(Branch *branches, char *initial_prompt, int *repositorio_flag)
 * {
 *      if (*repositorio_flag == 0)
 *      {
 *           printf("Repositorio de uGit incializado\n");
 *           ugit_branch("main", branches);
 *           ugit_branch_control("main", initial_prompt);
 *           *repositorio_flag = 1;
 *      }
 *      else
 *      {
 *           printf("Ya hay un repositorio inicializado\n");
 *      }
 *  }
 *
 * @endcond
 * @param branches se le debe pasar la estructura de datos actual de la rama
 * @param initial_prompt el programa identificara el prompt inicial al hacer el "ugit init"
 * @param repositorio_flag esta bandera sirve para saber si ya ha sido inicializado el repositorio
 */
void ugit_init(Branch *branches, char *initial_prompt, int *repositorio_flag)
{
    if (*repositorio_flag == 0)
    {
        printf("Repositorio de uGit incializado\n");
        ugit_branch("main", branches);
        ugit_branch_control("main", initial_prompt);
        *repositorio_flag = 1;
    }
    else
    {
        printf("Ya hay un repositorio inicializado\n");
    }
}
