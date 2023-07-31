#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Cod;
    float Valor, Pi,New_valor;
    printf("Ingrese el valor de su medida: ");
    scanf("%f",&Valor);
    printf("Ingrese el codigo de sistema de medida,siendo 1 para grados y 2 para readianes: ");
    scanf("%d",&Cod);
    Pi= 3.1416;
    if(Cod==1)
    {
        New_valor= Valor*Pi/180;
        printf("Su valor pasado a radianes es de: %f",New_valor);
    }
    else
    {
        New_valor=Valor*180/Pi;
        printf("Su valor pasado a grados es de: %f",New_valor);
    }

    return 0;
}
