#ifndef NODOLISTAMOVIMIENTO_H_INCLUDED
#define NODOLISTAMOVIMIENTO_H_INCLUDED

#include "movimiento.h"

typedef struct _nodoListaMovimiento{
	stMovimiento dato;
	struct _nodoListaMovimiento* sig;
}nodoListaMovimiento;

nodoListaMovimiento* inicListaMov;
nodoListaMovimiento* crearNodoCuentaMov(stMovimiento movimiento);

/// elima movimiento
void eliminaMovimiento(nodoListaMovimiento* lista,int id);

/// mostrar movimientos con filtro

void mostrarTodosLosMovimientosDeCuenta(nodoListaMovimiento* lista)
void mostrarMovimientosActivos (nodoListaMovimiento* lista);
void mostrarMovimientosEliminados(nodoListaMovimiento* lista);
void mostarmovimientoxfecha(nodoListaMovimiento* lista, int anio, int mes, int dia);

#endif // NODOLISTAMOVIMIENTO_H_INCLUDED
