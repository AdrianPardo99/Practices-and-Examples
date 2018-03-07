#include "Elem.h"

typedef struct Nodo{
            Elem dato;
            struct Nodo *sig;
            }*Lista;
            
Lista vacia(){return NULL;}
Lista cons(Elem e,Lista l){
    Lista t=(Lista)malloc(sizeof(struct Nodo));
    t->dato=e;
    t->sig=l;
    return t;
}
int esVacia(Lista l){return l==NULL;}
Elem cabeza(Lista l){return l->dato;}
Lista resto(Lista l){return l->sig;}

void impLista(Lista l){
	if(!esVacia(l)){
		impElem(cabeza(l));
		impLista(resto(l));
	}
}

void impListaR(Lista l){
	if(!esVacia(l)){
		impListaR(resto(l));
		impElem(cabeza(l));
	}
}

void impListaArch(Lista l,FILE *out){
	if(!esVacia(l)){
		impElemArch(cabeza(l),out);
		impListaArch(resto(l),out);
	}
}

void impListaArchR(Lista l,FILE *out){
	if(!esVacia(l)){
		impListaArch(resto(l),out);
		impElemArch(cabeza(l),out);

	}
}

int numElem(Lista l){
	return (!esVacia(l))?(1+numElem(resto(l))):(0);
}
Lista concat(Lista l,Lista l1){
	return (esVacia(l))?(l1):(cons(cabeza(l),concat(resto(l),l1)));
}
Lista invierte(Lista l){
	return (esVacia(l))?(l):(concat(invierte(resto(l)),cons(cabeza(l),vacia())));
}

Lista InsOrd(Elem e,Lista l){
	return (esVacia(l))?(cons(e,vacia())):((EsMoI(e,cabeza(l)))?(cons(e,l)):(cons(cabeza(l),InsOrd(e,resto(l)))));
}
Lista OrdList(Lista l){
	return (esVacia(l))?(l):(InsOrd(cabeza(l),OrdList(resto(l))));
}
