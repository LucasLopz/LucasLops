#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED
#include "cliente.h"

typedef struct{
stCliente dato;
    struct nodo* sig;
}nodo;

typedef struct{
     int dato;
    struct nodo1* sig;
}nodo1;

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
nodo* AgregarNodoArchivo (char NombreArchivo[], nodo* lista);
nodo* AgregarNodoArchivoconF (char NombreArchivo[], nodo* lista, int Elim);
nodo * cargarListaDesdeArchivo(FILE * archi, nodo* lista);
void lista2Archivo(char nombreArchivo[],nodo* lista);
void lista2ArchivocFiltro(char nombreArchivo[],nodo* lista,int Elim);
nodo* AgregarNodoArchivoOrd (char NombreArchivo[], nodo* lista, int dni);
void AgregarEnOrdenDNI(nodo *lista, nodo* nuevo);
nodo* agregarAlFinal(nodo *lista, nodo* nuevo);
int EncontrarElemLista(nodo* lista,int id);
nodo* twoListatoOne(nodo* lista1, nodo* lista2);
nodo* invertirLista(nodo* lista);
void enlistar (nodo1* lista,int dato);
int desEnlistar (nodo1* lista);
int TopeLista (nodo1* lista);
int listaVacia (nodo1* lista);
void mostrarLista (nodo1* lista);
nodo* borrarLista(nodo* lista);
nodo* borrarNodo(nodo* lista,char dni[]);
int lista2arreglo(nodo* lista, stCliente clientes[], int dim);
nodo* Array2List (stCliente clientes[], int v, nodo*lista,char dni []);
nodo* buscarNodoPorDNI(nodo* lista, char dni[]);




#endif // LISTACLIENTE_H_INCLUDED
