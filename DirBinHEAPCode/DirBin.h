/*Creado por Adrian González Pardo
Fecha de modificación: 21/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "HEAP.h"
/*Renombramiento de funciones y estrutura del arbol binario*/
typedef ArBin DirBin;
/*Ordenamiento de ramas del arbol*/
DirBin InsOrdA(Elem e,DirBin a){
	if(esvacio(a)){
		return consA(e,vacio(),vacio());
	}else if(EsMoI(e,raiz(a))){
		return consA(raiz(a),InsOrdA(e,izquierdo(a)),derecho(a));
	}else{
		return consA(raiz(a),izquierdo(a),InsOrdA(e,derecho(a)));
	}
}

/*Función que permite imprimir el arbol binario en forma horizontal*/
void impArbol(DirBin a,int con){
	int i;
	if(!esvacio(a)){
		impArbol(derecho(a),con+1);
		for(i=0;i!=con;i++){
			printf("\t");
		}
		impElem(raiz(a));
		impArbol(izquierdo(a),con+1);
	}else{
		for(i=0;i!=con;i++){
			printf("\t");
		}
		puts("-");
	}
}

void impArbolB(DirBin a){
	impArbol(a,0);
}

int tamAB(ArBin a){
	return (!esvacio(a))?(tamAB(izquierdo(a))+tamAB(derecho(a))+1):(0);
}
/*Función que permite imprimir el arbol binario en forma vertical*/
void impArbol2(ArBin a){
	Cola c=nueva();
	int total=tamAB(a);
	int techo=log2(total+1);
	c=formar(c,a);
	int i=0,j;
	while(sizeQueue(c) > 0){
			int nivel = sizeQueue(c);
			while(nivel > 0){
				ArBin aux=primero(c);
				c=desformar(c);
				if(nivel==pow(2,i)){
					for(j=0;j!=pow(2,techo-i);j++){
						printf("\t");
					}
				}else{
					for(j=0;j!=pow(2,techo-i+1);j++){
						printf("\t");
					}
				}
				printf("%d",raiz(aux));
				if(!esvacio(izquierdo(aux))){c=formar(c,izquierdo(aux));}
				if(!esvacio(derecho(aux))){c=formar(c,derecho(aux));}
				nivel--;
			}
			i++;
			printf("\n");
	}
}
