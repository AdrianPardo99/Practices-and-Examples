/*Creado por Adrian González Pardo
             Israel Bahena Brito
             Luis García
             Fecha de modificación: 10/06/2018
             2CV1
             Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
#include "Queue.h"
#include "ListaD.h"
void proceso(Cola,char*,char*,Cola2,char*);
void muestraTM(Cola,char*,char*,char*,Cola2);
void Lee(){
  FILE *out=fopen("Turing2.txt","r");
  char lec[100],*pal,*lenguaje,*efinal,*inicial;
  Cola c1=nueva(),c2=nueva(),cen=nueva(),fin=nueva(),init=nueva();
  Cola2 p=nueva2();
  int coun=0,i,j,k,l,in,da,si,es,pa;
  while(fscanf(out,"%s",lec)!=EOF){
    pal=(char*)malloc(sizeof(char)*100);
    strcpy(pal,lec);
    c1=formar(c1,pal);
    if(coun==1){
      cen=formar(cen,pal);
    }
    if(coun==3){
      init=formar(init,pal);
    }
    if(coun==5){
      fin=formar(fin,pal);
    }
    coun++;
  }
  lenguaje=sinComa(primero(cen));
  inicial=primero(init);
  efinal=primero(fin);
  free(cen);
  free(fin);
  free(init);
  c2=avanza(c1);
  p=crea(c2);
  muestraTM(c1,lenguaje,efinal,inicial,p);
}
void muestraTM(Cola TM,char* lenguaje,char* efinal,char* inicial,Cola2 T){
  int ban=0;
  char *cad;
  puts("Maquina de Turing:");
  impCola(TM,0);
  puts("Transiciones:");
  impCola2(T);
  puts("Ingresa una cadena para trabajar:");
  cad=(char*)malloc(sizeof(char)*100);
  fgets(cad,100,stdin);
  ban=valCad(lenguaje,cad);
  (!ban)?(printf("Cadena que usa el lengujes\nIniciando proceso...\n")):(printf("Cadena invalida\n"
  "Los caracteres que ingreso no pertenecen al lenguaje que esta colocado\n"));
  (!ban)?(proceso(TM,efinal,inicial,T,cad)):(exit(1));
  //estados finales

}
void proceso(Cola TM,char *efinal,char *inicial,Cola2 T,char *cadena){
  printf("Presiona una tecla para continuar...");
  getchar();
  ListaD l=vaciaD();
  int i,j=tamCad(cadena);
  for(i=0;i!=3;i++){
    l=consD('B',l);
  }
  for(i=0;i!=j-1;i++){
    l=consD(*(cadena+i),l);
  }
  for(i=0;i!=3;i++){
    l=consD('B',l);
  }
  printf("Mostrando cinta:\n");
  l=invierteD(l);
  impToTM(l,3,0);
  puts("");
}
