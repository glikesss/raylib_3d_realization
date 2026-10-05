RAYLIB ?= src/raylib/
INTERNAL ?= src/internal

RAYLIB_LIB ?= -I$(RAYLIB) -L$(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
FILES = main.c $(INTERNAL)/imath.c $(INTERNAL)/imatrix.c $(INTERNAL)/ivector.c 



all:
	tcc -o main $(FILES)  $(RAYLIB_LIB) -run

run:
	tcc -run -o main main.c -I$(RAYLIB) -L$(RAYLIB) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

