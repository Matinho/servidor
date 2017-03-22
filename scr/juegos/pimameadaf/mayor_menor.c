// determinar si el numero es mayor o menor que el anterior

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[]){

	int num1=0, num2=0, num3=0, n=5, i, opt=0;
	char datoIngresado[]="";
	time_t t;

	printf( "\nEste es el juego del Par-Impar, Mayor-Menor, Adentro-Afuera.\n\n");
	printf( "\t BIENVENIDO\n");

	/*----------------Aca empieza Par Impar-----------------------*/

	while (opt != 1 && opt != 2){
		printf("\n Elegi si el numero es Impar(1) o Par(2): ");
		scanf("%s",datoIngresado);
		opt=atoi(datoIngresado);
	}


	srand((unsigned) time(&t)); //creamos la semilla para el random

	/*Buscamos un munero entre 1 y 13*/
	num1=(rand()%13)+1;

	/*Comparamos el modulo del numero con lo que se eligió */
	/*Si el numero es par y si elegimos que sea par*/
	if ( num1%2==0 && opt==2){
		printf("\tEl numero que salió es %d es par y ganaste!\n", num1);
	}
	/*Si el numero es par y si elegimos que sea impar*/
	else if ( num1%2==0 && opt==1){
		printf("\tNo le pegaste, salió %d y es par\n", num1);
		return(0);
	}
	/*Si el numero es impar y si elegimos que sea impar*/
	else if ( num1%2==1 && opt==1){
		printf("\tEl numero que salió es %d es impar y ganaste!\n", num1);
	}
	/*Si el numero es impar y si elegimos que sea par*/
	else if ( num1%2==1 && opt==2){
		printf("\tNo le pegaste, salió %d y es impar\n", num1);
		return(0);
	}
	/*-------------------------------------------------------------*/

	/*----------------Aca empieza Mayor Menor----------------------*/

	opt=0;
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

	/*Evaluamos si el numero que salió es mayor o menor y si se eligió bien*/
	if (num2 < num1 && opt==1){
		printf("\tEl numero que salio es %d es menor que el anterior %d, ELEGISTE BIEN \n", num2, num1);
	}
	else if (num2 > num1 && opt==2){
		printf("\tEl numero que salio es %d es mayor al anterior %d, ELEGISTE BIEN \n", num2, num1);
	}
	else if (num2 == num1){
		printf("\tEl numero que salio es %d y el numero anterior %d, son iguales, que mala suerte tenes\n", num2 ,num1);
	}
	else if (num2 < num1 && opt==2){
		printf("\tNo le pegaste, salió %d y es menor que %d \n", num2, num1);
		return(0);
	}
	else if (num2 > num1 && opt==1){
		printf("\tNo le pegaste, salió %d y es mayor que %d \n", num2, num1);
		return(0);
	}

	/*-------------------------------------------------------------*/

	/*---------------Aca empieza Adentro Afuera--------------------*/

	opt=0;
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

	/*Elige adentro*/
	if (opt==1){
		//intervalo con el 1er numero menor
		if (num1<num2){
			if (num1 < num3 && num2 > num3){
					printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
				} else{
					 printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
				}
		}
		//intervalo con el 2do numero menor
		if (num2<num1){
			//el num3 entra en el intevalo
			if (num2 < num3 && num1 > num3){
					printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
				} else{
					 printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
				}
		}
	}

	/*Elige afuera*/
	if (opt==2){
		//intervalo con el 1er numero menor
		if (num1<num2){
			if (num1 > num3 || num2 < num3){
					printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
				} else{
					 printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
				}
		}
		//intervalo con el 2do numero menor
		if (num2<num1){
			//el num3 entra en el intevalo
			if (num2 < num3 || num1 > num3){
					printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
				} else{
					 printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
				}
		}
	}

	/*-------------------------------------------------------------*/
}
