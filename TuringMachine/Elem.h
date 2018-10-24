/*Creado por Adrian González Pardo
  Contacto: gozapaadr@gmail.com
  Nickname: DevCrack
  Fecha de modificación: 23/10/2018
  Licencia Creative Commons CC BY-SA*/
#include "Color.h"
typedef char Elem;
typedef char* Elem1;
/*Imprime la cabecera de alguna estructura de datos*/
void impElem(Elem e){printf("%c\n",e);}
/*Imprime la cabecera de la estructura de datos con un color caracteristico*/
void impElemColor(Elem e,char *color){printf("%s|%c|%s",color,e,KNRM);}
/*Compara dos enteros*/
int isEquals(int a,int b){return a==b;}
/*Mide el tamaño de un arreglo de caracteres*/
int lenCad(char *c){return (*c)?(1+lenCad(c+1)):(0);}
/*Imprime un arreglo de caracteres con salto de linea*/
void impElem1(Elem1 e){printf("%s\n",e);}
/*Imprime un arreglo de carecteres*/
void impElem2(Elem1 e){printf("%s",e);}
/*Localiza en un arreglo de caracteres en donde se ubica una coma, sirve para
limitar algunas funciones de la logica*/
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
/*Funcion que busca que la cadena que fue ingresada en la lectura del programa
pertenezca al lenguaje*/
int valCad(char *lenguaje,char *cadena){
  int i,j=lenCad(cadena),k,l=lenCad(lenguaje),ban;
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
/*Funcion que compara un par de arreglos de caracteres*/
int isElemEquals(Elem1 e,Elem1 e1){return (strcmp(e,e1))==0;}
/*Funcion que compara dos caracteres*/
int isCharEquals(char a,char b){return a==b;}
