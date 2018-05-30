/*Creado por Adrian González Pardo
Fecha de modificación: 29/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "ListH.h"
/*Creación del menu para el diccionario*/
void Menu(TablaH t){
  char *a,key;
  Lista l;
  TablaH t1=vaciaH();
  t1->li=tabla(t);
  a=(char*)malloc(sizeof(char)*20);
  printf("Se acaba de leer un diccionario de la tabla periodica por favor ingresa el elemento que deseas obtener información\n");
  scanf("%s",a);
  a=toUCase(a);
  key=keys(a,strlen(a));

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
    c=toUCase(c);
    l=InsOrd(c,l);
  }
  l=invierte(l);
  j=numElem(l);
  for(i=0;i!=j;i++){
    c=(Elem)malloc(sizeof(char)*1000);
    strcpy(c,cabeza(l));
    key=(Elem)malloc(sizeof(char));
    *key=keys(c,paren(c));
    t=consH(t,*key,c);
    l=resto(l);
  }
  free(l);
  Menu(t);
  fclose(r);
}
