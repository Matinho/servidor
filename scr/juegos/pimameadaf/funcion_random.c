#include <juego.h>

int * funcion_random(void) {

	static int numeros[3] = {0,0,0};
  time_t t;

  srand((unsigned) time(&t)); //creamos la semilla para el random

  numeros[0]=rand()%13+1;

  numeros[1]=rand()%13+1;
  while (numeros[1]==numeros[0]){
    numeros[1]=rand()%13+1;
  }

  numeros[2]=rand()%13+1;
  while (numeros[2]==numeros[0]){
    numeros[2]=rand()%13+1;
  }
  while (numeros[2]==numeros[1]){
    numeros[2]=rand()%13+1;
  }

  for (int i = 0; i < 3; i++) {
    printf( "numero[%d] = %d\n", i, numeros[i]);
  }

  return numeros;

}
