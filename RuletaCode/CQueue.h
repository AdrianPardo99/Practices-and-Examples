/*Creado por Adrian González Pardo
Fecha de modificación: 14/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
/*Creacion de TDA Circular
Creacion de la estructura Cola Circular*/
#include "Elem.h"
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
}*Circular;
/*Creacion del ultimo elemento de la cola segun su definición
y su comportamiento FIFO First Input First Output*/
Circular nueva(){return NULL;}
/*Función observadora que permite saber si la Circular esta en el ultmo elemento o no*/
int esNuevaC(Circular q){return q==NULL;}
/*Funcion que permite agregar elementos a la estructura*/
Circular formar(Circular q,Elem e){
	Circular t=(Circular)malloc(sizeof(struct Nodo));
	t->dato=e;
	if(esNuevaC(q)){
		/*q=q->sig=t;*/
		q=t;
		q->sig=t;
	}else{
		t->sig=q->sig;
		q->sig=t;
	}
	return t;
}
/*Función que permite acceder al primer elemento de la Cola Circular*/
Elem primero(Circular q){return q->sig->dato;}
/*Función que permite comparar si el apuntador de la Cola Circular esta
en la ultima posición o no*/
Circular desformar(Circular q){
	Circular t=q->sig;
	if(q==q->sig){
		free(t);
		return nueva();
	}else{
		q->sig=q->sig->sig;
		free(t);
		return q;
	}
}
/*Funcion que permite cambiar de apuntadores en la logica del programa*/
Circular rotar(Circular q){return q->sig;}
/*Funcion recursiva que imprime todos los elementos*/
void impColaC(Circular q){
		Circular t=q;
		if(!esNuevaC(q)){
			do{
				t=rotar(t);
				impElemC(primero(t));
				if(t==q){
					printf("\n");
				}
			}while(t!=q);
		}
}
