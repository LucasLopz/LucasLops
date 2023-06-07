#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>


typedef struct{
      int id;
    int idCliente;
    int nroCuenta;
    int tipoDeCuenta;
    float costoMensual
int eliminado;
}stCuenta


stCuenta AltadeCuenta(int idClint){
    stCuenta Cuenta;
int opcion=0;
char Continuar=0;

  File* archi=fopen(nombreArchivo, "a+b");
if(archi){
        fseek(archi,0,0)
    if(fread(&,sizeof(stCuenta),1,archi)>0){

     Cuenta.id= idClint + 00001000;
Cuenta.idCliente= idClint;
    nroCuenta= 1;
 do{
    TipoCuent();
    scanf("%d", opcion)

    switch(opcion){

case 1:
    Cuenta.tipoDeCuenta=1;
    Cuenta.costoMensual= 500;

break;
case 2:
    Cuenta.tipoDeCuenta=2;
    Cuenta.costoMensual= 600;
    break;
case 3:
    Cuenta.tipoDeCuenta=3;
    Cuenta.costoMensual= 100;
    break;
default:
    printf("Opcion Invalida");
    break;

    }
    system("cls");
    /// Agregar MostrarCuenta
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
}while(Continuar=! 83 || Continuar=! 115 );
    Cuenta.eliminado=0;

    }}
}


void TipoCuent(){
printf("Tipos de cuentas existentes con su costo Mensual:....");
printf("1- Caja de Ahorro en Pesos - $500");
printf("2- Caja de Ahorro en Dolares - $600");
printf("3- Cuenta Corriente - $100");
}
