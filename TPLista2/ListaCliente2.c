#include "ListaCliente2.h"
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

nodo2* inicLista2()
{
    return NULL;
}

nodo2* CrearNodo2(stCliente cliente)
{
    nodo2* NuevoNodo= (nodo2*) malloc(sizeof(nodo2));
    NuevoNodo->dato = cliente;
    NuevoNodo->ante= NULL;
    NuevoNodo->sig= NULL;
}

nodo2* AgregarAlPrinc2(nodo2* lista, nodo2* nuevo)
{
    nuevo->sig= lista;
    if(lista)
    {
        lista->ante=nuevo;
    }
    return nuevo;
}

void muestraNodo2(nodo2* nodoCliente)
{
    printf("\n _____ %p", nodoCliente);
    printf("\n _____ %p", nodoCliente->ante);
    MostrarUnCliente(nodoCliente->dato);
    printf("\n _____ %p", nodoCliente->sig);
}

void muestraLista2(nodo2* lista)
{
    nodo2* aux= lista;
    while(aux)
    {
        muestraNodo2(aux);
        aux= aux->sig;
    }
}

void muestraLista2recu(nodo2* lista)
{
    if(lista)
    {
        muestraNodo2(lista);
        muestraLista2recu(lista->sig);
    }
}

nodo2* AgregarEnOrdenDNI2(nodo2 *lista, nodo2* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.dni) <= atoi(lista->dato.dni))
        {
            lista= AgregarAlPrinc2(lista, nuevo);
        }
        else
        {
            nodo2* ante=lista;
            nodo2* aux= lista->sig;
            while(aux && atoi(nuevo->dato.dni)> atoi(aux->dato.dni))
            {
                ante=aux;
                aux= aux->sig;
            }
            nuevo->ante= ante;
            nuevo->sig=aux;
            ante->sig=nuevo;
            if(aux){
                aux->ante=nuevo;
            }
        }
        return lista;
    }
}

nodo2* agregarAlFinal2(nodo2 *lista, nodo2* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        nodo2*ultimo= buscarUltimo2(lista);
        ultimo->sig = nuevo;
        nuevo->ante= ultimo;
    }

    return nuevo;
}

nodo2* buscarUltimo2(nodo2* lista)
{
    nodo2* aux = lista;
    while(aux->sig)
    {
        aux= aux->sig;
    }
    return aux;
}
///---------------------------------------------------------------------------------------------------------------------------
nodo2* twoListatoOne2(nodo2* lista1, nodo2* lista2)
{
    nodo2* Aux= NULL;
    nodo2* listaNuev=NULL;
    while(lista1 && lista2)
    {
        if(lista1->dato.dni < lista2->dato.dni )
        {
            Aux= lista1;
            lista1= lista1->sig;
            lista1->ante=NULL;
            Aux->sig=NULL;
            Aux->ante=NULL;
            listaNuev= agregarAlFinal2(listaNuev,Aux);

        }
        else
        {
            if(lista1->dato.dni > lista2->dato.dni)
            {
                Aux= lista2;
                lista2= lista2->sig;
                lista2->ante=NULL;
                Aux->sig=NULL;
                Aux->ante=NULL;
                listaNuev= agregarAlFinal2(listaNuev,Aux);
            }
        }
    }
    if(lista1)
    {
        listaNuev= agregarAlFinal2(listaNuev,lista1);
    }
    if(lista2)
    {
        listaNuev= agregarAlFinal2(listaNuev,lista2);
    }
    return Aux;
}

nodo2* invertirLista2(nodo2* lista)
{
    nodo2* Aux= NULL;
    nodo2* listaInv=NULL;
    while(lista)
    {
        Aux= lista;
        lista=lista->sig;
        lista->ante=NULL;
        Aux->sig=NULL;
        Aux->ante=NULL;
        listaInv= AgregarAlPrinc2(listaInv, Aux);
    }
    return listaInv;
}

