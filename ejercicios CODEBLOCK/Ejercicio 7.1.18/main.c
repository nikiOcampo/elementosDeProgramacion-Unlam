/*Se procesan los datos de los casi 90 alumnos de un turno de la materia Elementos de Programaci�n. Por cada alumno se ingresan:
� DNI (entero, mayor que cero y menor que 99.999.999).
� Nota del Parcial 1 (entero, de 0 a 10).
� Nota del Parcial 2 (entero, de 0 a 10).
� Porcentaje de asistencia (real, mayor o igual a cero).
Para finalizar, se ingresa un DNI igual a cero.
Se pide informar con las leyendas aclaratorias y/o t�tulos:
a. Seg�n los parciales si promocion�, aprob�, reprob� o estuvo ausente (uno o ambos parciales igual a cero).
b. Listar los alumnos que no cumplen con la asistencia (mayor o igual a 75%).
c. Informar cu�ntos alumnos que promocionaron NO cumplen en la asistencia.
d. Informar los alumnos que sacaron 10 en el parcial 2.
e. Informar los alumnos con menor asistencia (puede haber varios).
f. Al finalizar, informar el promedio total de notas de cada parcial y de asistencia.*/

#include <stdio.h>
#include <stdlib.h>
//____________________
//FUNCIONES DESARROLLO
void blanco(int [],int);
int valida(int ,int ,int );
float valida_Flotante(float);
void Mostrar_Punto_a(int[],int[],int[],int);
void Mostrar_Punto_b(int[], float[],int);
void Mostrar_Punto_c(int[], int[], float[],int);
void Mostrar_Punto_d(int[],int[],int);
void Mostrar_Punto_e(int[], float[], int);
void Mostrar_Punto_f(int[], int[], float[],int);
//____________________

