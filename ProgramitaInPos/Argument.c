#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
int main(int argc,char *argv[]){
	int i=0,ban=0;
	char *pal;
	pal=*(argv+1);
	balance(pal);
	convert(pal);
	return 0;
}

