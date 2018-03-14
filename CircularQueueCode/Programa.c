/*Creado por Adrian González Pardo
Fecha de modificación: 10/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"
int main(){
	Circular q=formar(formar(formar(formar(nueva(),1),2),3),4);
	/*Ciclo que permite ver la implementación de una cola circular*/
	while(1){
		impCola(rotar(q));
		getchar();
	}
}
