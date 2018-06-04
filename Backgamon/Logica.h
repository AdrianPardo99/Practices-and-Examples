/*Creado por Adrian González Pardo
Fecha de modificación: 29/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include"Elem.h"
#include"Bicola.h"
#include "Color.h"
/*Las siguientes funciones manejan valores booleanos (int)
Ingresar un valor verdadero como su argumento hara movimientos con fichas rojas, mientras que un valor falso hara movimientos con fichas blancas.*/
int vanRojas()	{return 1;}
int vanBlancas(){return 0;}

/* Función para llenar la bicola con 24 espacios vacios (ceros)*/
Bicola nuevoTablero(){
	int i;
	Bicola bicolatemporal = nuevabq();
	for(i = 1; i <= 24; ++i)
		bicolatemporal = formard(0,bicolatemporal);
	return bicolatemporal;
}

/* Función para alternar un turno determinado*/
int cambiarTurno(int turno){
	if(turno == vanRojas())
		return vanBlancas();
	else
		return vanRojas();
}

/* Función para obtener el numero de fichas que hay en un punto*/
Elem verfiChasen(Bicola tablero, int turno, int punto){
	int i;
	Elem elemtemporal;
	ApNodoBq apnodotemporal;
	if(turno == vanRojas()){
		apnodotemporal = tablero->izq;
		for(i = 1; i <= punto; ++i){
			elemtemporal = apnodotemporal->datoBq;
			apnodotemporal = apnodotemporal->sig;
		}
	}else{
		apnodotemporal = tablero->der;
		for(i = 1; i <= punto; ++i){
			elemtemporal = apnodotemporal->datoBq;
			apnodotemporal = apnodotemporal->ant;
		}
	}
	return elemtemporal;
}



/* Función para modificar el valor de las fichas en un cierto punto */
Bicola modificarPunto(Bicola tablero, int turno, int punto, Elem modificacion){
	Bicola bicolatemporal;
	Bicola bqdesdepunto = tablero;
	Bicola bqresto = nuevabq();
	int i;
	if(turno == vanRojas()){
		for(i = 1; i <= punto; ++i){
			bqresto = formard(izquierda(bqdesdepunto),bqresto);
			bqdesdepunto = desformari(bqdesdepunto);
		}
		bqdesdepunto = formari(modificacion,bqdesdepunto);
		bqresto = desformard(bqresto);
		bicolatemporal = concatenarbicolas(bqresto,bqdesdepunto);
	}else if(turno == vanBlancas()){
		for(i = 1; i <= punto; ++i){
			bqresto = formari(derecha(bqdesdepunto),bqresto);
			bqdesdepunto = desformard(bqdesdepunto);
		}
		bqdesdepunto = formard(modificacion,bqdesdepunto);
		bqresto = desformari(bqresto);
		bicolatemporal = concatenarbicolas(bqdesdepunto,bqresto);
	}
	return bicolatemporal;
}

Bicola insertarFicha(Bicola tablero, int turno, int punto){
	int valorfichastemporal;
	if(turno == vanRojas())
		valorfichastemporal = verfiChasen(tablero,turno,punto) + 1;
	else
		valorfichastemporal = verfiChasen(tablero,turno,punto) - 1;
	return modificarPunto(tablero,turno,punto,valorfichastemporal);
}

Bicola quitarFicha(Bicola tablero, int turno, int punto){
	int valorfichastemporal;
	if(turno == vanRojas())
		valorfichastemporal = verfiChasen(tablero,turno,punto) - 1;
	else
		valorfichastemporal = verfiChasen(tablero,turno,punto) + 1;
	return modificarPunto(tablero,turno,punto,valorfichastemporal);
}

