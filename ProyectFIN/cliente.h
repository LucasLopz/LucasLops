#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

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
stCliente AltaDeCliente();


#endif // CLIENTE_H_INCLUDED
