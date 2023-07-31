/*Ingresar N y N Números naturales. Determinar e informar:
a. La sumatoria de los valores múltiplos de 3.
b. La cantidad de valores múltiplos de 5.
c. La sumatoria de los valores que se ingresan en orden par.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,SumM3,ContM5,SumPar,Bandera,Num;
    SumM3=ContM5=SumPar=Bandera=0;
    printf("Ingrese la cantidad de numeros naturales: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Ingrese %d numero: ",i);
        scanf("%d",&Num);
        if (Num%3==0)
            SumM3+=Num;
        if (Num%5==0)
            ContM5++;
        if (Bandera==1)
        {
            SumPar+=Num;
            Bandera=0;
        }
        else
            Bandera=1;
    }
    printf("La sumatoria de la los multiplos de 3 es de %d", SumM3);
    printf("\nLa cantidad de numeros que son multiplos de 5 son %d",ContM5);
    printf("\nLa sumatoria de los valores que se ingresaron en orden par es de %d", SumPar);

    return 0;
}
