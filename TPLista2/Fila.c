#include "Fila.h"

void inicFila(Fila* fila){
fila->inicio= inicLista2();
fila->fin= inicLista2();
}

void agregar(Fila* fila, stCliente dato){
    nodo2* nuevo= CrearNodo2(dato);
fila->fin = agregarAlFinal2(fila->fin, nuevo);
if(!fila->inicio){
    fila->inicio= nuevo;
}
fila->fin=nuevo;
}
stCliente verPrimeroFila(Fila* fila){
stCliente c = verPrimero2(fila->inicio);
return c;
}

stcliente extraer(Fila* fila){
stCliente c = verPrimero2(fila->inicio);
fila->inicio= borrarNodo2(fila->inicio);
if()

}

int filaVacia(Fila* fila);
void muestraFila (Fila* fila);
