// determinar si el numero siguiente esta dentro o afuera del intervalo dado por dos numeros anteriores

#include <juego.h>

int afuera_adentro(int num1, int num2, int num3, int opt){

  /*---------------Aca empieza Adentro Afuera--------------------*/

  /*Elige adentro*/
  if (opt==1){
    //intervalo con el 1er numero menor
    if (num1<num2){
      if (num1 < num3 && num2 > num3){
          printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
        } else{
           printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
           return 0;
        }
    }
    //intervalo con el 2do numero menor
    if (num2<num1){
      //el num3 entra en el intevalo
      if (num2 < num3 && num1 > num3){
          printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
        } else{
           printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
           return 0;
        }
    }
  }

  /*Elige afuera*/
  if (opt==2){
    //intervalo con el 1er numero menor
    if (num1<num2){
      if (num1 < num3 && num2 > num3){
          printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
          return 0;
        } else{
           printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
        }
    }
    //intervalo con el 2do numero menor
    if (num2<num1){
      //el num3 entra en el intevalo
      if (num2 < num3 && num1 > num3){
          printf("\tEl numero que salio es %d entra en el intervalo [%d,%d] y PERDISTE\n", num3, num2, num1);
          return 0;
        } else{
           printf("\tEl numero que salio es %d no entra en el intervalo [%d,%d] y GANASTE\n", num3, num2, num1);
        }
    }
  }
  /*-------------------------------------------------------------*/

}
