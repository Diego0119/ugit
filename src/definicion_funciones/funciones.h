/**
 * @file funciones.h
 * @author Diego Sanhueza y Manuel Gonzalez
 * @brief En este archivo se encuentran los prototipos de las funciones y estructuras de uGit.
 * @version 0.1
 * @date 2024-09-17
 *
 * @copyright Copyright (c) 2024
 *
 * Este archivo contiene las definiciones de estructuras y los prototipos de funciones
 * utilizadas en el simulador de un sistema de control de versiones uGit.
 * Incluye funciones para manejar ramas, commits, archivos y control de versiones.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 100 ///< Tamaño máximo para entradas de texto.
#define MAX_COMMITS 100    ///< Número máximo de commits por rama.
#define MAX_BRANCHES 1000  ///< Número máximo de ramas en el repositorio.
#define MAX_FILES 100      ///< Número máximo de archivos en el repositorio.
#define MAX_CONTENT 512    ///< Tamaño máximo del contenido de un archivo.
#define MAX_FILE_NAME 256  ///< Tamaño máximo para nombres de archivo.

/**
 * @struct commit
 * @brief Estructura que representa un commit en uGit.
 *
 * Esta estructura contiene la descripción del commit, el hash del commit,
 * y los archivos asociados con el commit.
 */
struct commit
{
    char descripcion_commit[MAX_INPUT_SIZE]; ///< Descripción del commit.
    long commit_hash;                        ///< Hash único del commit.
    char archivos_agregados[MAX_FILE_NAME];  ///< Archivo(s) asociado(s) con el commit.
};

typedef struct commit Commit; ///< Alias para la estructura commit.

/**
 * @struct branch
 * @brief Estructura que representa una rama en uGit.
 *
 * Esta estructura contiene el nombre de la rama, una lista de commits y
 * el número de commits en la rama.
 */
struct branch
{
    char nombre_rama[MAX_INPUT_SIZE]; ///< Nombre de la rama.
    Commit commit[MAX_COMMITS];       ///< Lista de commits en la rama.
    int commit_count;                 ///< Número de commits en la rama.
};

typedef struct branch Branch; ///< Alias para la estructura branch.

/**
 * @brief Muestra la versión actual del sistema uGit.
 *
 * Esta función imprime la versión del software uGit.
 */
void ugit_version(void);

/**
 * @brief Muestra el menú de comandos del sistema uGit.
 *
 * Esta función muestra el menú de comandos y gestiona la entrada del usuario.
 */
void commands_prompt(void);

/**
 * @brief Controla el flujo de operaciones en uGit.
 *
 * Esta función gestiona el flujo de operaciones y llamadas a otras funciones según
 * las acciones solicitadas por el usuario.
 */
void flow_control(void);

/**
 * @brief Calcula el hash de una cadena de caracteres.
 *
 * Esta función toma una cadena de caracteres y devuelve un valor hash basado en
 * el contenido de la cadena.
 *
 * @param input Cadena de caracteres para calcular el hash.
 * @return Valor hash calculado.
 */
int hash(char *input);

/**
 * @brief Controla las operaciones relacionadas con ramas.
 *
 * Esta función gestiona la creación, eliminación y cambio entre ramas en uGit.
 *
 * @param branch_name Nombre de la rama a gestionar.
 * @param action Acción a realizar en la rama (crear, eliminar, cambiar).
 */
void ugit_branch_control(char *branch_name, char *action);

/**
 * @brief Controla la creación de nuevas ramas.
 *
 * Esta funcion permite crear una nueva rama.
 *
 * @param prompt Nombre de la nueva rama que se desa crear.
 * @param branches Puntero a la estructura, para crear una nueva rama.
 */

void ugit_branch(char *prompt, Branch *branches);
/**
 * @brief Agrega un archivo al repositorio.
 *
 * Esta función agrega un archivo al repositorio y actualiza la lista de archivos
 * en la rama actual.
 *
 * @param file_name Nombre del archivo a agregar.
 * @param branch Puntero a la rama en la que se agregará el archivo.
 * @param file_content Contenido del archivo.
 * @param file_size Tamaño del contenido del archivo.
 */
void ugit_add(char *file_name, Branch *branch, char *file_content, int *file_size);

/**
 * @brief Crea un nuevo commit.
 *
 * Esta función crea un nuevo commit con los archivos añadidos y actualiza la lista
 * de commits en la rama actual.
 *
 * @param message Mensaje del commit.
 * @param author Autor del commit.
 * @param branch Puntero a la rama en la que se realizará el commit.
 * @param commit_count Puntero al número de commits en la rama.
 */
void ugit_commit(char *message, char *author, Branch *branch, int *commit_count);

/**
 * @brief Muestra el historial de commits.
 *
 * Esta función muestra el historial de commits de una rama específica.
 *
 * @param branch Puntero a la rama cuyo historial se desea ver.
 * @param start_date Fecha de inicio del rango de commits a mostrar.
 * @param end_date Fecha de fin del rango de commits a mostrar.
 */
void ugit_log(Branch *branch, char *start_date, char *end_date);

/**
 * @brief Cambia a una rama específica.
 *
 * Esta función cambia la rama activa al nombre de rama especificado.
 *
 * @param branch_name Nombre de la rama a la que se desea cambiar.
 * @param branch Puntero a la rama activa actual.
 * @param action Acción a realizar durante el cambio de rama.
 * @return Rama actualizada después del cambio.
 */
Branch ugit_checkout(char *branch_name, Branch *branch, char *action);

/**
 * @brief Inicializa un nuevo repositorio.
 *
 * Esta función inicializa un nuevo repositorio uGit y configura las ramas y archivos
 * necesarios.
 *
 * @param branch Puntero a la rama inicial del repositorio.
 * @param repo_path Ruta del repositorio.
 * @param branch_count Número de ramas en el repositorio.
 * @return Mensaje de estado de la inicialización.
 */
char *ugit_init(Branch *branch, char *repo_path, int *branch_count);

/**
 * @brief Maneja archivos en el repositorio.
 *
 * Esta función gestiona operaciones de archivo como apertura, lectura, escritura y
 * cierre dentro del repositorio uGit.
 *
 * @param file_name Nombre del archivo a manejar.
 * @param branch Puntero a la rama en la que se encuentra el archivo.
 * @param file_content Contenido del archivo.
 * @param file_size Tamaño del contenido del archivo.
 * @param action Acción a realizar en el archivo.
 * @param status Código de estado de la operación.
 */
void manejar_archivos(char *file_name, Branch *branch, char *file_content, int *file_size, int *action);
