#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>


typedef struct {
int id; /// campo único y autoincremental
int nroCliente;
char nombre[30];
char apellido[30];
char dni[10];
char email[30];
char domicilio[45];
char telefono[12];
int eliminado; /// 0 si está activo - 1 si está eliminado
}stCliente;



void MostrarUnCliente(stCliente Cliente);
stCliente AltaDeCliente(char nombreArchivo[]);



stCliente AltaDeCliente(char nombreArchivo[]){
stCliente Cliente;
char Aux[30];
int MailValido=0;

FILE* archi=fopen(nombreArchivo, "a+b");
if(archi){
 char opcion=0;

        fseek(archi,0,0);
    if(fread(&Cliente,sizeof(stCliente),1,archi)>0){

     Cliente.id=001000000;
    Cliente.nroCliente=1;
do{
printf("\n Ingrese el Nombre...................: ");
    fflush(stdin);
    gets(Cliente.nombre);
printf("\n Ingrese el Apellido.................: ");
    fflush(stdin);
    gets(Cliente.apellido);
printf("\n Ingrese el DNI......................: ");
    fflush(stdin);
    gets(Cliente.dni);
printf("\n Ingrese el Email....................: ");
    fflush(stdin);
    gets(Aux);
printf("\n Ingrese el Domicilio................: ");
    fflush(stdin);
    gets(Cliente.domicilio);
printf("\n Ingrese el telefono.................: ");
    fflush(stdin);
    gets(Cliente.telefono);

    Cliente.eliminado=0;
    system("cls");
    MostrarUnCliente(Cliente);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    opcion=getch();

    }while(opcion != 83 || opcion != 115 );



    }else{
        fseek(archi,-1*sizeof(stCliente),2);
    fread(&Cliente,sizeof(stCliente),1,archi);
Cliente.id= Cliente.id + 1000000;
Cliente.nroCliente++;
do{
printf("\n Ingrese el Nombre...................: ");
    fflush(stdin);
    gets(Cliente.nombre);
printf("\n Ingrese el Apellido.................: ");
    fflush(stdin);
    gets(Cliente.apellido);
printf("\n Ingrese el DNI......................: ");
    fflush(stdin);
    gets(Aux);
printf("\n Ingrese el Email....................: ");
    fflush(stdin);
    gets(Aux);
printf("\n Ingrese el Domicilio................: ");
    fflush(stdin);
    gets(Cliente.domicilio);
printf("\n Ingrese el telefono.................: ");
   fflush(stdin);
    gets(Aux);
     Cliente.eliminado=0;
     system("cls");
    MostrarUnCliente(Cliente);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    opcion=getch();
}while(opcion != 83 || opcion != 115 );
    }

    fwrite(&Cliente,sizeof(stCliente),1,archi);
    }
fclose(archi);
}

void MostrarUnCliente(stCliente Cliente){
printf("\n============================== Cliente %d ==============================", Cliente.id);
printf("\n Nro Cliente...........: %d", Cliente.nroCliente);
printf("\n Nombre................: %s", Cliente.nombre);
printf("\n Apellido..............: %s", Cliente.apellido);
printf("\n DNI...................: %s", Cliente.dni);
printf("\n Email.................: %s", Cliente.email);
printf("\n Domicilio.............: %s", Cliente.domicilio);
printf("\n Telefono..............: %s", Cliente.telefono);
printf("\n Estado del Cliente....: ");
if(Cliente.eliminado == 0){
    printf("Cliente Activo");
}else{
  printf("Cliente Inactivo");
}
printf("\n=====================================================================");
}

