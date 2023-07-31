/*9.3. Se sabe que como m�ximo en una comisi�n de Elementos de Programaci�n hay 80 alumnos. De cada alumno se conoce:
� N�mero de DNI (entero).
� Apellido y Nombre (80 caracteres).
� Nota1, Nota2 (entero).
� Nota Promedio (real, calculado seg�n Nota1 y Nota2).
Se solicita:
a. Declarar un tipo de dato que contenga la informaci�n del alumno.
b. Declarar un vector de estructuras del tipo de dato creado en el punto a.
c. Cargar en un vector de estructuras, los datos referentes a los alumnos de la
comisi�n, esta informaci�n termina con DNI igual al 0. Funci�n INGRESO.
d. Indicar cu�ntos alumnos aprobaron (ambos parciales con nota >= 4 y cu�ntos reprobaron la materia. Funci�n RESULTADO.
e. Informar los datos de los alumnos de (DNI � Apellido y Nombre � Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Funci�n INFORME_PROMO.*/


//Trabajo con Ejercicio 9.3
// solo modificar
// 1) Cargarlo en CODE BLOCK y en pantalla siempre debe verse Alumno Nombre ________ Apellido_________
// 2) Este programa tiene validaciones, con (do while) que se pueden realizar con funciones que validen, permitiendo mejorarlo
// 3) Completar el còdigo con un punto mas
//         f. Informar los datos cargados en estructura (DNI - Apellido y Nombre  - Nota 1 - Nota 2 - Promedio) de todos
//            informando al final Cantidad de cargados. Ej. "Se cargaron en este proceso 7 Alumnos"
// 4) Cuando termine envie por Mensaje el .c para probar los cambios, controle que funcione Gracias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nota1;
    int nota2;
}NOTAS;
//Declarar un tipo de dato que contenga la informaci�n del alumno.
typedef struct
{
    int nro_dni;
    char nom_apel[80];
    NOTAS nota;
    float nota_promed;
}alumno;

int ingreso (alumno[], int);
int buscar (alumno[],int,int);
void resultado (alumno[],int);
void informe_promo (alumno[],int);
int validar_entero (int,int);
void punto_f (alumno[],int);

int main()
{
    //Declarar un vector de estructuras del tipo de dato creado en el punto a.
    alumno alum[80];
    int cant;
    printf("                                                    OCAMPO NICOLE");
    cant=ingreso(alum,80);
    resultado(alum,cant);
    informe_promo(alum,cant);
    punto_f(alum,cant);
    return 0;
}

/*Cargar en un vector de estructuras, los datos referentes a los alumnos de la
comisi�n, esta informaci�n termina con DNI igual al 0. Funci�n INGRESO.*/
int ingreso (alumno alum[],int max)
{
    int i=0,pos,dato;
    do
    {
        printf("\nIngrese el nro de DNI del alumno[Salida 0]: ");
        scanf("%d",&dato);
        pos=buscar(alum,dato,i);
        if(pos!=-1)
                printf("Ya se han registrado datos para este alumno.\n");
    }while(dato<0||pos!=-1);
    while (i<max&&dato!=0)
    {
        alum[i].nro_dni=dato;
        do
        {
            printf("\nIngrese el apellido y nombre del alumno: ");
            fflush(stdin);
            gets(alum[i].nom_apel);
        }while(strlen(alum[i].nom_apel)<1||strlen(alum[i].nom_apel)>79);
        alum[i].nota.nota1=validar_entero(0,10);
        alum[i].nota.nota2=validar_entero(0,10);
        alum[i].nota_promed=(float)(alum[i].nota.nota1+alum[i].nota.nota2)/2;
        i++;
        if(i<max)
        {
            do
            {
                printf("\nIngrese el nro de DNI del alumno[Salida 0]: ");
                scanf("%d",&dato);
                pos=buscar(alum,dato,i);
                if(pos!=-1)
                        printf("Ya se han registrado datos para este alumno.\n");
            }while(dato<0||pos!=-1);
        }
        else
            printf("\nYa se cargo el maximo de alumnos");
    }
    return i;
}

int buscar(alumno v[], int dato, int tam)
{
    int i=0, pos=-1;
    while (pos==-1 && i<tam)
    {
        if (v[i].nro_dni == dato)
            pos =i;
        else
            i++;
    }
    return pos;
}

//Indicar cu�ntos alumnos aprobaron (ambos parciales con nota >= 4 y cu�ntos reprobaron la materia. Funci�n RESULTADO.
void resultado(alumno alum[],int n)
{
    int x,cont=0,cont2=0;
    system("cls");
    printf("                                                    OCAMPO NICOLE");
    for(x=0;x<n;x++)
    {
        if(alum[x].nota.nota1>=4&&alum[x].nota.nota2>=4)
            cont++;
        else
            cont2++;
    }
    printf("\n%d alumnos APROBARON la materia",cont);
    printf("\n%d alumnos REPROBARON la materia",cont2);
}

/*Informar los datos de los alumnos de (DNI � Apellido y Nombre � Nota Promedio) de los alumnos.
PROMOCIONADOS (ambas notas >= 7). Funci�n INFORME_PROMO.*/
void informe_promo (alumno alum[],int n)
{
    int x;
    printf("\n\tALUMNOS PROMOCIONADOS");
    printf("\nDNI\tAPELLIDO Y NOMBRE\tNOTA PROMEDIO");
    for(x=0;x<n;x++)
    {
        if(alum[x].nota.nota1>=7&&alum[x].nota.nota2>=7)
            printf("\n%d\t%s\t\t\t%0.2f",alum[x].nro_dni,alum[x].nom_apel,alum[x].nota_promed);
    }
}

int validar_entero(int i,int s)
{
    int dato;
    do
    {
        printf("\nIngrese la nota: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

////         f. Informar los datos cargados en estructura (DNI - Apellido y Nombre  - Nota 1 - Nota 2 - Promedio) de todos
//            informando al final Cantidad de cargados. Ej. "Se cargaron en este proceso 7 Alumnos"
void punto_f(alumno alum[],int n)
{
    int x;
    printf("\nDATOS DE TODOS LOS ALUMNOS");
    printf("\nDNI\tAPELLIDO Y NOMBRE\tNOTA 1\tNOTA 2\tPROMEDIO");
    for(x=0;x<n;x++)
    {
        printf("\n%d\t%s\t\t%d\t%d\t%0.2f",alum[x].nro_dni,alum[x].nom_apel,alum[x].nota.nota1,alum[x].nota.nota2,alum[x].nota_promed);
    }
    printf("\nSe cargaron en este proceso %d alumnos",n);
}
