#include "../definicion_funciones/funciones.h"

void manejar_archivos(char *prompt, Branch *branches, char *branch_name, int *files_count, int *modificacion_flag)
{
    printf("Entro a la funcion manejar archivo\n");
    char *filename = prompt + 3;
    printf("Branch name: %s\n", branch_name);
    printf("El filename que llego fue: %s\n", filename);
    int hash_value = hash(branch_name); // calcula el hash una vez
    int commit_count = branches[hash_value].commit_count;
    printf("commit count: %d\n", commit_count);
    printf("nombre del archivo a buscar: %s\n", branches[hash_value].commit[commit_count].archivos_agregados);

    // verificar si el archivo ya está registrado en el commit actual
    int archivo_encontrado = 0;
    for (int i = 0; i < *files_count; i++)
    {

        if (strncmp(branches[hash_value].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME) == 0)
        {
            archivo_encontrado = 1;

            // abre el archivo en modo lectura y escritura
            printf("Llego a FILE* archivo = fopen(filename, r+\n");
            FILE *archivo = fopen(filename, "r+");

            if (archivo)
            {
                printf("El archivo '%s' ya existe. Contenido actual:\n", filename);

                char buffer[256];
                while (fgets(buffer, sizeof(buffer), archivo) != NULL)
                {
                    printf("%s", buffer); // muestra el contenido
                }

                printf("\nDesea agregar más contenido al archivo? (s/n): ");
                char opcion;
                scanf(" %c", &opcion);

                if (opcion == 's' || opcion == 'S')
                {
                    printf("Ingrese el contenido adicional:\n");
                    fseek(archivo, 0, SEEK_END); // mueve el puntero al final del archivo

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

            break; // archivo encontrado, no es necesario continuar
        }
    }

    // el segmentation fault esta para aca abajo
    // si el archivo no fue encontrado, crearlo
    if (!archivo_encontrado)
    {
        printf("Archivo no encontrado\n");
        // asegurarse de no exceder el límite de archivos
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

                // registra el archivo en la estructura de commits
                strncpy(branches[hash_value].commit[commit_count].archivos_agregados, filename, MAX_FILE_NAME - 1);
                branches[hash_value].commit[commit_count].archivos_agregados[MAX_FILE_NAME - 1] = '\0'; // Asegura la terminación en \0
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
