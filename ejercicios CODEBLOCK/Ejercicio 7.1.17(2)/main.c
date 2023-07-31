/*En un negocio trabajan 12 vendedores. Cada vez que se realiza una venta durante el d�a,
se emite una factura donde se indican los siguientes datos:
� N�mero de Factura (entero, mayor que cero).
� C�digo de vendedor (entero).
� Importe de la venta (real, mayor que cero).
La informaci�n termina con un n�mero de Factura igual a cero. Al principio del ingreso,
se debe solicitar la fecha del d�a de procesamiento. Se pide informar con las leyendas aclaratorias:
� Importe total por facturaci�n por cada vendedor y Cantidad de facturas emitidas por
vendedor, ordenando de forma descendente por importe, con el siguiente formato:
Desarrollar 2 programas:
a. Con c�digo de vendedor num�rico correlativo de 1 a 12.
b. Con c�digo de vendedor num�rico de 3 cifras, no correlativo*/


#include <stdio.h>
#include <stdlib.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );
void mostrar_puntoB (int[],int[],float[],int,int,int,int);
int busqueda_secuencial (int[],int,int);

int main()
{
    int dia,mes,anio,validacion;
    int num_fac[100],cod_vend[100],x=0,a=0;
    float imp_venta[100];
    do
    {
        printf("FECHA DEL DIA DEL PROCESO:\n");
        printf("Ingrese un anio: ");
        scanf("%d",&anio);
        printf("Ingrese un mes: ");
        scanf("%d",&mes);
        printf("Ingrese un dia: ");
        scanf("%d",&dia);
        validacion=ValidarFecha(anio,mes,dia);
        if(validacion!=1)
            printf("\nFecha Invalida\n");
    }while(validacion!=1);
    while(validacion==1&&x<100&&a==0)
    {
        do
        {
            printf("Ingrese el nro de factura: ");
            scanf("%d",&num_fac[x]);
            if (num_fac[x]==0)
                a=1;
        }while(num_fac[x]<0);
        while(num_fac[x]>0)
        {
            do
            {
                printf("Ingrese el codigo de vendedor: ");
                scanf("%d",&cod_vend[x]);
            }while(cod_vend[x]<100||cod_vend[x]>999);
            do
            {
                printf("Ingrese el importe de la venta: ");
                scanf("%f",&imp_venta[x]);
            }while(imp_venta[x]<0);
            x++;
            do
            {
                printf("Ingrese el nro de factura: ");
                scanf("%d",&num_fac[x]);
                if (num_fac[x]==0)
                    a=1;
            }while(num_fac[x]<0);
        }
        //system("cls");
        mostrar_puntoB(cod_vend,num_fac,imp_venta,dia,mes,anio,x);
    }
    return 0;
}

int DIAS (int a, int m)
{
    int d;
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            d=30;
            break;
        case 2:
            if((a%4==0&&a%100!=0)||(a%400==0))
                d=29;
            else
                d=28;
            break;
    }
    return d;
}

int ValidarFecha (int a, int m, int d)
{
    int c,dias;
    if (m<1||m>12)
        c=0;
    dias=DIAS(a,m);
    if(d<=dias)
        c=1;
    else
        c=0;
    return c;
}

void mostrar_puntoB (int vendedor[],int facturas[],float importe[],int d, int m, int a,int n)
{
    int x,repite,i,cant_fac[n],cod_vend[n];
    float nuevos_import[n];
    for(x=0;x<n;x++)
    {
        repite=busqueda_secuencial(vendedor,n,vendedor[x]);
        if(repite!=-1)
        {
            cod_vend[x]=vendedor[x];
            importe[x]+=importe[repite];
            nuevos_import[x]=importe[x];
            cant_fac[x]++;
        }
        else
        {
            cod_vend[x]=vendedor[x];
            nuevos_import[x]=importe[x];
            cant_fac[x]=1;
        }
    }
    printf("\n\nVENTAS AL DIA: %d/%d/%d",d,m,a);
    printf("\nNUMERO DE VENDEDOR:\tIMPORTE VENDIDO:\tCANTIDAD DE FACTURAS EMITIDAS:");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t\t\t%f\t\t\t%d",cod_vend[i],nuevos_import[i],cant_fac[i]);
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
