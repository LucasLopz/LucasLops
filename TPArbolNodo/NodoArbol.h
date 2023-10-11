#ifndef NODOARBOL_H_INCLUDED
#define NODOARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "cliente.h"

typedef struct _NodoArbol{
stCliente dato;
struct NodoArbol* izq;
struct NodoArbol* der;
}NodoArbol;

NodoArbol* inicArbol();
NodoArbol* crearNodoArbol(stCliente dato);
NodoArbol* buscarNodoArbol(NodoArbol* Arbol,char dni[]);
NodoArbol* agregarNodoArbol (NodoArbol* Arbol, stCliente Cliente);
void mostrarPreOrdArb(NodoArbol* Arbol);
void mostrarInOrdArb(NodoArbol* Arbol);
void mostrarPostOrdArb(NodoArbol* Arbol);
int contCantHojas (NodoArbol* Arbol);
int cantNodoGra1 (NodoArbol* Arbol);
nodo* ArbolToLista (NodoArbol* Arbol,nodo* lista);
NodoArbol* buscarNodoArbolID(NodoArbol* Arbol,int id);
NodoArbol* buscarNodoArbolNomb(NodoArbol* Arbol,char nombre[]);
int calcAlturArbol(NodoArbol* Arbol);
int profundidadArbol(NodoArbol * arbol);
int cantNodoArbol (NodoArbol* Arbol);
NodoArbol* BorrarNodoArbol(NodoArbol* Arbol, int id);
NodoArbol* NMD(NodoArbol* Arbol);
NodoArbol* NMI(NodoArbol* Arbol);
int ArboltoArray(NodoArbol* Arbol,stCliente Cliente[],int dim);
NodoArbol* ArrayToArbol (NodoArbol* Arbol,stCliente Cliente[], int v);



#endif // NODOARBOL_H_INCLUDED
