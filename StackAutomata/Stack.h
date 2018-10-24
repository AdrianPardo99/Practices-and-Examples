/*Creado por Adrian González Pardo
Fecha de modificación: 25/05/2018
Correo electronico:gozapaadr@gmail.com
2CV1
Licencia Creative Commons CC BY-SA*/
/*Creación de Pila*/
typedef struct PNodo{
	Elem dat;
	struct PNodo *sig;
}*Pila;
/*Función que nos permite crear el tope de la estructura*/
Pila empty(){return NULL;}
/*Función que nos permite añadir valores a la pila*/
Pila push(Elem e,Pila p){
	Pila p1;
	p1=(Pila)malloc(sizeof(struct PNodo));
	p1->dat=e;
	p1->sig=p;
	return p1;
}
int isEmpty(Pila p){return p==NULL;}
/*Función que nos permite obtener el primer elementos de la Pila*/
Elem top(Pila p){return p->dat;}
/*Función que nos permite sacar elementos de la pila*/
Pila pop(Pila p){return p->sig;}

void impStack(Pila p){
	if(!isEmpty(p)){
		(!isEmpty(pop(p)))?impElem(top(p)):(printf("%s\t",top(p)));
		impStack(pop(p));
	}
}
