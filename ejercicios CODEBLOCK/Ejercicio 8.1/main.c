//8.1. Ingresar una frase de hasta 500 caracteres y contar cuántas palabras contiene dicha frase.
// a. Considerar que las palabras están separadas por un único espacio.
// b. Considerar que las palabras pueden estar separadas por más de un espacio consecutivo.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char frase[500];
    int conta=1,x=0;
    printf("\n Ingrese una frase Conocidad \n");
    fflush(stdin);
    gets(frase);
    while(frase[x]!='\0')
    {
      if(frase[x]==' ')
      {
           if(frase[x+1]==' ') x++;
           if(frase[x]==' ') x++;
           conta++;
      }
      x++;
    }
    printf(" La cantidad de palabras ingresadas en la frase son :%d\n",conta);
    return 0;
}
