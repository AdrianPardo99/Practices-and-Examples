/*Creado por Adrian González Pardo
Fecha de modificación: 26/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <string.h>
typedef int Elem;
int EsMoI(Elem e,Elem e1){return e<=e1;/*strcmp(e,e1)<=0;*/}
void impElem(Elem e){printf("%d\n",e);}
void impElemArch(Elem e,FILE *out){fprintf(out,"%d\n",e);}
