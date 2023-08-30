#include <stdio.h>
#include <stdlib.h>
#include "Listacliente.h"
#include "cliente.h"

nodo* inicLista()
{
    return NULL;
}
///----------------------------------------------------------------------------------------------
nodo* crearNodo (stCliente dato)
{
    nodo* nuevoNodo = (nodo*) malloc(sizeof(nodo));
    nuevoNodo->dato= dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}
///------------------------------------------------------------------------------------------------
nodo* agregarAlPrincipio(nodo *lista, nodo* nuevo)
{
    nuevo->sig=lista;
    return nuevo;
}
///------------------------------------------------------------------------------------------------
void muestraNodo(nodo* nodoCliente)
{
    printf("\n _____ %p", nodoCliente);
    MostrarUnCliente(modoCliente->dato);
    printf("\n _____ %p", nodoCliente->sig);
}
///-----------------------------------------------------------------------------------------------------------
void muestraLista (nodo* lista)
{
    nodo* aux= lista
               while(aux)    /// while(aux!= NULL)
    {
        muestraNodo(aux);
        aux= aux->sig;
    }
}
///-------------------------------------------------------------------------------------------------------
void muestraListaRec(nodo * lista)
{
    if (lista)
    {
        muestraNodo(lista);
        muestraListaRec(lista->sig);
    }
}
///---------------------------------------------------------------------------------------------------------
int cuentaNodos (nodo* lista)
{
    int cont=0;
    nodo* aux = lista
                while(aux)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}
///---------------------------------------------------------------------------------------------------------------
int cuentaNodosRecu (nodo* lista)
{
    int cont=0;
    if(lista)
    {
        cont = 1+ cuentaNodosRecu(lista->sig);
    }
}
///-----------------------------------------------------------------------------------------------------------------------
int cuentaNodosRecucFiltro(nodo* lista)
{
    int cont=0;
    if(lista)
    {
        if(lista->dato.id > 10)
        {
            cont = 1+ cuentaNodosRecucFiltro(lista->sig);
        }
        else
        {
            cont= cuentaNodosRecucFiltro(lista->sig);
        }
    }
    return cont;
}

///---------------------------------------------------------------------------------------------------------------------
///1.Hacer un programa que lea de un archivo datos y los inserte en una lista.

nodo* AgregarNodoArchivo (char NombreArchivo[], nodo* lista)
{
    FILE* Archi= fopen(NombreArchivo, "rb");
    if(Archi)
    {
        stCliente aux;
        while(fread(&aux,sizeof(stCliente),1,Archi)>0)
        {
            lista = agregarAlPrincipio(lista,crearNodo(aux));
        }
        fclose();


    }
    return lista;
}

nodo* AgregarNodoArchivoconF (char NombreArchivo[], nodo* lista, int Elim)
{
    FILE* Archi= fopen(NombreArchivo, "rb");
    if(Archi)
    {
        stCliente aux;
        while(fread(&aux,sizeof(stCliente),1,Archi)>0)
        {
            if(aux.eliminado == Elim)
            {
                lista = agregarAlPrincipio(lista,crearNodo(aux));
            }
        }
        fclose();
    }
    return lista;
}


nodo * cargarListaDesdeArchivo(FILE * archi, nodo* lista)
{
    stCliente aux;
    if(fread(&aux,sizeof(stCliente),1,archi)>0)
    {
        //fseek(archi,sizeof(stCliente)*(-1),SEEK_CUR);
        //fread(&aux,sizeof(stCliente),1,archi);
        lista  = agregarAlPrincipio(lista,crearNodo(aux));
        cargarListaDesdeArchivo(archi, lista);
    }
    return lista;
}
///------------------------------------------------------------------------------------------------------------------------
void lista2Archivo(char nombreArchivo[],nodo* lista)
{
    FILE* Archi= fopen(nombreArchivo,"ab");
    nodo* Aux= lista
               if(Archi)
    {
        while(fwrite(&Aux.dato,sizeof(stCliente),1,Archi)== 1)
        {
            Aux= Aux.sig;
        }
        fclose(Archi);
    }
}

void lista2ArchivocFiltro(char nombreArchivo[],nodo* lista,int Elim)
{
    FILE* Archi= fopen(nombreArchivo,"ab");
    nodo* Aux= lista
               if(Archi)
    {
        if(Aux.dato.eliminado== Elim)
        {
            while(fwrite(&Aux.dato,sizeof(stCliente),1,Archi)== 1)
            {
                Aux= Aux.sig;
            }
        }
        else
        {
            Aux=Aux.sig
        }
        fclose(Archi);
    }
}


///---------------------------------------------------------------------------------------------------------------------
///2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

nodo* AgregarNodoArchivoconF (char NombreArchivo[], nodo* lista, int dni)
{
    FILE* Archi= fopen(NombreArchivo, "rb");
    if(Archi)
    {
        stCliente aux;
        while(fread(&aux,sizeof(stCliente),1,Archi)>0)
        {
            while(lista->dato.dni < dni)
            {
                lista= lista->sig;
            }
            agregarAlMedio(lista, aux);
        }
    }
    fclose();
}
return lista;
}

///------------------------------------------------------------------------------------------------
void agregarAlMedio(nodo *lista, nodo* nuevo)
{
    nuevo->sig=lista->sig;
    lista->sig = nuevo

                 return nuevo;
}
///------------------------------------------------------------------------------------------------
void agregarAlFinal(nodo *lista, nodo* nuevo)
{
    while(lista->sig!= NULL)
    {
        lista= lista->sig;
    }
    lista->sig = nuevo;

    return nuevo;
}
