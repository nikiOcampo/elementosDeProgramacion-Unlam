/*De cada uno de los alumnos de un curso se ingresa su número de DNI y
las notas de los dos exámenes parciales confeccionar, un programa que muestre por
cada alumno su condición final con el siguiente mensaje:
“El alumno con DNI: xxxxxxx, obtuvo las notas: xx y xx [condición final]”
La condición final se establece según las siguientes reglas:
• PROMOCIONA: ambas notas > = 7
• RINDE EXAMEN FINAL: ambas notas > = 4
• REPROBO LA MATERIA: alguna nota no cumple lo anterior
El programa finaliza cuando se ingresa un valor negativo como número de DNI.
 Al finalizar mostrar la nota promedio de alumnos promocionados*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int DNI;
    float nota1,nota2,promedio,cantprom=0,sumanotas;
    do{
        printf("\nIngrese el DNI del alumno: ");
        scanf("%d",&DNI);
        if(DNI<0)
            printf ("\nDNI incorrecto- fin del programa");
        else
        {
        printf("\nIngrese la nota del primer parcial: ");
        scanf("%f",&nota1);
        printf("\nIngrese la nota del segundo parcial: ");
        scanf("%f",&nota2);

            if(nota1>=7&&nota2>=7)
            {
               printf("\nEl alumno con DNI: %d obtuvo las notas: %f y %f PROMOCIONA ",DNI,nota1,nota2);
               cantprom+=2;
               sumanotas+=nota1+nota2;
               promedio=sumanotas/cantprom;
            }
            else
             {
                if(nota1>=4&&nota2>=4)
                printf("\nEl alumno con DNI: %d obtuvo las notas: %f y %f RINDE EXAMEN FINAL",DNI,nota1,nota2);
                else
                printf("\nEl alumno con DNI: %d obtuvo las notas: %f y %f REPROBO LA MATERIA ",DNI,nota1,nota2);
             }
        }
    }while(DNI>0);
    printf("\nLa nota promedio de alumnos promocionados es de: %f",promedio);

    return 0;
}
