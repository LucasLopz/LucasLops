#include "NodoArbol.h"

NodoArbol* inicArbol()
{
    return NULL;
}

NodoArbol* crearNodoArbol(stCliente dato)
{

    NodoArbol* Aux = (NodoArbol*) malloc(sizeof(NodoArbol));
    Aux->dato = dato;
    Aux->izq=NULL;
    Aux->der=NULL;
    return Aux;
}

NodoArbol* buscarNodoArbol(NodoArbol* Arbol,char dni[])
{
    NodoArbol* rta=NULL;
    if(Arbol)
    {
        if(atoi(dni) == atoi(Arbol->dato.dni))
        {
            rta= Arbol;
        }
        if(atoi(dni) > atoi(Arbol->dato.dni))
        {
            rta = buscarNodoArbol(Arbol->izq, dni);
        }
        else
        {
            rta = buscarNodoArbol(Arbol->der, dni);
        }
    }
    return rta;
}

NodoArbol* agregarNodoArbol (NodoArbol* Arbol, stCliente Cliente)
{
    if(Arbol== NULL)
    {
        Arbol= crearNodoArbol(Cliente);
    }
    else
    {
        if(atoi(Arbol->dato.dni) > atoi(Cliente.dni))
        {
            Arbol->der = agregarNodoArbol(Arbol->der, Cliente);
        }
        else
        {
            if(atoi(Arbol->dato.dni) < atoi(Cliente.dni))
            {
                Arbol->izq= agregarNodoArbol(Arbol->izq, Cliente);
            }
        }
    }
    return Arbol;
}

void mostrarPreOrdArb(NodoArbol* Arbol)
{
    if(Arbol)
    {
        MostrarUnCliente(Arbol->dato);
        mostrarPreOrdArb(Arbol->izq);
        mostrarPreOrdArb(Arbol->der);
    }
}

void mostrarInOrdArb(NodoArbol* Arbol)
{
    if(Arbol)
    {
        mostrarInOrdArb(Arbol->izq);
        MostrarUnCliente(Arbol->dato);
        mostrarInOrdArb(Arbol->der);
    }
}


void mostrarPostOrdArb(NodoArbol* Arbol)
{
    if(Arbol)
    {
        mostrarPostOrdArb(Arbol->izq);
        mostrarPostOrdArb(Arbol->der);
        MostrarUnCliente(Arbol->dato);

    }
}

///--------------------------------------------------------------------------------------------------------------
/// Retornar la cantidad de nodos terminales. (hojas)
int contCantHojas (NodoArbol* Arbol)
{
    int cant=0;

    if(Arbol)
    {
        if(Arbol->der == NULL && Arbol->izq == NULL)
        {
            cant= 1 + contCantHojas(Arbol->izq) + contCantHojas(Arbol->der);
        }
        else
        {
            cant= contCantHojas(Arbol->izq) +  contCantHojas(Arbol->der);
        }
    }
    return cant;

}

///-------------------------------------------------------------------------------------------------------------
///Retornar la cantidad de nodos de grado 1.

int cantNodoGra1 (NodoArbol* Arbol)
{
    int cant=0;
    if (Arbol)
    {
        if((Arbol->der != NULL && Arbol->izq == NULL) || (Arbol->der == NULL && Arbol->izq != NULL))
        {
            cant= 1 + cantGrado1(Arbol->izq) + cantNodoGra1(Arbol->der);
        }
        else
        {
            cant= cantNodoGra1(Arbol->izq) +  cantNodoGra1(Arbol->der);
        }
    }
    return cant;
}

///----------------------------------------------------------------------------------------------------------------
///Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por legajo). - agregarNodoArbol
///-------------------------------------------------------------------------------------------------------------------
///Hacer una función que copie el contenido del árbol en una lista simplemente enlazada.

nodo* ArbolToLista (NodoArbol* Arbol,nodo* lista)
{
    if(Arbol)
    {
        ArbolToLista(Arbol->izq,lista);
        lista= agregarAlPrincipio(lista, crearNodo(Arbol->dato));
        ArbolToLista(ArbolToLista->der,lista);
    }
    return lista;
}

///----------------------------------------------------------------------------------------------------------------------
///Hacer una función que busque un nodo por legajo y lo retorne.

NodoArbol* buscarNodoArbolID(NodoArbol* Arbol,int id)
{
    NodoArbol* rta=NULL;
    if(Arbol)
    {
        if(id == Arbol->dato.id)
        {
            rta= Arbol;
        }
        if(id > Arbol->dato.id)
        {
            rta = buscarNodoArbolID(Arbol->izq, id);
        }
        else
        {
            rta = buscarNodoArbolID(Arbol->der, id);
        }
    }
    return rta;
}
///------------------------------------------------------------------------------------------------------------------------
///Hacer una función que busque un nodo por nombre. Cuidado, el árbol está ordenado por legajo.

