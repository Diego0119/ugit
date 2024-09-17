#include "../definicion_funciones/funciones.h"

/**
 * @file manejar_archivos.c
 * @brief Esta funcion permite modificar y crear archivos desde la shell de ugit
 *
 * @param prompt se le debe pasar por parametro el prompt para obtener el nombre del archivo
 * @param branches se le debe pasar la estructura de datos actual para guardar el archivo
 * @param branch_name se le debe pasar el nombre de la rama para poder realizar un hash con ese string
 * @param files_count se le debe para el numero de archivos acumulados
 * @param modificacion_flag este parametro es una flag que dependiendo de su valor (0 o 1) indica verdadero o falso, sirve para saber si hay modificaciones activas
 */
void manejar_archivos(char *prompt, Branch *branches, char *branch_name, int *files_count, int *modificacion_flag)
{
    printf("Entro a la funcion manejar archivo\n");
    char *filename = prompt + 3;
    printf("Branch name: %s\n", branch_name);
    printf("El filename que llego fue: %s\n", filename);
    int hash_value = hash(branch_name);
    int commit_count = branches[hash_value].commit_count;
    printf("commit count: %d\n", commit_count);
    printf("nombre del archivo a buscar: %s\n", branches[hash_value].commit[commit_count].archivos_agregados);

    int archivo_encontrado = 0;
    for (int i = 0; i < *files_count; i++)
    {

        if (strncmp(branches[hash_value].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME) == 0)
        {
            archivo_encontrado = 1;

            printf("Llego a FILE* archivo = fopen(filename, r+\n");
            FILE *archivo = fopen(filename, "r+");

            if (archivo)
            {
                printf("El archivo '%s' ya existe. Contenido actual:\n", filename);

                char buffer[256];
                while (fgets(buffer, sizeof(buffer), archivo) != NULL)
                {
                    printf("%s", buffer);
                }

                printf("\nDesea agregar más contenido al archivo? (s/n): ");
                char opcion;
                scanf(" %c", &opcion);

                if (opcion == 's' || opcion == 'S')
                {
                    printf("Ingrese el contenido adicional:\n");
                    fseek(archivo, 0, SEEK_END);

                    char nuevo_contenido[256];
                    fgets(nuevo_contenido, sizeof(nuevo_contenido), stdin);

                    fprintf(archivo, "%s", nuevo_contenido);
                }

                fclose(archivo);
                *modificacion_flag = 1;
            }
            else
            {
                printf("No se pudo abrir el archivo '%s'.\n", filename);
            }

            break;
        }
    }

    if (!archivo_encontrado)
    {
        printf("Archivo no encontrado\n");
        if (*files_count < MAX_FILES)
        {
            FILE *archivo = fopen(filename, "w");
            printf("Entro antes del FILE *archivo = fopen\n");
            if (archivo)
            {
                printf("El archivo '%s' no existía, ha sido creado.\n", filename);
                printf("Ingrese el contenido inicial del archivo:\n");

                char contenido_inicial[256];
                fgets(contenido_inicial, sizeof(contenido_inicial), stdin);

                fprintf(archivo, "%s", contenido_inicial);
                fclose(archivo);

                strncpy(branches[hash_value].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME - 1);
                branches[hash_value].commit[commit_count].archivos_agregados[MAX_FILE_NAME - 1] = '\0';
                (*files_count)++;
                *modificacion_flag = 1;
            }
            else
            {
                printf("No se pudo crear el archivo '%s'.\n", filename);
            }
        }
        else
        {
            printf("No se pueden añadir más archivos, límite alcanzado.\n");
        }
    }
}
