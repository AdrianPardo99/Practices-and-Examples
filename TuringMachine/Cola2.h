/*Creado por Adrian González Pardo
             Israel Bahena Brito
             José Luis García Mendoza
             Suarez Vazquez Erick
             Fecha de modificación: 10/06/2018
             2CV1
             Licencia Creative Commons CC BY-SA*/
/*Creación de una estructura de datos de tipo Cola como auxiliar a la Cola principal*/
typedef struct Nodo2{
	Elem1 inicio,dato,siguiente,escribe,pos;
	struct Nodo2 *sig;
}*ApNodo2;
typedef struct CNodo2{
	ApNodo2 prim;
	ApNodo2 ult;
}*Cola2;

/*Creación de la funcion constructora de la Cola*/
Cola2 nueva2(){
	Cola2 t=(Cola2)malloc(sizeof(struct CNodo2));
	t->prim=t->ult=NULL;
	return t;
}

/*Función observadora de la Cola*/
int esnueva2(Cola2 q){return (q->prim==NULL)&&(q->ult==NULL);}

/*Función constructora numero 2 de la Cola*/
Cola2 formar2(Cola2 q,Elem1 e,Elem1 e1,Elem1 e2,Elem1 e3,Elem1 e4){
	ApNodo2 t=(ApNodo2)malloc(sizeof(struct Nodo2));
	t->inicio=e;
	t->dato=e1;
	t->siguiente=e2;
	t->escribe=e3;
	t->pos=e4;
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

/*Función observadora del elemento de la cola*/
Elem1 inicio (Cola2 q){return q->prim->inicio;}
Elem1 dato (Cola2 q){return q->prim->dato;}
Elem1 siguiente(Cola2 q){return q->prim->siguiente;}
Elem1 escribe(Cola2 q){return q->prim->escribe;}
Elem1 pos(Cola2 q){return q->prim->pos;}
/*Función desdobladora de la Cola*/
Cola2 desformar2(Cola2 q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}

void impCola2(Cola2 q){
	if(!esnueva2(q)){
		Cola2 t=(Cola2)malloc(sizeof(struct CNodo2));
		printf("(");
		impElem2(inicio(q));
		printf(",");
		impElem2(dato(q));
		printf(")->(");
		impElem2(siguiente(q));
		printf(",");
		impElem2(escribe(q));
		printf(",");
		impElem2(pos(q));
		printf(")");
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

Elem1 Elemnuevo2(){
	Elem1 a=(Elem1)malloc(sizeof(char)*50);
	return a;
}