Bicola trasladarFicha(Bicola tablero, int turno, int origen, int destino){
	tablero = quitarFicha(tablero,turno,origen);
	tablero = insertarFicha(tablero,turno,destino);
	return tablero;
}
// Inicializando el tablero para jugar una nueva partida, siguiendo la regla de que cada jugador debe poner 2 fichas en su punto 24, 5 en su punto 13, 3 en su punto 8, y 5 en su punto 6
Bicola insertarFichasIniciales(){
	int i;
	int j;
	int turnoactual;
	Bicola tablerotemporal = nuevoTablero();
	turnoactual = vanRojas();
	for(j = 1; j <= 2; ++j){
		for(i = 1; i <= 2; ++i)
			tablerotemporal = insertarFicha(tablerotemporal,turnoactual,24);
		for(i = 1; i <= 5; ++i)
			tablerotemporal = insertarFicha(tablerotemporal,turnoactual,13);
		for(i = 1; i <= 3; ++i)
			tablerotemporal = insertarFicha(tablerotemporal,turnoactual,8);
		for(i = 1; i <= 5; ++i)
			tablerotemporal = insertarFicha(tablerotemporal,turnoactual,6);
		turnoactual = cambiarTurno(turnoactual);
	}
	return tablerotemporal;
}

Bicola moveraBarra(Bicola tablero, int turno, int origen, int* barra){
	/*quitarFicha(tablero,turno,origen);*/
	if(turno == vanRojas())
		*barra = *barra+1;
	else
		*barra = *barra-1;
	return quitarFicha(tablero,turno,origen);

}

Bicola sacarDeBarra(Bicola tablero, int turno, int destino, int* barra){
	/*quitarFicha(tablero,turno,origen);*/
	if(turno == vanRojas())
		*barra = *barra-1;
	else
		*barra = *barra+1;
	return insertarFicha(tablero,turno,destino);
}
/*Las siguientes funciones se encargan de la parte gráfica del programa
Las fichas rojas son representadas por +, mientras que las blancas son representadas por -
Función para traducir el valor de las fichas de los puntos a caracteres*/
char impFicha(Bicola tab, int turno, int fila, int col){
	turno = cambiarTurno(turno);
	if(col != 20)
		/*col =(fila-1) < verfiChasen(tab,turno,col) && */
		if(verfiChasen(tab,turno,col) > 0)
			if((verfiChasen(tab,turno,col)-(fila - 1)) > 0)
				return 'R';
			else
				return ' ';
		else if(verfiChasen(tab,turno,col) < 0)
			if((verfiChasen(tab,turno,col)+(fila - 1)) < 0)
				return 'B';
			else
				return ' ';
		else
			return ' ';
	else
		return ' ';
}
/*Función para traducir el valor de las fichas de la barra a caracteres*/
char impFichaBarra(int barra, int turno, int fila){
	turno = cambiarTurno(turno);
	if(barra > 0)
		if((fila-1) < barra && (barra-(fila - 1)) > 0)
			return 'R';
		else
			return ' ';
	else if(barra < 0)
		if((barra+(fila - 1)) < 0)
			return 'B';
		else
			return ' ';
	else
		return ' ';
}
/*Función para imprimir todo el tablero*/
void imprimirTablero(Bicola tab, int tur, int barra){
	int i,j;
	printf("%s* * * * * * * | | | * * * * * * *\n",KGRN);
	for(i = 1; i <= 7; ++i){
		printf("%s*%s",KGRN,KNRM);
		for(j = 12;j >= 1; --j){
			if(j == 6)
				printf(" %s|%s %c %s|%s",KGRN,KNRM,impFichaBarra(barra,tur,i),KGRN,KNRM);
			printf(" ");
			printf("%c",impFicha(tab,tur,i,j));
		}
		printf(" %s*%s\n",KGRN,KNRM);
	}
	printf("%s* v v v v v v |%s %c %s| v v v v v v *%s\n",KGRN,KNRM,impFichaBarra(barra,tur,8),KGRN,KNRM);
	printf("%s* ^ ^ ^ ^ ^ ^ |%s %c %s| ^ ^ ^ ^ ^ ^ *%s\n",KGRN,KNRM,impFichaBarra(barra,tur,9),KGRN,KNRM);
	for(i = 7; i >= 1; --i){
		printf("%s*%s",KGRN,KNRM);
		for(j = 13;j <= 24; ++j){
			if(j == 19)
				printf(" %s|%s %c %s|%s",KGRN,KNRM,impFichaBarra(barra,tur,i + 1 + (2*(8 - i))),KGRN,KNRM);
			printf(" ");
			printf("%c",impFicha(tab,tur,i,j));
		}
		printf(" %s*%s\n",KGRN,KNRM);
	}
	printf("%s* * * * * * * | | | * * * * * * *%s\n",KGRN,KNRM);
}

