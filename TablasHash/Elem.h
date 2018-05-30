/*Creado por Adrian González Pardo
Fecha de modificación: 21/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <string.h>
/*typedef int Elem;*/
typedef char* Elem;
void impElem(Elem e){printf("%s\n",e);}
void impElemArch(Elem e,FILE *out){fprintf(out,"%s\n",e);}
void impNum(int e){printf("El numero de elementos de la lista es: %d\n",e);}
//Elem EsMoI(Elem e,Elem e1){return e<=e1;}
int EsMoI(Elem e,Elem e1){return strcmp(e,e1)<=0;}
int esIgual(int e,int e1){return e==e1;}
void impElem2(Elem e){printf("%s\t",e);}
char *toUCase(char *a){
  int i=0;
  while(*(a+i)){
    *(a+i)=toupper(*(a+i));
    i++;
  }
  return a;
}
int paren(char *a){
  return (*a!='\0')?((*a!='_')?(1+paren(a+1)):(0)):(0);
}
char keys(char *a,int tam){
  int i=0,sum=0;
  for(i=0;i!=tam;i++){
    sum+=*(a+i);
  }
  return sum%10;
}
