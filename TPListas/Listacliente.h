#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED
#include "cliente.h"

typedef struct{
stCliente dato;
    struct nodo * sig;
}
nodo* inicLista();
nodo* crearNodo (stCliente dato);
nodo* agregarAlPrincipio(nodo *lista, nodo* nuevo);
void muestraNodo(nodo* nodoCliente);
void muestraLista (nodo* lista);
int cuentaNodos (nodo* lista);
void muestraListaRec(nodo * lista);
int cuentaNodos (nodo* lista);
int cuentaNodosRecu (nodo* lista);
int cuentaNodosRecucFiltro();

#endif // LISTACLIENTE_H_INCLUDED
