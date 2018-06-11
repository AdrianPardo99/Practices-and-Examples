/*Creado por Adrian González Pardo
             Israel Bahena Brito
             Luis García
             Fecha de modificación: 10/06/2018
             2CV1
             Licencia Creative Commons CC BY-SA*/
typedef struct LENodo{
  Elem el;
  struct LENodo *ant;
  struct LENodo *sig;
}*ListaD;
/*Analisis si es el tope o no de la estructura*/
int isNewD(ListaD l){return l==NULL;}
/*Creación del tope de una Lista Doblemente Enlazada*/
ListaD vaciaD(){return NULL;}
/*Función que añade datos a la estructura de datos*/
ListaD consD(Elem e,ListaD l){
  ListaD l1=(ListaD)malloc(sizeof(struct LENodo));
  l1->el=e;
  if(!isNewD(l)){
    l->ant=l1;
    l1->sig=l;
    l1->ant=NULL;
  }else{
    l1->sig=l;
    l1->ant=NULL;
  }
  return l1;
}
/*Función que jala la cabeza de la estructura*/
Elem cabezaD(ListaD l){return l->el;}
/*Función que avanza hacía la derecha*/
ListaD restoD(ListaD l){return l->sig;}
/*Función que avanza hacía la izquierda*/
ListaD anteriorD(ListaD l){return l->ant;}
/**/
ListaD concatD(ListaD l,ListaD l1){return (isNewD(l))?(l1):(consD(cabezaD(l),concatD(restoD(l),l1)));}
/*Función que invierte la Lista Doblemente Enlazada*/
ListaD invierteD(ListaD l){return (!isNewD(l))?(concatD(invierteD(restoD(l)),consD(cabezaD(l),vaciaD()))):(l);}
/*Función que imprime la Lista Doblemente Enlazada de izquierda a derecha*/
void impListaD(ListaD l){
  if(!isNewD(l)){
    impElem(cabezaD(l));
    impListaD(restoD(l));
  }
}
/*Función que imprime la Lista Doblemente Enlazada de derecha a izquierda*/
void impListaA(ListaD l){
  if(!isNewD(l)){
    impElem(cabezaD(l));
    impListaA(anteriorD(l));
  }
}
/*Función que imprime la Lista Doblemente Enlazada de izquierda a derecha con un color distintivo*/
void impToTM(ListaD l,int pos,int coun){
  if(!isNewD(l)){
    impElemColor(cabezaD(l),(isEquals(pos,coun))?KRED:KWHT);
    impToTM(restoD(l),pos,coun+1);
  }
}
/*Función que cuenta el tamaño de la Lista Doblemente Enlazada*/
int counD(ListaD l){return (!isNewD(l))?(1+counD(restoD(l))):(0);}
