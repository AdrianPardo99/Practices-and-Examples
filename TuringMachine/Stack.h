/*Creado por Adrian González Pardo
  Contacto: gozapaadr@gmail.com
  Nickname: DevCrack
  Fecha de modificación: 23/10/2018
  Licencia Creative Commons CC BY-SA*/
  /*Declaracion de la estructura de datos Stack*/
typedef struct SNodo{
  Elem1 dat;
  struct SNodo *sP;
}*Stack;
/*Creacion del tope de la funcion*/
Stack newStack(){return NULL;}
/*Funcion que añade datos a la estructura*/
Stack push(Stack s,Elem1 e){
  Stack s1=(Stack)malloc(sizeof(struct SNodo));
  s1->dat=e;
  s1->sP=s;
  return s1;
}
/*Funcion booleana que permite saber si la estructura llego a su tope*/
int isEmpty(Stack s){return s==NULL;}
/*Funcion que saca los datos del Stack*/
Stack pop(Stack s){return s->sP;}
/*Funcion observadora que permite ver el cabezal del Stack*/
Elem1 headStack(Stack s){return s->dat;}
/*Funcion que imprime todo el Stack*/
void printTranStack(Stack s){
  if(!isEmpty(s)){
    printTranStack(pop(s));
    printf("%s\t",headStack(s));
  }else{
    printf("\n");
  }
}
