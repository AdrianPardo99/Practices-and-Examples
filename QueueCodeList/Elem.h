#include <string.h>
//typedef int Elem;
typedef char* Elem;
void impElem(Elem e){printf("%s\n",e);}
void impElemArch(Elem e,FILE *out){fprintf(out,"%s\n",e);}
void impNum(int e){printf("El numero de elementos de la lista es: %d\n",e);}
//Elem EsMoI(Elem e,Elem e1){return e<=e1;}
int EsMoI(Elem e,Elem e1){return strcmp(e,e1)<=0;}

