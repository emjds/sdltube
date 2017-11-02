OBJS = main.cpp init.cpp window.cpp cleanup.cpp

CC = g++

COMPILER_FLAGS =

LINKER_FLAGS = -lSDL2 -lSDL2_ttf

OBJ_NAME = sdltube

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)