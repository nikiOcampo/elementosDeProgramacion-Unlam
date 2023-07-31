/*Realizar un programa que ingrese la fecha actual y la fecha de nacimiento de una persona y calcule su edad.
Para validar las fechas utilizar la función del punto 9.
Para el cálculo realizar una función que reciba las dos fechas y retorne la edad de la persona.*/

#include <stdio.h>
#include <stdlib.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );
int EDAD (int,int,int,int,int,int);

int main()
{
    int diaHoy,mesHoy,anioHoy,diaNac,mesNac,anioNac,edad,validacion1,validacion2;
    printf("\nIngrese dia  hoy:");
    scanf("%d",&diaHoy);
    printf("\nIngrese mes  hoy:");
    scanf("%d",&mesHoy);
    printf("\nIngrese anio hoy:");
    scanf("%d",&anioHoy);
    validacion1=ValidarFecha(diaHoy,mesHoy,anioHoy);
    if(validacion1==0)
    {
        printf("Fecha valida");
        printf("\n\n Ingrese dia Nacimiento :");
        scanf("%d",&diaNac);
        printf("\nIngrese mes  Nacimiento:");
        scanf("%d",&mesNac);
        printf("\nIngrese anio Nacimiento:");
        scanf("%d",&anioNac);
        validacion2=ValidarFecha(diaNac,mesNac,anioNac);
        if(validacion2==1)
            printf("Fecha invalida");
        else
        {
            printf("Fecha Valida");
            edad=EDAD(anioHoy,mesHoy,diaHoy,anioNac,mesNac,diaNac);
            printf("nLa persona tiene %d anios",edad);
        }
    }
    else
        printf("Fecha Invalida");
    return 0;
}

int EDAD(int ahoy, int mhoy, int dhoy, int anac, int mnac, int dnac)
{
    int edad;
    edad=ahoy-anac;
    if(mnac>mhoy)
        edad=edad-1;
    else
    {
        if(dnac>dhoy)
            edad=edad-1;
    }
    return edad;
}

int DIAS (int a, int m)
{
    int d;
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            d=30;
            break;
        case 2:
            if((a%4==0&&a%100!=0)||(a%400==0))
                d=29;
            else
                d=28;
            break;
    }
    return d;
}

int ValidarFecha (int a, int m, int d)
{
    int c,dias;
    if (m<1||m>12)
        c=0;
    dias=DIAS(a,m);
    if(d<=dias)
        c=1;
    else
        c=0;
    return c;
}

