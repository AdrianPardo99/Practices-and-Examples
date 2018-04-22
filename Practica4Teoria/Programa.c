#include <stdio.h>
#include <stdlib.h>
#include "Logica.h"
int main(){
  FILE *in=fopen("AFD.txt","r");
  Leer(in);
  return 0;
}
