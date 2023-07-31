/*Confeccionar un programa que permita ingresar diversas ternas de valores enteros mayores que 0 y
menores que 99. Finalizar el ingreso cuando se informen 3 valores iguales a 96, 97 y 98.
Determinar e informar para cada terna, el mayor y el menor de los valores.
Confeccionar y utilizar una función con parámetros llamada MayorMenor,
que permita calcular el menor o el mayor valor de la terna según un parámetro de configuración.*/

#include <stdio.h>
#include <stdlib.h>

int MayorMenor (int,int,int,int);

int main()
{
    int n1,n2,n3,menor, mayor ;
    do
    {
        printf("Ingrese una terna de valores: ");
        scanf("%d %d %d",&n1,&n2,&n3);
        if(n1<0||n1>99||n2<0||n2>99||n3<0||n3>99)
            printf("\nAlgun valor de su terna es incorrecto, vuelva a cargar su terna");
    }while(n1<0||n1>99||n2<0||n2>99||n3<0||n3>99);
    while(n1!=96&&n2!=97&&n3!=98)
    {
        menor=MayorMenor(n1, n2, n3, 0);
        printf("\nEl menor valor de los ingresados es %d", menor);
        mayor=MayorMenor(n1, n2, n3, 1);
        printf("\nEl meyor valor de los ingresados es %d", mayor);
         do
        {
            printf("\nIngrese una terna de valores: ");
            scanf("%d %d %d",&n1,&n2,&n3);
            if(n1<0||n1>99||n2<0||n2>99||n3<0||n3>99)
                printf("\nAlgun valor de su terna es incorrecto, vuelva a cargar su terna");
        }while(n1<0||n1>99||n2<0||n2>99||n3<0||n3>99);
    }
    return 0;
}

int MayorMenor(int a, int b, int c, int d)
{
    int n;
    if (d==1)
    {
        if(a>b&&a>c)
            n=a;
        if(b>a&&b>c)
            n=b;
        if(c>a&&c>b)
            n=c;
    }
    else
    {
        if(a<b&&a<c)
            n=a;
        if(b<a&&b<c)
            n=b;
        if(c<a&&c<b)
            n=c;
    }
    return n;
}
