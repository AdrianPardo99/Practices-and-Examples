#include "Elem.h"
typedef struct Nodo{
	Elem dat;
	struct Nodo *sig;
}*Pila;
//Stack
Pila empty(){
	return NULL;
}
Pila push(Elem e,Pila p){
	Pila p1;
	p1=(Pila)malloc(sizeof(struct Nodo));
	p1->dat=e;
	p1->sig=p;
	return p1;
}
int isEmpty(Pila p){return p==NULL;}
Elem top(Pila p){return p->dat;}
Pila pop(Pila p){return p->sig;}
