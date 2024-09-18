#include "../definicion_funciones/funciones.h"

/**
 * @file manejar_archivos.c
 * @brief Permite modificar y crear archivos desde la shell de uGit.
 *
 * Este archivo contiene la implementación de la función `manejar_archivos`, que gestiona
 * la creación y modificación de archivos dentro del sistema de control de versiones uGit.
 * Dependiendo del comando proporcionado, la función puede agregar contenido a un archivo existente
 * o crear un nuevo archivo si no existe.
 *
 * @version 0.1
 * @date 2024-09-17
 */

/**
 * @brief Modifica o crea un archivo basado en el comando proporcionado.
 *
 * La función `manejar_archivos` procesa un comando para manejar archivos dentro del repositorio.
 * Si el archivo especificado en el comando ya existe, la función permite agregar contenido adicional
 * al archivo o modificar el existente. Si el archivo no existe, se crea un nuevo archivo y se le
 * agrega el contenido inicial proporcionado por el usuario.
 *
 * @param prompt Cadena de caracteres que contiene el comando, incluyendo el nombre del archivo a manejar.
 * @param branches Array de estructuras `Branch` que representa el estado actual de las ramas y commits.
 * @param branch_name Nombre de la rama actual, usado para calcular el hash del archivo y verificar en qué commit está.
 * @param files_count Puntero a un entero que lleva el conteo de archivos acumulados en el repositorio.
 * @param modificacion_flag Puntero a un entero que indica si hay modificaciones activas (1) o no (0).
 *
 * @details La función:
 * - Asigna memoria para el nombre del archivo basado en el comando proporcionado.
 * - Verifica si el archivo ya existe en el repositorio.
 * - Si el archivo existe, permite al usuario agregar contenido adicional o modificar el existente.
 * - Si el archivo no existe, lo crea y agrega el contenido inicial proporcionado por el usuario.
 * - Actualiza la estructura de datos del commit y la bandera de modificación según corresponda.
 *
 * @note La función utiliza memoria dinámica para almacenar el nombre del archivo y el contenido.
 * Asegúrese de liberar esta memoria después de su uso para evitar fugas de memoria.
 */
void manejar_archivos(char *prompt, Branch *branches, char *branch_name, int *files_count, int *modificacion_flag)
{
    char *filename = (char *)malloc((strlen(prompt + 3) + 1) * sizeof(char));
    if (filename == NULL)
    {
        printf("Error al asignar memoria para el nombre del archivo\n");
        exit(1);
    }
    strcpy(filename, prompt + 3);
    int hash_value = hash(branch_name);
    int commit_count = branches[hash_value].commit_count;
    int archivo_encontrado = 0;
    for (int i = 0; i < *files_count; i++)
    {
        if (strncmp(branches[hash_value].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME) == 0)
        {
            archivo_encontrado = 1;

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
                    while (getchar() != '\n')
                        ;

                    printf("Ingrese el contenido adicional:\n");
                    fseek(archivo, 0, SEEK_END);
                    char *nuevo_contenido = (char *)malloc(256 * sizeof(char));
                    if (nuevo_contenido == NULL)
                    {
                        printf("Error al asignar memoria para el contenido adicional\n");
                        exit(1);
                    }
                    fgets(nuevo_contenido, 256, stdin);

                    fprintf(archivo, "%s", nuevo_contenido);
                    free(nuevo_contenido);
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
            if (archivo)
            {
                printf("El archivo '%s' no existía, ha sido creado.\n", filename);
                printf("Ingrese el contenido inicial del archivo:\n");

                char *contenido_inicial = (char *)malloc(256 * sizeof(char));
                if (contenido_inicial == NULL)
                {
                    printf("Error al asignar memoria para el contenido inicial\n");
                    exit(1);
                }
                fgets(contenido_inicial, 256, stdin);

                fprintf(archivo, "%s", contenido_inicial);
                fclose(archivo);
                free(contenido_inicial);

                *branches[hash_value].commit[commit_count].archivos_agregados = *(char *)malloc((strlen(filename) + 1) * sizeof(char));
                if (strcmp(branches[hash_value].commit[commit_count].archivos_agregados, " ") == 0)
                {
                    printf("Error al asignar memoria para archivos_agregados\n");
                    exit(1);
                }
                strcpy(branches[hash_value].commit[commit_count].archivos_agregados, filename);

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
    free(filename);
}
