/*Creado por Adrian González Pardo
Fecha de modificación: 21/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <string.h>
//typedef int Elem;
typedef char* Elem;
void impElem(Elem e){printf("%s\n",e);}
void impElemArch(Elem e,FILE *out){fprintf(out,"%s\n",e);}
void impNum(int e){printf("El numero de elementos de la lista es: %d\n",e);}
//Elem EsMoI(Elem e,Elem e1){return e<=e1;}
int EsMoI(Elem e,Elem e1){return strcmp(e,e1)<=0;}
int esIgual(int e,int e1){return e==e1;}
