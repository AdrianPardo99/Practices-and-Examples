/*Creado por Adrian González Pardo
Fecha de modificación: 26/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <string.h>
typedef char* Elem;
int EsMoI(Elem e,Elem e1){return strcmp(e,e1)<=0;}
void impElem(Elem e){printf("%s\n",e);}
void impElemArch(Elem e,FILE *out){fprintf(out,"%s\n",e);}
