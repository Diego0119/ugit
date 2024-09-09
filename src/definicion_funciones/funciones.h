#include <stdio.h>
#define MAX_INPUT_SIZE 100
#define MAX_COMMITS 100
#define MAX_BRANCHES 50
#include <string.h>

void ugit_version(void);
void commands_prompt(void);
void flow_control(void);
unsigned long hash(char *);
void ugit_branch_control(char *, char *);

// un commit tiene una descripcion
// un commit tiene un hash
struct commit
{
    char archivos_agregado[MAX_INPUT_SIZE];
    char descripcion_commit[MAX_INPUT_SIZE];
    long commit_hash;
};
// quede aca pensando como hacer que dentro de una rama esten
// los commits, y como hacer para cambiar de rama

typedef struct branch Branch;
typedef struct commit Commit;
void ugit_add(char *, Branch *, int *);
void ugit_commit(Commit *, char *, int);
void ugit_log(Commit *, int);
void ugit_branch(char *, Branch *, int *);
int ugit_checkout(char *, Branch *, int *);
void ugit_init(Branch *, int *, char *);

struct branch
{
    char nombre_rama[MAX_INPUT_SIZE];
    Commit commit[MAX_COMMITS];
};

// una rama tiene un nombre
// debe estar guardada en alguna parte
// una rama tiene commits, esos commits tienen un identificador
