//Se ingresan 50 números enteros. Determinar el promedio de los números pares.//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,resto,sumapares=0,contpares=0;
    float promedio;
    for(i=1;i<=50;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d",&num);
        resto=num%2;
        if (resto==0)
          {
            sumapares+=num;
            contpares++;
          }
    }
    if(contpares>0)
    {
        promedio= (float)sumapares/contpares;
        printf("El promedio de los numeros pares es de %.2f",promedio);
    }
    else
        printf("No se ingresaron numeros pares");
    return 0;
}
