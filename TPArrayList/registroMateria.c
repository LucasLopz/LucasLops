#include "materia.h"

void muestraUnaMateria(stMateria materia){

printf("\n =======================================================================");
printf("Nombre de la materia...............: %s", materia.materia);
printf("Nombre del alumno..................: %s", materia.nombreAlumno);
printf("Apellido del alumno................: %s", materia.apellidoAlumno);
printf("Nota del Alumno....................: %d", materia.nota);
printf("==========================================================================");


}
