/*Se ingresan n�meros enteros comprendidos entre 100 y 2000 (usar funci�n LeerYValidar).
Determinar usando la funci�n EstaDentroDelRango:
a. Cantidad de n�meros ingresados entre 100 y 500
b. Cantidad de n�meros pares ingresados entre 500 y 1200
c. Promedio de n�meros ingresados entre 1200 y 2000
El ingreso de datos finaliza cuando se ingresa un n�mero igual a 99.
Para realizar este programa se deben realizar las siguientes funciones:
� EstaDentroDelRango: que reciba 3 enteros correspondientes a un n�mero a validar
y los l�mites superior e inferior del rango. La funci�n debe retornar un 1 si el n�mero
a validar se encuentra dentro del rango indicado o un 0 si no lo est�.
� LeerYValidar: que reciba los l�mites superior e inferior de un rango
 y retorne un n�mero que se encuentre dentro del mismo.
 (El ingreso de datos se realiza dentro de la funci�n). Para validar el rango utilizar la
 funci�n EstaDentroDelRango realizada en el punto anterior.*/

#include <stdio.h>
#include <stdlib.h>

int EstaDentroDelRango (int,int,int);
int LeerYValidar(int,int);

int main()
{
    int num, cont1, cont2, acum1,cont3;
    float promedio;
    cont1=cont2=cont3=acum1=0;
    num=LeerYValidar(99,2000);
    while(num!=99)
    {
        if(num>=100 && num<=500)
            cont1++;
        if(num>=501 && num<=1200)
        {
            if(num%2==0)
                cont2++;
        }
        if(num>=1201 && num<=2000)
        {
            acum1+=num;
            cont3++;
        }
        num=LeerYValidar(99,2000);
    }
    printf("\nLa Cantidad de n�meros ingresados entre 100 y 500 son: %d",cont1);
    printf("\nLa Cantidad de n�meros pares ingresados entre 500 y 1200 son: %d ",cont2);
     promedio=(float)acum1/cont3;
    printf("\nEl Promedio de n�meros ingresados entre 1200 y 2000 es de: %f",promedio);
    return 0;
}

int EstaDentroDelRango(int x, int y, int z)
{
    if(x<y || x>z)
        return 1;
    else
        return 0;
};


int LeerYValidar(int y, int z)
 {
     int n;
     do
     {
         printf("\nIngrese un numero entero [entre 100 y 20000/ 99=salida]: ");
         scanf ("%d",&n);
     }while(EstaDentroDelRango(n,y,z)!=0);
     return n;
 };

