CC=gcc
EXEC=program.out
GRUPO=11
NTAR=1

SRC_DIR=src/funciones
OBJ_DIR=obj
SRC_FILES=$(wildcard $(SRC_DIR)/*.c) 
OBJ_FILES=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
INCLUDE=-I./src/definicion_funciones/ 
LIBS=

CFLAGS=-Wall -Wextra -Wpedantic -O3
LDFLAGS= -Wall -lm 

all: folders incs_files $(OBJ_FILES)
	$(CC) $(CFLAGS) -o build/$(EXEC) main.c $(OBJ_FILES) $(INCLUDE) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(INCLUDE)

.PHONY: clean folders send
clean:
	rm -f $(OBJ_FILES)
	rm -f build/$(EXEC)

folders:
	mkdir -p src obj incs build docs

incs_files:
	cp src/definicion_funciones/*.h incs/

send:
	tar czf $(GRUPO)-$(NTAR).tgz --transform 's,^,$(GRUPO)-$(NTAR)/,' MAKEFILE src test README.MD incs

run: build/$(EXEC)
	./build/$(EXEC)
