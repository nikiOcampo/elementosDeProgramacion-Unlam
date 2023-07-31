#include <stdio.h>
#include <stdlib.h>
// codgio de 1 a 15 la hora=$65/codigo de 16 a 32 $55 y de 33 a 50 $50
int validar(int,int,int);
void ordenamiento (int[],int[],int);

int main()
{
    int cod,horas,hr[50]={0},sueldos[50]={0},dia,dias[28]={0},totalsueldos=0,codigos[50]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    int max,x,i,mashoras,d,cont=0;
    cod=validar(0,50,1);
    while(cod!=0)
    {
        dia=validar(1,28,2);
        horas=validar(0,16,3);
        dias[dia]+=horas;
        hr[cod]+=horas;
        if(cod>=1&&cod<=15)
            sueldos[cod-1]+=horas*65;
        if(cod>15&&cod<=32)
            sueldos[cod-1]+=horas*55;
        if(cod>32)
            sueldos[cod-1]+=horas*50;
        cod=validar(0,50,1);
    }
    system("cls");
    ordenamiento(codigos,sueldos,50);
    for(x=0;x<50;x++)
    {
        totalsueldos+=sueldos[x];
    }
    printf("\nEl total de sueldos abonados es de: %d",totalsueldos);
    max=hr[0];
    for (i=1;i<15;i++)
    {
        if (hr[i]>max)
            max=hr[i];
    }
    printf("\n\nLa mayor cantidad de horas trabajadas [entre los trabajadores 1-15]fue de %d que la tuvieron el/los trabajadores:\n", max);
    for (i=0;i<15;i++)
    {
        if(hr[i]==max)
            printf("\n%d\n",i);
    }
    mashoras=dias[0];
    for (i=1;i<28;i++)
    {
        if (dias[i]>mashoras)
          {
              mashoras=dias[i];
              d=i;
          }
    }
    printf("\n\nLa mayor cantidad de horas trabajadas por dia fue de %d trabajadas el dia %d \n", mashoras,d);
    for(x=0;x<50;x++)
    {
        if(hr[x]==0)
            cont++;
    }
    printf("\n%d choferes no registraron horas en el periodo",cont);
    return 0;
}

int validar(int y, int z,int a)
 {
     int dato;
     if(a==1)
     {
            do
             {
                 printf("\nIngrese el codigo de chofer: ");
                 scanf ("%d",&dato);
                 if(dato<y||dato>z)
                    printf("\nEl codigo ingresado no existe");
             }while(dato<y||dato>z);
     }
     if(a==2)
     {
         do
             {
                 printf("\nIngrese el dia en que trabajo ese chofer: ");
                 scanf ("%d",&dato);
                 if(dato<y||dato>z)
                    printf("\nEl dia ingresado no existe");
             }while(dato<y||dato>z);
     }
     if(a==3)
     {
         do
             {
                 printf("\nIngrese el las horas trabajadas por el chofer ");
                 scanf ("%d",&dato);
                 if(dato<y||dato>z)
                    printf("\nLas horas trabajadas no son validas");
             }while(dato<y||dato>z);
     }
     return dato;
 };

 void ordenamiento(int cod[],int sueld[],int n)
{
    int x,j,aux;
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(sueld[j]<sueld[j+1])
            {
                aux=cod[j];
                cod[j]=cod[j+1];
                cod[j+1]=aux;

                aux=sueld[j];
                sueld[j]=sueld[j+1];
                sueld[j+1]=aux;
            }
        }
    }
    printf("\nLISTADO DE SUELDOS ABONADOS ORDENADO");
    printf("\nCODIGO     SUELDO ");
    for(x=0;x<n;x++)
    {
        printf("\n%d\t\t%d",cod[x],sueld[x]);
    }
}
