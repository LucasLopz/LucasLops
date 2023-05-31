#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <cliente.h>


typedef struct {
  int id; /// campo único y autoincremental
    int idCliente /// Id del Cliente dueño de la Cuenta;
    int nroCuenta;
    int tipoDeCuenta; /// 1. Caja de Ahorro en Pesos, 2. Caja de Ahorro en Dólares, 3. Cta Cte en $
    float costoMensual /// Costo de mantenimiento del producto;
int eliminado; /// 0 si está activo - 1 si está eliminado
}stCuenta

typedef struct {
int id; /// campo único y autoincremental
int idCuenta; /// Id de la cuenta
int anio;
int mes; /// 1 a 12
int dia; /// 1 a … dependiendo del mes
char detalle[100];
float importe;
int eliminado; /// 0 si está activo - 1 si está eliminado
}stMovimiento


int main()
{
    return 0;
}

