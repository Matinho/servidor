// determinar si el numero que sale es par o si es impar

#include <juego.h>

int par_impar(int num1, int opt){

  /*----------------Aca empieza Par Impar-----------------------*/

  /*Comparamos el modulo del numero con lo que se eligió */
  /*Si el numero es par y si elegimos que sea par*/
  if ( num1%2==0 && opt==2){
    printf("\tEl numero que salió es %d es par y ganaste!\n", num1);
  }
  /*Si el numero es par y si elegimos que sea impar*/
  else if ( num1%2==0 && opt==1){
    printf("\tNo le pegaste, salió %d y es par\n", num1);
    return 0;
  }
  /*Si el numero es impar y si elegimos que sea impar*/
  else if ( num1%2==1 && opt==1){
    printf("\tEl numero que salió es %d es impar y ganaste!\n", num1);
  }
  /*Si el numero es impar y si elegimos que sea par*/
  else if ( num1%2==1 && opt==2){
    printf("\tNo le pegaste, salió %d y es impar\n", num1);
    return 0;
  }
  /*-------------------------------------------------------------*/

}