///------------------------------------------------------------------------------------------------------------------------------------------------------
nodo2* borrarLista2(nodo2* lista)
{
    nodo2* proximo = NULL;
    nodo2* Aux= lista;

    while(Aux)
    {
        proximo= Aux->sig;
        free(Aux);
        Aux=proximo;
    }
    return Aux;
}


nodo2* borrarNodo2(nodo2* lista,char dni[])
{
    if(lista && strcmp(lista->dato.dni, dni)==0)
    {
        nodo2* aux=lista;
        lista= lista->sig;
        lista->ante=NULL;
        free(aux);
    }
    else
    {
        nodo2* aux=lista->sig;
        nodo2* ante= lista;

        while(aux && strcmp(aux->dato.dni, dni)!= 0)
        {
            ante=aux;
            aux=aux->sig;
        }
        if(aux)
        {
            ante->sig=aux->sig;
            free(aux);
            if(ante->sig)
            {
                aux=ante->sig;
                aux->ante=ante;
            }
        }
    }
    return lista;
}
///------------------------------------------------------------------------------------------------------------------------------
nodo2* OrdenarListaXDNI2(nodo2* lista)
{
    nodo2*Aux = NULL;
    nodo2* Nuevlista = NULL;
    while(Aux)
    {
        Aux=lista;
        lista=lista->sig;
        lista->ante= NULL;
        Aux->sig=NULL;
        Aux->ante=NULL;
        Nuevlista = AgregarEnOrdenDNI2(Nuevlista, Aux);
    }
    return Nuevlista;
}

/*nodo2* AgregarListaPorApellido2(nodo2* lista)
{
    nodo2* listaOrd=NULL;
    nodo2* Aux=NULL;
    while(lista)
    {
        Aux=lista;
        lista=lista->sig;
        lista->ante=NULL;
        Aux->sig=NULL;
        Aux->ante=NULL;

        listaOrd=AgregarPorApellidos2(listaOrd,Aux);
    }
}*/

///------------------------------------------------------------------------------------------------------------------------
stCliente verPrimero2(nodo2* lista)
{
    return lista->dato;
}

nodo2* borrarPrimero2(nodo2* lista)
{
    nodo2* Aux=NULL;
    Aux= lista;
    lista= lista->sig;
    lista->ante=NULL;
    Aux->sig=NULL;
    Aux->ante=NULL;
    return lista;
}
///------------------------------------------------------------------------------------------------------------------------------------
///Crear una función recursiva que determine si una lista doblemente vinculada es capicúa.
///(Después de ver recursividad - si no, hacer iterativo, NO usar contador)


int RecuCapic2(nodo2* lista, nodo2* finlista)
{
    int flag=1;
    if(lista && lista != finlista)  // lista->ante == finlista->sig
    {
        if(lista->dato.dni != finlista->dato.dni)
        {
            flag=0;

        }
        else
        {
            flag=RecuCapic2(lista->sig, finlista->ante);

        }
    }
    return flag;
}

///-----------------------------------------------------------------------------------------------------------------------------------------
///Dada una lista doblemente enlazada ordenada de enteros, eliminar el  nodo que se encuentra en el punto medio de la lista,
///si la cantidad de nodos es par, eliminar el inmediatamente superior.

void ElimMitNodo2(nodo2* lista, nodo2* finlista)
{
    if(lista)
    {
        nodo2* aux=lista;
        nodo2* auxfin=finlista;

        while(aux->dato.id < auxfin->dato.id)
        {
            aux=aux->sig;
            auxfin=auxfin->ante;
        }

        if(aux->dato.id == auxfin->dato.id)
        {
            aux=aux->ante;
            aux->sig=auxfin->sig;
            auxfin->ante=NULL;
            auxfin->sig=NULL;
            free(auxfin);
            auxfin=aux->sig;
            auxfin->ante=aux;
        }
        if(aux->dato.id > auxfin->dato.id)
        {
            aux=aux->ante;
            auxfin=auxfin->sig;
            aux->sig=auxfin->sig;
            auxfin->ante= NULL;
            auxfin->sig=NULL;
            free(auxfin);
            auxfin=aux->sig;
            aux->ante=aux;
        }
    }
}
