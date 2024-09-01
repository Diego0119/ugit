#include <stdio.h>
#define MAX_INPUT_SIZE 100
#include <string.h>

void ugit_init(void);
void ugit_add(char *);
void ugit_version(void);
void ugit_commit(void);
void ugit_log(void);
void ugit_checkout(void);
void commands_prompt(void);
void flow_control(void);

// un commit tiene una descripcion
// un commit tiene un hash
struct commit
{
    char descripcion_commit[MAX_INPUT_SIZE];
    long commit_hash;
};

// una rama tiene un nombre
// debe estar guardada en alguna parte
// una rama tiene commits, esos commits tienen un identificador

struct branch
{
    char nombre_rama[MAX_INPUT_SIZE];
};
