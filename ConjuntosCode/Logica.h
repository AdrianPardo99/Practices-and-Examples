/*Creado por Adrian González Pardo
Fecha de modificación: 08/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Conjunto.h"
#include "Esqueleto.h"
/*Primer parte del programa de conjuntos para agregar datos*/
void menu(){
  int t,t1,i,*j;
  Conjuntos c=vacioC(),c1=vacioC();
  printf("Bienvenido al programa de conjuntos:\n"
  "Por favor ingresa el tamaño en el que quieres trabajar el conjunto 1 que sea distinto de cero\n"
  "Nota por favor ingresa valores que no esten repetidos para que el conjunto\n"
  "Ingresa numeros:\n");
  scanf("%d",&t);
  for(i=0;i!=t;i++){
    printf("Valor %d: ",i+1);
    scanf("%d",&t1);
    j=(int*)malloc(sizeof(int));
    j=&t1;
    c=inserta(*j,c);
  }
  printf("Por favor ingresa el tamaño en el que quieres trabajar el conjunto 2 que sea distinto de cero\n");
  scanf("%d",&t);
  for(i=0;i!=t;i++){
    printf("Valor %d: ",i+1);
    scanf("%d",&t1);
    j=(int*)malloc(sizeof(int));
    j=&t1;
    c1=inserta(*j,c1);
  }
  printf("Conjunto 1\n");
  impConjunto(c,0,numElem(c));
  printf("Conjunto 2\n");
  impConjunto(c1,0,numElem(c1));
  menu2(c,c1);
}
/*Menu donde se trabaja con conjuntos*/
void menu2(Conjuntos c,Conjuntos c1){
  Conjuntos c2;
  int d;
  do{
    printf("Menu\nElige una opción para trabajar con los conjuntos que creaste\n"
    "1) Union\n2) Interseccion\n3) Diferencia (conjunto1 vs conjunto2)\n"
    "4) Diferencia (conjunto2 vs conjunto1)\n5) Mostrar conjuntos\n6) Salir\n");
    scanf("%d",&d);
    switch (d) {
      case 1:
        printf("Union\n");
        c2=Union(c,c1);
        impConjunto(c2,0,numElem(c2));
      break;
      case 2:
        printf("Interseccion\n");
        c2=Interseccion(c,c1);
        impConjunto(c2,0,numElem(c2));
      break;
      case 3:
        printf("Diferencia conjunto 1 vs conjunto 2\n");
        c2=Diferencia(c,c1);
        impConjunto(c2,0,numElem(c2));
      break;
      case 4:
        printf("Diferencia conjunto 2 vs conjunto 1\n");
        c2=Diferencia(c1,c);
        impConjunto(c2,0,numElem(c2));
      break;
      case 5:
        printf("Conjunto 1\n");
        impConjunto(c,0,numElem(c));
        printf("Conjunto 2\n");
        impConjunto(c1,0,numElem(c1));
      break;
      case 6:
      printf("Adios\n");
      free(c);
      free(c1);
      free(c2);
      break;
      default:
      printf("Ingresa una opción correcta\n");
    }
  }while(d!=6);
}
