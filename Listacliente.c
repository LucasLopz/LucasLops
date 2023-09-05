#include <stdio.h>
#include <stdlib.h>
#include "Listacliente.h"
#include "cliente.h"
#include "pila.h"

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
nodo* crearNodo1 (int dato)
{
    nodo1* nuevoNodo = (nodo1*) malloc(sizeof(nodo1));
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
    MostrarUnCliente(nodoCliente->dato);
    printf("\n _____ %p", nodoCliente->sig);
}
///-----------------------------------------------------------------------------------------------------------
void muestraLista (nodo* lista)
{
    nodo* aux= lista;
               while(aux){
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
    nodo* aux = lista;
                while(aux){
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
        fclose(Archi);


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
        fclose(Archi);
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
    nodo* Aux= lista;
               if(Archi)
    {
        while(fwrite(&Aux->dato,sizeof(stCliente),1,Archi)== 1)
        {
            Aux= Aux->sig;
        }
        fclose(Archi);
    }
}

void lista2ArchivocFiltro(char nombreArchivo[],nodo* lista,int Elim)
{
    FILE* Archi= fopen(nombreArchivo,"ab");
    nodo* Aux= lista;
               if(Archi)
    {
        if(Aux->dato.eliminado== Elim)
        {
            while(fwrite(&Aux->dato,sizeof(stCliente),1,Archi)== 1)
            {
                Aux= Aux->sig;
            }
        }
        else
        {
            Aux=Aux->sig;
        }
        fclose(Archi);
    }
}


///---------------------------------------------------------------------------------------------------------------------
///2. Hacer un programa que lea de un archivo datos y los inserte en una lista en forma ordenada.

nodo* AgregarNodoArchivoOrd (char NombreArchivo[], nodo* lista, int dni){

nodo* listaAux = lista;
    FILE* Archi= fopen(NombreArchivo, "rb");
    if(Archi)
    {
        stCliente aux;
        while(fread(&aux,sizeof(stCliente),1,Archi)>0){
            AgregarEnOrden (lista, aux);
    }

    fclose(Archi);
    }
return lista;
}

///------------------------------------------------------------------------------------------------
void AgregarEnOrdenDNI(nodo *lista, nodo* nuevo){
    if(!lista){
    lista=nuevo;
    }else{
        if(atoi(nuevo->dato.dni) <= atoi(lista->dato.dni)){
    lista= agregarAlPrincipio(lista, nuevo);
    }else{
        nodo* ante=lista;
        nodo* aux= lista->sig;

        while(aux && atoi(nuevo->dato.dni)> atoi(lista->dato.dni)){
            ante=aux;
            aux= aux->sig;
        }
        nuevo->sig=aux;
        ante->sig=nuevo;
    }
}
///------------------------------------------------------------------------------------------------
nodo* agregarAlFinal(nodo *lista, nodo* nuevo){
    if(!lista){
        lista=nuevo;
    }else{
    nodo*ultimo= buscarUltimo(lista);
    ultimo->sig = nuevo;
    }

    return nuevo;
}

nodo* buscarUltimo(nodo* lista){
nodo* aux = lista;
    while(aux->sig){
        aux= aux->sig;
    }
}
///---------------------------------------------------------------------------------------------
///Hacer una función que retorne un 1 (uno) o 0 (cero) si existe un determinado elemento en una lista dada.
int EncontrarElemLista(nodo* lista,int id){
    int flag=0;
    while(lista){
        if(lista->dato.id == id){
            flag=1;
        }
        lista=lista->sig;
    }


return flag;
}
///----------------------------------------------------------------------------------------------------------
///Hacer una función que intercale en orden los elementos de
///dos listas ordenadas generando una nueva lista. Se deben redireccionar los punteros,
nodo* twoListatoOne(nodo* lista1, nodo* lista2){
    nodo* Aux= NULL;
while(lista1 && lista2){
    if(lista1<lista2){
 Aux= agregarAlFinal(Aux,lista1);
        lista1= lista1->sig;
        }else{
        if(lista1>lista2){
 Aux= aagregarAlFinal(Aux,lista2);
        lista2= lista1->sig;
        }
}
}
if(lista1){
    while(lista1){
        Aux= agregarAlFinal(Aux,lista1);
        lista1=lista1->sig;
    }
    if(lista2){
    while(lista2){
        Aux= agregarAlFinal(Aux,lista2);
        lista2=lista2->sig;
    }
}
}
return Aux;
}

///-------------------------------------------------------------------------------------
///Invertir los elementos de una lista redireccionando solamente los punteros.
nodo* invertirLista(nodo* lista){
    nodo* Aux= NULL;
    nodo* listaInv=NULL;
while(lista){
    Aux= lista;
    lista=lista->sig;
    aux->sig=NULL;
    listaInv= agregarAlPrincipio(listaInv, aux);
}
return listaInv;
}


///-----------------------------------------------------------------------------------------------
/// Codificar el TDA Pila con las funciones necesarias, implementada con una lista enlazada
/// BIEN HECHO EN LIBRERIA PILA.C
void enlistar (nodo1* lista,int dato){
lista= agregarAlPrincipio(lista,crearNodo1(dato));
}

int desEnlistar (nodo1* lista){
int i=0;
i= lista->dato;
lista= lista->sig;
return i;
}

int TopeLista (nodo1* lista){
return lista->dato;
}

int listaVacia (nodo1* lista){
    int flag=0;
    if(lista){
            flag=1;
    }
return flag;
}

void mostrarLista (nodo1* lista){
while(lista){
    muestraLista(lista);
    lista= lista->sig;
}
}

///--------------------------------------------------------------------------------------------------------------------
///Luego, recorrer dicha pila e insertar por orden de llegada (al final) en una lista simplemente enlazada
///aquellos números que sean pares. Cuidado, la función no debe perder la pila original,
///trabaje de forma tal que se conserven sus datos.

nodo* PasajePilaToList(nodo* lista,int p){

}







///--------------------------------------------------------------------------------------------------------------
nodo* borrarLista(nodo* lista){
nodo* proximo = NULL;
nodo* Aux= lista;

while(Aux){
    proximo= Aux->sig;
    free(Aux);
    Aux=proximo;
}
return Aux;
}


nodo* borrarNodo(nodo* lista,char dni[]){
if(lista && strcmp(lista->dato.dni, dni)==0){
    nodo* aux=lista;
    lista= lista->sig;
    free(aux);
}else{
nodo* aux=lista->sig;
nodo* ante= lista;

while(aux && strcmp(aux->dato.dni, dni)!= 0){
    ante=aux;
    aux=aux->sig;
}
if(aux){
ante->sig=aux->sig;
free(aux);
}
}

return lista;
}
///-------------------------------------------------------------------------------------------------------------------
int lista2arreglo(nodo* lista, stCliente clientes[], int dim){
int i =0;
while(lista&& i<dim){
    clientes[i]= lista->dato;
    i++;
    lista=lista->sig;
}
return i;
}

nodo* Array2List (stCliente clientes[], int v, nodo*lista,char dni []){
for(int i=0; i<v;i++){
    if(atoi(clientes[i].dni)> atoi(dni));
        lista= agregarAlFinal(lista, crearNodo(clientes[i]));
}
return lista;
}

nodo* buscarNodoPorDNI(nodo* lista, char dni[]){
nodo* aux = lista;
while(aux && strcmp(aux->dato.dni, dni)!=0){
    aux = aux->sig;
}
return aux;
}
///----------------------------------------------------------------------------------
/// Ordenar Lista

nodo* OrdenarListaXDNI(nodo* lista){
    nodo*Aux = NULL;
    nodo* Nuevlista=NULL;
while(Aux){
        aux=lista;
    lista=lista->sig;
    aux->sig=NULL;
    Nuevlista= AgregarEnOrdenDNI(Nuevlista,Aux);
}
return Nuevlista;
}

nodo* AgregarListaPorApellido(nodo* lista){
nodo* listaOrd=NULL;
nodo* Aux=NULL;
while(lista){
    aux=lista;
    lista=lista->sig;
    aux->sig=NULL;

    listaOrd=AgregarPorApellidos(listaOrd,aux);
}
}


