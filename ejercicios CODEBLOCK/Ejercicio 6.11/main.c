/*Realizar una función que permita sumar n días a una fecha válida mostrando la fecha resultante.
 Si la fecha recibida no es válida informarlo con un mensaje (validar utilizando la función del punto 9).*/

#include <stdio.h>
#include <stdlib.h>
int CantidadDias(int,int);
int ValidaFecha(int,int,int);

int main ()
{
    int dia,dia2,mes,anio,validacion,sumar;
    printf("Ingrese un dia: ");
    scanf("%d",&dia);
    printf("Ingrese un mes: ");
    scanf("%d",&mes);
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    validacion=ValidaFecha(dia,mes,anio);
    if (validacion==0)
        printf("La fecha ingresada %d/%d/%d es incorrecta.\n\n",dia,mes,anio);
    else
        {
            printf("Ingrese la cantidad de dias a sumar: ");
            scanf("%d",&sumar);
            validacion=CantidadDias(mes,anio);
            dia2=dia+sumar;
            while(validacion<dia2)
            {
             dia2-=validacion;
             if(mes==12)
             {
                 mes=1;
                 anio++;
             }
             else mes++;
             validacion=CantidadDias(mes,anio);
            }
            printf("La fecha nueva queda: %d/%d/%d\n",dia2,mes,anio);
        }
    return 0;
}
int CantidadDias(int mes, int anio)
{
    switch(mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31; break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30; break;
        case 2:
            if((anio%4==0&&anio%100!=0)||anio%400==0)
                return 29;
            else
                return 28;
            break;
        default: return 0;
    }
}
int ValidaFecha(int dd,int mm,int aa)
{
    int dias;
    dias=CantidadDias(mm,aa);
    if(dd>dias)
        return 0;
    else
        if(dd<=dias&&dd>0)
            return 1;
        else
            return 0;
}
