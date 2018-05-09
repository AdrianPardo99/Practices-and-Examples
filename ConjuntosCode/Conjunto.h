/*Creado por Adrian González Pardo
Fecha de modificación: 08/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Lista.h"
/*Definición de Lista para trabajar como conjuntos*/
typedef Lista Conjuntos;

/*Redefinición de funcion vacio de tipo bool*/
int esVacioC(Conjuntos c){return esVacia(c);}
/*Función que revisa si en el conjunto tiene el valor que por obviedad en conjuntos no puede estar repetido*/
int Contiene(Elem e,Conjuntos c){
  int i,j=numElem(c);
  Conjuntos c1=c;
  for(i=0;i!=j;i++){
    if(cabeza(c1)==e){
      return 0;
    }
    c1=resto(c1);
  }
  return 1;
}
/*Función para el tope de la estructura*/
Conjuntos vacioC(){return vacia();}
/*Función que añade elementos a la estructura de datos*/
Conjuntos inserta(Elem e,Conjuntos c){
  if(esVacioC(c)){
    return cons(e,c);
  }else if(Contiene(e,c)){
    return InsOrd(e,c);
  }else{
    return c;
  }
}
/*Función que permite eliminar un elemento del conjunto*/
Conjuntos Elimina(Elem e,Conjuntos c){
  if(esVacioC(c)){
    return c;
  }else if(!Contiene(e,c)){
    Conjuntos c1=vacioC(),c2=c;
    int i,j=numElem(c);
    for(i=0;i!=j;i++){
      if(esIgual(e,cabeza(c2))){
      }else{
        c1=InsOrd(cabeza(c2),c1);
      }
      c2=resto(c2);
    }
    free(c);
    return c1;
  }else{
    return c;
  }
}
/*Función que permite la union entre dos conjuntos*/
Conjuntos Union(Conjuntos c,Conjuntos c1){
  if(esVacioC(c)){
    return c1;
  }else if(esVacioC(c1)){
    return c;
  }else{
    Conjuntos cc1=c1,cc=c;
    int i,j=numElem(c1);
    for(i=0;i!=j;i++){
      if(Contiene(cabeza(cc1),cc)){
        cc=InsOrd(cabeza(cc1),cc);
      }
      cc1=resto(cc1);
    }
    return cc;
  }
}
/*Función que permite la Interseccion entre dos conjuntos*/
Conjuntos Interseccion(Conjuntos c,Conjuntos c1){
  if(esVacioC(c)||esVacioC(c1)){
    return vacioC();
  }else{
    Conjuntos cc1=c1,cc=c,c2=vacioC();
    int i,j=numElem(c1);
    for(i=0;i!=j;i++){
      if(!Contiene(cabeza(cc1),cc)){
        c2=InsOrd(cabeza(cc1),c2);
      }
      cc1=resto(cc1);
    }
    return c2;
  }
}
/*Función que permite la diferencia entre dos conjuntos*/
Conjuntos Diferencia(Conjuntos c,Conjuntos c1){
  if(esVacioC(c)||esVacioC(c1)){
    return c;
  }else{
    Conjuntos ci=Interseccion(c,c1),cc,c2=vacioC();
    cc=(Conjuntos)malloc(sizeof(struct Nodo));
    cc->dato=c->dato;
    cc->sig=c->sig;
    int i,j=numElem(ci);
    for(i=0;i!=j;i++){
      if(!Contiene(cabeza(ci),cc)){
        cc=Elimina(cabeza(ci),cc);
      }
      ci=resto(ci);
    }
    return cc;
  }
}
/*Función que imprime los conjuntos de una forma chida uwu*/
void impConjunto(Conjuntos c,int con,int lim){
  if(!esVacioC(c)){
    impCon(cabeza(c));
    printf("%s",(!esIgual(con+1,lim))?",":"");
    impConjunto(resto(c),con+1,lim);
  }else{
    printf("\n");
  }
}
