/*Se realizó un concurso de tiro al blanco. Existen 5 participantes y
cada uno de ellos efectúa 3 disparos, registrándose las coordenadas X-Y de cada disparo. Determinar:
a. Cuantos disparos se efectuaron en cada cuadrante por cada participante
b. Cuantos disparos se efectuaron en total en el centro.
NOTA: no considere disparos sobre los ejes.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,X,Y,cont1,cont2,cont3,cont4,cont5;
    cont1=cont2=cont3=cont4=cont5=0;
    for(i=1;i<=15;i++)
    {
        printf("Ingrese las coordenadas X e Y del disparo respectivamente: ");
        scanf("%d %d",&X,&Y);
        if(X>0&&Y>0)
            cont1++;
        if(X<0&&Y>0)
            cont2++;
        if(X<0&&Y<0)
            cont3++;
        if(X>0&&Y<0)
            cont4++;
        if(X==0&&Y==0)
            cont5++;
    }
    printf("La cantidad de disparos en el primer cuadrante son:%d ",cont1);
    printf("\nLa cantidad de disparos en el segundo cuadrante son:%d ",cont2);
    printf("\nLa cantidad de disparos en el tercer cuadrante son:%d ",cont3);
    printf("\nLa cantidad de disparos en el cuarto cuadrante son:%d",cont4);
    printf("\nLa cantidad de disparos en el centro son: %d",cont5);
    return 0;
}
