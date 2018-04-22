typedef char* Elem;

typedef struct Nodo2{
	Elem inicio,dato,siguiente;
	struct Nodo2 *sig;
}*ApNodo2;
typedef struct CNodo2{
	ApNodo2 prim;
	ApNodo2 ult;
}*Cola2;
Cola2 nueva2(){
	Cola2 t=(Cola2)malloc(sizeof(struct CNodo2));
	t->prim=t->ult=NULL;
	return t;
}
int esnueva2(Cola2 q){return (q->prim==NULL)&&(q->ult==NULL);}
Cola2 formar2(Cola2 q,Elem e,Elem e1,Elem e2){
	ApNodo2 t=(ApNodo2)malloc(sizeof(struct Nodo2));
	t->inicio=e;
	t->dato=e1;
	t->siguiente=e2;
	if(esnueva2(q)){
		q->prim=q->ult=t;
		t->sig=NULL;
	}else{
		q->ult->sig=t;
		q->ult=t;
		t->sig=NULL;
	}
	return q;
}

Elem inicio (Cola2 q){return q->prim->inicio;}
Elem primero2 (Cola2 q){return q->prim->dato;}
Elem siguiente(Cola2 q){return q->prim->siguiente;}

Cola2 desformar2(Cola2 q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}

void impElem2(Elem e){printf("%s",e);}

void impCola2(Cola2 q){
	if(!esnueva2(q)){
		Cola2 t=(Cola2)malloc(sizeof(struct CNodo2));
		impElem2(inicio(q));
		printf("(");
		impElem2(primero2(q));
		printf(")->");
		impElem2(siguiente(q));
		printf("\n");
		t->prim=q->prim;
		t->ult=q->ult;
		impCola2(desformar2(t));
	}
}
int tamCola2(Cola2 q){
	Cola2 t=(Cola2)malloc(sizeof(struct CNodo2));
	t->prim=q->prim;
	t->ult=q->ult;
	return (!esnueva2(q))?(1+tamCola2(desformar2(t))):(0);
}

Elem Elemnuevo2(){
	Elem a=(Elem)malloc(sizeof(char)*50);
	return a;
}
