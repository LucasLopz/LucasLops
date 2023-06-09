#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

stCuenta AltadeCuenta(char nombreArchivo[],int idClint);
void TipoCuent();
void MostrarUnaCuenta (stCuenta Cuenta);
void MostrarTodCuen (stCuenta Cuenta[],int validos);
void MostrarTodCuenActiv (stCuenta Cuenta[],int validos);
void MostrarTodCuenInact (stCuenta Cuenta[],int validos);
void MostrarCuentaClient(stCuenta Cuentas[],int validos,int idcliente);
void MostrarCuentaid(stCuenta Cuentas[],int validos,int id);
void EliminarCuenta(stCuenta Cuenta);

typedef struct{
      int id;
    int idCliente;
    int nroCuenta;
    int tipoDeCuenta;
    float costoMensual;
int eliminado;
}stCuenta


stCuenta AltadeCuenta(char nombreArchivo[],int idClint){
    stCuenta Cuenta;
int opcion=0;
char Continuar=0;

  File* archi=fopen(nombreArchivo, "a+b");
if(archi){
        fseek(archi,0,0)
    if(fread(&Cuenta,sizeof(stCuenta),1,archi)>0){

     Cuenta.id= idClint + 00001000;
Cuenta.idCliente= idClint;
    nroCuenta= 1;
 do{
    TipoCuent();
    scanf("%d", opcion);

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
    MostrarUnaCuenta(Cuenta);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
}while(Continuar=! 83 || Continuar=! 115 );
    Cuenta.eliminado=0;
  fwrite(&Cuenta, sizeof(stCuenta),1,archi);
}else{

    int flag=0;
while(fread(&Cuenta,sizeof(stCuenta),1,archi)>0 && flag==0){
if(Cuenta.idCliente== idCliente){
    flag=1;
}}
    if(flag==0){
            Cuenta.id= idClint + 00001000;
Cuenta.idCliente= idClint;
    nroCuenta= 1;
 do{
    TipoCuent();
    scanf("%d", opcion);

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
    MostrarUnaCuenta(Cuenta);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
}while(Continuar=! 83 || Continuar=! 115 );
    Cuenta.eliminado=0;

fwrite(&Cuenta, sizeof(stCuenta),1,archi);

    }else{
    fseek(archi,-1*sizeof(stCuenta),2);
    fread(&Cuenta,sizeof(stCliente),1,archi);
    fseek(archi,-1*sizeof(stCuenta),1);

    while(Cuenta.idcliente != idCliente){
        fseek(archi,-1*sizeof(stCuenta),1);
    fread(&Cuenta,sizeof(stCliente),1,archi);
    fseek(archi,-1*sizeof(stCuenta),1);
    }

    Cuenta.id= Cuenta.id + 00001000;
Cuenta.idCliente= idClint;
    nroCuenta= nroCuenta + 1;

 do{
    TipoCuent();
    scanf("%d", opcion);

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
    MostrarUnaCuenta(Cuenta);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
}while(Continuar=! 83 || Continuar=! 115 );
    Cuenta.eliminado=0;
    fwrite(&Cuenta, sizeof(stCuenta),1,archi);
    }
}
   fclose(archi); }
}


void TipoCuent(){
printf("Tipos de cuentas existentes con su costo Mensual:....");
printf("1- Caja de Ahorro en Pesos - $500");
printf("2- Caja de Ahorro en Dolares - $600");
printf("3- Cuenta Corriente - $100");
}

void MostrarUnaCuenta (stCuenta Cuenta){

printf("\n============================== Cuenta %d ==============================", Cuenta.id);
printf("\n ID Cliente.....................: %d", Cuenta.idCliente);
printf("\n Tipo de Cuenta.................: %d", Cuenta.tipoDeCuenta);
printf("\n Costo Mensual..................: $ %f", Cuenta.costoMensual);
printf("\n Estado de la cuenta.............: ")
if(Cuenta.eliminado == 0){
    printf("Cuenta Activo");
}else{
  printf("Cuenta Inactivo");
}
printf("\n=======================================================================");
}

void MostrarTodCuen (stCuenta Cuenta[],int validos){
nt i=0;
for(i=0;i<validos;i++){
 MostrarUnaCuenta(Cuenta[i]);
}
}

void MostrarTodCuenActiv (stCuenta Cuenta[],int validos){
nt i=0;
for(i=0;i<validos;i++){
        if(Cuenta[i].eliminado== 0){
 MostrarUnaCuenta(Cuenta[i]);
}
}
}

void MostrarTodCuenInact (stCuenta Cuenta[],int validos){
int i=0;
for(i=0;i<validos;i++){
        if(Cuenta[i].eliminado == 1){
 MostrarUnaCuenta(Cuenta[i]);
}
}
}

void MostrarCuentaClient(stCuenta Cuentas[],int validos,int idcliente){
int i=0;
for(i=0;i<validos;i++){
        if(Cuenta[i].idCliente == idcliente){
 MostrarUnaCuenta(Cuenta[i]);
}
}
}

void MostrarCuentaid(stCuenta Cuentas[],int validos,int id){
int i=0;
for(i=0;i<validos;i++){
        if(Cuenta[i].id == id){
 MostrarUnaCuenta(Cuenta[i]);
}
}
}

void MostrarCuentaTipo(stCuenta Cuentas[],int validos,int TipoCuent){
int i=0;
for(i=0;i<validos;i++){
        if(Cuenta[i].tipoDeCuenta == TipoCuent){
 MostrarUnaCuenta(Cuenta[i]);
}
}
}



void EliminarCuenta(stCuenta Cuenta){
char opcion=0;
printf("\n Esta seguro de querer eliminar el Cuenta?....");
printf("\n Presiona S para continuar....");
opcion=getch()
if(opcion== 83 || opcion== 115){
 Cuenta.eliminado=1;
}
}


void CambiarIDCli(stCliente Cuentas){
            printf("Ingrese el nuevo id del Cliente: ");
            fflush(stdin);
    gets(Cuentas.idCliente);
    }
void CambiarnroCuent(stCliente Cuenta){

            printf("Ingrese el nuevo nro de Cuenta: ");
            fflush(stdin);
    gets(Cuentas[i].nroCliente);
    }

void CambiartipoCuenta(stCliente Cuentas){
printf("Ingrese el nuevo tipo de cuenta: ");
            TipoCuent();
    scanf("%d",&opcion);
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
    }}}

void CambiarTodoCuenta(stCuenta Cuentas[], int validos, int idCuenta) {
int i=0;
for(i=0;i<validos;i++){
    if(Cuentas[i].id == idCuenta){
int opcion=0;
printf("Seleccione lo que quiere cambiar: \n")
printf("1-............... id del cliente \n");
printf("2-............. Numero de cuenta \n");
printf("3-............... Tipo de cuenta \n");
scanf("%d",&opcion);

switch(opcion){
case 1:
    CambiarIDCli(Cuenta[i]);
    break
    case 2:
    CambiarnroCuent(Cuenta[i]);
    break
    case 3:
    CambiartipoCuenta(Cuenta[i]);
    break
    case default:
        printf("Opcion Invalida");

}
}
