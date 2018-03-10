/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "TDAQueue.h"
/*Dar un alias a la estructura de datos de tipo Cola como Elem*/
typedef Cola Elem;
/*Al hacer uso de la función random en el lenguaje esta función permite
trabajar con diversos intervalos de la funcion random y que sera trabajada en 4
Listas con 5 elementos en la cola*/
int ret(int j){
	switch(j){
		case 1:
			return rand()%(99);
		break;
		case 2:
			return 100+rand()%(199-100);
		break;
		case 3:
			return 200+rand()%(299-200);
		break;
		case 4:
			return 360+rand()%(399-360);
		break;
	}
}
