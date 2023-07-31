/*Confeccionar un programa que me permita calcular y mostrar una cantidad de n�meros primos
 que se solicita por la pantalla. Los n�meros se calculan a partir del 2.
 Ejemplo: Si ingreso 6, genero los n�meros: 2 � 3 - 5 - 7 - 11 - 13.
  El algoritmo para el c�lculo de si un n�mero es primo o no,
 debe estar optimizado para que si encuentra un divisor no seguir buscando ya que se sabe que no es primo.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i=2,cont=0;
    printf("Ingresa la cantidad de numeros primos que desea ver: ");
    scanf("%d",&n);
    while(cont<n)
    {
        if((i==2 || i==3 || i==5 || i==7) || (i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0))
        {
            printf("\n%d",i);
            cont++;
        }
        i++;
    }
    return 0;
}
