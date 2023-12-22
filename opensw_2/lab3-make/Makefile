PROJ_DIR = $(PWD)
SRC_DIR = $(PROJ_DIR)/src
INCLUDE_DIR = $(PROJ_DIR)/include
BIN_DIR = $(PROJ_DIR)/bin
OBJ_DIR = $(PROJ_DIR)/obj
LIB_DIR = $(PROJ_DIR)/lib

all: $(BIN_DIR)/myapp

OBJS = $(addprefix $(OBJ_DIR)/, func1.o func2.o)

$(BIN_DIR)/myapp: $(SRC_DIR)/main.c $(LIB_DIR)/libmyfuncs.a
	gcc $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lmyfuncs -o $@

$(LIB_DIR)/libmyfuncs.a: $(OBJS)
	ar rv $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -c $< -o $@ -I$(INCLUDE_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_DIR)/*
	

