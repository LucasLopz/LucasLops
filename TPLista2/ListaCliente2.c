#include "ListaCliente2.h"
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"

nodo2* inicLista2(){
return NULL;
}

nodo2* CrearNodo2(stCliente cliente){
    nodo2* NuevoNodo= (nodo2*) malloc(sizeof(nodo2));
    NuevoNodo->dato = cliente;
    NuevoNodo->ante= NULL;
    NuevoNodo->sig= NULL;
}

nodo2* AgregarAlPrinc2(nodo2* lista, nodo2* nuevo){
nuevo->sig= lista;
if(lista){
lista->ante=nuevo;}
return nuevo;
}

void muestraNodo2(nodo2* nodoCliente)
{
    printf("\n _____ %p", nodoCliente);
    printf("\n _____ %p", nodoCliente->ante);
    MostrarUnCliente(nodoCliente->dato);
    printf("\n _____ %p", nodoCliente->sig);
}

void muestraLista (nodo2* lista)
{
    nodo2* aux= lista;
    while(aux)
    {
        muestraNodo(aux);
        aux= aux->sig;
    }
}

nodo2* AgregarEnOrdenDNI(nodo2 *lista, nodo2* nuevo)
{
    if(!lista)
    {
        lista=nuevo;
    }
    else
    {
        if(atoi(nuevo->dato.dni) <= atoi(lista->dato.dni))
        {
            lista= agregarAlPrincipio(lista, nuevo);
        }
        else
        {
            nodo2* ante=lista;
            nodo2* aux= lista->sig;
            while(aux && atoi(nuevo->dato.dni)> atoi(lista->dato.dni))
            {
                ante=aux;
                aux= aux->sig;
            }
            nuevo->ante= ante;
            aux->ante=nuevo;
            nuevo->sig=aux;
            ante->sig=nuevo;
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
            nodo2*ultimo= buscarUltimo(lista);
            ultimo->sig = nuevo;
            nuevo->ante= ultimo;
        }

        return nuevo;
    }

    nodo2* buscarUltimo(nodo2* lista)
    {
        nodo2* aux = lista;
        while(aux->sig)
        {
            aux= aux->sig;
        }
        return aux;
    }
///---------------------------------------------------------------------------------------------------------------------------
     nodo2* twoListatoOne(nodo2* lista1, nodo2* lista2)
    {
        nodo2* Aux= NULL;
        nodo2* ListaNuev=NULL;
        while(lista1 && lista2)
        {
            if(lista1->dato < lista2->dato )
            {
                Aux= lista1;
                lista1= lista1->sig;
                lista1->ante=NULL;
                Aux->sig=NULL;
                Aux->ante=NULL;
                ListaNuev= agregarAlFinal(listanuev,Aux);

            }
            else
            {
                if(lista1>lista2)
                {
                    Aux= lista2;
                    lista2= lista2->sig;
                    lista2->ante=NULL;
                    Aux->sig=NULL;
                    Aux->ante=NULL;
                    ListaNuev= agregarAlFinal(listanuev,Aux);
                }
            }
        }
        if(lista1)
        {
            ListaNuev= agregarAlFinal(listanuev,lista1);
        }
        if(lista2)
        {
            ListaNuev= agregarAlFinal(listanuev,lista2);
        }
return Aux;
    }

    nodo2* invertirLista(nodo2* lista)
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
        listaInv= agregarAlPrincipio(listaInv, Aux);
    }
    return listaInv;
}

///------------------------------------------------------------------------------------------------------------------------------------------------------
nodo2* borrarLista(nodo2* lista)
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


nodo2* borrarNodo(nodo2* lista,char dni[])
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
            if(ante->sig){
            aux=ante->sig;
            aux->ante=ante;
            }
        }
    }
    return lista;
}
///------------------------------------------------------------------------------------------------------------------------------
nodo2* OrdenarListaXDNI(nodo2* lista)
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
        Nuevlista = AgregarEnOrdenDNI(Nuevlista, Aux);
    }
    return Nuevlista;
}

nodo2* AgregarListaPorApellido(nodo2* lista)
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

        listaOrd=AgregarPorApellidos(listaOrd,Aux);
    }
}

///------------------------------------------------------------------------------------------------------------------------
stCliente verPrimero(nodo2* lista)
{
    return lista->dato;
}

nodo2* borrarPrimero(nodo2* lista)
{
    nodo2* Aux=NULL;
    Aux= lista;
    lista= lista->sig;
    lista->ante=NULL;
    Aux->sig=NULL;
    Aux->ante=NULL;
    return lista;
}
