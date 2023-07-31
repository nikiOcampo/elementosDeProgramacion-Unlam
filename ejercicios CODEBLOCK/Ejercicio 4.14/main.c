#include <stdio.h>
#include <stdlib.h>

int main()
{
    float importe, descuento,new_importe;
    printf("Ingrese el importe de su compra: ");
    scanf("%f",&importe);
    if(importe<=55)
    {
        descuento= importe*0.045;
        new_importe=importe-descuento;
        printf("Se aplico un descuento del 4.5 porciento");
        printf("\n\nNeto a cobrar: %f", new_importe);
    }
    else
    {
        if(importe<=100)
        {
            descuento= importe*0.08;
            new_importe=importe-descuento;
            printf("Se aplico un descuento del 8 porciento.");
            printf("\n\nNeto a cobrar:%f", new_importe);
        }
        else
        {
            descuento= importe*0.105;
            new_importe=importe-descuento;
            printf("Se aplico un descuento del 10,5 porciento.");
            printf("Neto a cobrar= %f", new_importe);
        }
    }
    return 0;
}
