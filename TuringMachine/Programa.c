/*Creado por Adrian González Pardo
  Contacto: gozapaadr@gmail.com
  Nickname: DevCrack
  Fecha de modificación: 23/10/2018
  Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Logica.h"
int main(int argc, char* argv[]){
  /*Lectura de archivo txt donde este contiene la configuración de la Maquina de Turing
  Determinista de 1 Cinta con el siguiente formato
    1.- Q <- es el numero de estados que tiene de la Maquina de Turing
    2.- Σ <- Alfabeto de la Maquina de Turing
    3.- T <- Conjunto de símbolos de la cinta
    4.- q <- Estado incicial de la Maquina de Turing
    5.- B <- Símbolo de espacio en blanco
    6.- F <- Estados Final de la Maquina de Turing
    7.- δ <- Transiciones de la Maquina de Turing*/
    if(argc>1){
      Lee(*(argv+1));
    }else{
      Lee("Turing4.txt");
    }
  return 0;
}
