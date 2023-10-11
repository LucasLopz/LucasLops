#ifndef ARRAYLIST_H_INCLUDED
#define ARRAYLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include "nodoAlumno.h"
#include "registroMateria.h"


typedef struct{
char materia[20];
struct nodoAlumno* lista;
}celda;

int ingresarNotas(celda adl[],int dim)
int alta(celda adl[],char alumno[],int nota, char materia[],int validos)
int buscarPosMateria(celda adl[],char materia[],int validos)
int agregarMateria (celda adl[],char materia[],int validos)



#endif // ARRAYLIST_H_INCLUDED
