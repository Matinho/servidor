// determinar si el numero es mayor o menor que el anterior

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){

	int opt=0, num1=0, num2=0, num3=0, n=5, i;
	time_t t;

	printf( "\nEste es el juego del Par-Impar, Mayor-Menor, Adentro-Afuera.\n\n");
	printf( "\t BIENVENIDO\n\n");
	
	/*----------------Aca empieza Par Impar-----------------------*/
	printf( " Elegi si el numero es Par(0) o Impar(1):\n\n");

	scanf("%d",&opt);
	while (opt != 0 && opt != 1){
		printf("\nIngresá un valor valido, 0 para par o 1 para impar\n\n");
		scanf("%d",&opt);
	}

	srand((unsigned) time(&t));
	num1=rand()%14;
	while (num1==0){
		num1=rand()%14;
	}

	printf( "\tnumero que salió = %d\n\n", num1);	

	if ( num1%2==0 && opt%2==0){ 
		printf("\tEl numero salido %d es par\n", num1); 
	}
	else if ( num1%2==1 && opt%2==1){ 
		printf("\tEl numero salido %d es impar\n", num1); 
	}else if ( num1%2==0 && opt%2==1){ 
		printf("\tNo le pegaste, era par\n"); 
		return(0);
	}else if ( num1%2==1 && opt%2==0){ 
		printf("\tNo le pegaste, era impar\n"); 
		return(0);
	}
	/*-------------------------------------------------------------*/

	/*----------------Aca empieza Mayor Menor----------------------*/

	num2=rand()%14;
	while (num2==0){
		num2=rand()%14;
	}

	printf( "\n Elegi si el numero es Mayor(1) o Menor(0):\n\n");

	scanf("%d",&opt);

	while (opt != 0 && opt != 1){
		printf("\nIngresá un valor valido, 1 para mayor o 0 para menor\n\n");
		scanf("%d",&opt);
	}

	printf( "\n\tnumero que salió = %d\n\n", num2);

	if (num2 < num1 && opt==0){ 
		printf("\tEl numero salido %d es menor que el anterior %d, ELEGISTE BIEN \n", num2, num1); 
	}
	else if (num2 > num1 && opt==1){ 
		printf("\tEl numero salido %d es mayor al anterior %d, ELEGISTE BIEN \n", num2, num1); 
	}else if (num2 == num1){
		printf("\tEl numero salido %d y el numero anterior %d son iguales, que mala suerte tenes\n", num2 ,num1); 
	}else if (num2 < num1 && opt==1){
		printf("\tNo le pegaste, era menor\n");
		return(0);
	}else if (num2 < num1 && opt==0){
		printf("\tNo le pegaste, era mayor\n");
		return(0);
	}

	/*-------------------------------------------------------------*/

	/*---------------Aca empieza Adentro Afuera--------------------*/

	num3=rand()%14;
	while (num3==0){
		num3=rand()%14;
	}

	if (num2<num1) printf( "\n\tSe formó el intervalo [%d,%d] \n\n", num2, num1);
	if (num2>num1) printf( "\n\tSe formó el intervalo [%d,%d] \n\n", num1, num2);

	printf( "\n Elegi si el numero es Adentro(0) o Afuera(1):\n\n");

	scanf("%d",&opt);

	while (opt != 0 && opt != 1){
		printf("\nIngresá un valor valido, 0 para menor o 1 para mayor\n\n");
		scanf("%d",&opt);
	}

	printf( "\n\tEl numero que salió = %d\n\n", num3);

	//intervalo con el 2do numero menor
	if (num2<num1){
		//el num3 entra en el intevalo
		if (num2 < num3 && num1 >num3){ 
			printf("\tEl numero salido %d entra en el intervalo [%d,%d] \n", num3, num2, num1); 
		}
		//el num3 no entra en el intervalo
		else if (num1 < num3 && num2 >num3){ 
			printf("\tEl numero salido %d no entra en el intervalo [%d,%d] \n", num3, num1, num2); 
		}
	}

	//intervalo con el 1er numero menor
	if (num1<num2){
		//el num3 entra en el intevalo
		if (num1 < num3 && num2 >num3){ 
			printf("\tEl numero salido %d entra en el intervalo [%d,%d] \n", num3, num1, num2); 
		}
		//el num3 no entra en el intervalo
		else if (num2 < num3 && num1 >num3){ 
			printf("\tEl numero salido %d no entra en el intervalo [%d,%d] \n", num3, num2, num1); 
		}
	}

	/*-------------------------------------------------------------*/
}
