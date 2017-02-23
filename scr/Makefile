# CC, GFLAGS son constantes, DEPS es una macro
# CC=indica el compilador 
# GFLAGS=lista de banderas que le paso al compilador
# DEPS=conjunto de archivos .h de los que dependen los archivos .c

IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=../obj
IDIR=../lib

LIBS=-lm

_DEPS = server.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = server.o sigchld_handler.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

#Esta regla dice que va a generar los .O que se necesitan para compilar los .C
# -c indica que se van a generar objetos
# -c $@ indica que va a poner la salida en el archivo que esta determinado a su izquierda
# $< es el primer elemento en la lista de dependencias

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

# $^ indica que va a poner la salida en el archivo determinado a la derecha de los :

servidor: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean: 
	rm -f $(ODIR)/*.o *.~ core $(IDIR)/*~


