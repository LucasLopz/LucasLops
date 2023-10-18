#include "movimiento.h"


void mostrarUnMovimiento(stMovimiento movimiento)
{
    printf("\n============================== Movimiento de la cuenta id: %d ==============================", movimiento.idcuenta);
    printf("\nID del movimiento ..: %d",movimiento.id);
    printf("\nFecha del movimiento %d/%d/%d", movimiento.dia, movimiento.mes, movimiento.anio);
    printf("\nDetalle: %s", movimiento.detalle);

    printf("\nImporte; $%f", movimiento.importe);

    printf("\nEstado del Cliente ....: ");
    if(movimiento.eliminado == 0)
    {
        printf("Cliente Activo");
    }
    else
    {
        printf("Cliente Inactivo");
    }
    printf("\n=====================================================================");
}
