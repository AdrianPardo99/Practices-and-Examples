/*Creado por Adrian González Pardo
Fecha de modificación: 18/04/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "DirBin.h"
typedef DirBin AVL;
/*Función que devuelve el valor absoluto*/
int absoluto(int a){
  return (a>=0)?(a):(-a);
}
/*Función que checa el factor de balanceo del arbol binario*/
int factBal(AVL a){
  return Altura(izquierdo(a))-Altura(derecho(a));
}
/*Función que revisa si el arbol binario es un arbol AVL*/
int esAVL(AVL a){
  if(esvacio(a))
    return 1;
  else
    if(absoluto(factBal(a))<=1)
      if(esAVL(izquierdo(a))&&esAVL(derecho(a)))
        return 1;
      else
        return 0;
  else
    return 0;
}
/*Función que rota el arbol hacia la izquierda*/
AVL rotIzq(AVL a){
  return consA(raiz(derecho(a)),
  consA(raiz(a),izquierdo(a),izquierdo(derecho(a))),
  derecho(derecho(a)));
}
/*Función que rota el arbol hacia la derecha*/
AVL rotDer(AVL a){
  return consA(raiz(izquierdo(a)),
  izquierdo(izquierdo(a)),
  consA(raiz(a),derecho(izquierdo(a)),derecho(a)));
}
/*Función que rota el arbol hacia la izquierda y luego a la derecha*/
AVL rotDerIzq(AVL a){
  return rotDer(consA(raiz(a),
  rotIzq(izquierdo(a)),
  derecho(a)));
}
/*Función que rota el arbol hacia la derecha y luego a la izquierda*/
AVL rotIzqDer(AVL a){
  return rotIzq(consA(raiz(a),
  izquierdo(a),
  rotDer(derecho(a))));
}
/*Función que checa como rotar el AVL*/
AVL rota(AVL a){
  if(factBal(a)>0){
    if(factBal(izquierdo(a))>0){
      return rotDer(a);
    }else{
      return rotDerIzq(a);
    }
  }else if(factBal(derecho(a))<0){
    return rotIzq(a);
  }else{
    return rotIzqDer(a);
  }
}
/*Función que crea el AVL*/
AVL hazAVL(AVL a){
  if(esAVL(a)){
    return a;
  }else if(!esAVL(izquierdo(a))){
    return consA(raiz(a),hazAVL(izquierdo(a)),derecho(a));
  }else if(!esAVL(derecho(a))){
    return consA(raiz(a),izquierdo(a),hazAVL(derecho(a)));
  }else{
    return rota(a);
  }
}
/*Función que permite crear el arbol AVL y jalando un elemento*/
AVL InsAVL(Elem e,AVL a){
  return hazAVL(InsOrdA(e,a));
}
