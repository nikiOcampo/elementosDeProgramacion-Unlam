#include <stdio.h>
#include <stdlib.h>

int main()
{
    int anio, mes;
    printf("Ingresa el anio: ");
    scanf("%d",&anio);
    printf("\nIngresa el numero del mes: ");
    scanf("%d",&mes);
    switch(mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("El mes ingresado tiene 31 dias");
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            printf("El mes ingresado tiene 30 dias");
            break;
        case 2:
            if(anio%4)
                printf("El mes ingresado tiene 28 dias");
            else
                printf("El mes ingresado tiene 29 dias");
            break;
        default:
        printf("El numero de mes no es valido");
    }
    return 0;
}