/*La siguiente función es para tirar un dado*/
int tirarDado(){
	return (rand() % 6) + 1;
}
// Las siguientes funciones verifican el estado del juego, y sus condiciones.
int primeroEnMover(int dado1, int dado2){
	if(dado1 > dado2){
		//printf("Dado 1: %d - Dado 2: %d\n",dado1,dado2);
		//printf("El jugador rojo va primero\n");
		return vanRojas();
	}else if(dado1 < dado2)	{
		//printf("Dado 1: %d - Dado 2: %d\n",dado1,dado2);
		//printf("El jugador blanco va primero\n");
		return vanBlancas();
	}else{
		return primeroEnMover(tirarDado(),tirarDado());
	}
}

int contarFichasEnPunto(Bicola tablero, int turno,int punto){
	if(turno == vanRojas())
		if(verfiChasen(tablero,turno,punto) > 0)
			return verfiChasen(tablero,turno,punto);
		else
			return 0;
	if(turno == vanBlancas())
		if(verfiChasen(tablero,turno,punto) < 0)
			return (-1)*verfiChasen(tablero,turno,punto);
		else
			return 0;
}

int contarFichasEnBarra(int barra, int turno){
	if(turno == vanRojas())
		if(barra >= 0)
			return barra;
	if(turno == vanBlancas())
		if(barra <= 0)
			return (-1)*barra;
}

int tieneFichasEnBarra(int barra, int turno){
	if(turno == vanRojas())
		if(barra > 0)
			return 1;
		else
			return 0;
	else if(turno == vanBlancas())
		if(barra < 0)
			return 1;
		else
			return 0;
}

int contarFichasEnTablero(Bicola tablero, int turno){
	int i;
	int acumulador = 0;
	for(i = 1; i <= 24; ++i){
		acumulador += contarFichasEnPunto(tablero,turno,i);
	}
	return acumulador;
}

int contarFichasAfuera(Bicola tablero, int turno){
	int i;
	int acumulador = 0;
	for(i = 7; i <= 24; ++i){
		acumulador += contarFichasEnPunto(tablero,turno,i);
	}
	return acumulador;
}

int tieneFichasAfuera(Bicola tablero, int turno){
	return contarFichasAfuera(tablero,turno) > 0;
}

int contarFichasTotales(Bicola tablero, int barra, int turno){
	return contarFichasEnTablero(tablero,turno) + contarFichasEnBarra(barra,turno);
}

int tieneFichasEnJuego(Bicola tablero, int barra, int turno){
	if(contarFichasTotales(tablero,turno,turno) > 0)
		return 1;
	else
		return 0;
}

int esPosibleMoverA(Bicola tablero, int turno, int destino){
	return (contarFichasEnPunto(tablero,cambiarTurno(turno),25 - destino) <= 1 && destino > 0 && destino < 25);
}

