#include "../definicion_funciones/funciones.h"

void ugit_branch_control(char *prompt, char *initial_prompt)
{
    char *branch_name = prompt + 14;
    snprintf(initial_prompt, MAX_INPUT_SIZE, "ugit(%s) ", branch_name);
}
