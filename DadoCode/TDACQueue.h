/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
/*Creacion de TDA Circular 
Creacion de la estructura Cola Circular*/
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
}*ApNodo;
/*Creación de los nodos que apuntaran a la estructura*/
typedef struct CNodo{
	ApNodo prim;
	ApNodo ult;
}*Circular;
/*Creacion del ultimo elemento de la cola segun su definición
y su comportamiento FIFO First Input First Output*/
Circular nueva(){
	Circular t=(Circular)malloc(sizeof(struct CNodo));
	t->prim=t->ult=NULL;
	return t;
}
/*Función observadora que permite saber si la Circular esta en el ultmo elemento o no*/
int esNueva(Circular q){return (q->prim==NULL)&&(q->ult==NULL);}
/*Funcion que permite agregar elementos a la estructura*/
Circular formar(Circular q,Elem e){
	ApNodo t=(ApNodo)malloc(sizeof(struct Nodo));
	t->dato=e;
	if(esNueva(q)){
		q->prim=q->ult=t;
		t->sig=NULL;
	}else{
		q->ult->sig=t;
		q->ult=t;
		t->sig=NULL;
	}
	return q;
}
/*Función que permite acceder al primer elemento de la Cola Circular*/
Elem primero (Circular q){return q->prim->dato;}
/*Función que permite comparar si el apuntador de la Cola Circular esta
en la ultima posición o no*/
Circular desformar(Circular q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}
/*Funcion que permite cambiar de apuntadores en la logica del programa*/
Circular rotar(Circular q){
	if(esNueva(q)){
		return q;
	}else{
		return formar(desformar(q),primero(q));
	}
}
/*Funcion recursiva que imprime todos los elementos*/
void impCola(Circular q){
	if(!esNueva(q)){
		Circular t=(Circular)malloc(sizeof(struct CNodo));
		impElem(primero(q));
		t->prim=q->prim;
		t->ult=q->ult;
		impCola(desformar(t));
	}
}