Bicola hacerMovimientoLegal(Bicola tablero, int* barra, int turno, int origen, int destino, int tipomovimiento){

	/*La variable tipo movimiento tiene 3 posibles valores, 1 si es un movimiento de punto a punto, 2 si es un movimiento de barra a barra.*/
	if(tipomovimiento == 1 && esPosibleMoverA(tablero,turno,destino)){
		printf("Moviendo ficha del punto %d al punto %d\n",origen,destino);
		if(contarFichasEnPunto(tablero,cambiarTurno(turno),25 - destino) == 0){
			tablero = trasladarFicha(tablero,turno,origen,destino);
		}else if(contarFichasEnPunto(tablero,cambiarTurno(turno),25 - destino) == 1){
			tablero = moveraBarra(tablero,cambiarTurno(turno),25 - destino,barra);
			tablero = trasladarFicha(tablero,turno,origen,destino);
		}
	}else if(tipomovimiento == 2 && esPosibleMoverA(tablero,turno,destino)){
		printf("Moviendo ficha la barra al punto %d\n",destino);
		if(contarFichasEnPunto(tablero,cambiarTurno(turno),25 - destino) == 0){
			tablero = sacarDeBarra(tablero,turno,destino,barra);
			//tablero = insertarFicha(tablero,turno,destino);
		}else if(contarFichasEnPunto(tablero,cambiarTurno(turno),25 - destino) == 1){
			tablero = moveraBarra(tablero,cambiarTurno(turno),25 - destino,barra);
			tablero = sacarDeBarra(tablero,turno,destino,barra);
		}
	}else if(tipomovimiento == 3 && !tieneFichasAfuera(tablero,turno)){
		if(contarFichasEnPunto(tablero,turno,origen) >= 0){
			printf("Sacando ficha del punto %d del tablero\n",origen);
			tablero = quitarFicha(tablero,turno,origen);
		}else{
			printf("No hay fichas en ese punto\n");
		}
	}else{
			printf("Movimiento ilegal\n");
		}
	return tablero;
}

/* Función para leer un dato*/

int leerInt(){
	int t; scanf("%d",&t); return t;
}

void nomTurno(char* cadena, int valorturno){
	if(valorturno == vanRojas(1))
		strcpy(cadena,"rojo");
	else
		strcpy(cadena,"blanco");
}

