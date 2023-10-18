#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "string.h"

typedef struct{
	int id; /// campo único y autoincremental
	int idCliente;
	int nroCuenta;
	int tipoDeCuenta; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $
	float costoMensual; /// Costo de mantenimiento del producto
	int baja; /// 0 si está activo - 1 si está eliminado
}stCuenta;

void muestraUnaCuenta(stCuenta cuenta);

/*
/// control
int crearIdCuenta(char nombreArchivo[]);
int crearNumeroCuenta(char nombreArchivo[]);
int buscaIdCliente(char nombreArchivo[],int numCliente); /// NO SE QUE HACER CON ESTAS FUNCIONES

/// carga y muestra archivo
void cargaArchivoCuentas(char nombreArchivo[],char archivoClientes[]);
*/

#endif // CUENTA_H_INCLUDED
