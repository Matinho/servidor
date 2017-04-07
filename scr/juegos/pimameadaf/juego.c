// determinar si el numero es mayor o menor que el anterior

#include <juego.h>

int main(int argc, char *argv[]){

	int num1=0, num2=0, num3=0, opt=0, *num;
	char datoIngresado[]="";

	/*------------------- Funcion Random ---------------------------*/

	num = funcion_random();

	/*------------------------------------------------------------*/

	printf( "\nEste es el juego del Par-Impar, Mayor-Menor, Adentro-Afuera.\n\n");
	printf( "\t BIENVENIDO\n");

	/*----------------Aca empieza Par Impar-----------------------*/

	while (opt != 1 && opt != 2){
		printf("\n Elegi si el numero es Impar(1) o Par(2): ");
		scanf("%s",datoIngresado);
		opt=atoi(datoIngresado);
	}

	if (par_impar(num[0], opt)==0) return 0; //si perdió sale del programa

	/*-------------------------------------------------------------*/
	/*----------------Aca empieza Mayor Menor----------------------*/

	opt = 0;

	/*Preguntamos si el siguiente numero es mayor o menor*/
	while (opt != 1 && opt != 2){
		printf("\n Elegi si el numero es Menor(1) o Mayor(2): ");
		scanf("%s",datoIngresado);
		opt=atoi(datoIngresado);
	}

	if (mayor_menor(num[0], num[1], opt)==0) return 0; //si perdió sale del programa

	/*-------------------------------------------------------------*/
	/*---------------Aca empieza Adentro Afuera--------------------*/

	opt = 0;

  if (num[1]<num[0]) printf( "\n\tSe formó el intervalo [%d,%d] \n\n", num[1], num[0]);
  if (num[1]>num[0]) printf( "\n\tSe formó el intervalo [%d,%d] \n\n", num[0], num[1]);

  while (opt != 1 && opt != 2){
    printf( "\n Elegi si el numero es Adentro(1) o Afuera(2): ");
    scanf("%s",datoIngresado);
    opt=atoi(datoIngresado);
  }

  printf( "\n\n\tEl numero que salió = %d\n\n", num[2]); //si perdió sale del programa

	if(afuera_adentro(num[0], num[1], num[2], opt)==0) return 0;

	/*-------------------------------------------------------------*/
}
