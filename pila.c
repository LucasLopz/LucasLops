#include "pila.h"

void inicPila(Pila* pila){
(*Pila) = inicLista();
}

void apilar(Pila* pila, stCliente dato){
(*pila) = agregarAlPrincipio(pila,crearNodo(dato));
}

stCliente tope (Pila* pila){
    return pila->dato;
}

stCliente desapilar (Pila* pila){
nodo* Aux= pila;
pila= pila->sig;
Aux->sig= NULL;
return Aux->dato;
}

void mostrar(Pila* pila){
nodo*Aux= pila;
while(Aux){
    muestraLista(Aux);
    Aux= Aux->sig;
}

int pilaVacia(Pila* pila){
int flag=0;
    if(lista){
            flag=1;
    }
return flag;
}
}
