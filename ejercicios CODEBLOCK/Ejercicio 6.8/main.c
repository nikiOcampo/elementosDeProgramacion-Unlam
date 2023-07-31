/*Realizar una función que, dado un mes y un año, calcule la cantidad de días de dicho mes.
El año se utilizará en el caso de que el mes sea febrero ya que los años bisiestos tienen 29 días en lugar de 28.
 Un año es bisiesto cuando: (el año es divisible por 4 y NO por 100) o (el año es divisible por 400).*/

#include <stdio.h>
#include <stdlib.h>

int DIAS(int, int );

int main()
{
    int anio,mes,dias;
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    do
    {
        printf("\nIngrese un mes [del 1 al 12]: ");
        scanf("%d",&mes);
        if(mes<1||mes>12)
            printf("\nEl mes ingresado es inexistente");
    }while(mes<1||mes>12);
    dias=DIAS(anio,mes);
    printf("\nEl mes cargado tiene %d dias", dias);
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
