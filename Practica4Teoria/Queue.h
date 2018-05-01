/*Creado por Adrian González Pardo
Fecha de modificación: 30/04/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Cola2.h"
#include "Cola.h"
/*Función que arma una cola auxiliar a partir de la primer Cola que permite ver las transiciones*/
Cola2 Armar(Cola q,int tam){
  int i,j,ini=0,dat=0,sigg=0,ban=0;
  Elem inicio=Elemnuevo2(),dato=Elemnuevo2(),siguiente=Elemnuevo2(),pal,pal2,pal3,centinela;
  Cola2 q1=nueva2();
  Cola b=nueva();
  b->prim=q->prim;
  b->ult=q->ult;
  for(i=0;i!=tam;i++){
		centinela=primero(b);
		for(j=0;j!=tamElem(primero(b));j++){
			if(ban==0){
				if(*(centinela+j)==','){
					ban++;
					*(inicio+1)='\0';
					ini=0;
				}else{
					*(inicio+ini)=*(centinela+j);
					ini++;
				}
			}else if(ban==1){
				if(*(centinela+j)==','){
					ban++;
					*(dato+1)='\0';
					dat=0;
				}else{
					*(dato+dat)=*(centinela+j);
				}
			}else if(ban==2){
				*(siguiente+sigg)=*(centinela+j);
				sigg++;
			}
		}
		*(siguiente+sigg)='\0';
		pal=(char*)malloc(sizeof(char)*tamElem(inicio));
		pal2=(char*)malloc(sizeof(char)*tamElem(dato));
		pal3=(char*)malloc(sizeof(char)*tamElem(siguiente));
		strcpy(pal,inicio);
		strcpy(pal2,dato);
		strcpy(pal3,siguiente);
		q1=formar2(q1,pal,pal2,pal3);
		sigg=0;
		ban=0;
		b=desformar(b);
	}
  return q1;
}