void iniciar(){
  Bicola tablero; /* Bicola donde se almacenarón los 24 puntos del tablero.*/
	srand(time(NULL));
	int i;
	int dado1 = tirarDado(); /* Inicialmente el dado del jugador rojo*/
	int dado2 = tirarDado(); /* Inicialmente el dado del jugador blanco*/
	int segundodado = 0; /* Variable que almacena el valor del segundo dado que va a usar el jugador*/
	int turnoactual = primeroEnMover(dado1,dado2); /* Variable donde se manejar�n los turnos a lo largo del juego*/
	int barra = 0; /* Bicola donde se almacenar�n las fichas movidas a la barra.*/
	int origenmovimiento = 0;
	int destinomovimiento = 0;
	int tipomovimiento = 0;
	char nomtur[50];
	tablero = insertarFichasIniciales();

	while(tieneFichasEnJuego(tablero,barra,0) && tieneFichasEnJuego(tablero,barra,1))	{
		nomTurno(nomtur,turnoactual);
		printf("%sEs el turno del jugador %s.\n",(strcmp(nomtur,"rojo")==0)?(KRED):(KWHT),nomtur);
		printf("%s",KNRM);
		imprimirTablero(tablero,turnoactual,barra);
		if(!tieneFichasEnBarra(barra,turnoactual) && tieneFichasAfuera(tablero,turnoactual))		{
			printf("%sJugador %s, tus dados son %d y %d. Inserta el punto del que quieres mover.\n",(strcmp(nomtur,"rojo")==0)?(KRED):(KWHT),nomtur,dado1,dado2);
			printf("%s",KNRM);
			origenmovimiento = leerInt();
			if(contarFichasEnPunto(tablero,turnoactual,origenmovimiento) > 0){
				printf("Los puntos a los que alcanza tu ficha con tus dados son %d y %d. Inserta uno de estos dos numeros para moverte, asegurandote que tu movimiento sea legal.\n",origenmovimiento + dado1, origenmovimiento + dado2);
				destinomovimiento = leerInt();
				if(destinomovimiento == origenmovimiento + dado1 || destinomovimiento == origenmovimiento + dado2){
					if(destinomovimiento == origenmovimiento + dado1)					{
						segundodado = dado2;
						tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,1);
					}else if(destinomovimiento == origenmovimiento + dado2){
						segundodado = dado1;
						tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,1);
					}
					imprimirTablero(tablero,turnoactual,barra);
					printf("Ahora inserta el punto desde el cual quieres moverte utilizando el segundo dado, el cual tiene un valor de %d.\n",segundodado);
					origenmovimiento = leerInt();
					if(contarFichasEnPunto(tablero,turnoactual,origenmovimiento) > 0){
						destinomovimiento = origenmovimiento + segundodado;
						if(esPosibleMoverA(tablero,turnoactual,destinomovimiento)){
							printf("Presiona enter para mover la ficha del punto %d al punto %d.\n",origenmovimiento,destinomovimiento);
							getchar();getchar();
							tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,1);
						}else{
							printf("Ese punto no tiene movimientos posibles.\n");
						}
					}else{
						printf("No tienes fichas en ese punto.\n");
					}
				}
			}else{
				printf("No tienes fichas en ese punto.\n");
			}
		}else if(tieneFichasEnBarra(barra,turnoactual)){
			printf("Jugador %s, tus dados son %d y %d. Tienes fichas en la barra. Inserta el valor de uno de estos dados para trasladar una de ellas al respectivo punto en el tablero.\n",nomtur,dado1,dado2);
			destinomovimiento = leerInt();
			if(destinomovimiento == dado1){
				segundodado = dado2;
				tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,2);
			}else if(destinomovimiento == dado2){
				segundodado = dado1;
				tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,2);
			}
			if(tieneFichasEnBarra(barra,turnoactual)){
				destinomovimiento = segundodado;
				if(esPosibleMoverA(tablero,turnoactual,destinomovimiento)){
					printf("Ahora presiona enter para mover otra ficha de la barra al punto %d.\n",destinomovimiento);
					getchar();getchar();
					tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,2);
				}else{
					printf("Ya no te quedan movimientos posibles.\n");
				}
			}else{
					printf("Ya no tienes fichas en la barra. Ahora inserta el punto desde el cual quieres moverte utilizando el segundo dado, el cual tiene un valor de %d.\n",segundodado);
					origenmovimiento = leerInt();
					if(contarFichasEnPunto(tablero,turnoactual,origenmovimiento) > 0){
						destinomovimiento = origenmovimiento + segundodado;
						if(esPosibleMoverA(tablero,turnoactual,destinomovimiento)){
							printf("Presiona enter para mover la ficha del punto %d al punto %d.\n",origenmovimiento,destinomovimiento);
							getchar();getchar();
							tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,1);
						}else{
							printf("Ese punto no tiene movimientos posibles.\n");getchar();
						}
					}else{
						printf("No tienes fichas en ese punto.\n");
					}
			}
		}else if(!tieneFichasAfuera(tablero,turnoactual)){
			printf("¡Es tu momento para empezar a sacar fichas del tablero! Tus dados son %d y %d, inserta el valor de uno de ellos para intentar sacar una ficha de ahi.\n",dado1,dado2);
			origenmovimiento = leerInt();
			if(origenmovimiento == dado1){
				segundodado = dado2;
				tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,3);
			}else if(origenmovimiento == dado2){
				segundodado = dado1;
				tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,3);
			}
			origenmovimiento = segundodado;
			if(contarFichasEnPunto(tablero,turnoactual,origenmovimiento) != 0){
				printf("Ahora presiona enter para sacar una ficha del punto %d\n",origenmovimiento);
				getchar();getchar();
				tablero = hacerMovimientoLegal(tablero,&barra,turnoactual,origenmovimiento,destinomovimiento,3);
			}else{
				printf("Ya no tienes movimientos posibles con esos dados\n");getchar();
			}
		}
		printf("Presiona enter para continuar.\n");
		getchar();
		turnoactual = cambiarTurno(turnoactual);
		dado1 = tirarDado();
		dado2 = tirarDado();
		printf("\x1B[2J");
	}
}
