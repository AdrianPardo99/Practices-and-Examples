/*Creado por Adrian González Pardo
Fecha de modificación: 08/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Bags.h"
#include "Esqueleto.h"
/*Primer parte del programa de Bags para agregar datos*/
void menu(){
  int t,t1,i,*j;
  Bags c=vacioC(),c1=vacioC();
  printf("Bienvenido al programa de Bags:\n"
  "Por favor ingresa el tamaño en el que quieres trabajar con la bag 1 que sea distinto de cero\n"
  "Ingresa numeros:\n");
  scanf("%d",&t);
  for(i=0;i!=t;i++){
    printf("Valor %d: ",i+1);
    scanf("%d",&t1);
    j=(int*)malloc(sizeof(int));
    j=&t1;
    c=inserta(*j,c);
  }
  printf("Por favor ingresa el tamaño en el que quieres trabajar con la bag 2 que sea distinto de cero\n");
  scanf("%d",&t);
  for(i=0;i!=t;i++){
    printf("Valor %d: ",i+1);
    scanf("%d",&t1);
    j=(int*)malloc(sizeof(int));
    j=&t1;
    c1=inserta(*j,c1);
  }
  printf("Bag 1\n");
  impBags(c,0,numElem(c));
  printf("Bag 2\n");
  impBags(c1,0,numElem(c1));
  menu2(c,c1);
}
/*Menu donde se trabaja con Bags*/
void menu2(Bags c,Bags c1){
  Bags c2;
  int d;
  do{
    printf("Menu\nElige una opción para trabajar con las Bags que creaste\n"
    "1) Union\n2) Interseccion\n3) Diferencia (Bag1 vs Bag2)\n"
    "4) Diferencia (Bag2 vs Bag1)\n5) Mostrar Bags\n6) Salir\n");
    scanf("%d",&d);
    switch (d) {
      case 1:
        printf("Union\n");
        c2=Union(c,c1);
        impBags(c2,0,numElem(c2));
      break;
      case 2:
        printf("Interseccion\n");
        c2=Interseccion(c,c1);
        impBags(c2,0,numElem(c2));
      break;
      case 3:
        printf("Diferencia Bag 1 vs Bag 2\n");
        c2=Diferencia(c,c1);
        impBags(c2,0,numElem(c2));
      break;
      case 4:
        printf("Diferencia Bag 2 vs Bag 1\n");
        c2=Diferencia(c1,c);
        impBags(c2,0,numElem(c2));
      break;
      case 5:
        printf("Bag 1\n");
        impBags(c,0,numElem(c));
        printf("Bag 2\n");
        impBags(c1,0,numElem(c1));
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
