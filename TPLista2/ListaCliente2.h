#ifndef LISTACLIENTE2_H_INCLUDED
#define LISTACLIENTE2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

typedef struct _nodo2{
stCliente dato;
struct _nodo2* ante;
struct _nodo2* sig;
}nodo2;

nodo2* inicLista2();
nodo2* CrearNodo2(stCliente cliente);
nodo2* AgregarAlPrinc2(nodo2* lista, nodo2* nuevo);
void muestraNodo2(nodo2* nodoCliente);
void muestraLista2(nodo2* lista);
void muestraLista2recu(nodo2* lista);
nodo2* AgregarEnOrdenDNI2(nodo2 *lista, nodo2* nuevo);
nodo2* agregarAlFinal2(nodo2 *lista, nodo2* nuevo);
nodo2* buscarUltimo2(nodo2* lista);
nodo2* twoListatoOne2(nodo2* lista1, nodo2* lista2);
nodo2* invertirLista2(nodo2* lista);
nodo2* borrarLista2(nodo2* lista);
nodo2* borrarNodo2(nodo2* lista,char dni[]);
nodo2* OrdenarListaXDNI2(nodo2* lista);
///nodo2* AgregarListaPorApellido2(nodo2* lista);
stCliente verPrimero2(nodo2* lista);
nodo2* borrarPrimero2(nodo2* lista);
int RecuCapic2(nodo2* lista, nodo2* finlista);
void ElimMitNodo2(nodo2* lista, nodo2* finlista);






#endif // LISTACLIENTE2_H_INCLUDED
