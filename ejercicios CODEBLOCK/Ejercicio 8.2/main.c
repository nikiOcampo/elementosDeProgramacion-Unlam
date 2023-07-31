/*8.2. Ingresar dos Strings, uno con el nombre y el otro con el apellido de una persona.
Utilizando las funciones de la biblioteca string.h generar un tercer string formado por: NOMBRE,
 APELLIDO (nombre coma espacio y apellido) y mostrarlo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[20],apellido[20];
    printf("Ingrese su nombre: ");
    gets(nombre);
    printf("\nIngrese su apellido: ");
    gets(apellido);
    strcat(nombre,", ");
    strcat(nombre,apellido);
    printf("\nEl nombre completo es: %s",nombre);
    return 0;
}
