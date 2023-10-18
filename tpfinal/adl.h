#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED
#include "cuenta.h"
#include <string.h>


typedef struct {
    char tipoCuenta[20];
    stCuenta cuenta;
    nodoListaMovimiento* lista;
}celdaCuentas;

///Alta Movimiento
int altaMovimientos(celdaCuentas adl[], char tipoCuenta[], stMovimiento Movimiento, int v );

///Alta Cuenta
int buscarPosCuenta(celdaCuentas adl[],char tipoCuenta[],int validos);
int agregarCuenta (celdaCuentas adl[],char tipoCuenta[],int validos);

/// modificacion
void modificaTipoDeCuenta(celdaCuentas adl[],char tipoCuenta[]);
void modificaCostoMensual(celdaCuentas adl[],char tipoCuenta[]);

///elimina cuenta
void eliminaCuenta(celdaCuentas adl[],char tipoCuenta[]);





#endif // ADL_H_INCLUDED
