#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "string.h"

typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    char domicilio[45];
    char teléfono[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado
} stCliente;


/// Muestra
void muestraUnCliente(stCliente cliente);





#endif // CLIENTE_H_INCLUDED
