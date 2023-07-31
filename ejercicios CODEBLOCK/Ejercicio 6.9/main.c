/*Realizar una función que reciba 3 números enteros correspondientes al día,
mes y año de una fecha y valide si la misma es correcta. En caso de que la fecha
es correcta debe retornar un 1 y si es incorrecta debe retornar un 0.
Para la validación usar la función del punto 8 que retorna la cantidad de días de un mes.*/

#include <stdio.h>
#include <stdlib.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );


int main()
{
    int dia,mes,anio,validacion;
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    printf("Ingrese un mes: ");
    scanf("%d",&mes);
    printf("Ingrese un dia: ");
    scanf("%d",&dia);
    validacion=ValidarFecha(anio,mes,dia);
    if(validacion==1)
        printf("Fecha Valida");
    else
        printf("Fecha Invalida");
    return 0;
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

