
CC=gcc
CFLAGS=-I.
DEPS = juego.h
OBJ = juego.o mayor_menor.o par_impar.o afuera_adentro.o funcion_random.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

juego: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
