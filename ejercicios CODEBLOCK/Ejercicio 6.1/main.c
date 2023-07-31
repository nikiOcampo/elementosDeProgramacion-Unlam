/*6.1. Realizar un programa que al ingresar solicite el ingreso de dos números enteros y luego muestre por pantalla el siguiente menú (las xx de los números deben ser reemplazadas con los valores correspondientes):
Menú de Opciones
---- -- --------
Numero 1: xx Numero 2: xx
1) Sumar
2) Restar
3) Multiplicar
4) Dividir
5) Ingresar Nuevos Números
6) Salir
Ingrese su opción:
Al ingresar el número de la opción del 1 al 4, se realiza la operación y muestra el
 resultado hasta que se presione una tecla. Luego vuelve a mostrar el menú para poder realizar
 otra operación con los mismos números. La opción 5 pide el ingreso de dos nuevos números de
 trabajo mientras que la opción 6 sale y cierra el programa.
El ingreso de la opción debe estar validado y en
caso de ingresarse un número no válido debe solicitarlo nuevamente.
Usar una función para mostrar el menú y retornar el valor elegido.*/

#include <stdio.h>
#include <stdlib.h>

int IngresoValor(int);
int menu (int,int);
int valida (int,int);
int suma(int,int);
int resta(int, int);
int multiplicacion (int,int );
float division (int,int);

int main()
{
    int sen=0,num1,num2,sum,res,mul;
    float div;
    num1=IngresoValor(1);
    num2=IngresoValor(2);
    while (sen!=6)
    {
        sen=menu(num1,num2);
        switch(sen)
        {
           case 1:
               sum=suma(num1,num2);
               printf("\nLa suma de los valores ingresados es de: %d\n", sum);
               system ("pause");
               break;
           case 2:
               res=resta(num1,num2);
               printf("\nLa resta de los valores ingresados es de: %d\n",res);
               system ("pause");
               break;
           case 3:
               mul=multiplicacion(num1,num2);
               printf("\nLa multiplicacion de los valores ingresados es de %d\n",mul);
               system ("pause");
               break;
           case 4:
               div=division(num1,num2);
               printf("\nLa divsion de los valores ingresados es de %f\n",div);
               system ("pause");
               break;
           case 5:
               num1=IngresoValor(1);
               num2=IngresoValor(2);
        }
    }
    return 0;
}

int IngresoValor(int x)
{
    int n;
    if (x==1)
        system("cls");
    printf("Ingrese el Nro %d: ",x);
    scanf("%d", &n);
    return n;
};
int menu(int a, int b)
{
    int op;
    system("cls");
    printf("\t\t\tMenu de opciones: ");
    printf("\t\t\t---- -- --------\n");
    printf("\n\n Numero 1: %d Numero 2: %d\n",a,b);
    printf("\n     1) Sumar                   ");
    printf("\n     2) Restar                  ");
    printf("\n     3) Multiplicar             ");
    printf("\n     4) Dividir                 ");
    printf("\n     5) Ingresar Nuevos Numeros ");
    printf("\n     6) Salir                   ");
    printf("\n Ingrese Opcion:");
    op = valida(1,6);
    return op;
};
int valida(int c ,int d)
{
    int opcion;
    do
    {
        scanf("%d",&opcion);
        if(opcion<c || opcion>d)
            printf("\nRESPETE EL RANGO\n");
    }while(opcion<c || opcion>d);
    return opcion;
};
int suma(int a, int b)
{
    int s;
    s=a+b;
    return s;
};
int resta(int a, int b)
{
    int r;
    r=a-b;
    return r;
};
int multiplicacion(int a, int b)
{
    int m;
    m=a*b;
    return m;
};
float division (int a, int b)
{
    int d;
    d= (float) a/b;
    return d;
};

