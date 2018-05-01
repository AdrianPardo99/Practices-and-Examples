/*Creado por Adrian González Pardo
Fecha de modificación: 30/04/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Logica.h"
int main(){
  /*Lectura de archivo txt donde este contiene el AFD con el siguiente formato
    1.- Q <- es el numero de estados que tiene el AFD
    2.- Σ <- Alfabeto del AFD
    3.- S <- Estado inicial de AFD
    4.- F <- Estado(s) finales del AFD
    5.- δ <- Transiciones del AFD*/
  FILE *in=fopen("3.txt","r");
  Leer(in);
  return 0;
}
