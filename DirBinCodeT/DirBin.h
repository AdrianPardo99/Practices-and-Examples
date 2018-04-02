/*Creado por Adrian González Pardo
Fecha de modificación: 26/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "ArBin.h"
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

void impInOrdArch(DirBin a, FILE *out){
	if(!esvacio(a)){
		impInOrdArch(izquierdo(a),out);
		impElemArch(raiz(a),out);
		impInOrdArch(derecho(a),out);
	}
}
