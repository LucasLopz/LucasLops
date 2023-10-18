#include "adl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int altaMovimientos(celdaCuentas adl[], char tipoCuenta[], stMovimiento movimiento, int v ){


   nodoListaMovimiento* Aux= crearNodoMov(Movimiento);
    int pos= buscarPosCuenta(adl,tipoCuenta,v)
             if(pos== -1)
    {
        validos= agregarCuenta(adl,tipoCuenta,v);
        pos= validos-1;

    }
    adl[pos].lista = agregarPpio(adl[pos].lista, Aux);
    return validos;




}
int buscarPosCuenta(celdaCuentas adl[],char tipoCuenta[],int validos);
{
    int rta= -1;
    int i=0;
    while(rta== -1 && i<validos)
    {
        if(strcmp(adl[i].tipoCuenta, tipoCuenta)==0)
        {
            rta=i
        }
        else
        {
            i++;
        }
    }
    return rta;
}
int agregarCuenta (celdaCuentas adl[],char tipoCuenta[],int validos)
{
    stcpy(adl[validos].tipoCuenta ,tipoCuenta);
    adl[validos].listaCuenta= inicListaCuenta();
    adl[validos].lista= inicLista();
    validos++;
    return validos;
}
