/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
typedef int Ele;
/*Creacion de TDA Cola 
Creacion de la estructura Cola*/
typedef struct NodoQ{
	Ele dato;
	struct NodoQ *sig;
}*ApNodo;
/*Creación de los nodos que apuntaran a la estructura*/
typedef struct CNodo{
	ApNodo prim;
	ApNodo ult;
}*Cola;
/*Creacion del ultimo elemento de la cola segun su definición
y su comportamiento FIFO First Input First Output*/
Cola nueva(){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=t->ult=NULL;
	return t;
}
/*Función observadora que permite saber si la Cola esta en el ultmo elemento o no*/
int esNueva(Cola q){return (q->prim==NULL)&&(q->ult==NULL);}
/*Funcion que permite agregar elementos a la estructura*/
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
/*Función que permite acceder al primer elemento de la Cola*/
Ele primero (Cola q){return q->prim->dato;}
/*Función que permite comparar si el apuntador de la Cola esta
en la ultima posición o no*/
Cola desformar(Cola q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}
/*Función que imprime un elemento de la lista*/
void impElem(Ele e){printf("%d\n",e);}
/*Función que permite imprimir toda la Cola de forma recursiva*/
void impCola(Cola q){
	if(!esNueva(q)){
		Cola t=(Cola)malloc(sizeof(struct CNodo));
		impElem(primero(q));
		t->prim=q->prim;
		t->ult=q->ult;
		impCola(desformar(t));
	}
}
