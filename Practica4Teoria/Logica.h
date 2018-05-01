/*Creado por Adrian González Pardo
Fecha de modificación: 30/04/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Queue.h"
void Leer(FILE*);
void AFD(Cola,Cola2,Cola);
void Cadenas(Cola,Cola2,Cola,Elem);
void Tran(Cola,Cola2,Cola,Elem,Elem,Elem,Elem,Elem,Elem);

/*Función que permite la lectura del archivo txt para crear el AFD a partir de una
estructura de datos de tipo Cola (FIFO)*/
void Leer(FILE *f){
	int ini=0,dat=0,sigg=0
	,i,j,coun=0,ban=0,num;
	char c[1000],*pal,*pal2,*pal3;
	Elem inicio,dato,siguiente,centinela;
	Cola a=nueva(),b=nueva(),e=nueva();
	Cola2 d=nueva2();
	/*Ciclo de lectura del txt*/
	while(fscanf(f,"%s",c)!=EOF){
		pal=(char*)malloc(sizeof(char)*1000);
		strcpy(pal,c);
		a=formar(a,pal);
		e=(coun==1)?(formar(e,pal)):(e);
		coun++;
		if(coun>4){
			b=formar(b,pal);
		}
	}
	num=tamCola(a)-4;
	inicio=Elemnuevo2();
	dato=Elemnuevo2();
	siguiente=Elemnuevo2();
	/*Creacion de las transiciones que necesita cada conjunto de estados del AFD*/
	for(i=0;i!=num;i++){
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
		d=formar2(d,pal,pal2,pal3);
		sigg=0;
		ban=0;
		b=desformar(b);
	}
	AFD(a,d,e);
}

/*Función que imprime en un formato bonito (en Linux) el AFD para despues trabajar con el*/
void AFD(Cola a,Cola2 b,Cola c){
	int i,j=0;
	Elem alf,cen;
	printf("AFD={Q,Σ,S,F,δ}\n");
	impCola(a,0);
	printf("Numero total de transiciones : %d\n",tamCola(a)-4);
	impCola2(b);
	impCola(c,1);
	cen=primero(c);
	alf=(Elem)malloc(sizeof(char)*tamElem(primero(c)));
	for(i=0;i!=tamElem(cen);i++){
		if(*(cen+i)==','){

		}else{
			*(alf+j)=*(cen+i);
			j++;
		}
	}
	*(alf+j+1)='\0';
	printf("Alfabeto: %s\n",alf);
	Cadenas(a,b,c,alf);
}

/*Función que permite la lectura de una cadena de texto para trabajar en el AFD*/
void Cadenas(Cola a,Cola2 b,Cola c,Elem e){
	Elem cad,efinal2;
	int ban1=0,i,j;
	cad=(Elem)malloc(sizeof(char)*1000);
	printf("Ingresa una cadena para el AFD:\n");
	fgets(cad,1000,stdin);
	/*Ciclo que investiga en la cadena si esta dentro del alfabeto todas las letras que ingresa*/
	for(i=0;i!=tamElem(cad);i++){
		if(ban1==1){
			printf("Los caracteres que ingreso no son validos en el alfabeto del AFD\n");
			free(cad);
			exit(0);
			break;
		}
		for(j=0;j!=tamElem(e);j++){
			if(*(cad+i)==*(e+j)){
				ban1=0;
				break;
			}else{
				ban1=1;
			}
		}
	}
	Elem estado,caractes,siguientes,efinal;
	Cola d=nueva();
	d->prim=a->prim;
	d->ult=a->ult;
	estado=primero(desformar(desformar(d)));
	d=estadoFinal(a,0);
	efinal=primero(d);
	j=0;
	/*Bandera que permite saber si exite más de un estado final*/
	ban1=ElemComa(efinal);
	if(ban1==0){
		printf("Estado final: %s\n", efinal);
		Tran(a,b,c,e,cad,estado,caractes,siguientes,efinal);
	}else{
		efinal2=(Elem)malloc(sizeof(char)*tamElem(efinal));
		for(i=0;i!=tamElem(efinal);i++){
			if(*(efinal+i)==','){
				*(efinal2+j+1)='\0';
				printf("Estado final: %s\n", efinal2);
				Tran(a,b,c,e,cad,estado,caractes,siguientes,efinal2);
				*efinal2='\0';
				j=0;
			}else{
				*(efinal2+j)=*(efinal+i);
				j++;
			}
		}
		*(efinal2+j+1)='\0';
		printf("Estado final: %s\n", efinal2);
		Tran(a,b,c,e,cad,estado,caractes,siguientes,efinal2);
	}
}

/*Función que realiza las transiciones de forma recursiva de la cadena en el AFD*/
void Tran(Cola a,Cola2 b,Cola c,Elem e,Elem cad,Elem estado,Elem caracteres,Elem siguientes,Elem efinal){
	caracteres=Elemnuevo2();
	siguientes=Elemnuevo2();
	int i,j=0,k=0,l;
	Cola2 centinela=nueva2(),trans=nueva2();
	centinela->prim=b->prim;
	centinela->ult=b->ult;
	Elem a1=Elemnuevo2(),b1=Elemnuevo2(),c1=Elemnuevo2(),sigui;
	Cola d=nueva(),cen=nueva();
	/*Ciclo que permite jalar los estados siguientes a los que trabaja el estado inicial que contiene
	un ejemplo es decir que el estado 0 apunta a los estados 0,1,2 y de este modo permite saber que caracter sigue*/
	for(i=0;i!=tamCola2(b);i++){
		a1=primero2(centinela);
		b1=siguiente(centinela);
		c1=inicio(centinela);
		if(!(strcmp(estado,c1))){
			*(caracteres+j)=*a1;
			for(l=0;l!=tamElem(b1);l++){
				*(siguientes+k)=*(b1+l);
				k++;
			}
			*(siguientes+k)=',';
			j++;
			k++;
		}
		centinela=desformar2(centinela);
	}
	*(caracteres+j+1)='\0';
	*(siguientes+k-1)='\0';
	j=0;
	for(i=0;i!=tamElem(siguientes);i++){
		if(*(siguientes+i)!=','||(isdigit(*(siguientes+i)))){
				*(a1+j)=*(siguientes+i);
				j++;
		}else{
			*(a1+j)='\0';
			d=formar(d,a1);
			a1=Elemnuevo2();
			j=0;
		}
	}
	*(a1+j+1)='\0';
	d=formar(d,a1);
	cen->prim=a->prim->sig->sig->sig->sig;
	cen->ult=a->ult;
	for(i=0;i!=tamElem(caracteres);i++){
		sigui=primero(d);
		if(*(caracteres+i)==*(cad)){
			printf("%s(%c)->%s,",estado,*cad,primero(d));
			/*Llamo recursivamente a la funcion para seguir con los demas caminos del AFD*/
			Tran(a,Armar(cen,tamCola(a)-4),c,e,cad+1,sigui,caracteres,siguientes,efinal);
		}else{
		}
		d=desformar(d);
	}
	if((*(cad+1)=='\0')){
		if(!strcmp(efinal,estado)){
			printf("\tCadena valida\n");
		}else{
			printf("\tCadena invalida\n");
		}
	}else{
		if(!strcmp(efinal,estado)){
			printf("\tCadena invalida: sobran %s\n",cad);
		}else{
		}
	}
}
