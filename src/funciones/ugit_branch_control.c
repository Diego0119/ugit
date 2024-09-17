#include "../definicion_funciones/funciones.h"

/**
 * @file ugit_branch_control.c
 * @brief Esta función permite cambiar el prompt de la shell
 *
 * @param prompt se le debe pasar el prompt que desea el programa
 * @param actual_prompt se le debe pasar el prompt actual de la shell
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
