/*Creado por Adrian González Pardo
Fecha de modificación: 21/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Lista.h"
/*Creación de una lista de listas para la Tabla Hash*/
typedef struct Nodo2{
  Lista li;
  char key;
  struct Nodo2 *sigu;
}*TablaH;
/*Función booleana para saber el tope de la estructura*/
int esVaciaH(TablaH l){return l==NULL;}
/*Función que regresa el tope de la estructura*/
TablaH vaciaH(){return NULL;}
/*Función que permite hacer uso de una llave*/
char llave(TablaH l){return l->key;}
/*Función que permite pasar a la siguiente tabla*/
TablaH restoH(TablaH l){return l->sigu;}
/*Función que accede a la lista*/
Lista tabla(TablaH l){return l->li;}
/*Función que permite contar el numero de elementos de la Tabla Hash*/
int counH(TablaH l){return (!esVaciaH(l))?(1+counH(restoH(l))):(0);}
/*Función que permite buscar si existe la llave en la Tabla Hash*/
int existe(TablaH l,char key){
  int i,lim=counH(l);
  TablaH l1=l;
  for(i=0;i!=lim;i++){
    if(llave(l1)==key){
      return 1;
    }
    l1=restoH(l1);
  }
  return 0;
}
/*Función que añade elementos a la Tabla Hash*/
TablaH consH(TablaH t,char k,char *info){
  if(esVaciaH(t)){
    TablaH t1=(TablaH)malloc(sizeof(struct Nodo2));
    t1->key=k;
    Lista l=vacia();
    l=InsOrd(info,l);
    t1->li=l;
    t1->sigu=t;
    return t1;
  }else{
    if(existe(t,k)){
      if(llave(t)==k){
        t->li=InsOrd(info,t->li);
      }else{
        return consH(restoH(t),k,info);
      }
      return t;
    }else{
      TablaH t1=(TablaH)malloc(sizeof(struct Nodo2));
      t1->key=k;
      Lista l=vacia();
      l=InsOrd(info,l);
      t1->li=l;
      t1->sigu=t;
      return t1;
    }
  }
}
/*Función que imprime las llaves de la Tabla Hash*/
void impLlaves(TablaH t,int con,int lim){
  if(!esVaciaH(t)){
    printf("%c",llave(t));
    printf("%s",(!esIgual(con+1,lim))?",":"");
    impLlaves(restoH(t),con+1,lim);
  }else{
    printf("\n");
  }
}
/*Función que imprimer el contenido de la Tabla Hash*/
void impTablaH(TablaH t,int i){
  if(!esVaciaH(t)){
    printf("Diccionario %d\n",i+1);
    impLista(tabla(t));
    printf("\n");
    impTablaH(restoH(t),i+1);
  }
}
