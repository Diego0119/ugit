#include "../definicion_funciones/funciones.h"

Branch ugit_checkout(char *prompt, Branch *branches)
{
    char *branch_name = prompt + 14;
    // *initial_prompt = branch_name;
    // printf("nuevo prompt inicial: %s\n", initial_prompt);

    if (strcmp(branch_name, branches[hash(branch_name)].nombre_rama) == 0)
    {
        return branches[hash(branch_name)];
    }
    // else if (strcmp(numero_hash, branches[hash(branch_name)].commit->commit_hash) == 0)
    // {
    //     return branches[hash(branch_name)].commit;
    // }

    printf("No existe una rama con ese nombre\n");

    return branches[hash(branch_name)];
}
