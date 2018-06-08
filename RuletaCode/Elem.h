/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Color.h"
typedef int Elem;
void impElem(Elem e){printf("%d\n",e);}
void impElemC(Elem e){
  if(e==0){
    printf("%s%d%s ",KGRN,e,KNRM);
  }else if(e==1||e==3||e==5||e==7||e==9||e==12||e==14||e==16||e==18||e==19||e==21||e==23||e==25||e==27||e==30||e==32||e==34||e==36){
    printf("%s%d%s ",KRED,e,KNRM);
  }else{
    printf("%s%d%s ",KWHT,e,KNRM);
  }
}
int casColor(Elem e){
  if(e==0){
    return 0;
  }else if(e==1||e==3||e==5||e==7||e==9||e==12||e==14||e==16||e==18||e==19||e==21||e==23||e==25||e==27||e==30||e==32||e==34||e==36){
    return 1;
  }else{
    return -1;
  }
}
int isIgual(int e,int e1){return e==e1;}
int isPar(int e){return (e%2)==0;}
int isPasa(int e){return (e>=17);}
int docenas(int e){return (e>0&&e<=12)?(0):((e>12&&e<=24)?(1):(-1));}
int Columna(int e){
  switch (e) {
    case 1:case 4:case 7:case 10:case 13:case 16:case 19:case 22:case 25:case 28:case 31:case 34:
      return 0;
    break;
    case 2:case 5:case 8:case 11:case 14:case 17:case 20:case 23:case 26:case 29:case 32:case 35:
      return 1;
    break;
    case 3:case 6:case 9:case 12:case 15:case 18:case 21:case 24:case 27:case 30:case 33:case 36:
      return -1;
  }
}
int gana(int casilla,int apuesta,int dinero,int tipo){
  int color=casColor(casilla),b,b1=0,ap=1;
  if(tipo==1){
    b=casColor(apuesta);
    b1=(isIgual(b,color));
    dinero-=ap;
    ap=(b1)?(1):(0);
    dinero+=ap;

  }else if(tipo==2){
    b=(isPar(apuesta));
    b1=(isPar(casilla));
    b1=(isIgual(b1,b));
    dinero-=ap;
    ap=(b1)?(1):(0);
    dinero+=ap;

  }else if(tipo==3){
    b=(isPasa(casilla));
    b1=(isPasa(apuesta));
    b1=(isIgual(b1,b));
    dinero-=ap;
    ap=(b1)?(1):(0);
    dinero+=ap;

  }else if(tipo==4){
    b=(docenas(casilla));
    b1=(docenas(apuesta));
    b1=(isIgual(b1,b));
    dinero-=ap;
    ap=(b1)?(2):(0);
    dinero+=ap;

  }else if(tipo==5){
    b=(Columna(casilla));
    b1=(Columna(apuesta));
    b1=(isIgual(b1,b));
    dinero-=ap;
    ap=(b1)?(2):(0);
    dinero+=ap;
  }else if(tipo==6){
    b=casilla;
    b1=apuesta;
    b1=(isIgual(b1,b));
    dinero-=ap;
    ap=(b1)?(35):(0);
    dinero+=ap;
  }
  printf("Ficha en la que cae: %d\nFicha en la que aposto:%d\nUsted: %s\n",casilla,apuesta,(b1)?("Gano"):("Perdio"));
  return dinero;
}
