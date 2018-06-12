/*Creado por Adrian González Pardo
             Israel Bahena Brito
             José Luis García Mendoza
             Suarez Vazquez Erick
             Fecha de modificación: 10/06/2018
             2CV1
             Licencia Creative Commons CC BY-SA*/
#include "Color.h"
typedef char Elem;
typedef char* Elem1;
void impElem(Elem e){printf("%c\n",e);}
void impElemColor(Elem e,char *color){printf("%s|%c|%s",color,e,KNRM);}
int isEquals(int a,int b){return a==b;}
int lenCad(char *c){return (*c)?(1+lenCad(c+1)):(0);}
void impElem1(Elem1 e){printf("%s\n",e);}
void impElem2(Elem1 e){printf("%s",e);}
Elem1 sinComa(Elem1 e){
  Elem1 e1=(Elem1)malloc(sizeof(char)*strlen(e));
  int i=0,j=0;
  while(*(e+i)){
    if(*(e+i)!=','){
      *(e1+j)=*(e+i);
      j++;
    }
    i++;
  }
  return e1;
}
int tamCad(char *cadena){return (*cadena)?(1+tamCad(cadena+1)):(0);}
int valCad(char *lenguaje,char *cadena){
  int i,j=tamCad(cadena),k,l=tamCad(lenguaje),ban;
  for(i=0;i!=j;i++){
    if(ban==1){
      return 1;
      break;
    }
    for(k=0;k!=l;k++){
      if(*(lenguaje+k)==*(cadena+i)){
        ban=0;
        break;
      }else{
        ban=1;
      }
    }
  }
  return 0;
}
int isElemEquals(Elem1 e,Elem1 e1){return (strcmp(e,e1))==0;}
int isCharEquals(char a,char b){return a==b;}
