/*Confeccionar un programa que permita ingresar varias
 ternas de valores a punto flotante, que finalice al ingresar una terna con los valores
 ORDENADOS en forma creciente. Para cada terna exhibir la siguiente pantalla:
** OPCIONES POSIBLES **
1 – Mayor valor
2 – Promedio
3 – Suma
4 - Finalizar
** Digite su opción:
Según la opción deseada debe aparecer en pantalla el resultado,
 sin borrar el menú. No admitir otros valores de opción. Confeccionar y utilizar
 una función PARA CADA UNA de las opciones y otra para detectar la condición final.*/

#include <stdio.h>
#include <stdlib.h>

float MayorValor ( float, float, float);
float Promedio (float,float,float);
float Suma (float, float, float);
int IngreseOpcion (int,int);

int main()
{
    float n1,n2,n3,opcion1,opcion2,opcion3;
    int opcion,sen=1,ban=0;
    do
    {
        if(ban==0)
        {
            printf("Ingrese una terna: ");
            scanf("%f" "%f" "%f",&n1,&n2,&n3);
        }
        if(n1<n2&&n2<n3)
        {
            printf("Fin del programa");
        }
    }while(n1<n2&&n2<n3);
    while(n1>n2||n2>n3)
    {
        if(sen==1)
        {
            printf("\nOPCIONES POSIBLES\n");
            printf(" 1 – Mayor valor\n 2 – Promedio\n 3 – Suma\n 4 - Finalizar");
            opcion=IngreseOpcion(1,4);
            switch(opcion)
            {
            case 1:
                opcion1=MayorValor(n1,n2,n3);
                printf("El valor mayor ingresado en esta terna es de %f",opcion1);
                break;
            case 2:
                opcion2=Promedio(n1,n2,n3);
                printf("\nEl promedio de los valores ingresados es de: %f",opcion2);
                break;
            case 3:
                opcion3=Suma(n1,n2,n3);
                printf("La suma de los valores ingresados es de: %f",opcion3);
                break;
            case 4:
                printf("Fin del programa");
                break;
            }
            sen=0;
        }
        do
        {
            if(ban==0)
            {
                printf("\nIngrese una terna: ");
                scanf("%f" "%f" "%f",&n1,&n2,&n3);
            }
            if(n1<n2&&n2<n3)
            {
                printf("Fin del programa");
            }
        }while(n1<n2&&n2<n3);
    }
}

float MayorValor(float a, float b, float c)
{
    float mayor;
    if(a>b&&a>c)
       mayor=a;
    if(b>a&&b>c)
        mayor=b;
    if(c>a&&c>b)
        mayor=c;
    return mayor;
}

float Suma(float a, float b, float c)
{
    float sum;
    sum= a+b+c;
    return sum;
}

float Promedio(float c, float d, float e)
{
    float acumul,prom;
    acumul=Suma(c,d,e);
    prom=acumul/3;
    return prom;
}


int IngreseOpcion(int x, int y)
{
    int op;
    do
    {
        printf("\nDigite su opcion: ");
        scanf("%d",&op);
            if(op<x||op>y)
                printf("\nSu opcion no es valida");
    }while(op<x||op>y);
    return op;
}



