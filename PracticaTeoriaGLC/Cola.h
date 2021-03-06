/*Creado por Adrian González Pardo
Fecha de modificación: 19/05/2018
Correo electronico:gozapaadr@gmail.com
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
		printf("%s",(i==0)?("VN: "):((i==1)?("VT: "):((i==2)?("S: "):((i==3)?("F: "):((i==4)?("δ: "):("   "))))));
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

/*Función programada para un fin en el AFD*/
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

/*Función bandera que permite saber si existen comas o no en el apartado F del AFD*/
int ElemComa(Elem e){
	int i,ban=0;
	for(i=0;i!=tamElem(e);i++){
		if(*(e+i)==','){
			ban=1;
			break;
		}
	}
	return ban;
}
void impCola3(Cola q,int conu){
	int i;
	if(!esNueva(q)){

		Cola t=malloc(sizeof(struct CNodo));
		t->prim=q->prim;
		t->ult=q->ult;
		for(i=0;i!=conu;i++){
			printf(" ");
		}
		printf("%s\n", primero(q));
		impCola3(desformar(q),conu+1);
	}else{
		for(i=0;i!=conu;i++){
			printf(" ");
		}
		printf("λ\n");
	}
}
