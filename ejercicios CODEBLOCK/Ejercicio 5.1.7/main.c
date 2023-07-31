/*5.1.7 Dadas 20 notas y legajos de alumnos de un curso. Determinar:
a. Cantidad de alumnos aplazados.
b. Cuando la nota sea mayor a 7, mostrar el mensaje: “El alumno con legajo xxx ha Promocionado”.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota,legajo,CantAplazos=0,i;
    for(i=1;i<=20;i++)
    {
        printf("\nIngrese la nota del alumno: ");
        fflush(stdin);
        scanf("%d",&nota);
        printf("\nIngrese el legajo del alumno: ");
        fflush(stdin);
        scanf("%d",&legajo);
        if(nota<4)
            CantAplazos++;
        if(nota>7)
            printf("El alumno con legajo %d ha promocionado",legajo);
    }
    printf("\nLa cantidad de alumnos aplazados son: %d",CantAplazos);
    return 0;
}
