#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "ListaCliente2.h"
typedef struct{
struct nodo2* inicio;
struct nodo2* fin;
}Fila;

void inicFila(Fila* fila);
void agregar(Fila* fila, stCliente dato);
stCliente verPrimeroFila(Fila* fila);
int filaVacia(Fila* fila);
void muestraFila (Fila* fila);


#endif // FILA_H_INCLUDED
