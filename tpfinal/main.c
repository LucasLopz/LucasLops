#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "string.h"
#include "adl.h"
#include "nodoArbolCliente.h"
#include "nodoListaMovimiento.h"

/// LO COPIE TAL CUAL EL TP ANTERIOR, HAY QUE CHEQUEARLO




///printF

void menuPrincipal();

void menuClientes();
void modificarCliente();
void consultaClientes();

void menuCuentas();
void modificarCuenta();
void consultaCuenta();

void menuMovimientos();
void modicarMovimentos();
void consultaMovimientos();

///Switch
void SmenuPrincipal();

void SmenuCliente();
void SmodificarCliente();
void SconsultaClientes();

void SmenuCuentas();
void SmodificarCuenta();
void SconsultaCuentas ();

void SmenuMovimientos();
void SconsultaMovimientos();



/// MAIN
int main()
{

    color(125);
    printf("Presione una tecla para empezar.......");
    getch();
    SmenuPrincipal();


    return 0;
}





/// -----------------------switch-------------------------------

/// SPrincipal
void SmenuPrincipal()
{
    char opcion;
    system("cls");

    do
    {
        ;
        menuPrincipal();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            SmenuCliente();
            break;
        case 'b':
            SmenuCuentas();
            break;
        case 'c':
            SmenuMovimientos();
            break;
        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }

        printf("\nDesea seguir en la aplicacion? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);


}
///Smovimientos


void SmenuMovimientos()
{
    char opcion;
    int idMoviento;
    int numCuenta;
    system("cls");

    do
    {

        menuMovimientos();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            /// FUNCION CARGAR MOVIMIENTO
            cargaArchivoMovimientos(ARCHIVO_MOVIMIENTOS,ARCHIVO_CUENTAS);
            break;
        case 'b':
            ///FUNCION ELIMINAR MOVIMIENTO
            printf("\nIngrese el ID del movimiento a eliminar: ");
            scanf("%d",&idMoviento);
            eliminaMovimiento(ARCHIVO_MOVIMIENTOS,idMoviento);
            break;
        case 'c':
            SconsultaMovimientos();
            break;
        case 'd':
            milMovimientos(ARCHIVO_MOVIMIENTOS,ARCHIVO_CUENTAS);
            break;
        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }

        printf("\nDesea seguir en movimientos? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);
}

void SconsultaMovimientos()
{
    char opcion;
    int nCuenta;
    int anio;
    int mes;
    int dia;
    system("cls");

    do
    {
        consultaMovimientos();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            ///FUNCION CONSULTA POR NUMERO DE CUENTA
            printf("\nIngrese el numero de cuenta: ");
            scanf("%d",&nCuenta);
            mostrarMovimientoXidCuenta(ARCHIVO_MOVIMIENTOS,ARCHIVO_CUENTAS,nCuenta);
            break;
        case 'b':
            ///FUNCION CONSULTAR POR FECHA
            printf("\nIngrese el anio: ");
            scanf("%d",&anio);
            printf("\nIngrese el mes: ");
            scanf("%d",&mes);
            printf("\nIngrese el dia: ");
            scanf("%d",&dia);
            mostarmovimientoxfecha(ARCHIVO_MOVIMIENTOS,anio,mes,dia);
            break;
        case 'c':
            ///FUNCION ACTIVOS
            mostrarMovimientosActivos(ARCHIVO_MOVIMIENTOS);
            break;
        case 'd':
            ///FUNCION INACTIVOS
            mostrarMovimientosEliminados(ARCHIVO_MOVIMIENTOS);
            break;
        case 'e':
            ///FUNCION TODOS
            muestraArchivoMovimientos(ARCHIVO_MOVIMIENTOS);
            break;
        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }

        printf("\nDesea consultar otra cosa? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);
}


///Scuentas
void SmenuCuentas()
{
    char opcion;
    int numCuenta;
    system("cls");

    do
    {

        menuCuentas();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            cargaArchivoCuentas(ARCHIVO_CUENTAS,ARCHIVO_CLIENTES);
            break;
        case 'b':
            printf("\nIngrese el numero de cuenta a eliminar: ");
            scanf("%d",&numCuenta);
            eliminaCuenta(ARCHIVO_CUENTAS,numCuenta);
            break;
        case 'c':
            SmodificarCuenta();
            break;
        case 'd':
            SconsultaCuentas();
            break;

        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }

        printf("\nDesea seguir en cuentas? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);
}


void SconsultaCuentas ()
{
    char opcion;
    int aux;
    float costo;
    system("cls");

    do
    {
        consultaCuenta();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            ///MOSTRAR CUENTA POR CLIENTE
            printf("\nIngrese el numero de cliente: ");
            scanf("%d",&aux);
            muestraCuentaXcliente(ARCHIVO_CUENTAS,ARCHIVO_CLIENTES,aux);
            break;
        case 'b':
            ///MOSTRAR POR TIPO  DE CUENTA
            printf("\nIngrese el tipo de cuenta: \n1 - Caja de ahorro en pesos\n2 - Caja de ahorro en dolares\n3 - Cuenta corriente\n");
            scanf("%d",&aux);
            muestraCuentaXtipo(ARCHIVO_CUENTAS,aux);
            break;
        case 'c':
            ///MOSTRAR POR COSTO MENSUAL
            printf("\nIngrese el costo mensual: ");
            scanf("%f",&costo);
            muestraCuentaXcostoMensual(ARCHIVO_CUENTAS,costo);
            break;
        case 'd':
            ///MOSTRAR CUENTAS ACTIVAS
            muestraCuentaActivas(ARCHIVO_CUENTAS);
            break;
        case 'e':
            ///MOSTRAR CUENTAS INACTIVAS
            muestraCuentaInactivas(ARCHIVO_CUENTAS);
            break;
        case 'f':
            muestraArchivoCuentas(ARCHIVO_CUENTAS);
            break;

        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }

        printf("\nDesea consultar otra cosa? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);
}



void SmodificarCuenta()
{
    char opcion;
    int numCuenta;
    system("cls");

    do
    {
        modificarCuenta();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            ///FUNCION MODIFICAR TIPO CUENTA
            printf("\nIngrese el numero de cuenta a modificar: ");
            scanf("%d",&numCuenta);
            modificaTipoDeCuenta(ARCHIVO_CUENTAS,numCuenta);

            break;
        case 'b':
            ///FUNCION MODIFICAR COSTO MENSUAL
            printf("\nIngrese el numero de cuenta a modificar: ");
            scanf("%d",&numCuenta);
            modificaCostoMensual(ARCHIVO_CUENTAS,numCuenta);
            break;
        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }

        printf("\nDesea modificar otra cosa? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);
}


///SClientes
void SmenuCliente()
{

    char opcion;
    system("cls");
    int aux;

    do
    {
        ;
        menuClientes();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case 'a':
            cargaArchivoClientes(ARCHIVO_CLIENTES);
            break;
        case 'b':
            printf("\nIngrese el numero del cliente a eliminar: ");
            scanf("%d",&aux);
            eliminarCliente(ARCHIVO_CLIENTES,aux);
            break;
        case 'c':
            SmodificarCliente();
            break;
        case 'd':
            SconsultaClientes();
            break;

        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }
        printf("\nDesea seguir en clientes? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);


}
///
void SconsultaClientes()
{
    char opcion;
    system("cls");
    char aux[30];
    int Aux;

    do
    {
        consultaClientes();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case'a':
                printf("\nIngrese el nombre del cliente a buscar: ");
                fflush(stdin);
                gets(aux);
                muestraXnombre(ARCHIVO_CLIENTES,aux);
                break;
        case'b':
                printf("\nIngrese el apellido del cliente a buscar: ");
                fflush(stdin);
                gets(aux);
                muestraXapellido(ARCHIVO_CLIENTES,aux);
                break;
        case'c':
                printf("\nIngrese el telefono del cliente a buscar: ");
                fflush(stdin);
                gets(aux);
                muestraXtelefono(ARCHIVO_CLIENTES,aux);
                break;
        case'd':
                printf("\nIngrese el DNI del cliente a buscar: ");
                fflush(stdin);
                gets(aux);
                muestraXdni(ARCHIVO_CLIENTES,aux);
                break;
        case'e':
                printf("\nIngrese el domicilio del cliente a buscar: ");
                fflush(stdin);
                gets(aux);
                muestraXdomicilio(ARCHIVO_CLIENTES,aux);
                break;
        case'f':
                printf("\nIngrese el email del cliente a buscar: ");
                fflush(stdin);
                gets(aux);
                muestraXemail(ARCHIVO_CLIENTES,aux);
                break;
        case'g':
                printf("\nIngrese el numero del cliente a buscar: ");
                scanf("%d",&Aux);
                muestraXnumCliente(ARCHIVO_CLIENTES,Aux);
                break;
        case'h':
                ///FUNCION BUSCAR POR ID
                printf("\nIngrese el ID del cliente a buscar: ");
                scanf("%d",&Aux);
                muestraXid(ARCHIVO_CLIENTES,Aux);
                break;
        case'i':
                muestraActivos(ARCHIVO_CLIENTES);
                break;
        case'j':
                muestraiNctivos(ARCHIVO_CLIENTES);
                break;
        case'k':
            muestraArchivoClientes(ARCHIVO_CLIENTES);
            break;
        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }


        printf("\nDesea consultar otra cosa? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);
}

///

void SmodificarCliente()
{
    char opcion;
    int numCliente;
    system("cls");

    do
    {
        modificarCliente();
        fflush(stdin);
        scanf("%c",&opcion);
        switch(opcion)
        {
        case'a':
                printf("\nIngrese el numero del cliente a modificar: ");
                scanf("%d",&numCliente);
                modificaNombre(ARCHIVO_CLIENTES,numCliente);
                break;
        case'b':
                printf("\nIngrese el numero del cliente a modificar: ");
                scanf("%d",&numCliente);
                modificaApellido(ARCHIVO_CLIENTES,numCliente);
                break;
        case'c':
                printf("\nIngrese el numero del cliente a modificar: ");
                scanf("%d",&numCliente);
                modificaTelefono(ARCHIVO_CLIENTES,numCliente);
                break;
        case'd':
                printf("\nIngrese el numero del cliente a modificar: ");
                scanf("%d",&numCliente);
                modificaDNI(ARCHIVO_CLIENTES,numCliente);
                break;
        case'e':
                printf("\nIngrese el numero del cliente a modificar: ");
                scanf("%d",&numCliente);
                modificaDomicilio(ARCHIVO_CLIENTES,numCliente);
                break;
        case'f':
                printf("\nIngrese el numero del cliente a modificar: ");
                scanf("%d",&numCliente);
                modificaEmail(ARCHIVO_CLIENTES,numCliente);
                break;
        default:
            printf("\nOpcion invalida (controle no tener bloqueadas las mayusculas)");
        }
        printf("\nDesea modificar otra cosa? Presione ESC para salir...");
        fflush(stdin);
        opcion=getch();
        system("cls");
    }
    while(opcion != ESC);


}



/// -------------------------------------------Printf-----------------------------

/// MENU PRINCIPAL
void menuPrincipal()
{
    printf("\n\t\t\t Banco Bicicleta Facil S.A.");
    printf("\n");
    printf("\na - Clientes");
    printf("\nb - Cuentas");
    printf("\nc - Movimientos");
    printf("\n");

}
/// CLIENTES

void menuClientes()
{
    printf("\n\t\t\t Clientes");
    printf("\n");
    printf("\na - Cargar clientes");
    printf("\nb - Dar de baja un cliente");
    printf("\nc - Modificar un cliente");
    printf("\nd - Consultar un cliente");
    printf("\n");

}

void modificarCliente()
{
    printf("\n\t\t\t Modificacion de un cliente");
    printf("\n");
    printf("\na - Cambiar Nombre");
    printf("\nb - Cambiar Apellido");
    printf("\nc - Cambiar telefono");
    printf("\nd - Cambiar DNI");
    printf("\ne - Cambiar Domicilio");
    printf("\nf - Cambiar Email");
    printf("\n");

}

void consultaClientes()
{
    printf("\n\t\t\t Consulta de clientes");
    printf("\n");
    printf("\na - Buscar por nombre");
    printf("\nb - Buscar por apellido");
    printf("\nc - Buscar por telefono");
    printf("\nd - Buscar por DNI");
    printf("\ne - Buscar por Domicilio");
    printf("\nf - Buscar por Email");
    printf("\ng - Buscar por numero de cliente");
    printf("\nh - Buscar por ID");
    printf("\ni - Clientes activos");
    printf("\nj - Clientes inactivos");
    printf("\nk - Todos los clientes");
    printf("\n");
}




/// CUENTAS


void menuCuentas()
{
    printf("\n\t\t\t Cuentas");
    printf("\n");
    printf("\na - Crear cuentas");
    printf("\nb - Dar de baja una cuenta");
    printf("\nc - Modificar una cuenta");
    printf("\nd - Consultar una cuenta");
    printf("\n");

}
void modificarCuenta()
{
    printf("\n\t\t\t Modificacion de una cuenta");
    printf("\n");
    printf("\na - Tipo cuenta");
    printf("\nb - Costo mensual");
    printf("\n");

}

void consultaCuenta()
{
    printf("\n\t\t\t Modificacion de una cuenta");
    printf("\n");
    printf("\na - Por cliente");
    printf("\nb - Por tipo de cuenta");
    printf("\nc - Por costo mensual");
    printf("\nd - Cuentas activas");
    printf("\ne - Cuentas inactivas");
    printf("\nf - Todas las cuentas");
    printf("\n");

}

/// Movimientos

void menuMovimientos()
{
    printf("\n\t\t\t Movimientos");
    printf("\n");
    printf("\na - Cargar un movimiento");
    printf("\nb - Eliminar un movimiento");
    printf("\nc - Consultar un movimiento");
    printf("\nd - Carga aleatoria movimientos");
    printf("\n");

}

void consultaMovimientos()
{
    printf("\n\t\t\t Consulta de movimientos");
    printf("\n");
    printf("\na - Consultar por cuenta");
    printf("\nb - Consultar por fecha");
    printf("\nc - Movimientos activos");
    printf("\nd - Movimientos inactivos");
    printf("\ne - Todos los movimientos");
    printf("\n");
}
