/*Creado por Adrian González Pardo
Fecha de modificación: 18/04/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"
int al(){return 1+(rand()%59)+(rand()%40);}
int main(){
  srand(time(NULL));
  /*AVL a=vacio();
  a=InsOrdA("Kilo",a);
  a=InsOrdA("escuela",a);
  a=InsOrdA("mesa",a);
  a=InsOrdA("Foto",a);
  a=InsOrdA("Laura",a);
  //a=InsOrdA("perro",a);
  //a=InsOrdA("oso",a);
  printf("El factor de balanceo es: %d\n",factBal(a));
  esAVL(a)?puts("Es AVL"):puts("No es AVL");*/
  int i;
  AVL a=vacio();

    for(i=0;i!=5000;i++){
      a=InsAVL(i+1,a);
      printf("%d:Raiz %d\n",i+1,raiz(a));
    }

    printf("El factor de balanceo es: %d\n",factBal(a));
    esAVL(a)?puts("Es AVL"):puts("No es AVL");
    free(a);

}
