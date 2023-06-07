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
}stCliente

void EliminarCliente(stCliente Cliente);
void CambiarTelCli(stCliente Clientes[], int validos,char telefono[30]);
void CambiarDomCli(stCliente Clientes[], int validos,char domicilio[30]);
void CambiarEmCli(stCliente Clientes[], int validos,char email[30]);
void CambiarDniCli(stCliente Clientes[], int validos,char dni[30]);
void CambiarApellCli(stCliente Clientes[], int validos,char apellido[30]);
void CambiarNombCli(stCliente Clientes[], int validos,char nombre[30]);
void MostrarUnClientPorTel(stCliente Clientes[], int validos,char telefono[30]);
void MostrarUnClientPorDom(stCliente Clientes[], int validos,char domicilio[30]);
void MostrarUnClientPorEM(stCliente Clientes[], int validos,char email[30]);
void MostrarUnClientPorDNI(stCliente Clientes[], int validos,char dni[12]);
void MostrarUnClientPorApell(stCliente Clientes[], int validos,char apellido[30]);
void MostrarUnClientPorNombr(stCliente Clientes[], int validos,char nombre[30]);
void MostrarUnClientPorNrCli(stCliente Clientes[], int validos,int nroCliente);
void MostrarUnClientPorId(stCliente Clientes[], int validos,int id);
void MostrarTodoClientInactiv (stCliente Clientes[],int validos);
void MostrarTodoClientActiv (stCliente Clientes[],int validos);
void MostrarTodoClient (stCliente Clientes[],int validos);
void MostrarUnCliente(stCliente Cliente);
int ValidacionDatosDni(stCliente Cliente[],char Dato[20],int validos);
int ValidacionDatosTel(stCliente Cliente[],char Dato[20],int validos);
int ValidacionDatosEmail(stCliente Cliente[],char Dato[20],int validos);
int ValidosdeGmail(char Gmail[]);
int ValidosdeYahoo(char Yahoo[]);
int ValidosdeHotmail(char Hotmail[]);
int ValidGeneMails(char email[]);
stCliente AltaDeCliente();



stCliente AltaDeCliente(){
stCliente Cliente;
char Aux[30];
int MailValido=0;

File* archi=fopen(nombreArchivo, "a+b");
if(archi){
 char opcion=0;

        fseek(archi,0,0)
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
    if((ValidGeneMails(Aux)=0)){
    while(ValidGeneMails(Aux)=0){
        printf("Mail Invalido, Ingrese nuevo mail");
        fflush(stdin);
        gets(Aux);
    }}
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

    }while(opcion=! 83 || opcion=! 115 );



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
    if(ValidacionDatosDni(Cliente.dni,Aux,Cliente.id/1000000)=1){
 while(ValidacionDatosDni(Cliente.dni,Aux,Cliente.id/1000000)=1){
    printf("Ingrese un DNI valido");
     fflush(stdin);
    gets(Aux);
    }
    }
    strcpy(Cliente.dni, Aux);



printf("\n Ingrese el Email....................: ");
    fflush(stdin);
    gets(Aux);
 while(MailValido==0){

    if((ValidGeneMails(Aux)=0)){
    while(ValidGeneMails(Aux)=0){
        printf("Mail Invalido, Ingrese nuevo mail");
         fflush(stdin);
        gets(Aux);
    }
    }


    if(ValidacionDatosEmail(Cliente.email,Aux,Cliente.id/1000000)=1){
 while(ValidacionDatosEmail(Cliente.email,Aux,Cliente.id/1000000)=1){
    printf("Mail ya existente, Ingrese otro");
     fflush(stdin);
    gets(Aux);
    }
    }
 }

    strcpy(Cliente.email, Aux);
printf("\n Ingrese el Domicilio................: ");
    fflush(stdin);
    gets(Cliente.domicilio);
printf("\n Ingrese el telefono.................: ");
   fflush(stdin);
    gets(Aux);
    if(ValidacionDatosTel(Cliente.telefono,Aux,Cliente.id/1000000)=1){
 while(ValidacionDatosTel(Cliente.telefono,Aux,Cliente.id/1000000)=1){
    printf("Ingrese un Telefono valido");
     fflush(stdin);
    gets(Aux);
    }
    }

    if(ValidacionDatosTel(Cliente.telefono,Aux,Cliente.id/1000000)=0){
    strcpy(Cliente.telefono, Aux);
    MailValido=1;
    }
     Cliente.eliminado=0;
     system("cls");
    MostrarUnCliente(Cliente);
    printf("Estan correctos los datos ingresados?\n");
    printf("Presione S para continuar...");
    fflush(stdin);
    opcion=getch();
}while(opcion=! 83 || opcion=! 115 );
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
printf("\n Estado del Cliente....: ")
if(Cliente.eliminado == 0){
    printf("Cliente Activo");
}else{
  printf("Cliente Inactivo");
}
printf("\n=====================================================================");
}

void MostrarTodoClient (stCliente Clientes[],int validos){
int i=0;
for(i=0;i<validos;i++){
 MostrarUnCliente(Clientes[i]);
}
}

void MostrarTodoClientActiv (stCliente Clientes[],int validos){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].eliminado == 0){
 MostrarUnCliente(Clientes[i]);
}
}
}
void MostrarTodoClientInactiv (stCliente Clientes[],int validos){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].eliminado == 1){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorId(stCliente Clientes[], int validos,int id){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].id == id){
 MostrarUnCliente(Clientes[i]);
}
}
}


