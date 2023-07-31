/*Confeccionar un programa que solicite el ingreso de un valor entero N < 12 y luego una lista de N números
reales sobre la cual debe calcular:
a. el promedio de los positivos.
b. el promedio de los negativos.
c. la cantidad de ceros.
Si el valor ingresado N es mayor que 12 informar 'VALOR EXCEDIDO” y si es menor o igual a 0 informar “CANTIDAD INVALIDA”.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,valor,numeros,cant_ceros,sumpositivos,sumnegativos,cantpositivos,cantnegativos
    ;
    float prom_pos,prom_neg;
    cantnegativos=cantpositivos=cant_ceros=sumnegativos=sumpositivos=0;
    do
    {printf("\nIngrese la cantidad de numeros de la lista(menor a 12): ");
    scanf("%d",&valor);
    if(valor>12)
        printf("\nVALOR EXCEDIDO");
    if(valor<=0)
        printf("\nCANTIDAD INVALIDA");
    }while(valor>12&&valor!=0);
    for(i=1;i<=valor;i++)
    {
        printf("\nIngrese un numero real: ");
        fflush(stdin);
        scanf("%d",&numeros);
        if(numeros>0)
        {
            sumpositivos+=numeros;
            cantpositivos++;
        }
        else
        {
            if(numeros==0)
                cant_ceros++;
            else
             {
                sumnegativos+=numeros;
                cantnegativos++;
             }
        }
    }
    prom_pos=sumpositivos/cantpositivos;
    prom_neg=sumnegativos/cantnegativos;
    printf("El promedio de numeros positivos es de: %f ", prom_pos);
    printf("El promedio de numeros negativos es de: %f ",prom_neg);
    printf("La cantidad de ceros es de: %d ",cant_ceros);
    return 0;
}
