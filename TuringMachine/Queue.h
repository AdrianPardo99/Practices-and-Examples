/*Creado por Adrian González Pardo
             Israel Bahena Brito
             José Luis García Mendoza
             Suarez Vazquez Erick
             Fecha de modificación: 10/06/2018
             2CV1
             Licencia Creative Commons CC BY-SA*/
#include "Cola.h"
#include "Cola2.h"
/*Función para avanzar la estructura y despues se crean las Transiciones en la
  segunda Cola*/
Cola avanza(Cola c){
  int i;
  Cola c1=(Cola)malloc(sizeof(struct CNodo));
  c1->prim=c->prim;
  c1->ult=c->ult;
  for(i=0;i!=6;i++)
  c1=desformar(c1);
  return c1;
}
/*Función que crea el apartado de las Transiciones de la Máquina de Turing*/
Cola2 crea(Cola c2){
  Cola2 p=nueva2();
  char *pal,*pal1,*pal2,*pal3,*pal4,inicio[20],dato[20],
  siguiente[20],escribe[20],pasa[20],*centi;
  int coun,i,j,k,l,in,da,si,es,pa;
  j=tamCola(c2);
  coun=0;
  for(i=0;i!=j;i++){
    centi=primero(c2);
    l=tamElem(centi);
    coun=in=da=si=es=pa=0;
    for(k=0;k!=l;k++){
        if(coun==0){
          if(*(centi+k)!=','){
            *(inicio+in)=*(centi+k);
            in++;
          }else{
            *(inicio+in)='\0';
            coun++;
          }
        }else if(coun==1){
          if(*(centi+k)!=','){
            *(dato+da)=*(centi+k);
            da++;
          }else{
            *(dato+da)='\0';
            coun++;
          }
        }else if(coun==2){
          if(*(centi+k)!=','){
            *(siguiente+si)=*(centi+k);
            si++;
          }else{
            *(siguiente+si)='\0';
            coun++;
          }
        }else if(coun==3){
          if(*(centi+k)!=','){
            *(escribe+es)=*(centi+k);
            es++;
          }else{
            *(escribe+es)='\0';
            coun++;
          }
        }else if(coun==4){
          if(*(centi+k)!=','){
            *(pasa+pa)=*(centi+k);
            pa++;
          }
        }
      }
      *(pasa+pa)='\0';
      pal=(char*)malloc(sizeof(char)*tamElem(inicio));
      pal1=(char*)malloc(sizeof(char)*tamElem(dato));
      pal2=(char*)malloc(sizeof(char)*tamElem(siguiente));
      pal3=(char*)malloc(sizeof(char)*tamElem(escribe));
      pal4=(char*)malloc(sizeof(char)*tamElem(pasa));
      strcpy(pal,inicio);
      strcpy(pal1,dato);
      strcpy(pal2,siguiente);
      strcpy(pal3,escribe);
      strcpy(pal4,pasa);
      p=formar2(p,pal,pal1,pal2,pal3,pal4);
      c2=desformar(c2);
    }
    return p;
}
