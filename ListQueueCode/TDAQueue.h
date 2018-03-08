typedef char Ele;
typedef struct NodoQ{
	Ele dato;
	struct NodoQ *sig;
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
Cola formar(Cola q,Ele e){
	ApNodo t=(ApNodo)malloc(sizeof(struct NodoQ));
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
Ele primero (Cola q){return q->prim->dato;}
Cola desformar(Cola q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}
