/*Se realizó un concurso de tiro al blanco. Por cada participante se ingresa un número que lo
 identifica y el resultado de los disparos efectuados. El ingreso finaliza con un número de participante negativo.
Cada participante efectúa 5 disparos, registrándose las coordenadas X-Y de cada disparo.
    • No considere disparos sobre los ejes, pero sí en el centro (
    si es sobre los ejes las coordenadas deberán volver a ingresarse).
    • Para determinar el cuadrante utilizar la función CUADRANTE que
    reciba las dos coordenadas y retorne el cuadrante al cual pertenece
    (1 a 4) y 0 para indicar un tiro en el centro.
Para calcular el puntaje utilizar la función PUNTAJE que reciba
5 parámetros que representan la cantidad disparos en cada cuadrante y en el centro.
 La función debe retornar el puntaje obtenido según la siguiente escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos
Determinar:
a. El puntaje obtenido por cada participante, detallando cuantos disparos realizó en cada cuadrante.
b. Mostrar el número del participante ganador y el puntaje obtenido.
c. Calcular y mostrar la cantidad total de disparos en el centro (de todos los participantes)
*/

#include <stdio.h>
#include <stdlib.h>

int CUADRANTE (int,int);
int PUNTAJE (int, int, int, int, int);

int main()
{
    int i,coordenada1,coordenada2,num,numcuadra,puntos,mayorpuntos,mayornum;
    int cont1,cont2,cont3,cont4,cont5,acuml;
    mayorpuntos=cont1=cont2=cont3=cont4=cont5=acuml=0;
    printf("\nIngrese el numero de participante: ");
    scanf("%d",&num);
    while(num>0)
    {
        cont1=cont2=cont3=cont4=cont5=0;
        for(i=1;i<=5;i++)
        {
            do
            {
                printf("\nIngrese las coordenadas X e Y del disparo %d respectivamente: ",i);
                scanf("%d %d",&coordenada1,&coordenada2);
                if((coordenada1==0&&coordenada2!=0)||(coordenada1!=0&&coordenada2==0))
                    printf("COORDENADA INCORRECTA, vuelva a ingresar el tiro: ");
            }while((coordenada1==0&&coordenada2!=0)||(coordenada1!=0&&coordenada2==0));

            numcuadra=CUADRANTE(coordenada1,coordenada2);
            if(numcuadra==1)
                cont1++;
            if(numcuadra==2)
               cont2++;
            if(numcuadra==3)
                cont3++;
            if(numcuadra==4)
                cont4++;
            if(numcuadra==0)
                cont5++;
            puntos=PUNTAJE(cont1,cont2,cont3,cont4,cont5);
            if(puntos>mayorpuntos)
            {
                mayorpuntos=puntos;
                mayornum=num;
            }
        }
        acuml+=cont5;
        printf("El puntaje obtenido por el participante %d fue de: %d\n ",num,puntos);
        printf("Cant Tiros en el 1er cuadrante: %d \n",cont1);
        printf("Cant Tiros en el 2do cuadrante:%d \n",cont2);
        printf("Cant tiros en el 3er cuadrante: %d \n",cont3);
        printf("Cant tiros en el 4to cuadrante: %d \n",cont4);
        printf("Cant tiros en el centro: %d",cont5);
        printf("\nIngrese el numero de participante: ");
        scanf("%d",&num);

    }
    printf("\nEl participante ganador fue el participante num %d, con %d puntos",mayornum,mayorpuntos);
    printf("\nLa cantidad total de disparos en el centro fueron de:%d",acuml);
    return 0;
}

int CUADRANTE (int x, int y)
{
    int a;
    if(x>0&&y>0)
        a=1;
    if(x<0&&y>0)
        a=2;
    if(x<0&&y<0)
        a=3;
    if(x>0&&y<0)
        a=4;
    if(x==0&&y==0)
        a=0;
    return a;
};

/*Para calcular el puntaje utilizar la función PUNTAJE que reciba
5 parámetros que representan la cantidad disparos en cada cuadrante y en el centro.
 La función debe retornar el puntaje obtenido según la siguiente escala:
✓ Cuadrantes 1 y 2: 50 puntos
✓ Cuadrantes 3 y 4: 40 puntos
✓ Centro: 100 puntos*/
int PUNTAJE(int c1, int c2, int c3,int c4,int c5)
{
    int p1,p2,p3,total;
    p1=(c1+c2)*50;
    p2=(c3+c4)*40;
    p3=c5*100;
    total= p1+p2+p3;
    return total;
};

