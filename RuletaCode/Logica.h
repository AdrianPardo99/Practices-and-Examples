#include "CQueue.h"
int main();
void logica();
int vueltas();
void pregunta(int di);
void again(int di);
void again(int di){
	int i,j=0,d,d1,ti;
	Circular q=nueva();
	for(i=0;i!=37;i++){
		q=formar(q,i);
	}
	if(isIgual(di,0)){
		printf("Ingresa de nuevo un monto para jugar\n");
		scanf("%d",&di);
	}
	printf("Ingresa el tipo de apuesta que deseas realizar,\nprimer dato es el numero de fichas que ingresa\nel segundo es en caso de ganar el numero de fichas por las que se multiplica\n1.-Rojo/Negro 1x1\n2.-Par/Impar 1x1\n"
	"3.-Pasa/Falta 1x1\n4.-Docena 1x2\n5.-Columna 1x2\n6.-Pleno 1x35\n");
	scanf("%d",&ti);
	printf("¿A que numero le apuestas?\nIngresa del 1-36\n");
	scanf("%d",&d);
  printf("\x1B[2J");
  /*Ciclo que permite ver la implementación de una cola circular*/
	d1=vueltas();
	while(j!=d1){
    impColaC(q);
		q=rotar(q);
		j++;
    for(i=0;i!=17;i++){
      puts("");
    }
    sleep(1);
    if(j!=d1){
      printf("\x1B[2J");
    }
	}
  i=primero(q);
	di=gana(i,d,di,ti);
	printf("Usted tiene %d\n", di);
	free(q);
	printf("Deseas volver a jugar?\nIngresa (s ó n)\n");
	pregunta(di);
}
/*Funcion que contiene toda la logica del programa del juego de la ruleta*/
void logica(){
	int i,j=0,d,d1,di,ti;
	Circular q=nueva();
	for(i=0;i!=37;i++){
		q=formar(q,i);
	}
	printf("Ingresa el tipo de apuesta que deseas realizar,\nprimer dato es el numero de fichas que ingresa\nel segundo es en caso de ganar el numero de fichas por las que se multiplica\n1.-Rojo/Negro 1x1\n2.-Par/Impar 1x1\n"
	"3.-Pasa/Falta 1x1\n4.-Docena 1x2\n5.-Columna 1x2\n6.-Pleno 1x35\n");
	scanf("%d",&ti);
	printf("¿Cuanto dinero quieres apostar?\n");
	scanf("%d",&di);
	printf("¿A que numero le apuestas?\nIngresa del 1-36\n");
	scanf("%d",&d);
  printf("\x1B[2J");
  /*Ciclo que permite ver la implementación de una cola circular*/
	d1=vueltas();
	while(j!=d1){
    impColaC(q);
		q=rotar(q);
		j++;
    for(i=0;i!=15;i++){
      puts("");
    }
    sleep(1);
    if(j!=d1){
      printf("\x1B[2J");
    }
	}
  i=primero(q);
	di=gana(i,d,di,ti);
	printf("Usted tiene %d\n", di);
	free(q);
	printf("Deseas volver a jugar?\nIngresa (s ó n)\n");
	pregunta(di);
}
/*Funcion que permite dar un cierto numero de vueltas a la ruleta uwu*/
int vueltas(){
	return rand()%38;
}
/*Función que permite saber si se repetira el programa uwu*/
void pregunta(int di){
	char r;
	scanf("%c",&r);
	if(r=='s'||r=='S'){
		again(di);
	}else if(r=='n'||r=='N'){
		exit(0);
	}else{
		pregunta(di);
	}
}
