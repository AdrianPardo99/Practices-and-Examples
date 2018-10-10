/*Creado por Adrian González Pardo
Fecha de modificación: 19/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Logica.h"
int main(int argc, char* argv[]){
  /*Lectura de archivo txt donde este contiene el GLC con el siguiente formato
    1.- VN <- Los No Terminales a usar en la gramática.
    2.- VT <- Los Terminales
    3.- S <- Estado inicial de GLC
    4.- F <- Estado(s) finales del GLC
    5.- δ <- Reglas de producción del GLC*/
    FILE *in;
  if(argc>1){
    in=fopen(*(argv+1),"r");
  }else{
    in=fopen("3.txt","r");
  }
  Leer(in);
  return 0;
}
