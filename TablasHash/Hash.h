/*Creado por Adrian González Pardo
Fecha de modificación: 29/05/2018
Correo electronico:gozapaadr@gmail.com
Licencia Creative Commons CC BY-SA*/
#include "Lista.h"
/*Modificación de la estructura de datos lista para crear una Tabla Hash*/
typedef Lista *TablaH;
TablaH creaDic(int tam){
  TablaH t;
  t=(TablaH)malloc(sizeof(Lista)*tam);
  return t;
}
