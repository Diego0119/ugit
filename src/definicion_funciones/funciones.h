#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT_SIZE 100
#define MAX_COMMITS 100
#define MAX_BRANCHES 50
#define MAX_FILES 100
#define MAX_CONTENT 512
#define MAX_FILE_NAME 256

void ugit_version(void);
void commands_prompt(void);
void flow_control(void);
unsigned long hash(char *);
void ugit_branch_control(char *, char *);

struct file
{
    char nombre_archivo[MAX_FILE_NAME];
    int hash_archivo;
    char contenido[MAX_CONTENT];
};

typedef struct file File;

struct commit
{
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

typedef struct branch Branch;

void ugit_add(char *, Branch *, char *, int *);
void ugit_commit(char *, char *, Branch *, int *);
void ugit_log(Branch *, char *);
char ugit_branch(char *, Branch *);
Branch ugit_checkout(char *, Branch *, char *);
void ugit_init(Branch *, char *, int *);
void manejar_archivos(char *, Branch *, char *, int *, int *);
