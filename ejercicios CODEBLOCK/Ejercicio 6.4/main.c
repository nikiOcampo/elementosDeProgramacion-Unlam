/*Se ingresa valores positivos entre 1 y 50, finalizando el ingreso con el valor -10,
 para ello generar una funci�n que valide dicho ingreso. Calcular:
a. Cu�ntos n�meros son primos.
b. Cantidad de n�meros pares.
c. Promedio de los n�meros impares.
Utilizar las siguientes funciones:
� Resto: recibe por par�metro el Dividendo y el Divisor; Retorna el resto.
� EsPar: recibe por par�metro un n�mero; Retorna 1 si es Par, 0 si es Impar; Invoca a la funci�n Resto.
� EsPrimo: recibe por par�metro un n�mero; Retorna 1 si es primo, 0 si no es primo; Invoca a la funci�n Resto.
(un n�mero es primero si solo es divisible por 1 y por s� mismo).
� Promedio: recibe por par�metro la suma y el contador; Retorna el promedio si contador > 0 sino Retorna 0.*/

#include <stdio.h>
#include <stdlib.h>

int LeerYValidar (int, int);
float Resto (int ,int );
int EsPar (int);
int EsPrimo (int);
float Promedio(int, int );

int main()
{
    int num,primos,pares;
    int cont_primos,cont_pares,cont_impares,acumul_impares;
    cont_impares=cont_pares=cont_primos=acumul_impares=0;
    float prom_impar;
    num= LeerYValidar(1,50);
    while(num>=1&&num<=50)
    {
    primos=EsPrimo(num);
    if(primos==1)
        cont_primos++;
    pares=EsPar(num);
    if(pares==1)
        cont_pares++;
    else
        {
            cont_impares++;
            acumul_impares+=num;
        }
    num=LeerYValidar(1,50);
    }
    prom_impar=Promedio(acumul_impares,cont_impares);
    printf("\nLa cantidad de numeros primos ingresados es de: %d",cont_primos);
    printf("\nLa cantidad de numeros pares ingresados es de: %d",cont_pares);
    printf("\nEl promedio de los numeros impares es de: %f",prom_impar);
    return 0;
}

int LeerYValidar(int x ,int y)
{
    int n;
    do
    {
        printf("\nIngrese un valor positivo entre 1 y 50: ");
        scanf("%d",&n);
        if((n<x||n>y)&& (n!=-10))
            printf("\nEl numero no respeta el rango vuelva a ingresarlo");
        if(n==-10)
            printf("\nFIN DEL PROGRAMA");
    }while((n<x||n>y)&&(n!=-10));
    return n;
}

/*Resto: recibe por par�metro el Dividendo y el Divisor; Retorna el resto.*/
float Resto(int dividendo, int divisor)
{
    int res;
    res=dividendo%divisor;
    return res;
};

/* EsPar: recibe por par�metro un n�mero; Retorna 1 si es Par, 0 si es Impar; Invoca a la funci�n Resto.*/
int EsPar(int n)
{
    int a,b;
    a=Resto(n, 2);
    if (a==0)
        b=1;
    else
        b=0;
    return b;
};

/*EsPrimo: recibe por par�metro un n�mero; Retorna 1 si es primo, 0 si no es primo; Invoca a la funci�n Resto.
(un n�mero es primero si solo es divisible por 1 y por s� mismo).*/
int EsPrimo(int n)
{
    int c,d,e,f,g;
    c=Resto(n, 2);
    d=Resto(n, 3);
    e=Resto(n, 5);
    f=Resto(n, 7);
    if (c!=0&&d!=0&&e!=0&&f!=0)
        g=1;
    else
        {
            if(n==7||n==5||n==3||n==2)
                g=1;
            else
                g=0;
        }
    return g;
};

/*Promedio: recibe por par�metro la suma y el contador; Retorna el promedio si contador > 0 sino Retorna 0.*/
float Promedio(int sum,int cont)
{
    int p,r;
    p=(float)sum/cont;
    if(cont>0)
        r=p;
    else
        r=0;
    return r;
};
