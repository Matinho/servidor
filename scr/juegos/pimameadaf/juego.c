// determinar si el numero es mayor o menor que el anterior

#include <juego.h>

int main(int argc, char *argv[]){

	int num1=0, num2=0, num3=0, opt=0;
	char datoIngresado[]="";
	time_t t;

	srand((unsigned) time(&t)); //creamos la semilla para el random

	printf( "\nEste es el juego del Par-Impar, Mayor-Menor, Adentro-Afuera.\n\n");
	printf( "\t BIENVENIDO\n");

	/*----------------Aca empieza Par Impar-----------------------*/

	/*Buscamos un munero entre 1 y 13*/
  num1=(rand()%13)+1;

	while (opt != 1 && opt != 2){
		printf("\n Elegi si el numero es Impar(1) o Par(2): ");
		scanf("%s",datoIngresado);
		opt=atoi(datoIngresado);
	}

	par_impar(num1, opt);

	/*-------------------------------------------------------------*/
	/*----------------Aca empieza Mayor Menor----------------------*/

	opt = 0;
	
	/*Buscamos un munero entre 1 y 13*/
	num2=rand()%13+1;
	while (num1==num2){
		num2=rand()%13+1;
	}

	/*Preguntamos si el siguiente numero es mayor o menor*/
	while (opt != 1 && opt != 2){
		printf("\n Elegi si el numero es Menor(1) o Mayor(2): ");
		scanf("%s",datoIngresado);
		opt=atoi(datoIngresado);
	}

	mayor_menor(num1, num2, opt);

	/*-------------------------------------------------------------*/
	/*---------------Aca empieza Adentro Afuera--------------------*/

	opt = 0;

	/*Buscamos un munero entre 1 y 13*/
  num3=rand()%13+1;
  while (num1==num3){
    num3=rand()%13+1;
  }
  while (num2==num3){
    num3=rand()%13+1;
  }

  if (num2<num1) printf( "\n\tSe formó el intervalo [%d,%d] \n\n", num2, num1);
  if (num2>num1) printf( "\n\tSe formó el intervalo [%d,%d] \n\n", num1, num2);

  while (opt != 1 && opt != 2){
    printf( "\n Elegi si el numero es Adentro(1) o Afuera(2): ");
    scanf("%s",datoIngresado);
    opt=atoi(datoIngresado);
  }

  printf( "\n\n\tEl numero que salió = %d\n\n", num3);

	afuera_adentro(num1, num2, num3, opt);

	/*-------------------------------------------------------------*/
}
