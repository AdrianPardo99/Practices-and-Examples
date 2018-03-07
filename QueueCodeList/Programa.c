#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
int main(){
	Cola c=formar(formar(formar(nueva(),"a"),"b"),"c");
	impLista(c);
	c=desformar(c);
	impLista(desformar(c));
}
