/*Realizar un programa que le solicite al usuario el ingreso de una vocal (este dato de ingreso se debe validar).
Luego el programa debe dibujar en pantalla la vocal ingresada en cinco líneas y cuatro columnas.
La vocal debe estar formada en cada carácter por la misma letra en mayúscula.
El programa finaliza al ingresar la letra f.
Restricciones: Por cada printf se debe exhibir un solo carácter o salto de línea o espacio.
Ejemplos:
Ingreso del carácter a:
AAAA
A  A
AAAA
A  A
A  A*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char s='Z',voc;
    int n,l,c,d,x;
    while (s!='F')
    {
        do
        {
            printf("n Ingrese una vocal, [F] para cerrar el programa:");
            fflush(stdin);
            scanf("%c", &voc);
            voc=toupper(voc);
        }while(voc!='A'&& voc!='E'&& voc!='I'&& voc!='O'&& voc!='U' && voc!='F');
    x=1;
    n=1;
        while (voc!='F'&&voc!='Z')
        {
            n=n*x;
            d=5*n;
            for (l=1;l<=d;l++)
            {
                if(l<=n)
                {
                    printf ("n");
                    switch (voc)
                    {
                        case 'A':
                        case 'E':
                        case 'I':
                        case 'O':
                            for (c=1;c<=4*n;c++)
                            {
                                printf("%c",voc);
                            }
                        break;
                        case 'U':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf("%c",voc);
                                else
                                    printf(" ");
                            }
                        break;
                    }
                }
                if(l>n && l<=(2*n))
                {
                    printf("n");
                    switch (voc)
                    {
                        case 'E':
                            for (c=1;c<=n;c++)
                            {
                                printf("%c",voc);
                            }
                        break;
                        case 'I':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf(" ");
                                else
                                    printf("%c",voc);
                            }
                        break;
                        case 'O':
                        case 'A':
                        case 'U':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf("%c",voc);
                                else
                                    printf(" ");
                            }
                        break;
                    }
                }
                if(l>(2*n) && l<=(3*n))
                {
                    printf("n");
                    switch (voc)
                    {
                        case 'A':
                        case 'E':
                            for (c=1;c<=4*n;c++)
                            {
                                printf("%c",voc);
                            }
                        break;
                        case 'O':
                        case 'U':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf("%c",voc);
                                else
                                    printf(" ");
                            }
                        break;
                        case 'I':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf(" ");
                                else
                                    printf("%c",voc);
                            }
                    }
                }
                if(l>(3*n) && l<=(4*n))
                {
                    printf("n");
                    switch (voc)
                    {
                        case 'E':
                            for (c=1;c<=n;c++)
                            {
                                printf("%c",voc);
                            }
                        break;
                        case 'A':
                        case 'O':
                        case 'U':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf("%c",voc);
                                else
                                    printf(" ");
                            }
                            break;
                        case 'I':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf(" ");
                                else
                                    printf("%c",voc);
                            }
                    }
                }
                if(l>(n*4) && l<=(n*5))
                {
                    printf("n");
                    switch (voc)
                    {
                        case 'I':
                        case 'U':
                        case 'E':
                        case 'O':
                            for (c=1;c<=4*n;c++)
                            {
                                printf("%c",voc);
                            }
                        break;
                        case 'A':
                            for (c=1;c<=4*n;c++)
                            {
                                if (c<=n || (c>n*3 && c<=n*4))
                                    printf("%c",voc);
                                else
                                    printf(" ");
                            }
                        break;
                    }
                }
            }
            printf("n Si desea amplificar la vocal escriba el numero de veces que quiere amplificarla y sino escriba 0 ");
            scanf("%d", &x);
                if (x==0)
                {
                    do
                    {
                        printf("n Si quiere cerrar el programa escriba F, si quiere ingresar otra vocal escriba Z:");
                        fflush(stdin);
                        scanf("%c",&voc);
                        voc=toupper(voc);
                    }while (voc!='F' && voc!='Z');
                    s=voc;
                }
        }
        if ( voc=='Z')
            s='Z';
        else
            s='F';
}
return 0;
}


