/*La Empresa   “Charlie Chocolate Factory” de Willy Wonka, posee una planta distribuidora en Capital Federal,
 necesita hacer una estadística de ventas de los distintos productos que ofrece al mercado.
  Se cuenta con la siguiente información  no ordenada. Finaliza  la carga de la misma con un producto =  0.
Producto  [1-50]
Mes       [1-12]
Ventas    (por unidades)
(se cuenta con un vector YA cargado de 50 elementos que contiene el precio de los productos llamado p_venta)
Se pide:   A - Mes que se vendieron más Unidades.
    B - Del mes de Enero que Producto se Vendió más Unidades.
    C - Del mes de Julio que producto recaudo (plata) más.
    D - Mostrar en forma ordenada la cantidad total de  productos vendidos por mes
          durante  todo el año.
                               Mes     Cantidad Vendida
                                7            35000
                                10           32400
                                3            31300
                                1	         30900
                                2	         29800
                                Etc.
Funciones:
    1  -  Ingreso de Producto y Mes,  Validar
    2  -  El ordenamiento del punto   D)

*/

#include <stdio.h>
#include <stdlib.h>

int LeerYValidar (int, int,int);
void punto_C (float[],int[][50],int,int);
void punto_D (int[],int);

int main()
{
    float p_ventas[50];
    int m[12][50]={{0}},x,producto,mes,i,suma_fila[50]={0},max=0,j,cant_vendida,enero;
    for(x=0;x<50;x++)
    {
        p_ventas[x]=10*(x+1);
    }
    producto= LeerYValidar(0,50,1);
    while(producto!=0)
    {
        mes=LeerYValidar(1,12,2);
        do
        {
            printf("\nIngrese la cantidad de unidades vendidas de ese producto: ");
            scanf("%d",&cant_vendida);
        }while(cant_vendida<0);
        m[mes-1][producto-1]+=cant_vendida;
        producto= LeerYValidar(0,50,1);
    }
    //A - Mes que se vendieron más Unidades.
    system("cls");
    for(x=0;x<12;x++)
    {
        for(i=0;i<50;i++)
        {
            suma_fila[x]+=m[x][i];
        }
    }
    max=suma_fila[0];
    for (i=1;i<12;i++)
    {
        if (suma_fila[i]>max)
            max=suma_fila[i];
    }
    printf("\n\nLa mayor cantidad de unidades vendidas es de %d, vendidas en el/los mes/es: ",max);
    for(j=0;j<12;j++)
    {
        if(suma_fila[j]==max)
            printf("\n%d",j+1);
    }
     // B - Del mes de Enero que Producto se Vendió más Unidades.
    enero=m[0][0];
    for(i=0;i<50;i++)
    {
        if(m[0][i]>enero)
            enero=m[0][i];
    }
    if(enero==0)
        printf("\n\nNO hubo ventas en el mes de enero");
    else
    {
        printf("\n\nLa mayor cantidad de unidades vendidas de un mismo producto en Enero fue de %d, de el/los producto/s nro: ",enero);
        for(i=0;i<50;i++)
        {
            if(m[0][i]==enero)
                printf("\n%d",i+1);
        }
    }
    // C - Del mes de Julio que producto recaudo (plata) más.
    punto_C(p_ventas,m,12,50);
    punto_D(suma_fila,12);
    return 0;
}

int LeerYValidar(int x ,int y,int n)
{
    int dato;
    do
    {
        if(n==1) printf("\nIngrese el numero del producto: ");
        if(n==2) printf("\nIngrese el mes: ");
        scanf("%d",&dato);
    }while(dato<x||dato>y);
    return dato;
}

// C - Del mes de Julio que producto recaudo (plata) más.
void punto_C(float precios[],int m[12][50],int f,int c)
{
    int x;
    float recaudacion[50]={0},max;
    for (x=0;x<c;x++)
    {
        recaudacion[x]=(float)m[6][x]*precios[x];
    }
    max=recaudacion[0];
    for(x=1;x<c;x++)
    {
        if(recaudacion[x]>max)
            max=recaudacion[x];
    }
    if(max==0)
        printf("\n\nNo hubo ventas en el mes de Julio");
    else
    {
        printf("\n\nLa mayor cantidad de dineral recaudado en el mes de Julio fue de %0.2f, recaudado por el producto nro: ",max);
        for(x=0;x<c;x++)
        {
            if(recaudacion[x]==max)
                printf("\n%d",x+1);
        }
    }
}

/*D - Mostrar en forma ordenada la cantidad total de  productos vendidos por mes
          durante  todo el año.
                               Mes     Cantidad Vendida
                                7            35000
                                10           32400
                                3            31300
                                1	         30900
                                2	         29800
                                Etc.*/

void punto_D(int cant_vendidas[],int n)
{
	int meses[12]={1,2,3,4,5,6,7,8,9,10,11,12};
	int sen=0,i,aux;
	while(sen==0)
	{
		sen=1;
		for(i=0;i<n-1;i++)
		{
			if(cant_vendidas[i]<cant_vendidas[i+1])
			   {
			   	aux=cant_vendidas[i];
			   	cant_vendidas[i]=cant_vendidas[i+1];
			   	cant_vendidas[i+1]=aux;
			   	aux=meses[i];
			   	meses[i]=meses[i+1];
			   	meses[i+1]=aux;
			   	sen=0;
			   }
		}
    }
   printf("\n MES:     CANTIDAD VENDIDA: \n");
   for(i=0;i<12;i++)
     {
     	printf("\n %d\t\t\t%d",meses[i],cant_vendidas[i]);
	 }

}
