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


#endif // LISTACLIENTE2_H_INCLUDED
