/*10.1. Los datos de los alumnos de una comisión de Computación Transversal son:
• Número de DNI (entero)
• Nombre y Apellido (80 caracteres)
• Nota1, Nota2 (entero)
• Nota Promedio (real, calculado según Nota1 y Nota2)
a. Declarar un tipo de dato que contenga la información del alumno.
b. Con la información indicada para los alumnos. Grabar los datos en el archivo “ALUMNOS.dat”. Esta información
de grabación finaliza con DNI cero.
c. Leer los datos del archivo, mediante la Función LECTURA.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nota1;
    int nota2;
}NOTAS;

typedef struct
{
    int dni;
    char nombre_apel[81];
    NOTAS nota;
    float nota_promedio;
}alumno;

int validar_entero (int,int);
void LECTURA ();

int main()
{
    alumno alum;
    FILE*fp;
    fp=fopen ("ALUMNOS.dat", "wb");
    if (fp==NULL)
    {
        printf("Error al abrir el archivo.");
        exit(1);
    }
    do
    {
        printf ("\nIngrese dni del alumno [Salida 0]:");
        scanf("%d", &alum.dni);
    }while(alum.dni<0);
    while (alum.dni>0)
    {
        do
        {
            printf ("\nIngrese el nombre y apellido:");
            fflush(stdin);
            gets(alum.nombre_apel);
        }while(strlen(alum.nombre_apel)<1||strlen(alum.nombre_apel)>80);
        alum.nota.nota1=validar_entero(1,10);
        alum.nota.nota2=validar_entero(1,10);
        alum.nota_promedio=(float)(alum.nota.nota1+alum.nota.nota2)/2;
        fwrite(&alum,sizeof(alumno),1,fp);
        do
        {
            printf ("\nIngrese dni del alumno [Salida 0]:");
            scanf("%d", &alum.dni);
        }while(alum.dni<0);
    }
    fclose(fp);
    LECTURA();
    return 0;
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

void LECTURA()
{
    alumno Alu;
    FILE *A_01;
    A_01 = fopen("ALUMNOS.dat","rb");
    if(A_01==NULL)
    {
        puts("Error en apertura de Archivo");
        exit(0);
    }
    fread(&Alu,sizeof(alumno),1,A_01);
    while(!feof(A_01))
    {
      printf("\n Numero de DNI     : %d",Alu.dni);
      printf("\n Nombre y Apellido : %s",Alu.nombre_apel);
      printf("\n Nota 1            : %d",Alu.nota.nota1);
      printf("\n Nota 2            : %d",Alu.nota.nota2);
      printf("\n Promedio          : %.2f\n\n",Alu.nota_promedio);
      fread(&Alu,sizeof(alumno),1,A_01);
    }
   fclose(A_01);
}
