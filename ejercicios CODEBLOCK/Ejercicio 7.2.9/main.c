/*7.2.9 Se desea contabilizar los votos recibidos en las elecciones de un club de fútbol.
Existen 10 candidatos cada uno representado por un número de lista diferente (número de 3 cifras no correlativo).
La votación se realiza en 15 sedes distintas codificadas del 1 al 15.
 Se ingresan los votos registrados en cada una de las sedes registrando:
• Número de lista
• Número de sede
• Cantidad de votos
(Solo se informan candidatos que recibieron votos).
La carga de votos finaliza con un número de lista igual a 0
Mostrar:
a. Cantidad de votos recibidos por cada candidato en cada sede.
b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
c. Candidatos que NO recibieron votos en la sede 5.*/

#include <stdio.h>
#include <stdlib.h>

void carga(int[10][15],int,int,int[]);
void punto_a(int [10][15],int[],int,int);
int busqueda_secuencial (int[], int, int);
void punto_b (int [][15],int[],int,int);
void ordenamiento (int[], float[],int[],int);
void punto_c(int [][15],int,int[],int);

int main()
{
    int candidatos[10]={0},m[10][15]={0};
    carga(m,10,15,candidatos);
    punto_a(m,candidatos,10,15);
    punto_b(m,candidatos,10,15);
    punto_c(m,10,candidatos,5);
    return 0;
}

void carga(int m[][15],int f,int c,int num_lista[])
{
    int candidato,sede,cant_votos,x,pos;
        for(x=0;x<10;x++)
        {
            do
            {
                printf("Ingrese el numero de lista nro %d: ",x+1);
                scanf("%d",&num_lista[x]);
                if (num_lista[x]<100||num_lista[x]>999)
                    printf("\nEl numero ingresado no es valido");
            }while(num_lista[x]<100||num_lista[x]>999);
        }
        do
        {
            printf("\nIngrese el numero de lista del que desea cargar votos: ");
            scanf("%d",&candidato);
            pos=busqueda_secuencial(num_lista,10,candidato);
            if (pos==-1 && candidato!=0)
                    printf("\nEl numero ingresado no es valido");
        }while(pos==-1 && candidato!=0);
        while(candidato!=0)
        {
            do{
                printf("\nIngrese el numero de sede: ");
                scanf("%d",&sede);
                if(sede<1||sede>15)
                    printf("\nEl numero de sede no es valido");
            }while(sede<1||sede>15);
            printf("\nIngrese la cantidad de votos: ");
            scanf("%d",&cant_votos/*&m[x][sede-1]*/);
            m[pos][sede-1]+=cant_votos;
            do
            {
                printf("\nIngrese el numero de lista del que desea cargar votos: ");
                scanf("%d",&candidato);
                pos=busqueda_secuencial(num_lista,10,candidato);
                if (pos==-1 && candidato!=0)
                        printf("\nEl numero ingresado no es valido");
            }while(pos==-1 && candidato!=0);
        }
}

int busqueda_secuencial (int v[], int cant, int elem)
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
}

//a. Cantidad de votos recibidos por cada candidato en cada sede.
void punto_a(int m[][15],int num_lista[],int f,int c)
{
    int x,i;
    system("cls");
    printf("\n             SEDES:\n");
    printf("           ");
    for(x=0;x<c;x++)
    {
        printf(" %2d  ",x+1);
    }
    for(x=0;x<f;x++)
    {
        printf("\nLISTA: %d  ",num_lista[x]);
        for(i=0;i<c;i++)
        {
            if(m[x][i]==0)
                printf("  X  ");
            else
                printf("%3d ",m[x][i]);
        }
    }
}

//b. Listado ordenado por cantidad de votos totales en formar decreciente, con el siguiente formato:
void punto_b (int m[][15],int num_lista[], int f,int c)
{
    int x,i,totateles[10]={0},totalvotos=0;
    float porentajes[10]={0};
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            totateles[x]+=m[x][i];
            //totalvotos+=totateles[x];
        }
        totalvotos+=totateles[x];
    }
    for(x=0;x<f;x++)
    {
        porentajes[x]=(float)(totateles[x]*100)/totalvotos;
    }
    ordenamiento(totateles,porentajes,num_lista,f);
}

void ordenamiento(int total[],float porcentaje[],int lista[],int n)
{
    int x,j,aux;
    float auxf;
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(total[j]<total[j+1])
            {
                aux=total[j];
                total[j]=total[j+1];
                total[j+1]=aux;

                auxf=porcentaje[j];
                porcentaje[j]=porcentaje[j+1];
                porcentaje[j+1]=auxf;

                aux=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;
            }
        }
    }
    system("cls");
    printf("\nTOTAL DE VOTOS:  PORCENTAJES:  LISTA: ");
    for(x=0;x<n;x++)
    {
        printf("\n  %d\t\t%f\t\t%d ",total[x],porcentaje[x],lista[x]);
    }
}

//c. Candidatos que NO recibieron votos en la sede 5.*/
void punto_c(int m[][15],int f,int num_lista[],int n)
{
    int x;
    printf("\nLos candidatos que no recibieron votos en la sede 5 fueron: ");
    for(x=0;x<f;x++)
    {
        if(m[x][n-1]==0)
            printf("\n%d",num_lista[x]);
    }


}
