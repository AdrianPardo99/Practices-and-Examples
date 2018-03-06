#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lista.h"

int main(int argc,char *argv[]){
	char pal[80],*w;
	Lista words=vacia();
	FILE *in=fopen(*(argv+1),"r"),
	*out=fopen(*(argv+2),"w");
	while(fscanf(in,"%s ",pal)!=EOF){
		w=(char*)malloc(sizeof(char)*80);
		strcpy(w,pal);
		words=InsOrd(w,words);
		//words=cons(w,words);
	}
	impLista(OrdList(words));
	impListaArch(OrdList(words),out);
	fclose(in);
	fclose(out);
	return 0;
}
