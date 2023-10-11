#include "nodoAlumno.h"

nodoAlumno* inicLista()
{
    return NULL;
}

nodoAlumno* crearNodo(stAlumno dato)
{
    nodoAlumno* nuevo = (nodoAlumno*) malloc(sizeof(nodoAlumno));
    nuevo->dato = dato;
    nuevo->sig= NULL;

    return nuevo;
}

nodoAlumno* agregarAlPrincipio(nodoAlumno* lista, nodoAlumno* nuevo)
{
    if(lista)
    {
        nuevo->sig = lista;
        lista= nuevo;
    }else{
    lista=nuevo;
    }

    return lista;
}

nodoAlumno* buscarUltimo(nodoAlumno* lista)
{
    nodoAlumno* aux = lista;
        while(aux->sig)
        {
            aux= aux->sig;
        }
        return aux;
}

nodoAlumno* agregarAlFinal(nodoAlumno* lista, nodoAlumno* nuevo)
{
    if(lista){
    nodoAlumno* ultimo = buscarUltimo(lista);
    ultimo->sig= nuevo;}
    else{
        lista = nuevo;
    }
    return lista;
}

nodoAlumno* agregarPorApellido(nodoAlumno* lista, nodoAlumno* nuevo)
{

    if(!lista){
            lista=nuevo;

    }else{
        if(strcmp(lista.dato.apellidoAlumno, nuevo.dato.apellidoAlumno)>0)
           lista= agregarPorApellido(lista->sig,nuevo);

    }else{
            nodoAlumno* ante = lista;
            nodoAlumno* aux = lista->sig;
            while(aux && strcmp(lista.dato.apellidoAlumno, nuevo.dato.apellidoAlumno)>0){
                ante = aux;
                aux = aux->sig;
            }
            nuevo->sig = aux;
            ante->sig = nuevo;
        }

    return Aux;
}

void muestraUnNodoAlumno(nodoAlumno* nodo)
{
 printf("\n =======================================================================");
printf("Nombre del alumno..................: %s", nodo.dato.nombreAlumno);
printf("Apellido del alumno................: %s", nodo.dato.apellidoAlumno);
printf("Nota del Alumno....................: %d", nodo.dato.nota);
printf("==========================================================================");
}


void muestraListaAlumno(nodoAlumno* lista)
{
while(lista){
    mostrarUnNodoAlumno(lista);
    lista= lista->sig;
}
}
