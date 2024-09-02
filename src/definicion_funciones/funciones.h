#include <stdio.h>
#define MAX_INPUT_SIZE 10
#define MAX_COMMITS 100
#define COUNT 0
#include <string.h>

void ugit_init(void);
void ugit_add(char *);
void ugit_version(void);
void ugit_checkout(void);
void commands_prompt(void);
void flow_control(void);
int hash(void);

// un commit tiene una descripcion
// un commit tiene un hash
struct commit
{
    char descripcion_commit[MAX_INPUT_SIZE];
    long commit_hash;
};

typedef struct commit Commit;

void ugit_log(Commit *, int);
Commit ugit_commit(char *, int);

// una rama tiene un nombre
// debe estar guardada en alguna parte
// una rama tiene commits, esos commits tienen un identificador

struct branch
{
    char nombre_rama[MAX_INPUT_SIZE];
};
