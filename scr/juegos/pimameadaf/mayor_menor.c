// determinar si el numero es mayor o menor que el anterior

#include <juego.h>

void mayor_menor(int num1, int num2, int opt){
	/*----------------Aca empieza Mayor Menor----------------------*/

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

}
