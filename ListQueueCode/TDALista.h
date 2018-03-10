/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
/*Declaración de la estructura de datos de tipo Lista que incluye una Cola*/
typedef struct Nodo{
            Elem dato;
            struct Nodo *sig;
            }*Lista;
/*Creacion del elemento Nulo que en la estructura hace una definición a su comportamiento
LIFO Last Input First Output en este caso este seria el primer elemento de la estructur*/
Lista vacia(){return NULL;}
/*Función que permite agregar elementos a la Lista*/
Lista cons(Elem e,Lista l){
    Lista t=(Lista)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}
/*Función que permite reconocer si la lista esta vacia o no*/
int esVacia(Lista l){return l==NULL;}
/*Función que permite obtener el elemento de la Lista*/
Elem cabeza(Lista l){return l->dato;}
/*Función que permite apuntar al siguiente elemento de la Lista*/
Lista resto(Lista l){return l->sig;}
/*Función recursiva que permite hacer uso tanto de las funciones del TDAQueue.h
donde permite acceder a la impresión en terminal de los elementos que contiene la Cola
y pasar a la siguiente Lista*/
void impLista(Lista l,int i){
	if(!esVacia(l)){
		printf("Lista %d:\n",i);
		impCola(cabeza(l));
		getchar();
		impLista(resto(l),i+1);
	}
}
