#include "../definicion_funciones/funciones.h"
/**
 * @file ugit_add.c
 * @brief Esta funcion permite añadir un archivo al area de "stagin"
 *
 *
 * @param prompt se le debe pasar el prompt, el cual sera el nombre del archivo, esto para poder verificar si existe
 * @param branches se debe pasar la estructura de datos actual para poder realizar modificaciones
 * @param branch_name se le debe pasar el nombre de la rama actual para realizar un hash y hacer el "add" donde se debe
 * @param modificacion_flag esta flag permite saber en que estado esta el repositorio (si hay modificaciones activas o si todo esta en "stagin")
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
