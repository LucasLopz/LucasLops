#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct {
int id; /// campo único y autoincremental
int nroCliente;
char nombre[30];
char apellido[30];
char dni[10];
}stCliente;


void MostrarUnCliente(stCliente Cliente);
stCliente AltaDeCliente();



#endif // CLIENTE_H_INCLUDED
