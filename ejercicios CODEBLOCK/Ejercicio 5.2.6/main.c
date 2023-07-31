/*Un negocio de perfumería efectúa descuentos en sus ventas según el importe de las mismas, con la siguiente escala:
• menor a 50 pesos el 3.5 %
• entre 50 y 150 pesos el 10 %
• entre 151 y 300 pesos el 20 %.
• mayor a 300 pesos el 25 %
Confeccionar un programa que:
a. Solicite un importe y calcule el descuento a efectuar y el importe neto a cobrar, con mensajes aclaratorios.
b. Informe el importe promedio de todas las ventas realizadas.
Se debe contemplar que se puedan ingresar varios importes y para finalizar se ingresa un valor negativo o cero.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float importe, importe_neto,promedio,contventas=0,sumaventas=0;
    do
    {
        printf("\n\n\nIngrese el importe: ");
        scanf("%f",&importe);
        if(importe<=0)
            printf("FIN DEL PROGRAMA");
        else
        {
        if (importe<=50)
            {
                importe_neto=importe-(importe*0.035);
                printf("\nImporte inicial: %f \nDescuento efectuado: 3.5 porciento \nImporte a cobrar: %f",importe,importe_neto);
                contventas++;
                sumaventas+=importe;
            }
        else
        {
            if(importe>50&&importe<=150)
                {
                    importe_neto=importe-(importe*0.1);
                    printf("\nImporte inicial: %f \nDescuento efectuado: 10 porciento \nImporte a cobrar: %f",importe,importe_neto);
                    contventas++;
                    sumaventas+=importe;
                }
            else
            {
                if(importe>=151&&importe<300)
                    {
                        importe_neto=importe-(importe*0.2);
                        printf("\nImporte inicial: %f \nDescuento efectuado: 20 porciento \nImporte a cobrar: %f",importe,importe_neto);
                        contventas++;
                        sumaventas+=importe;
                    }
                else
                    {
                        importe_neto=importe*(importe*0.25);
                        printf("\nImporte inicial: %f \nDescuento efectuado: 25 porceinto \nImporte a cobrar: %f",importe,importe_neto);
                        contventas++;
                        sumaventas+=importe;
                    }
            }
        }
        }
    }while(importe>0);
    promedio=sumaventas/contventas;
    printf("\n\n\n\nEl importe promedio de todas las ventas realizadas es de: %f ",promedio);
    return 0;
}
