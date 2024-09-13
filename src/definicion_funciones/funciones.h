#include <stdio.h>
#define MAX_INPUT_SIZE 100
#define MAX_COMMITS 100
#define MAX_BRANCHES 50
#define MAX_FILES 100
#define MAX_CONTENT 512
#define MAX_FILE_NAME 256
#include <string.h>

void ugit_version(void);
void commands_prompt(void);
void flow_control(void);
unsigned long hash(char *);
void ugit_branch_control(char *, char *);

// un commit tiene una descripcion
// un commit tiene un hash
struct file
{
    char nombre_archivo[MAX_FILE_NAME];
    int hash_archivo;
    char contenido[MAX_CONTENT];
};

typedef struct file File;

struct commit
{
    // char archivos_agregado[MAX_INPUT_SIZE];
    char descripcion_commit[MAX_INPUT_SIZE];
    long commit_hash;
    char archivos_agregados[MAX_FILE_NAME];
};

typedef struct commit Commit;

struct branch
{
    char nombre_rama[MAX_INPUT_SIZE];
    Commit commit[MAX_COMMITS];
    int commit_count;
};
// quede aca pensando como hacer que dentro de una rama esten
// los commits, y como hacer para cambiar de rama

typedef struct branch Branch;

void ugit_add(char *, Branch *, char *, int *);
void ugit_commit(char *, char *, Branch *, int *);
void ugit_log(Branch *, int, char *);
char ugit_branch(char *, Branch *, int *);
Branch ugit_checkout(char *, Branch *);
void ugit_init(Branch *, int *, char *, int *);

// una rama tiene un nombre
// debe estar guardada en alguna parte
// una rama tiene commits, esos commits tienen un identificador
void manejar_archivos(char *, Branch *, char *, int *, int *);
