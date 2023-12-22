PROJ_DIR = $(PWD)
SRC_DIR = $(PROJ_DIR)/src
INCLUDE_DIR = $(PROJ_DIR)/include
BIN_DIR = $(PROJ_DIR)/bin
OBJ_DIR = $(PROJ_DIR)/obj
LIB_DIR = $(PROJ_DIR)/lib

all: $(BIN_DIR)/myapp.shared

OBJS = $(addprefix $(OBJ_DIR)/, func1.o func2.o main.o)

$(BIN_DIR)/myapp.shared: $(SRC_DIR)/main.c $(LIB_DIR)/libmyfuncs.so.1.0
	gcc -fPIC $< -I$(INCLUDE_DIR) -L$(LIB_DIR) -lmyfuncs -o $@\
	export = LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(LIB_DIR)

$(LIB_DIR)/libmyfuncs.so: libmyfuncs.so.1.0
	ln -s $^ $@

$(LIB_DIR)/libmyfuncs.so.1: libmyfuncs.so.1.0
	ln -s $^ $@

$(LIB_DIR)/libmyfuncs.so.1: $(OBJS)
	gcc -shared -Wl, -soname=libmyfuncs.so.1 -o lib/libmyfuncs.so.1.0 $< -lc

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -fPIC -c $< -o $@ -I$(INCLUDE_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/*
	rm -f $(LIB_DIR)/*
	

