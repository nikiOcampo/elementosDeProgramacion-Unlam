/*7.2.7 Una empresa desea registrar las ventas realizadas de cada uno de sus 20 productos
a lo lardo del año. Los productos están identificados por un código numérico correlativo del 1 al 20.
 Como primera información se ingresa el precio unitario de cada uno de los productos.
 Luego por cada venta se ingresa:
• Código de producto
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. Informar:
a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
b. El producto con el cual se obtuvo la mayor recaudación.
c. El trimestre de menor recaudación del año.*/

#include <stdio.h>
#include <stdlib.h>

void carga(float[],int);
void carga_venta (int [][20]);
void mostrar (int [][20],int,int);
void punto_b(int[][20],float[],int,int);
void punto_c(int[][20],float[],int,int);

int main()
{
    float precios_unitarios[20];
    int m[12][20]={0};
    carga(precios_unitarios,20);
    carga_venta(m);
    mostrar(m,12,20);
    punto_b(m,precios_unitarios,12,20);
    punto_c(m,precios_unitarios,12,20);
    return 0;
}

void carga(float precios[], int n)
{
    int x;
    for (x=0;x<n;x++)
    {
        printf("\nIngrese el precio del producto nro %d:",x+1);
        scanf("%f",&precios[x]);
    }
}
/*Luego por cada venta se ingresa:
• Código de producto
• Día de venta
• Mes de venta
• Cantidad de unidades vendidas
El ingreso de datos finaliza con un código de producto igual a 0. */
void carga_venta (int m[][20])
{
    int codigo,mes,dia,unidades_vendidas;
    do
    {
        system("cls");
        printf("\nIngrese el codigo de producto que se vendio: ");
        scanf("%d",&codigo);
        if(codigo<0||codigo>20)
            printf("\nCODIGO INEXISTENTE");
    }while(codigo<0||codigo>20);
    while (codigo!=0)
    {
       do
       {
           printf("\nIngrese el mes de la venta: ");
           scanf("%d",&mes);
           if(mes<1||mes>12)
            printf("\nMES INEXSISTENTE");
       }while(mes<1||mes>12);
       if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)
       {
           do
           {
                printf("\nIngrese el dia de la venta: ");
                scanf("%d",&dia);
                if(dia<1||dia>31)
                    printf("\nDIA NO VALIDO");
           }while(dia<1||dia>31);
       }
       if(mes==4||mes==6||mes==9||mes==11)
       {
           do
           {
                printf("\nIngrese el dia de la venta: ");
                scanf("%d",&dia);
                if(dia<1||dia>30)
                    printf("\nDIA NO VALIDO");
           }while(dia<1||dia>30);
       }
       if(mes==2)
       {
           do
           {
                printf("\nIngrese el dia de la venta: ");
                scanf("%d",&dia);
                if(dia<1||dia>29)
                    printf("\nDIA NO VALIDO");
           }while(dia<1||dia>29);
       }
       printf("Ingrese la cantidad de unidades vendidas de ese articulo: ");
       scanf("%d",&unidades_vendidas);
       m[mes-1][codigo-1]+=unidades_vendidas;
       do
        {
            printf("\nIngrese el codigo de producto que se vendio: ");
            scanf("%d",&codigo);
            if(codigo<0||codigo>20)
                printf("\nCODIGO INEXISTENTE");
        }while(codigo<0||codigo>20);
    }
}

//a. El detalle de unidades vendidas de cada producto en cada uno de los 12 meses.
void mostrar(int m[][20], int f, int c)
{
    int x,i;
    system("cls");
    printf("                        Producto:\n");
    printf("       ");
    for(x=0;x<c;x++)
    {
        printf("%2d ",x+1);
    }
    for(x=0;x<f;x++)
    {
        printf("\nMes:%d ",x+1);
        for(i=0;i<c;i++)
        {
            printf("%2d ",m[x][i]);
        }
    }
}

//b. El producto con el cual se obtuvo la mayor recaudación.
void punto_b(int m[][20], float precios[],int f,int c)
{
    int x,i;
    float max;
    float mayor[20]={0},suma[20]={0};
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma[x]+=m[i][x];//suma[x] es la cantidad de productos vendidos en el año
            mayor[x]=suma[x]*precios[x];//mayor[x] es la recaudacion que se hizo por producto
        }
    }
    max=mayor[0];
    for(x=1;x<c;x++)
    {
        if(mayor[x]>max)
            max=mayor[x];
    }
    printf("\nLa mayor recaudacion fue de %f, obtenida por el/los producto/s:", max);
    for(x=0;x<c;x++)
    {
        if(max==mayor[x])
            printf("\n%d",x+1);
    }
}

//c. El trimestre de menor recaudación del año.*/
void punto_c(int m[][20],float pre_unidad[],int f,int c)
{
    int x,i,suma[20]={0},j;
    float recauda[20],trimestres[4]={0},mayor;
    for(j=0;j<4;j++)
    {
        for(x=0;x<c;x++)
        {
            for(i=j*3;i<(j*3)+3;i++)//primer trimestre
            {
                suma[x]+=m[i][x];//suma de los productos hasta el tercer mes
                recauda[x]=suma[x]*pre_unidad[x];//cantidad recaudada por producto hasta el tercer mes por producto
            }
            trimestres[j]+=recauda[x];//cantidad total recaudad en el trimestre
        }
    }
    mayor=trimestres[0];
    for(x=1;x<4;x++)
    {
        if(trimestres[x]>mayor)
            mayor=trimestres[x];
    }
    printf("\nLa mayor recaudacion por trimestre fue de %f, dada en el/los trimestre/s nro: ",mayor);
    for(x=0;x<4;x++)
    {
        if(trimestres[x]==mayor)
            printf("\n%d",x);
    }
}
