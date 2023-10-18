#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "string.h"

typedef struct {
int id; /// campo único y autoincremental
int idCuenta; /// Id de la cuenta
int anio;
int mes; /// 1 a 12
int dia; /// 1 a … dependiendo del mes
char detalle[100];
float importe;
int eliminado; /// 0 si está activo - 1 si está eliminado
} stMovimiento;

/*
/// aleatorio
void milMovimientos(char nombreArchivo[],char archivoCuentas[]);
void obtenerDetalle(char detalle[],float importe);
void cargaaletoriadatos(char nombreArchivo[],char archivoCuentas[]); /// Encontrar El Modo de que funci
int randomrango(int minimo, int maximo);


/// carga y muestra archivo movimientos

void cargaArchivoMovimientos(char nombreArchivo[],char archivoCuentas[]);
void muestraArchivoMovimientos(char nombreArchivo[]);

/// control
int crearIdMovimiento(char nombreArchivo[]);
int buscaIdCuenta(char nombreArchivo[],int numCuenta);
int randomRangoInt(int min, int max);
*/

/// carga y muestra un movimiento

void mostrarUnMovimiento(stMovimiento movimiento);




#endif // MOVIMIENTO_H_INCLUDED
