/*Creado por Adrian González Pardo
Fecha de modificación: 08/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
/*Creacion de la estructura Lista*/
typedef struct Nodo{
            Elem dato;
            struct Nodo *sig;
            }*Lista;
/*Función constructora para la base o el tope*/
Lista vacia(){return NULL;}
/*Función que agrega datos a la lista*/
Lista cons(Elem e,Lista l){
    Lista t=(Lista)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}
/*Función que permite saber si en la lista es el tope o no*/
int esVacia(Lista l){return l==NULL;}
/*Función que jala el dato que se desea consultar*/
Elem cabeza(Lista l){return l->dato;}
/*Función que avanza al siguiente dato*/
Lista resto(Lista l){return l->sig;}
/*Función que imprime el contenido de la lista*/
void impLista(Lista l){
	if(!esVacia(l)){
		impElem(cabeza(l));
		impLista(resto(l));
	}
}
/*Función que imprime el contenido de la lista al reves*/
void impListaR(Lista l){
	if(!esVacia(l)){
		impListaR(resto(l));
		impElem(cabeza(l));
	}
}
/*Función que cuenta el numero de elementos que tiene la lista*/
int numElem(Lista l){
	return (!esVacia(l))?(1+numElem(resto(l))):(0);
}
/*Función que concatena los elementos de dos listas una union de ambas*/
Lista concat(Lista l,Lista l1){
	return (esVacia(l))?(l1):(cons(cabeza(l),concat(resto(l),l1)));
}
/*Lo mismo que concat pero al reves*/
Lista invierte(Lista l){
	return (esVacia(l))?(l):(concat(invierte(resto(l)),cons(cabeza(l),vacia())));
}
/*Función que recibe los elementos de la Lista pero este los ordena*/
Lista InsOrd(Elem e,Lista l){
	return (esVacia(l))?(cons(e,vacia())):((EsMoI(e,cabeza(l)))?(cons(e,l)):(cons(cabeza(l),InsOrd(e,resto(l)))));
}
/*Funcion que ordena la lista sin que esta reciba elementos*/
Lista OrdList(Lista l){
	return (esVacia(l))?(l):(InsOrd(cabeza(l),OrdList(resto(l))));
}
