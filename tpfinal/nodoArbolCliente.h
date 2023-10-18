#ifndef NODOARBOLCLIENTE_H_INCLUDED
#define NODOARBOLCLIENTE_H_INCLUDED
#include "cliente.h"

typedef struct _nodoArbolCliente{
	stCliente dato;
	celdaCuentas* arregloCuentas; /// el arreglo puede ser estático o dinámico.
	struct _nodoArbolCliente* izq;
	struct _nodoArbolCliente* der;
}nodoArbolCliente;

///Muestra de Cuentas

void muestraCuentaXcliente(nodoArbolCliente* cliente,char apellido[], char nombre[]);
void muestraCuentaXtipo(nodoArbolCliente* cliente,char tipoDeCuenta[]);
void muestraCuentaTodas(nodoArbolCliente* cliente);
void muestraCuentaActivas(nodoArbolCliente* cliente);
void muestraCuentaInctivas(nodoArbolCliente* cliente);

/// Funciones de Cliente

///Muestra con filtro
void muestraXnombre(nodoArbolCliente* Arbol, char nombre[]);
void muestraXapellido(nodoArbolCliente* Arbol, char apellido[]);
void muestraXdni(nodoArbolCliente* Arbol, char DNI[]);
void muestraXemail(nodoArbolCliente* Arbol, char mail[]);
void muestraXdomicilio(nodoArbolCliente* Arbol, char domicilio[]);
void muestraXtelefono(nodoArbolCliente* Arbol, char telefono[]);
void muestraXnumCliente(nodoArbolCliente* Arbol, int numCliente);
void muestraXid(nodoArbolCliente* Arbol, int id);
void muestraActivos(nodoArbolCliente* Arbol);
void muestraiNctivos(nodoArbolCliente* Arbol);

/// Modificacion

void modificaNombre(nodoArbolCliente* Arbol,int numCliente);
void modificaApellido(nodoArbolCliente* Arbol,int numCliente);
void modificaDNI(nodoArbolCliente* Arbol,int numCliente);
void modificaEmail(nodoArbolCliente* Arbol,int numCLiente);
void modificaDomicilio(nodoArbolCliente* Arbol,int numCliente);
void modificaTelefono(nodoArbolCliente* Arbol,int numCliente);


/// Carga

int crearId(nodoArbolCliente* Arbol);
int crearNumeroCliente(char nombreArchivo[]);
int controlDNI(nodoArbolCliente* Arbol, char dni[]);
int controlEmail (nodoArbolCliente* Arbol,char email[]);
int EmailValido (nodoArbolCliente* Arbol,char email[]);
stCliente cargaUnCliente(nodoArbolCliente* Arbol);

/// ELIMINA
void eliminarCliente(nodoArbolCliente* Arbol, char nombre[],char apellido[]);






#endif // NODOARBOLCLIENTE_H_INCLUDED
