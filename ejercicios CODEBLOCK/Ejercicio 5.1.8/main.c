/*Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:
a. Edad promedio.
b. Estatura promedio.
c. Cantidad de alumnos mayores de 10 años.
d. Cantidad de alumnos que miden menos de 1.40 cm.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,edad,estatura,suma_edad,suma_est,cant10,cant140;
    float prome_edad,prome_est;
    suma_edad=suma_est=cant10=cant140=0;
    for(i=1;i<=45;i++)
    {
        printf("\nIngrese la edad del alumno: ");
        fflush(stdin);
        scanf("%d",&edad);
        printf("\nIngrese la estatura del alumno en cm: ");
        fflush(stdin);
        scanf("%d",&estatura);
        suma_edad+=edad;
        suma_est+=estatura;
        if(edad<10)
            cant10++;
        if(estatura<140)
            cant140++;
    }
    if(cant10>0)
        printf("\nCantidad de alumnos menores de 10: %d",cant10);
    if(cant140>0)
        printf("\nCantidad de alumnos que miden menos de 1.40:%d ",cant140);
    prome_edad=(float)suma_edad/45;
    prome_est=(float)suma_est/45;
    printf("\n\nLa edad promedio es de %f",prome_edad);
    printf("\n\nLa estatura promedio es de %f",prome_est);
    return 0;
}
