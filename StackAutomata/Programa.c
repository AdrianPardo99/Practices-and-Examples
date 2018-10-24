/*Creado por Adrian González Pardo
Fecha de modificación: 25/05/2018
Correo electronico:gozapaadr@gmail.com
2CV1
Licencia Creative Commons CC BY-SA*/
#include "Logica.h"
int main(){
  /*Lectura de archivo txt donde este contiene el AP con el siguiente formato
    1.- Q <- es el numero de estados que tiene el AP
    2.- Σ <- Alfabeto del AP
    3.- P <- Alfabeto de la pila AP
    4.- q <- Estado incicial del AP
    5.- Z <- Estado inicial o simbolo inicial de la pila
    6.- F <- Estado Final Ap
    7.- δ <- Transiciones del AP*/
  FILE *in=fopen("3.txt","r");
  Leer(in);
  return 0;
}
