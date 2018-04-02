/*Creado por Adrian González Pardo
Fecha de modificación: 26/03/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DirBin.h"

int main(int argc,char *argv[]){
	char pal[80],*w;
	DirBin words;
	FILE *in=fopen(*(argv+1),"r"),
	*out=fopen(*(argv+2),"w");
	while (fscanf(in,"%s",pal)!=EOF) {
		w=(char*)malloc(sizeof(char)*80);
		strcpy(w,pal);
		words=InsOrdA(w,words);
	}
	ImpInOrd(words);
	impInOrdArch(words,out);
	/*Hacer programa con 2 archivos de texto donde con 1 archivo leer los datos y en el otro archivo escribir los datos
		Arboles ABL ->Por altura
		Arboles Heap -> Por peso
	*/
}