void MostrarUnClientPorNrCli(stCliente Clientes[], int validos,int nroCliente){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].nroCliente == nroCliente){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorNombr(stCliente Clientes[], int validos,char nombre[30]){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].nombre == nombre){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorApell(stCliente Clientes[], int validos,char apellido[30]){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].apellido == apellido){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorDNI(stCliente Clientes[], int validos,char dni[12]){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].dni == dni){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorEM(stCliente Clientes[], int validos,char email[30]){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].email == email){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorDom(stCliente Clientes[], int validos,char domicilio[30]){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].domicilio == domicilio){
 MostrarUnCliente(Clientes[i]);
}
}
}

void MostrarUnClientPorTel(stCliente Clientes[], int validos,char telefono[30]){
int i=0;
for(i=0;i<validos;i++){
    if(Clientes[i].telefono == telefono){
 MostrarUnCliente(Clientes[i]);
}
}
}

void CambiarNombCli(stCliente Clientes[], int validos,char nombre[30]){
int i=0;
char cambio[30];
for(i=0;i<validos;i++){
    if(Clientes[i].nombre == nombre){
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
    gets(Clientes[i].nombre);
}
}
}

void CambiarApellCli(stCliente Clientes[], int validos,char apellido[30]){
int i=0;
char cambio[30];
for(i=0;i<validos;i++){
    if(Clientes[i].apellido == apellido){
            printf("Ingrese el nuevo Apellido: ");
            fflush(stdin);
    gets(Clientes[i].apellido);
}
}
}

void CambiarDniCli(stCliente Clientes[], int validos,char dni[30]){
int i=0;
char cambio[30];
for(i=0;i<validos;i++){
    if(Clientes[i].dni == dni){
            printf("Ingrese el nuevo DNI: ");
            fflush(stdin);
    gets(Clientes[i].dni);
}
}
}

void CambiarEmCli(stCliente Clientes[], int validos,char email[30]){
int i=0;
char cambio[30];
for(i=0;i<validos;i++){
    if(Clientes[i].email == email){
            printf("Ingrese el nuevo Email: ");
            fflush(stdin);
    gets(Clientes[i].email);
}
}
}

void CambiarDomCli(stCliente Clientes[], int validos,char domicilio[30]){
int i=0;
char cambio[30];
for(i=0;i<validos;i++){
    if(Clientes[i].domicilio == domicilio){
            printf("Ingrese el nuevo Domicilio: ");
            fflush(stdin);
    gets(Clientes[i].domicilio);
}
}
}
void CambiarTelCli(stCliente Clientes[], int validos,char telefono[30]){
int i=0;
char cambio[30];
for(i=0;i<validos;i++){
    if(Clientes[i].telefono == telefono){
            printf("Ingrese el nuevo Telefono: ");
            fflush(stdin);
    gets(Clientes[i].telefono);
}
}
}

void EliminarCliente(stCliente Cliente){
char opcion=0;
printf("\n Esta seguro de querer eliminar el Cliente?....");
printf("\n Presiona S para continuar....");
opcion=getch()
if(opcion== 83 || opcion== 115){
 Cliente.eliminado=1;
}
}


int ValidacionDatosDni(stCliente Cliente[],char Dato[20],int validos){
int flag=0;
int i=0;
while(i<validos && flag!=1){
    if(strcmp(Dato, Cliente.dni[i])= 0){
     flag=1
    }else{
    i++;
    }
}
return flag;
}
int ValidacionDatosEmail(stCliente Cliente[],char Dato[20],int validos){
int flag=0;
int i=0;
while(i<validos && flag!=1){
    if(strcmp(Dato, Cliente.email[i])= 0){
     flag=1
    }else{
    i++;
    }
}
return flag;
}


int ValidacionDatosTel(stCliente Cliente[],char Dato[20],int validos){
int flag=0;
int i=0;
while(i<validos && flag!=1){
    if(strcmp(Dato, Cliente.telefono[i])= 0){
     flag=1
    }else{
    i++;
    }
}
return flag;
}


int ValidosdeGmail(char Gmail[]){
char gmail[10];
strcpy(gmail,"@gmail.com");
int flag=0;
int contador=0;
int contadorgmail=10;
int i=0;
while(Cliente.email(i)!= '\0'){
contador++;
i++;
}
i= contador-10;
while(i!=contador && flag ==0){

if(Cliente.email[contador]== Gmail[contadorgmail]){
contador--;
contadorgmail--;
}else{
flag=1;
}
}
return flag;
}

int ValidosdeYahoo(char Yahoo[]){
char Yahoo[10];
strcpy(Yahoo,"@yahoo.com");
int flag=0;
int contador=0;
int contadorYahoo=10;
int i=0;
while(Cliente.email(i)!= '\0'){
contador++;
i++;
}
i= contador-10;
while(i!=contador && flag ==0){

if(Cliente.email[contador]== Yahoo[contadorYahoo]){
contador--;
contadorYahoo--;
}else{
flag=1;
}
}
return flag;
}



int ValidosdeHotmail(char Hotmail[]){
char Hotmail[10];
strcpy(Hotmail,"@hotmail.com");
int flag=0;
int contador=0;
int contadorhot=10;
int i=0;
while(Cliente.email(i)!= '\0'){
contador++;
i++;
}
i=contador-10;
while(i!=contador && flag ==0){

if(Cliente.email[contador]== Hotmail[contadohot]){
contador--;
contadorhot--;
}else{
flag=1;
}
}
return flag;
}

int ValidGeneMails(char email[]){
int flag=0;

if(ValidosdeGmail(email)=0){
    flag=1;
}else{
if(ValidosdeYahoo(email)=0){
    flag=1;
}else{
if(ValidosdeHotmail(email)=0}{
   flag=1;
   }
}

return flag;
}

