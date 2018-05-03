/*Creado por Adrian González Pardo
Fecha de modificación: 23/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DirBin.h"
int ra(){return 30+rand()%20;}
int main(){
	srand(time(NULL));
	int i;
	DirBin ab=vacio(),v=vacio();
	for(i=0;i!=7;i++){
		ab=hazCompleto(ra(),ab);
	}
	ab=consHeap(ab);
	AlturaAB(ab);
	puts("\n");
	impArbol(ab,0);
	puts("\n");
	impArbol2(ab);
	/*Hacer programa con 2 archivos de texto donde con 1 archivo leer los datos y en el otro archivo escribir los datos
		Arboles ABL ->Por altura
		Arboles Heap -> Por peso
	*/
}
