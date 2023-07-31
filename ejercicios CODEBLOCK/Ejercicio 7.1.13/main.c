/*7.1.13 Para una carrera de automóviles, se toman los tiempos de clasificación
(real, mayor que 0 en segundos y centésimos de segundo) de como máximo 60 autos de carrera inscriptos para la competencia.
Los autos se identifican con números correlativos del 1 al 60,
quedando sin información aquellos que no participan de la presente carrera.
Cuando ya no hay más tiempos de clasificación para cargar, se ingresa un auto con número negativo.
Se solicita determinar:
a. El número de auto que clasificó en primer lugar.
b. El número de auto que obtuvo el peor tiempo de clasificación.
c. La cantidad de autos que superaron el promedio de tiempo de clasificación.
d. El o los números de autos que no participan de la carrera actual.*/

#include <stdio.h>
#include <stdlib.h>

int busqueda_secuencial(int[],int,int);
void masrapido (int[],float[],int);
void maslento (int[],float[],int);
void punto_C(int[],float[],float,int);
void punto_D(int[],float[],int);

int main()
{
    int autos[60]={0},num_auto/*pos=-1*/,x,i=0;
    float tiempos[60],acuml_tiempos=0,promedio_tiempos;
    for(x=0;x<60;x++)
    {
        do
        {
            printf("Ingresa el numero de auto: ");
            scanf("%d",&num_auto);
            if(num_auto>60)
                printf("\nEl numero de auto no existe");
            autos[x]=num_auto;
            /*i++;*/
            if(num_auto<0)
            printf("FIN DE LA CARGA DE TIEMPOS");
            x=60;
            //autos[x]=num_auto;
        }while(num_auto>60/*&&pos!=-1*/);
        while(num_auto>0)
        {
            printf("\nIngrese el tiempo de clasificacion de dicho auto: ");
            scanf("%f",&tiempos[i]);
            acuml_tiempos+=tiempos[i];
            printf("Ingresa el numero de auto: ");
            scanf("%d",&num_auto);
            i++;
        }

    }
    masrapido(autos,tiempos,i);
    maslento(autos,tiempos,i);
    //c. La cantidad de autos que superaron el promedio de tiempo de clasificación.
    promedio_tiempos=(float)acuml_tiempos/i;
    punto_C(autos,tiempos,promedio_tiempos,i);
    //d. El o los números de autos que no participan de la carrera actual.
    punto_D(autos,tiempos,60);
    return 0;
}

/*int busqueda_secuencial (int v[], int cant, int elem)
{
    int i, pos;
    i = 0;
    pos = -1;
    while(i < cant && pos == -1)
    {
        if(v[i] == elem)
            pos = i;
        else
            i++;
    }
    return pos;
}*/

void masrapido(int autos[],float tiempos[],int n)
{
    int x,j;
    float rapido;
    rapido=tiempos[0];
    for(x=1;x<n;x++)
    {
        if(tiempos[x]<rapido)
            rapido=tiempos[x];
    }
    printf("\n\nEl tiempo mas rapido fue de %f, de el/los autos: ",rapido);
    for(j=0;j<n;j++)
    {
        if(tiempos[j]==rapido)
            printf("\n%d", autos[j]);
    }
}

void maslento(int autos[],float tiempos[],int n)
{
    int x,j;
    float lento;
    lento=tiempos[0];
    for(x=1;x<n;x++)
    {
        if(tiempos[x]>lento)
            lento=tiempos[x];
    }
    printf("\n\nEl tiempo mas lento fue de %f, de el/los autos: ",lento);
    for(j=0;j<n;j++)
    {
        if(tiempos[j]==lento)
            printf("\n%d", autos[j]);
    }
}

void punto_C(int autos[],float tiempos[],float prom,int n)
{
    int x;
    printf("\n\nLos autos que superan el tiempo promedio son: ");
    for(x=0;x<n;x++)
    {
        if(tiempos[x]>prom)
           printf("\n%d",autos[x]);
    }
}

void punto_D(int autos[],float tiempos[],int n)
{
    int x;
    printf("\n\nLos autos que no participaron fueron los autos numero: ");
    for(x=0;x<n;x++)
    {
        if(tiempos[x]==0)
            printf("\n%d",autos[x]);
    }
}



