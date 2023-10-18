#include "nodoListaMovimiento.h"

nodoListaMovimiento* crearNodoCuentaMov(stMovimiento movimiento){
    nodoListaMovimiento* nuevoNodo = (nodoListaMovimiento*) malloc(sizeof(nodoListaMovimiento));
    nuevoNodo->dato = movimiento;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

nodoListaMovimiento* inicListaMov(){
return NULL;
}
