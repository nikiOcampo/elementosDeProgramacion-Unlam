/*Un negocio de venta de granos desea controlar las ventas realizadas.
De cada una ingresa el importe total y un código que indica la forma de pago. El código puede ser:
• C: cheque, 20% de recargo.
• E: efectivo, 10% de descuento.
• T: con tarjeta, 12% de recargo.
Se debe ingresar una F para finalizar el día de venta y arrojar los siguientes totales.
Efectivo en Caja:
$ xxxx.xx
Ventas con Tarjeta de Crédito:
$ xxxx.xx
Ventas con cheque:
$ xxxx.xx
Total de Venta:
$ xxxx.xx
Importe del IVA:
$ xxxx.xx
Nota: El IVA corresponde al 21% del total de ventas.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float importotal, cheque,efectivo,tarjeta,impC,impE,impT;
    char codigo;
    cheque=efectivo=tarjeta=0;
    impC=impE=impT=0;
    do{printf("Ingrese el importe total: ");
    scanf("%f",&importotal);
    printf("Ingrese el codigo de forma de pago: ");
    fflush(stdin);
    scanf("%c",&codigo);
    if(codigo!='C'&&codigo!='E'&&codigo!='T'&&codigo!='F')
        printf("Codigo No correspondiente");
    switch(codigo)
    {
    case 'C':
        impC=importotal+(importotal*0.2);
        cheque+=impC;
        break;
    case 'E':
        impE=importotal-(importotal*0.1);
        efectivo+=impE;
        break;
    case 'T':
        impT=importotal+(importotal*0.12);
        tarjeta+=impT;
        break;
    }
    }while(codigo!='F');

    printf("\nEfectivo en Caja:\n $%f",efectivo);
    printf("\nVentas con Tarjeta de Credito: \n $%f",tarjeta);
    printf("\nVentas con cheque:\n $%f",cheque);
    printf("\nTotal de Venta:\n $%f",efectivo+tarjeta+cheque);
    printf("\nImporte del IVA: \n$%f",(efectivo+tarjeta+cheque)*0.21);

    return 0;
}
