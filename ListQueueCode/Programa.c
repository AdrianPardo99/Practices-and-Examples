/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TDALista.h"
/*Creación de la semilla para trabajar con valores dinamicos de random
Creación de una estructura de tipo Lista con elementos de tipo Cola
Instancia del TDALista.h que permite trabajar con todas las funciones y demas 
TDA previamente ya programados*/
int main(){
	srand(time(NULL));
	Lista l=cons(formar(formar(formar(formar(formar(nueva(),ret(1)),ret(1)),ret(1)),ret(1)),ret(1)),
		cons(formar(formar(formar(formar(formar(nueva(),ret(2)),ret(2)),ret(2)),ret(2)),ret(2)),
		cons(formar(formar(formar(formar(formar(nueva(),ret(3)),ret(3)),ret(3)),ret(3)),ret(3)),
		cons(formar(formar(formar(formar(formar(nueva(),ret(4)),ret(4)),ret(4)),ret(4)),ret(4)),vacia()))));
	impLista(l,1);
	
}
