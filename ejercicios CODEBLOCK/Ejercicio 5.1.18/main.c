/*Realizar un programa que muestre por pantalla las tablas de multiplicar del 1 al 9 de la siguiente forma:
1  2  3  4  5  6  7  8  9
2  4  6  8 10 12 14 16 18
3  6  9 12 15 18 21 24 27
4  8 12 16 20 24 28 32 36
5 10 15 20 25 30 35 40 45
6 12 18 24 30 36 42 48 54
7 14 21 28 35 42 49 56 63
8 16 24 32 40 48 56 64 72
9 18 27 36 45 54 63 72 81*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,uno=1,dos=2,tres=3,cuatro=4,cinco=5,seis=6,siete=7,ocho=8,nueve=9;
    for(i=1;i<=9;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",uno*i,dos*i,tres*i,cuatro*i,cinco*i,seis*i,siete*i,ocho*i,nueve*i);
    }
    return 0;
}
