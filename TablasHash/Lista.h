/*Creado por Adrian González Pardo
Fecha de modificación: 18/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
/*Definición de las estructura de datos de tipo Lista*/
typedef struct Nodo{
            Elem dato;
            struct Nodo *sig;
            }*Lista;
/*Creación del tope de la estructura*/
Lista vacia(){return NULL;}
/*Función que añade elementos a la lista*/
Lista cons(Elem e,Lista l){
    Lista t=(Lista)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}
/*Función booleana que permite tener un control de la estructura*/
int esVacia(Lista l){return l==NULL;}
/*Función que permite acceder al dato de la lista*/
Elem cabeza(Lista l){return l->dato;}
/*Función que permite pasar al siguiente apuntador de la estructura*/
Lista resto(Lista l){return l->sig;}
/*Función recursiva que permite imprimir los datos*/
void impLista(Lista l){
	if(!esVacia(l)){
		impElem(cabeza(l));
		impLista(resto(l));
	}
}
/*Función recursiva que permite imprimir los datos al reves*/
void impListaR(Lista l){
	if(!esVacia(l)){
		impListaR(resto(l));
		impElem(cabeza(l));
	}
}
/*Función que permite saber el tamaño de la lista*/
int numElem(Lista l){
	return (!esVacia(l))?(1+numElem(resto(l))):(0);
}
/*Función que permite unir dos listas*/
Lista concat(Lista l,Lista l1){
	return (esVacia(l))?(l1):(cons(cabeza(l),concat(resto(l),l1)));
}
/*Función que permite invertir el orden de la unión*/
Lista invierte(Lista l){
	return (esVacia(l))?(l):(concat(invierte(resto(l)),cons(cabeza(l),vacia())));
}

Lista InsOrd(Elem e,Lista l){
	return (esVacia(l))?(cons(e,vacia())):((EsMoI(e,cabeza(l)))?(cons(e,l)):(cons(cabeza(l),InsOrd(e,resto(l)))));
}
Lista OrdList(Lista l){
	return (esVacia(l))?(l):(InsOrd(cabeza(l),OrdList(resto(l))));
}

/*Función recursiva que permite imprimir los elementos de forma lineal*/
void impLista1(Lista l){
  if(!esVacia(l)){
    impLista1(resto(l));
    impElem2(cabeza(l));
  }
}
