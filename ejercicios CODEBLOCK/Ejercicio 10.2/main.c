/*10.2. Tomando como base el archivo ALUMNOS.DAT creado en el ejercicio anterior
 se desea desarrollar un programa que, basado en la información del archivo, genere 3 archivos:
• Uno con los alumnos PROMOCIONADOS (ambas notas mayores o igual a 7).
• Otro archivo con los alumnos en condición CURSADO (ambas notas mayores o igual a 4 pero no promocionados).
• Y un tercer archivo con los REPROBADOS (al menos una nota, menor que 4).
Para comprobar los datos guardados realizar una función que reciba por parámetro el nombre
 del archivo a mostrar, lo abre y muestre su contenido. Se debe invocar a la función 3 veces para
 mostrar todos los archivos generados.*/

#include <stdio.h>
#include <stdlib.h>

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

int Lee_datos(alumno [],int );
void carga_vector(alumno [],int);
void mostrar_carga(char [10]);


int main()
{
    int cant=0;
    alumno alu[100];
    cant=Lee_datos(alu,100);
    carga_vector(alu,cant);
    printf("\nAlumnos promocionados: ");
    mostrar_carga("promo.dat");
    system("pause");
    printf("\nAlumnos cursados: ");
    mostrar_carga("curso.dat");
    system("pause");
    printf("\nAlumnos reprobados: ");
    mostrar_carga("repro.dat");
    system("pause");
    return 0;
}

void mostrar_carga(char t[10])
{
     alumno aux;
     FILE * rr;
     rr=fopen(t,"rb");
     if(rr==NULL) {puts("Error en generacion de Archivo");exit(1);}
     fread(&aux,sizeof(alumno),1,rr);
     while(!feof(rr))
     {printf("\n DNI : %d",aux.dni);
      printf("\n Nombre y Apellido : %s",aux.nombre_apel);
      printf("\n Nota 01: %d",aux.nota.nota1);
      printf("\n Nota 02: %d",aux.nota.nota2);
      printf("\n Promedio: %6.2f\n",aux.nota_promedio);
      fread(&aux,sizeof(alumno),1,rr);
 }
 fclose(rr);
}

int Lee_datos(alumno a[],int n )
{
     int i=0;
     FILE * rr;
     rr=fopen("ALUMNOS.dat","rb");
     if(rr==NULL) {puts("Error en generacion de Archivo");exit(1);}
     fread(&a[i],sizeof(alumno),1,rr);
     while(!feof(rr)&&i<n)
     {
          i++;
          fread(&a[i],sizeof(alumno),1,rr);
     }
     fclose(rr);
     return i;
}
void carga_vector(alumno a[],int n)
{
 int i;
     alumno aux;
     FILE * r1;
     r1=fopen("promo.dat","wb");
     if(r1==NULL) {puts("Error en generacion de Archivo");exit(1);}
     FILE * r2;
     r2=fopen("curso.dat","wb");
     if(r2==NULL) {puts("Error en generacion de Archivo");exit(1);}
     FILE * r3;
     r3=fopen("repro.dat","wb");
     if(r3==NULL) {puts("Error en generacion de Archivo");exit(1);}
     for(i=0;i<n;i++)
      {
       if(a[i].nota.nota1>=7&&a[i].nota.nota2>=7)
         {
           aux=a[i];
           fwrite(&aux,sizeof(alumno),1,r1);
         }
       else
        {
         if(a[i].nota.nota1>=4&&a[i].nota.nota2>=4)
          {
           aux=a[i];
           fwrite(&aux,sizeof(alumno),1,r2);
          }
         else
          {
           aux=a[i];
           fwrite(&aux,sizeof(alumno),1,r3);
          }
        }
       }
     fclose(r1);
     fclose(r2);
     fclose(r3);
}
