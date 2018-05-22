/*Creado por Adrian González Pardo
Fecha de modificación: 21/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "ListH.h"
/*Creación del menu para el diccionario*/
void Menu(TablaH t){
  char d;
  int i,j=counH(t);
  TablaH t1=(TablaH)malloc(sizeof(struct Nodo2));
  t1->li=tabla(t);
  t1->key=llave(t);
  t1->sigu=restoH(t);
  printf("Menu se acaba de leer un diccionario de acuerdo a los resultados se presentan las siguientes llaves de acceso para trabajar\n");
  impLlaves(t,0,counH(t));
  printf("Ingresa la letra con la que deseas trabajar\n");
  scanf("%c",&d);
  for(i=0;i!=j;i++){
    if(llave(t1)==d){
      impLista(tabla(t1));
      puts("");
      break;
    }
    t1=restoH(t1);
  }
}
/*Función que lee el txt*/
void Leer(){
  FILE *r=fopen("Dic.txt","r");
  TablaH t=vaciaH();
  Lista l = vacia();
  char cad[1000],*c,*key;
  int i=0,j;
  while(fscanf(r,"%s",cad)!=EOF){
    c=(Elem)malloc(sizeof(char)*1000);
    strcpy(c,cad);
    l=InsOrd(c,l);
  }
  l=invierte(l);
  j=numElem(l);
  for(i=0;i!=j;i++){
    c=(Elem)malloc(sizeof(char)*1000);
    strcpy(c,cabeza(l));
    key=(Elem)malloc(sizeof(char));
    *key=*c;
    *key=toupper(*key);
    t=consH(t,*key,c);
    l=resto(l);
  }
  free(l);
  Menu(t);
  fclose(r);
}
