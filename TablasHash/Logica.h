/*Creado por Adrian González Pardo
Fecha de modificación: 29/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Hash.h"
/*Creacion del menu de la Tabla Hash*/
void Menu(TablaH t){
  char *ele,k,*pal,*pal2;
  int key,i,j,lim;
  Lista l;
  printf("Ingresa el nombre del elemento que deseas visualizar\n");
  ele=(char*)malloc(sizeof(char)*100);
  scanf("%s",ele);
  ele=toUCase(ele);
  k=keys(ele,strlen(ele));
  key=k;
  l=t[key];
  lim=numElem(l);
  for(i=0;i!=lim;i++){
    pal=(char*)malloc(sizeof(char)*100);
    pal2=(char*)malloc(sizeof(char)*100);
    pal=cabeza(l);
    for(j=0;j!=strlen(pal);j++){
      if(*(pal+j)=='_'){
        *(pal2+j)='\0';
        break;
      }
      *(pal2+j)=*(pal+j);
    }
    if(strcmp(ele,pal2)==0){
      impElem(pal);
      free(ele);
      free(pal);
      free(pal2);
      break;
    }

    l=resto(l);
  }
}
/*Función que lee un txt para crear un diccionario Hash*/
void Lee(){
  int i;
  char *key,*rea,sca[1000];
  FILE *out=fopen("Dic.txt","r");
  TablaH t;
  t=creaDic(10);
  for(i=0;i!=10;i++){
    t[i]=vacia();
  }
  while(fscanf(out,"%s",sca)!=EOF){
    rea=(char*)malloc(sizeof(char)*1000);
    key=(char*)malloc(sizeof(char));
    strcpy(rea,sca);
    rea=toUCase(rea);
    *key=keys(rea,paren(rea));
    i=*key;
    t[i]=InsOrd(rea,t[i]);
  }
  Menu(t);
}
