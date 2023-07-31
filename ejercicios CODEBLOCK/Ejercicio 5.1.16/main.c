/*Se ingresan DNI y la nota promedio de 10 alumnos.
Determinar el DNI del alumno de mayor nota promedio (considerar único).*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,DNI,nota,mayorn=0,mayordni=0;
    for(i=1;i<=3;i++)
    {
    printf("\nIngresa el DNI del alumno: ");
    scanf("%d",&DNI);
    printf("\nIngresa la nota promedio del alumno: ");
    scanf("%d",&nota);
        if(i==1||nota>mayorn)
        {
            mayorn=nota;
            mayordni=DNI;
        }
    }
    printf("El alumno con DNI %d es quien tiene mayor nota promedio",mayordni);
    return 0;
}
