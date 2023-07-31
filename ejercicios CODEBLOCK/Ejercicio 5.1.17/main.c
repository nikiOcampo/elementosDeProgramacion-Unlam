/*Ingresar N artículos (códigos) y sus correspondientes precios. Indicar el código del artículo
más caro y el precio del más barato. NOTA: todos los artículos tienen precios distintos.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,i , precio, codigos, mayorcodi, mayorpre,masbarato;
    mayorcodi=mayorpre=masbarato=0;
    printf("Ingrese la cantidad de articulos: ");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        printf("Ingrese el codigo de su articulo: ");
        scanf("%d",&codigos);
        printf("Ingrese el precio de ese articulo: ");
        scanf("%d",&precio);
        if(i==1||precio>mayorpre)
        {
            mayorpre=precio;
            mayorcodi=codigos;
        }
        if(i==1||precio<masbarato)
            masbarato=precio;
    }
    printf("\nEl codigo del articulo mas caro es: %d ",mayorcodi);
    printf("\nEl precio del mas barato es de: %d",masbarato);
    return 0;
}