NodoArbol* buscarNodoArbolNomb(NodoArbol* Arbol,char nombre[])
{
    NodoArbol* rta=NULL;
    if(Arbol)
    {
        if(strcmp(Arbol->dato.nombre,nombre)== 0)
        {
            rta=Arbol;
        }
        else
        {
            rta= buscarNodoArbolNomb(Arbol->izq,nombre);
            if(rta== NULL)
            {
                rta=buscarNodoArbolNomb(Arbol->der,nombre);
            }
        }
    }
    return rta;
}
///--------------------------------------------------------------------------------------------------------------------------
///Hacer una función que calcule la altura que tiene el árbol.
int calcAlturArbol(NodoArbol* Arbol)
{
    int calc=0;
    int calcAux1=0;
    int calcAux2=0;
    if(Arbol)
    {
        calcAux1= calcAlturArbol(Arbol->izq);
        calcAux2= calcAlturArbol(Arbol->der);
        if(calcAux1 == 0 && calcAux2 == 0)
        {
            calc= 1;
        }
        else
        {
            if(calcAux1> calcAux2)
            {
                calc= 1 + calcAux1;
            }
            else
            {
                calc= 1 + calcAux2;
            }
        }
    }
    return calc;
}

int profundidadArbol(NodoArbol * arbol)
{
    int izq = 0;
    int der = 0;
    if(arbol)
    {
        izq = profundidadArbol(arbol->izq);
        der = profundidadArbol(arbol->der);
    }

    return (der>izq)? der +1 : izq +1;
}

///------------------------------------------------------------------------------------------------------
///Hacer una función que calcule la cantidad de nodos del árbol.

int cantNodoArbol (NodoArbol* Arbol)
{
    int cant=0;
    if (Arbol)
    {

        cant= 1 + cantNodoArbol(Arbol->izq) + cantNodoArbol(Arbol->der);

    }
    return cant;
}

///------------------------------------------------------------------------------------------------------
/// Hacer una función que borre un nodo de un árbol.
NodoArbol* BorrarNodoArbol(NodoArbol* Arbol, int id)
{
    if(Arbol!= NULL)
    {
        if(Arbol->dato.id == id)
        {
            if(Arbol->izq!=NULL)
            {
                NodoArbol* masDer= NMD(Arbol->izq);
                Arbol->dato= masDer->dato;
                Arbol->izq= BorrarNodoArbol(Arbol->izq, masDer->dato.dni);
            }
            else
            {
                if(Arbol->der != NULL)
                {
                    NodoArbol* masIzq= NMI(Arbol->der);
                    Arbol->dato= masIzq->dato;
                    Arbol->der= BorrarNodoArbol(Arbol->der, masIzq->dato.dni);
                }
                else
                {
                    free(Arbol);
                    Arbol=NULL;
                }
            }
        }
        if(id > Arbol->dato.id)
        {
            Arbol->der = BorrarNodoArbol(Arbol->der,id);
        }
        if(id < Arbol->dato.id)
        {
            Arbol->izq= BorrarNodoArbol(Arbol->izq,id);
        }

    }
    return Arbol;
}

NodoArbol* NMD(NodoArbol* Arbol)
{
    NodoArbol*rta =NULL;
    if(Arbol)
    {
        rta= NMD(Arbol->izq);
        if(rta->dato.dni > Arbol->dato.id)
        {
            rta=Arbol;
        }
    }
    return rta;
}

NodoArbol* NMI(NodoArbol* Arbol)
{
    NodoArbol*rta =NULL;
    if(Arbol)
    {
        rta= NMI(Arbol->der);
        if(rta->dato.dni < Arbol->dato.id)
        {
            rta=Arbol;
        }
    }
    return rta;
}

///---------------------------------------------------------------------------------------------------------------------------------

///
int ArboltoArray(NodoArbol* Arbol,stCliente Cliente[],int dim)
{
    int validos=0;


    if(Arbol)
    {
        validos = ArboltoArray(Arbol->izq,Cliente,dim);
        if(validos > dim)
        {
            (Cliente) = (stCliente*) realloc(Cliente, sizeof(stCliente)*(dim+50));
            Cliente[validos] = Arbol->dato;
            validos++;
        }
        else
        {
            Cliente[validos] = Arbol->dato;
            validos++;
        }
        validos = validos +  ArboltoArray(Arbol->der,Cliente,dim)
    }
    return validos;
}

NodoArbol* ArrayToArbol (NodoArbol* Arbol,stCliente Cliente[], int v)
{
    int i=0;
    for(i=0; i<v; i++)
    {
        Arbol = agregarNodoArbol(Arbol,Cliente[v]);
    }
    return Arbol;
}
///-------------------------------------------------------------------------------------------------------------------------------
/// ARCHIVO - ARBOL
void subProgramaArbolToArchi(NodoArbol* Arbol, char NombreArchivo[])
{

    FILE * archi = fopen(NombreArchivo,"ab");

    if(archi)
    {
        ArbolToArchi(arbol,archi);
        fclose(archi);
    }

}

void ArbolToArchi(NodoArbol* arbol,FILE * archi)
{
    if(arbol)
    {
        fwrite(&arbol->dato,sizeof(stCliente),1,archi);
        ArbolToArchi(arbol->izq, archi);
        ArbolToArchi(arbol->der, archi);
    }
}

NodoArbol* ArchiToArbol(NodoArbol* Arbol,char NombreArchivo[])
{
    stCliente Aux;
    FILE* Archi= fopen(NombreArchivo,"rb");
    if(Archi)
    {
        while(fread(Aux,sizeof(stCliente),1,Archi)>0)
        {
            Arbol= agregarNodoArbol(Arbol, Aux);
        }
        fclose(Archi);
    }
    return Arbol;
}

///-----------------------------------------------------------------------------------------------------------------
///

