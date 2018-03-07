#include <stdio.h>
#include <stdlib.h>
#include "TDAQueue.h"
int main(){
	Cola q=formar(formar(formar(formar(nueva(),"a"),"b"),"c"),"d");
	impElem(primero(q));
	q=desformar(q);
	impElem(primero(q));
	impElem(primero(desformar(q)));
}
