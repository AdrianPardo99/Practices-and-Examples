/*Creado por Adrian González Pardo
Fecha de modificación: 25/05/2018
Correo electronico:gozapaadr@gmail.com
2CV1
Licencia Creative Commons CC BY-SA*/
#include "Queue.h"
void Leer(FILE*);
void AP(Cola,Cola2,Cola);
void Cadenas(Cola,Cola2,Cola,Elem);
void Tran(Cola a,Cola b,Cola2 c,Elem estado,Elem caracteres,Elem cadena,Elem efinal,Pila p);

/*Función que permite la lectura del archivo txt para crear el AP a partir de una
estructura de datos de tipo Cola (FIFO)*/
void Leer(FILE *f){
	int ini=0,dat=0,sigg=0
	,i,j,coun=0,ban=0,num,inip=0,sip=0;
	char c[1000],*pal,*pal2,*pal3,*pal4,*pal5;
	Elem inicio,dato,siguiente,centinela,inp,sigp;
	Cola a=nueva(),b=nueva(),e=nueva();
	Cola2 d=nueva2();
	/*Ciclo de lectura del txt*/
	while(fscanf(f,"%s",c)!=EOF){
		pal=(char*)malloc(sizeof(char)*1000);
		strcpy(pal,c);
		a=formar(a,pal);
		e=(coun==1)?(formar(e,pal)):(e);
		coun++;
		if(coun>6){
			b=formar(b,pal);
		}
	}
	num=tamCola(a)-6;
	inicio=Elemnuevo2();
	dato=Elemnuevo2();
	siguiente=Elemnuevo2();
	inp=Elemnuevo2();
	sigp=Elemnuevo2();
	/*Creacion de las transiciones que necesita cada conjunto de estados del AP*/
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
				if(*(centinela+j)==','){
					ban++;
					*(siguiente+1)='\0';
					sigg=0;
				}else{
					*(siguiente+sigg)=*(centinela+j);
					sigg++;
					}
			}else if(ban==3){
				if(*(centinela+j)==','){
					ban++;
					*(inp+1)='\0';
					inip=0;
				}else{
					*(inp+inip)=*(centinela+j);
					inip++;
				}
			}else if(ban==4){
				*(sigp+sip)=*(centinela+j);
				sip++;
			}
		}
		*(sigp+sip)='\0';
		pal=(char*)malloc(sizeof(char)*tamElem(inicio));
		pal2=(char*)malloc(sizeof(char)*tamElem(dato));
		pal3=(char*)malloc(sizeof(char)*tamElem(siguiente));
		pal4=(char*)malloc(sizeof(char)*tamElem(inp));
		pal5=(char*)malloc(sizeof(char)*tamElem(sigp));
		strcpy(pal,inicio);
		strcpy(pal2,dato);
		strcpy(pal3,siguiente);
		strcpy(pal4,inp);
		strcpy(pal5,sigp);
		d=formar2(d,pal,pal2,pal3,pal4,pal5);
		sip=0;
		ban=0;
		*inicio=*dato=*siguiente=*inp=*sigp='\0';
		b=desformar(b);
	}
	AP(a,d,e);
}

/*Función que imprime en un formato bonito (en Linux) el AP para despues trabajar con el*/
void AP(Cola a,Cola2 b,Cola c){
	int i,j=0;
	Elem alf,cen;
	printf("AP={Q,Σ,P,q,p,F,δ}\n");
	impCola(a,0);
	printf("Numero total de transiciones : %d\n",tamCola(a)-6);
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

/*Función que permite la lectura de una cadena de texto para trabajar en el AP*/
void Cadenas(Cola a,Cola2 b,Cola c,Elem e){
	Elem cad,efinal2;
	int ban1=0,i,j;
	cad=(Elem)malloc(sizeof(char)*1000);
	printf("Ingresa una cadena para el AP:\n");
	fgets(cad,1000,stdin);
	/*Ciclo que investiga en la cadena si esta dentro del alfabeto todas las letras que ingresa*/
	for(i=0;i!=tamElem(cad);i++){
		if(ban1==1){
			printf("Los caracteres que ingreso no son validos en el alfabeto del AP\n");
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
	Elem estado,caracteres,efinal;
	Cola d=nueva();
	Pila p=empty();
	d->prim=a->prim->sig->sig->sig;
	d->ult=NULL;
	estado=primero(d);
	d=desformar(d);
	p=push(primero(d),p);
	d=desformar(d);
	efinal=primero(d);
	free(d);
	Tran(a,c,b,estado,caracteres,cad,efinal,p);

}

/*Función que realiza las transiciones de forma recursiva de la cadena en el AP*/
void Tran(Cola a,Cola b,Cola2 c,Elem estado,Elem caracteres,Elem cadena,Elem efinal,Pila p){
	int i,ban=0,j;
	Elem pil=Elemnuevo2(),com=Elemnuevo2(),elpil;
	puts("Pila\tCadena");
	impStack(p);
	impElem(cadena);
	puts("");
	Cola2 d=nueva2();
	d->prim=c->prim;
	d->ult=c->ult;
	Cola centinela=nueva();
	centinela->prim=a->prim->sig->sig->sig->sig->sig->sig;
	centinela->ult=a->ult;
	j=tamCola2(d);
	while (!esnueva2(d)){
		com=inicio(d);
		/*Saber en que estado del AP esta*/
		if(strcmp(estado,com)==0){
			*pil=*cadena;
			com=primero2(d);
			/*Saber si el dato de la cadena es correcto*/
			if(strcmp(pil,com)==0){
				pil=top(p);
				com=iniPila(d);
				/*Saber si el dato que esta en la pila corresponde correctamente*/
				if(strcmp(pil,com)==0){
					estado=siguiente(d);
					pil=sigPila(d);
					if(strcmp(pil,"E")==0){
						p=pop(p);
					}else{
						elpil=(Elem)malloc(sizeof(char)*2);
						strcpy(elpil,pil);
						p=push(elpil,p);
					}
					d=Armar(centinela,tamCola(a)-6);
					impStack(p);
					cadena++;
					impElem(cadena);
				}else{
					ban=1;
				}
			}else{
				ban=1;
			}
		}else{
			ban=1;
		}
		if(ban==1){
			d=desformar2(d);
		}
		*pil='\0';
		*com='\0';
	}
	if((strcmp(top(p),"Z")==0)&&(*cadena!='\0')&&(strcmp(efinal,estado)==0)){
		printf("Cadena Valida\n");
	}else{
		printf("Cadena Invalida\n");
	}
}
