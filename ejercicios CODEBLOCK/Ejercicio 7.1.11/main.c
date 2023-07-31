/*Confeccionar un programa para:
a. Generar los vectores necesarios para guardar la informaci�n ingresada por teclado.
Se ingresa los datos de 300 art�culos diferentes. De cada art�culo se ingresa los siguientes datos:
� C�digo de art�culo (int, entre 1 y 500).
� Clase de art�culo (char, �A� o �B� o �C� o �D�).
� N�mero de dep�sito donde se encuentra el art�culo (int, entre 1 y 100).
� Stock (int, entre o y 2000).
� Punto de reposici�n (int, entre 500 y 1000).
b. Generar e informar el vector VB, que contenga los c�digos de art�culos
de aquellos que hayan quedado con el saldo igual a cero.
c. Generar e informar el vector VC, que contengo a los c�digos de art�culos
de aquellos que hayan quedado con saldo por debajo del punto de reposici�n.
d. Generar e informar el vector VD, que contengo los c�digos de art�culos
de aquellos que est�n en los dep�sitos entre el 15 y 50.
Informar el/los c�digos de el/los art�culos que tienen el stock m�s alto.
(puede haber varios art�culos que tienen la misma cantidad de stock).
FUNCIONES:
I. Para generar los vectores del punto a).
II. Para generar el vector VB.
III. Para generar el vector VC.
IV. Para generar el vector VD.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int valida (int, int, int);
char valida_char (char, char, char,char);

int main()
{
    int cod_articulos[300],num_deposito[300],stock[300],punto_reps[300];
    char clase_articulo[300];
    int cod,x=0;
    cod=valida(1,500,1);
    while(cod!=0)
    {
        x++;
        cod_articulos[x-1]=cod;
        clase_articulo[x-1]=valida_char('A','B','C','D');
        num_deposito[x-1]=valida(1,100,2);
        stock[x-1]=valida(0,2000,3);
        punto_reps[x-1]=valida(500,1000,4);
        cod=valida(1,500,1);
    }
    system("cls");

    return 0;
}
int valida(int i,int f,int t)
{
	int dato;
	do
	{
	  printf("\n Ingrese ");
	  if(t==1)printf(" EL codigo del articulo, Sale 0:");
      if(t==2)printf(" EL Numero de deposito en el que se encuentra el producto :");
      if(t==3)printf(" La cantidad de estock del articulo:");
      if(t==4)printf(" El punto de reposicion: ");
	  scanf("%d",&dato);
	}while(dato<i||dato>f);
 return dato;
}

char valida_char(char a, char b, char c, char d)
{
    char dato;
    do
    {
        printf("\nIngrese la clase del aritulo: ");
        fflush(stdin);
        scanf("%c",&dato);
        dato=toupper(dato);
    }while(dato!=a&&dato!=b&&dato!=c&&dato!=d);
    return dato;
}

//b. Generar e informar el vector VB, que contenga los c�digos de art�culos
//de aquellos que hayan quedado con el saldo igual a cero.
