/*Creado por Adrian González Pardo
Fecha de modificación: 25/05/2018
Correo electronico:gozapaadr@gmail.com
2CV1
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef char* Elem;
/*Creación de una estructura de datos de tipo Cola*/
typedef struct Nodo{
	Elem dato;
	struct Nodo *sig;
}*ApNodo;
typedef struct CNodo{
	ApNodo prim;
	ApNodo ult;
}*Cola;

/*Creación de la funcion constructora de la Cola*/
Cola nueva(){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=t->ult=NULL;
	return t;
}

/*Función observadora de la Cola*/
int esNueva(Cola q){return (q->prim==NULL)&&(q->ult==NULL);}

/*Función constructora numero 2 de la Cola*/
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

/*Función observadora del elemento de la cola*/
Elem primero (Cola q){return q->prim->dato;}

/*Función desdobladora de la Cola*/
Cola desformar(Cola q){
	if(q->prim==q->ult){
		q->prim=q->ult=NULL;
	}else{
		q->prim=q->prim->sig;
	}
	return q;
}

/*Función que permite imprimir cada dato de la Cola*/
void impElem(Elem e){printf("%s\n",e);}

/*Función recursiva que imprime los elementos de la Cola*/
void impCola(Cola q,int i){
	if(!esNueva(q)){
		Cola t=(Cola)malloc(sizeof(struct CNodo));
		printf("%s",(i==0)?("Q: "):((i==1)?("Σ: "):((i==2)?("P: "):((i==3)?("q: "):((i==4)?("p: "):((i==5)?("F: "):((i==6)?"δ: ":"   ")))))));
		impElem(primero(q));
		t->prim=q->prim;
		t->ult=q->ult;
		impCola(desformar(t),i+1);
	}
}

/*Función que mide el tamaño de la Cola*/
int tamCola(Cola q){
	Cola t=(Cola)malloc(sizeof(struct CNodo));
	t->prim=q->prim;
	t->ult=q->ult;
	return (!esNueva(q))?(1+tamCola(desformar(t))):(0);
}

/*Función que mide el tamaño del dato en este caso la cadena*/
int tamElem(Elem e){return (*e!='\0')?(1+tamElem(e+1)):(0);}
