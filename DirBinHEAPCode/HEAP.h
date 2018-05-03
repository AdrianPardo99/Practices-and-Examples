/*Creado por Adrian González Pardo
Fecha de modificación: 03/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Queue.h"
/*Función que devuelve el valor absoluto*/
int absoluto(int a){
  return (a>=0)?(a):(-a);
}
/*Función que checa el factor de balanceo del arbol binario*/
int factBal(ArBin a){
  return Altura(izquierdo(a))-Altura(derecho(a));
}
/*Función que permite saber si el arbol binario es completo en sus nivel y subniveles*/
int esCompleto(ArBin a){
  if(esvacio(a)){
    return 1;
  }else if((absoluto(factBal(a))<=1)&&esCompleto(izquierdo(a))&&esCompleto(derecho(a))){
    return 1;
  }else{
    return 0;
  }
}
/*Función que permite saber si el arbol binario esta lleno en su nivel y subniveles para liberar otro subnivel*/
int esLleno(ArBin a){
  if(esvacio(a)){
    return 1;
  }else if((Altura(izquierdo(a))==Altura(derecho(a)))&&esLleno(izquierdo(a))&&esLleno(derecho(a))){
    return 1;
  }else{
    return 0;
  }
}

ArBin hazCompleto(Elem e,ArBin a){
  if(esvacio(a)){
    return consA(e,vacio(),vacio());
  }else if(((Altura(izquierdo(a))==(Altura(derecho(a))+1))&&esLleno(izquierdo(a)))||
  ((Altura(izquierdo(a))==Altura(derecho(a)))&&!esLleno(derecho(a)))){
    return consA(raiz(a),izquierdo(a),hazCompleto(e,derecho(a)));
  }else{
    return consA(raiz(a),hazCompleto(e,izquierdo(a)),derecho(a));
  }
}

typedef ArBin Heap;
Heap hazHeap(Elem e,Heap i,Heap d){
  if(esvacio(i)&&esvacio(d)){
    return consA(e,i,d);
  }else if(esvacio(d)){
    if(EsMoI(e,raiz(i))){
      return consA(e,i,d);
    }else{
      return consA(raiz(i),consA(e,vacio(),vacio()),vacio());
    }
  }else if(EsMayor(e,raiz(i))&&EsMayor(e,raiz(d))){
    return consA(e,i,d);
  }else if(EsMAoI(raiz(i),raiz(d))){
    return consA(raiz(i),hazHeap(e,izquierdo(i),derecho(i)),d);
  }else{
    return consA(raiz(d),i,hazHeap(e,izquierdo(d),derecho(d)));
  }
}
Heap consHeap(ArBin a){
  if(esvacio(a)){
    return a;
  }else if(factBal(a)<=1){
    return hazHeap(raiz(a),consHeap(izquierdo(a)),consHeap(derecho(a)));
  }
}
//Meter 10 datos al heap
