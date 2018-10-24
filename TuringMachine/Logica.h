/*Creado por Adrian González Pardo
  Contacto: gozapaadr@gmail.com
  Nickname: DevCrack
  Licencia Creative Commons CC BY-SA*/
#include "Elem.h"
#include "Queue.h"
#include "ListaD.h"
#include "Stack.h"
/*Función que realizara el recorrido de la cinta de la Máquina de Turing*/
void proceso(Cola,char*,char*,Cola2,char*);
/*Función que muestra la configuración de la Máquina de Turing*/
void muestraTM(Cola,char*,char*,char*,Cola2);
/*Función que lee el archivo txt de la configuración para la Máquina*/
void Lee(char *dir){
  if(isElemEquals(dir,"Turing1.txt")){
    puts("La siguiente máquina maneja el lenguaje: (01)*0");
  }else if(isElemEquals(dir,"Turing2.txt")){
    puts("La siguiente máquina maneja el lenguaje: 0*1+");
  }else if(isElemEquals(dir,"Turing3.txt")){
    puts("La siguiente máquina maneja el lenguaje: 01*");
  }else if(isElemEquals(dir,"Turing4.txt")){
    puts("La siguiente máquina maneja el lenguaje: (0)^n(1)^n | n>0");
  }else if(isElemEquals(dir,"Turing5.txt")){
    puts("La siguiente máquina maneja el lenguaje: (1*01*0)*");
  }
  FILE *out=fopen(dir,"r");
  if(out==NULL){
    puts("Error al leer el archivo txt. Saliendo del programa...");
    exit(1);
  }
  char lec[100],*pal,*lenguaje,*efinal,*inicial;
  Cola c1=nueva(),c2=nueva(),cen=nueva(),fin=nueva(),init=nueva();
  Cola2 p=nueva2();
  int coun=0,i,j,k,l,in,da,si,es,pa;
  /*Ciclo que lee el txt y lo agrega a la Cola*/
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
/*Funcion que muestra la configuracion de la maquina de Turing*/
void muestraTM(Cola TM,char* lenguaje,char* efinal,char* inicial,Cola2 T){
  int ban=0;
  char *cad;
  puts("Máquina de Turing:");
  impCola(TM,0);
  puts("Transiciones:");
  impCola2(T);
  puts("Ingresa una cadena para trabajar:");
  cad=(char*)malloc(sizeof(char)*100);
  fflush(stdin);
  fgets(cad,100,stdin);
  ban=valCad(lenguaje,cad);
  (!ban)?(printf("Cadena que usa el lenguaje\nIniciando proceso...\n")):
  (printf("Cadena invalida\nLos caracteres que ingreso no pertenecen al
  lenguaje que esta colocado\n"));
  (!ban)?(proceso(TM,efinal,inicial,T,cad)):(exit(1));
}
/*Funcion que realiza las transiciones y la animacion del cabeza de la maquina*/
void proceso(Cola TM,char *efinal,char *inicial,Cola2 T,char *cadena){
  Stack s=newStack();
  char *cab,*ch;
  cab=(char*)malloc(sizeof(char));
  ListaD l=vaciaD(),l1=(ListaD)malloc(sizeof(struct LENodo));
  int i,j;
  Cola2 T1=(Cola2)malloc(sizeof(ApNodo2));
  T1->prim=T->prim;
  T1->ult=T->ult;
  printf("Presiona una tecla para continuar...");
  getchar();
  for(i=0;i!=3;i++){
    l=consD('B',l);
  }
  j=lenCad(cadena);
  for(i=0;i!=j-1;i++){
    l=consD(*(cadena+i),l);
  }
  for(i=0;i!=3;i++){
    l=consD('B',l);
  }
  printf("Mostrando cinta:\n");
  l=invierteD(l);
  l1->el=cabezaD(l);
  l1->sig=restoD(l);
  l1->ant=NULL;
  l1=restoD(restoD(restoD(l1)));
  j=counD(l)-counD(l1);
  impToTM(l,j,0);
  puts("\n");
  sleep(1);
  Elem1 transicion;
  /*Cola2
    inicio()->Estado en el que estados
    dato()->El caracter que se encuentra en la cinta
    siguiente()->El siguiente estado en el que se modifica
    escribe()->Escribe en la cinta
    pos()->Posicion a la que pasa la cinta

  Proceso en el que analísa si el cabezal en el que esta es valido en la configuración*/
  while (!esnueva2(T1)) {
    if(isElemEquals(inicial,inicio(T1))){
      *cab=cabezaD(l1);
      if(isElemEquals(cab,dato(T1))){
        ch=(char*)malloc(sizeof(char));
        ch=escribe(T1);
        l1=change(*ch,l1);
        free(inicial);
        inicial=(char*)malloc(sizeof(char));
        inicial=siguiente(T1);
        if(isElemEquals(pos(T1),"R")){
          l1=restoD(l1);
        }else if(isElemEquals(pos(T1),"L")){
          l1=anteriorD(l1);
        }
        s=push(s,impTransicion(T1));
        printTranStack(s);
        puts("");
        T1=crea(avanza(TM));
        j=counD(l)-counD(l1);
        impToTM(l,j,0);
        puts("\n");
        //printf("\033[H\033[J");
        sleep(1);
      }else{
        T1=desformar2(T1);
      }
    }else{
      T1=desformar2(T1);
    }
  }
  if(isElemEquals(inicial,efinal)){
    printf("Cadena valida\n");
  }else{
    printf("Cadena invalida\n");
  }
}
