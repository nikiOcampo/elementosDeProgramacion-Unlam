/*Escribir las sentencias que permitan el ingreso
correcto del valor numérico de un día y un mes determinado. Por algún error volver a solicitar.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dia, mes;
    do{printf("Ingrese el mes: ");
    scanf("%d",&mes);
    if (mes>12)
        printf("MES INEXISTENTE");
    }while(mes>12);
    if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)
     {
         do{
            printf("\nIngrese el dia: ");
            scanf("%d",&dia);
            if(dia>31) printf("El dia indicado no es correcto, intentelo nuevamente");
         }while(dia>31);
     }
     if (mes==2)
     {
         do{
            printf("\nIngrese el dia: ");
            scanf("%d",&dia);
            if(dia>29)
                printf("DIA INEXISTENTE");
         }while(dia>29);
     }
    if (mes==4||mes==6||mes==9||mes==11)
    {
        do{
            printf("\nIngrese el dia: ");
            scanf("%d",&dia);
            if (dia>30)
                printf("DIA INEXISTENTE");
        }while(dia>30);
    }
    return 0;
}
