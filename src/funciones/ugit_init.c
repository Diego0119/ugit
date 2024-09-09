#include "../definicion_funciones/funciones.h"

void ugit_init(Branch *branches, int *branches_count, char *initial_prompt)
{
    printf("Repositorio de uGit incializado\n");
    ugit_branch("main", branches, branches_count);
    ugit_branch_control("main", initial_prompt);
}
