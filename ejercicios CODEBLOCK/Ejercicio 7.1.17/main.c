/*En un negocio trabajan 12 vendedores. Cada vez que se realiza una venta durante el día,
se emite una factura donde se indican los siguientes datos:
• Número de Factura (entero, mayor que cero).
• Código de vendedor (entero).
• Importe de la venta (real, mayor que cero).
La información termina con un número de Factura igual a cero. Al principio del ingreso,
se debe solicitar la fecha del día de procesamiento. Se pide informar con las leyendas aclaratorias:
• Importe total por facturación por cada vendedor y Cantidad de facturas emitidas por
vendedor, ordenando de forma descendente por importe, con el siguiente formato:
Desarrollar 2 programas:
a. Con código de vendedor numérico correlativo de 1 a 12.
b. Con código de vendedor numérico de 3 cifras, no correlativo*/

#include <stdio.h>
#include <stdlib.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );
void mostrar_puntoA (int[],int[],float[],int,int,int,int);

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
            }while(cod_vend[x]<1||cod_vend[x]>12);
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
        system("cls");
        mostrar_puntoA(cod_vend,num_fac,imp_venta,dia,mes,anio,x);
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

void mostrar_puntoA(int vendedor[],int facturas[],float importe[],int d, int m, int a,int n)
{
    int x,i,cant_fact[12]={0};
    float importes_nuevos[12]={0};
    for(x=0;x<n;x++)
    {
        switch(vendedor[x])
        {
        case 1:
            importes_nuevos[0]+=importe[x];
            cant_fact[0]++;
            break;
        case 2:
            importes_nuevos[1]+=importe[x];
            cant_fact[1]++;
            break;
        case 3:
            importes_nuevos[2]+=importe[x];
            cant_fact[2]++;
            break;
        case 4:
            importes_nuevos[3]+=importe[x];
            cant_fact[3]++;
            break;
        case 5:
            importes_nuevos[4]+=importe[x];
            cant_fact[4]++;
            break;
        case 6:
            importes_nuevos[5]+=importe[x];
            cant_fact[5]++;
            break;
        case 7:
            importes_nuevos[6]+=importe[x];
            cant_fact[6]++;
            break;
        case 8:
            importes_nuevos[7]+=importe[x];
            cant_fact[7]++;
            break;
        case 9:
            importes_nuevos[8]+=importe[x];
            cant_fact[8]++;
            break;
        case 10:
            importes_nuevos[9]+=importe[x];
            cant_fact[9]++;
            break;
        case 11:
            importes_nuevos[10]+=importe[x];
            cant_fact[10]++;
            break;
        case 12:
            importes_nuevos[11]+=importe[x];
            cant_fact[11]++;
            break;
        }
    }
    printf("\n\nVENTAS AL DIA: %d/%d/%d",d,m,a);
    printf("\nNUMERO DE VENDEDOR:\tIMPORTE VENDIDO:\tCANTIDAD DE FACTURAS EMITIDAS:");
    for(i=0;i<12;i++)
    {
        printf("\n%d\t\t\t%f\t\t\t%d",i+1,importes_nuevos[i],cant_fact[i]);
    }
}

