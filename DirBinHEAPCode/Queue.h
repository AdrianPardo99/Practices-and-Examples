#include "ArBin.h"
typedef ArBin Elem2;
typedef struct Nodo{
	Elem2 dato;
	struct Nodo *sig;
}*ApNodo;
typedef struct CNodo{
	ApNodo prim;
	ApNodo ult;
}*Cola;
Cola nueva(){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=t->ult=NULL;
	return t;
}
int esNueva(Cola q){return (q->prim==NULL)&&(q->ult==NULL);}
Cola formar(Cola q,Elem2 e){
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
Elem2 primero (Cola q){return q->prim->dato;}
Cola desformar(Cola q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}

int sizeQueue(Cola q){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=q->prim;
	t->ult=q->ult;
	return (!esNueva(q))?(1+sizeQueue(desformar(t))):(0);}
