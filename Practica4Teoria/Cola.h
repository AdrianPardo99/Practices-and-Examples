typedef char* Elem;
typedef struct Nodo{
	Elem dato;
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
Cola formar(Cola q,Elem e){
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
Elem primero (Cola q){return q->prim->dato;}
Cola desformar(Cola q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}

void impElem(Elem e){printf("%s\n",e);}

void impCola(Cola q,int i){
	if(!esNueva(q)){
		Cola t=(Cola)malloc(sizeof(struct CNodo));
		printf("%s",(i==0)?("Q: "):((i==1)?("Σ: "):((i==2)?("S: "):((i==3)?("F: "):((i==4)?("δ: "):("   "))))));
		impElem(primero(q));
		t->prim=q->prim;
		t->ult=q->ult;
		impCola(desformar(t),i+1);
	}
}
int tamCola(Cola q){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=q->prim;
	t->ult=q->ult;
	return (!esNueva(q))?(1+tamCola(desformar(t))):(0);
}

int tamElem(Elem e){return (*e!='\0')?(1+tamElem(e+1)):(0);}

Cola estadoFinal(Cola q,int i){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=q->prim;
	t->ult=q->ult;
	if(i==3){
		return t;
	}else{
		return estadoFinal(desformar(t),i+1);
	}
}
