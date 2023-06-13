#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

typedef struct{
int id; /// campo único y autoincremental
int idCuenta; /// Id de la cuenta
int anio;
int mes; /// 1 a 12
int dia; /// 1 a … dependiendo del mes
char detalle[100];
float importe;
int eliminado; /// 0 si está activo - 1 si está eliminado
}stMovimiento

///AÑADIR LAS FECHAS
stMovimiento AltadeMovimiento(char nombreArchivo[],int idCuenta){
    stMovimiento Movimiento1;
    char Continuar=0;

File* archi=fopen(nombrearchivo, "a+b");
if(archi){
    fseek(archi,0,0)
    if(fread(&Movimiento1,sizeof(stMovimiento),1,archi)>0){
        Movimiento1.idCuenta = idCuenta;
    Movimiento1.id= idCuenta++;
    Movimiento1.anio= ;
    Movimiento1.mes= ;
    Movimiento1.dia= ;
     do{
    printf("Ingrese los Detalles del movimiento:");
    fflush(stdin);
    gets(Movimiento1.detalle);
    printf("Ingrese el Monto del Movimiento:")
    scanf("%f", Movimiento1.importe);
    system("cls");

    MostrarUnMovim(Movimiento1);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
    }while(Continuar=! 83 || Continuar=! 115 );
    Movimiento1.eliminado=0;
    fseek(archi,0,2);
  fwrite(&Movimiento1, sizeof(stMovimiento),1,archi);
    }else{
        int flag=0;
while(fread(&Movimiento1,sizeof(stMovimiento),1,archi)>0 && flag==0){
if(Movimiento.idCuenta == idCuenta){
    flag=1;
}}
    if(flag==0){
Movimiento1.id= idCuenta ++;
Movimiento1.idCuenta= idCuenta;
Movimiento1.anio= ;
Movimiento1.mes= ;
Movimiento1.dia= ;
 do{
    printf("Ingrese los Detalles del movimiento:");
    fflush(stdin);
    gets(Movimiento1.detalle);
    printf("Ingrese el Monto del Movimiento:")
    scanf("%f", Movimiento1.importe);
    system("cls");

    MostrarUnMovim(Movimiento1);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
}while(Continuar=! 83 || Continuar=! 115 );
    Movimiento1.eliminado=0;

fseek(archi,0,2);
fwrite(&Movimiento1, sizeof(stMovimiento),1,archi);

    }else{
    fseek(archi,-1*sizeof(stMovimiento),2);
    fread(&Movimiento1,sizeof(stMovimiento),1,archi);
    fseek(archi,-1*sizeof(stMovimiento),1);

    while(Movimiento1.idCuenta != idCuenta){
        fseek(archi,-1*sizeof(stMovimiento),2);
    fread(&Movimiento1,sizeof(stMovimiento),1,archi);
    fseek(archi,-1*sizeof(stMovimiento),1);

    }

    Movimiento1.id= Movomiento.id + 1;
Movimiento1.idCuenta= idCuenta;
Movimiento1.anio= ;
Movimiento1.mes= ;
Movimiento1.dia= ;

 do{

    printf("Ingrese los Detalles del movimiento:");
    fflush(stdin);
    gets(Movimiento1.detalle);
    printf("Ingrese el Monto del Movimiento:")
    scanf("%f", Movimiento1.importe);
    system("cls");

    MostrarUnMovim(Movimiento1);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    Continuar=getch();
}while(Continuar=! 83 || Continuar=! 115 );
    Movimiento1.eliminado=0;

fseek(archi,0,2);
fwrite(&Movimiento1, sizeof(stMovimiento),1,archi);
    }
}
    fclose(archi);}
}




 void  MostrarUnMovim(stMovimiento Movimiento1){

 printf("[%d/%d/%d] ~ ",Movimiento1.dia,Movimiento1.mes, Movimiento1.anio)






 }
