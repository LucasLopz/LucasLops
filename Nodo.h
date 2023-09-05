#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
typedef struct{
int ID;
int Edad;
char G;
}Datos;

typedef struct{
struct Datos* dato;
struct Nodo * sig;
}Nodo;

#endif // NODO_H_INCLUDED
