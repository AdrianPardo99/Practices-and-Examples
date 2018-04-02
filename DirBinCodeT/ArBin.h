/*Creado por Adrian González Pardo
Fecha de modificación: 21/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
/*Estructura de datos de tipo Arbol binario*/
typedef struct NodoA{
	Elem raiz;
	struct NodoA *izq;
	struct NodoA *der;
}*ArBin;
/*Creación de la raíz*/
ArBin vacio(){return NULL;}
/*Cración de de la raiz y sus ramas*/
ArBin consA(Elem r,ArBin i,ArBin d){
	ArBin t=(ArBin)malloc(sizeof(struct NodoA));
	t->izq=i;
	t->der=d;
	t->raiz=r;
	return t;
}
/*Función que permite comparar si esa rama del arbol es vacia*/
int esvacio(ArBin a){return a==NULL;}
/*Función que accede al dato que almacena rama principal o subramas del arbol*/
Elem raiz(ArBin a){return a->raiz;}
/*Función que accede a la rama izquierda*/
ArBin izquierdo(ArBin a){return a->izq;}
/*Función que accede a la rama derecha*/
ArBin derecho(ArBin a){return a->der;}
/*Función que permite contar el numero de elementos de todo el arbol*/
int numElemA(ArBin a){return (!esvacio(a))?(1+numElemA(izquierdo(a))+numElemA(derecho(a))):(0);}
/*Función que permite imprimir los elementos del arbol de forma ordenada (Izquierda a derecha)*/
void ImpInOrd(ArBin a){
	if(!esvacio(a)){
		ImpInOrd(izquierdo(a));
		impElem(raiz(a));
		ImpInOrd(derecho(a));
	}
}
/*Función que permite imprimir los elementos del arbol de forma prefija inicia izquierda->derecha*/
void ImpInPre(ArBin a){
	if(!esvacio(a)){
		impElem(raiz(a));
		ImpInPre(izquierdo(a));
		ImpInPre(derecho(a));
	}
}
/*Función que permite imprimir los elementos del arbol de forma Postfija izquierda a derecha y raíz*/
void ImpInPost(ArBin a){
	if(!esvacio(a)){
		ImpInPost(izquierdo(a));
		ImpInPost(derecho(a));
		impElem(raiz(a));
	}
}
