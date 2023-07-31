/*Realizar los siguientes vectores con 10 valores reales. Confeccionar un programa para:
a. Generar el vector VA con la informaci�n ingresada por teclado.
b. Generar el vector VB, donde cada elemento es la ra�z cuadrada del respectivo elemento de VA.
(para el c�lculo de la ra�z cuadrada utilizar la funci�n sqrt disponible en la biblioteca math.h).
Si el n�mero es negativo poner un 0 ya que no se puede calcular la ra�z
c. Calcular el vector VC como VA+VB.
d. Copiar el vector VC en orden inverso en otro vector llamado VD.
e. Hallar el valor m�ximo del vector VA y en qu� posici�n se hall� (el mayor es �nico).
f. Hallar el valor m�nimo del vector VB y en qu� posiciones se hallaron (el m�nimo se pude repetir).
g. Dado un valor ingresado por teclado, indicar en qu� posici�n se encontr� del vector VC.
h. Ordenar el vector VD en forma ascendente (de menor a mayo).
i. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
j. Mostrar el contenido de todos los vectores.
FUNCIONES:
I. Para el ingreso del vector AA, del punto a).
II. Para generar el vector CC, del punto c).
III. Para realizar la b�squeda del punto g).
IV. Para realizar el ordenamiento del punto h).
V. Para generar el vector VE del punto i).
VI. Para mostrar los valores de todos los vectores del punto j).*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void Carga_VectorAA (int[],int);
void GeneracionVectorCC (int[],int[],int[],int);
int busqueda_secuencial (int[],int,int);
void ordenamiento (int[],int);
int VectorVE (int[],int[],int);
void MostrarVectorVE (int[],int);

int main()
{
    int VA[10]={0},VB[10]={0},VC[10]={0},VD[10]={0},VE[10];
    int num,max,pos,min,num_buscado,pos3,a;
    int i=0,j,z=0,x,k,l,m;
    Carga_VectorAA(VA,10);
    for(i=0;i<10;i++)
    {
        num=VA[i];
        VB[i]= sqrt(num);
    }
    GeneracionVectorCC(VA,VB,VC,10);
    for(j=9;j>=0;j--)
    {
        VD[j]=VC[z];
        z++;
    }
    //e. Hallar el valor m�ximo del vector VA y en qu� posici�n se hall� (el mayor es �nico).
    max=VA[0];
    for(x=1;x<10;x++)
    {
        if(max<VA[x])
        {
            max=VA[x];
            pos=x;
        }
    }
    printf("\nEl valor maximo del vector VA fue de %d, hallada en la posicion:%d ",max,pos+1);
    //Hallar el valor m�nimo del vector VB y en qu� posiciones se hallaron (el m�nimo se pude repetir).
    min=VB[0];
    for(k=1;k<10;k++)
    {
        if(min>VB[k])
        {
            min=VB[k];
        }
    }
    printf("\nEl valor minimo del vector VB fue de %d, hallado en la/las posicion/es: ",min);
    for(l=0;l<10;l++)
    {
        if(VB[l]==min)
            printf("\n%d",l+1);
    }
    //g. Dado un valor ingresado por teclado, indicar en qu� posici�n se encontr� del vector VC.
    printf("\nIngrese el valor que desea buscar en el Vector C: ");
    scanf("%d",&num_buscado);
    pos3=busqueda_secuencial(VC,10,num_buscado);
    if(pos3==-1)
        printf("El valor buscado no se encuentra en el vector C");
    else
        printf("\nEl valor ingresado %d, se ecuentra en la posicion %d del vector C",num_buscado,pos3+1);
    //h. Ordenar el vector VD en forma ascendente (de menor a mayor).
    ordenamiento(VD,10);
    //i. Generar un vector VE con aquellos valores negativos que se encuentran en el vector VA.
    a=VectorVE(VE,VA,10);
    //j. Mostrar el contenido de todos los vectores.
    printf("\nNumeros del vector A:");
    for(m=0;m<10;m++)
    {
        printf("\n%d",VA[m]);
    }
    printf("\nNumeros del vector B:");
    for(m=0;m<10;m++)
    {
        printf("\n%d",VB[m]);
    }
    printf("\nNumeros del vector C:");
    for(m=0;m<10;m++)
    {
        printf("\n%d",VC[m]);
    }
    printf("\nNumeros del vector D:");
    for(m=0;m<10;m++)
    {
        printf("\n%d",VD[m]);
    }
    printf("\nNumeros del vector E:");
    MostrarVectorVE(VE,a);
    return 0;
}

//I. Para el ingreso del vector AA, del punto a).
void Carga_VectorAA( int v[], int n)
{
    int x,pos=0;
    for(x=0;x<n;x++)
    {
        do
        {
            printf("Ingrese el valor nro %d: ",x+1);
            scanf("%d",&v[x]);
            pos=busqueda_secuencial(v,x,v[x]);
        }while(pos!=-1);
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

void GeneracionVectorCC(int vec_1[], int vec_2[], int vec_3[], int n)
{
    int x;
    for(x=0;x<n;x++)
    {
        vec_3[x]=vec_1[x]+vec_2[x];
    }
}

void ordenamiento(int v[], int n)
{
    int j, cota, aux, desordenado,i;
    cota = n-1;
    desordenado =1;
    while (desordenado !=0)
    {
        desordenado=0;
        for (j=0; j<cota; j++)
            if (v[j]>v[j+1])
            {
                aux = v[j];
                v[j]=v[j+1];
                v[j+1] = aux;
                desordenado = j;
            }
        cota = desordenado;
    }
    printf("\nVECTOR D ORDENADO DE FORMA ASCENDENTE:");
    for(i=0;i<n;i++)
    {
        printf("\n%d",v[i]);
    }
}

int VectorVE(int vE[],int vA[], int n)
{
    int x,j=0;
    for(x=0;x<n;x++)
    {
        if(vA[x]<0)
        {
            vE[x]=vA[x];
            j++;
        }
    }
    return j;
}

void MostrarVectorVE (int Vector_E[], int n)
{
    int x;
    for(x=0;x<n;x++)
    {
        printf("\n%d",Vector_E[x]);
    }
}

