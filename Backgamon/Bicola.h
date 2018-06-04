/*Creado por Adrian González Pardo
Fecha de modificación: 29/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
typedef struct NodoBq{
	Elem datoBq;
	struct NodoBq* ant;
	struct NodoBq* sig;
}*ApNodoBq;

typedef struct CNodoBq{
	ApNodoBq izq;
	ApNodoBq der;
}*Bicola;

Bicola nuevabq(){
	Bicola t=(Bicola)malloc(sizeof(struct CNodoBq));
	t->der=t->izq=NULL;
	return t;
}

int esnuevabq(Bicola q){
	return ((q->der==NULL)&&(q->izq==NULL));
}

Bicola formari(Elem e,Bicola q){
	ApNodoBq t =(ApNodoBq)malloc(sizeof(struct NodoBq));
	t->datoBq=e;
	if(esnuevabq(q)){
		q->der=q->izq=t;
		t->ant=t->sig=NULL;
	}else{
		t->sig=q->izq;
		q->izq->ant=q->izq=t;
		t->ant=NULL;
	}
	return q;
}
Bicola formard(Elem e, Bicola q){
	ApNodoBq t =(ApNodoBq)malloc(sizeof(struct NodoBq));
	t->datoBq=e;
	if(esnuevabq(q)){
		q->der=q->izq=t;
		t->ant=t->sig=NULL;
	}else{
		t->ant=q->der;
		q->der->sig=q->der=t;
		t->sig=NULL;
	}
	return q;
}

Elem izquierda(Bicola q){
	return q->izq->datoBq;
}

Elem derecha(Bicola q){
	return q->der->datoBq;
}

Bicola desformari(Bicola q){
	if(q->der==q->izq){
		return nuevabq();
	}else {
		q->izq=q->izq->sig;
		q->izq->ant=NULL;
	}
	return q;
}

Bicola desformard(Bicola q){
	if(q->der==q->izq){
		return nuevabq();
	}else {
		q->der=q->der->ant;
		q->der->sig=NULL;
	}
	return q;
}

void impbicolai(Bicola q){
	ApNodoBq t=q->izq;
	while(t!=NULL){
		impelem(t->datoBq);
		t=t->sig;
	}
}

void impbicolad(Bicola q){
	ApNodoBq t=q->der;
	while(t!=NULL){
		impelem(t->datoBq);
		t=t->ant;
	}
}

Bicola concatenarbicolas(Bicola qi, Bicola qd){
	while(!esnuevabq(qd))
	{
		qi = formard(izquierda(qd),qi);
		qd = desformari(qd);
	}
	return qi;
}