int main()
{
    int dni_alumnos[90], nota1[90],nota2[90],dni,x=0;
    float asistencia[90]={0};
    blanco(dni_alumnos,90);
    blanco(nota1,90);
    blanco(nota2,90);
    dni= valida(0,99999999,1);
    while(dni!=0)
    {
        x++;
        dni_alumnos[x-1]=dni;
        nota1[x-1]= valida(0,10,2);
        nota2[x-1]= valida(0,10,3);
        asistencia[x-1]= valida_Flotante(0);
        system("cls");
        dni=valida(0,99999999,1);
    }
    system("cls");
    Mostrar_Punto_a(dni_alumnos,nota1,nota2,x);
    Mostrar_Punto_b(dni_alumnos,asistencia,x);
    Mostrar_Punto_c(nota1,nota2,asistencia,x);
    Mostrar_Punto_d(dni_alumnos,nota2,x);
    Mostrar_Punto_e(dni_alumnos,asistencia,x);
    Mostrar_Punto_f(nota1,nota2,asistencia,x);
  return 0;
}
//____________________
//FUNCIONES DESARROLLO
void blanco(int a[],int n)
{
 int x;
 for(x=0;x<n;x++)
 {
  a[x]=0;
 }
};
//__________________________
int valida(int i,int f,int t)
{
	int dato;
	do
	{
	  printf("\n Ingrese ");
	  if(t==1)printf(" Nro. DNI [1 a 99.999.999] Sale 0:");
      if(t==2)printf(" Nota 1er Parcial [0 a 10]:");
      if(t==3)printf(" Nota 2do Parcial [0 a 10]:");
	  scanf("%d",&dato);
	}while(dato<i||dato>f);
 return dato;
}
//___________________________________________
float valida_Flotante(float x)
{
	float dato;
	do
	{
	  printf("\n Ingrese Porcentaje asistencia[mayor o igual a cero]:");
	  scanf("%f",&dato);
	}while(dato<x);
  return dato;
}
//a. Seg�n los parciales si promocion�, aprob�, reprob� o estuvo ausente (uno o ambos parciales igual a cero).
void Mostrar_Punto_a( int dni[], int not1[], int not2[], int n )
{
	int x;
	for(x=0;x<n;x++)
    {
        if(not1[x]>=7&&not2[x]>=7)
        {
            printf("\nEl alumno con DNI %d PROMOCIONO la materia con las siguientes notas: ",dni[x]);
            printf("\nNota primer parcial: %d\nNota segundo parcial: %d",not1[x],not2[x]);
        }
        if(not1[x]>=4&&not2[x]>=4&&(not1[x]<7||not2[x]<7))
        {
            printf("\nEl alumno con DNI %d APROBO la materia con las siguientes notas: ",dni[x]);
            printf("\nNota primer parcial: %d\nNota segundo parcial: %d",not1[x],not2[x]);
        }
        if((not1[x]<4||not2[x]<4)&&(not1[x]!=0&&not2[x]!=0))
        {
            printf("\nEl alumno con DNI %d REPROBO la materia con las siguientes notas: ",dni[x]);
            printf("\nNota primer parcial: %d\nNota segundo parcial: %d",not1[x],not2[x]);
        }
        if(not1[x]==0||not2[x]==0)
        {
            printf("\nEl alumno con DNI %d  estuvo AUSENTE a algun parcial ",dni[x]);
            printf("\nNota primer parcial: %d\nNota segundo parcial: %d",not1[x],not2[x]);
        }
    }
}
//b. Listar los alumnos que no cumplen con la asistencia (mayor o igual a 75%).
void Mostrar_Punto_b( int dni[], float asis[], int n )
{
	int x;
    printf("\nLISTA DE ALUMNOS QUE NO CUMPLEN CON LA ASISTENCIA:");
    printf("\nDNI:\tPORCENTAJE DE ASISTENCIA:");
	for (x=0;x<n;x++)
    {
        if(asis[x]<=75)
        {
            printf("\n%d\t\t%f",dni[x],asis[x]);
        }
    }
}
//c. Informar cu�ntos alumnos que promocionaron NO cumplen en la asistencia.
void Mostrar_Punto_c( int not1[],int not2[],float asis[], int n )
{
	int x,j=0;
	for(x=0;x<n;x++)
    {
        if(not1[x]>=7&&not2[x]>=7&&asis[x]<=75)
            j++;
    }
    printf("\nLa cantidad de alumnos PROMOCIONADOS que NO cumplen con la asistencia son: %d",j);

}
//d. Informar los alumnos que sacaron 10 en el parcial 2.
void Mostrar_Punto_d( int dni[], int not2[], int n )
{
	int x;
	printf("\nALUMNOS QUE SE SACARON 10 EN EL SEGUNDO PARCIAL");
	for(x=0;x<n;x++)
    {
        if(not2[x]==10)
            printf("\n%d",dni[x]);
    }
}
//e. Informar los alumnos con menor asistencia (puede haber varios).
void Mostrar_Punto_e( int dni[], float asis[], int n )
{
	int x;
	float min;
	min=asis[0];
	for(x=1;x<n;x++)
    {
        if(asis[x]<min)
            min=asis[x];
    }
    printf("\nLa menor asistencia fue de %f, dada por el/los alumnos con DNI: ",min);
    for(x=0;x<n;x++)
    {
        if(asis[x]==min)
        printf("\n%d",dni[x]);
    }
}
//f. Al finalizar, informar el promedio total de notas de cada parcial y de asistencia.
void Mostrar_Punto_f( int not1[], int not2[], float asis[], int n )
{
	int x;
	float prom_primer, prom_segundo,prom_asistencia;
	float acumul_not1=0,acumul_not2=0,acumul_asis=0;
	for(x=0;x<n;x++)
    {
        acumul_not1+=not1[x];
        acumul_not2+=not2[x];
        acumul_asis+=asis[x];
    }
    prom_primer=(float)acumul_not1/x;
    prom_segundo=(float)acumul_not2/x;
    prom_asistencia=(float)acumul_asis/x;
	printf("\nEl promedio total de notas del primer parcial fue de %f",prom_primer);
	printf("\nEl promedio total de notas del segundo parcial fue de %f",prom_segundo);
	printf("\nEl promedio total de las asistencias fue de %f",prom_asistencia);
}
