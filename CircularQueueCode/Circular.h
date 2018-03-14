/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "TDAQueue.h"
/*Agrego funciones de la estructura Cola para realizar una Cola Circular*/
typedef Cola Circular;
Circular rotar(Circular q){
	if(esNueva(q)){
		return q;
	}else{
		return formar(desformar(q),primero(q));
	}
}
