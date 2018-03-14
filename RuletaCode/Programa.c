/*Creado por Adrian González Pardo
Fecha de modificación: 13/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TDACQueue.h"
void logica();
int vueltas();
void pregunta();
int main(){
	srand(time(NULL));
	logica();
}
/*Funcion que contiene toda la logica del programa del juego de la ruleta*/
void logica(){
	int i,j=0,d;
	Circular q=nueva();
	for(i=0;i!=37;i++){
		q=formar(q,i);
	}
	/*Ciclo que permite ver la implementación de una cola circular*/
	d=vueltas();
	while(j!=d){
		q=rotar(q);
		j++;
	}
	printf("¿A que numero le apuestas?\nIngresa del 0-36\n");
	scanf("%d",&d);
	printf("El resultado es: %d\n%s\n",primero(q),(primero(q)==d)?("Excelente ganaste"):("Lo siento perdiste"));
	free(q);
	printf("Deseas volver a jugar?\nIngresa (s ó n)\n");
	pregunta();
}
/*Funcion que permite dar un cierto numero de vueltas a la ruleta uwu*/
int vueltas(){
	return rand()%37+1;
}
/*Función que permite saber si se repetira el programa uwu*/
void pregunta(){
	char r;
	scanf("%c",&r);
	if(r=='s'||r=='S'){
		main();
	}else if(r=='n'||r=='N'){
		exit(0);
	}else{
		pregunta();
	}
}
