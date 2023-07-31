/*8.5. Una empresa de alquiler de autos tiene una flota de 30 autos de alta gama,
identificados por su número de patente, cargado en la memoria principal en un vector de 30 posiciones.
 Al comenzar el procesamiento de los alquileres, se ingresa la fecha y la cotización del dólar de ese día.
  A continuación, se ingresan los siguientes datos correspondiente a cada alquiler realizado en el día:
• Patente del auto (alfanumérico, de 6 caracteres)
• Cantidad de días de alquiler (entero, mayor que 0)
• Precio diario del alquiles en dólares (real, mayor que 0)
Para finalizar la carga del día, se ingresa una patente de auto igual a “FINDIA”
Determinar e informar:
a. El porcentaje de autos alquilados durante el día.
b. Realizar el informe con el formato siguiente:*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );
void punto_b (char[][7],int [],float[],int,int,int,int,float);

int main()
{
    char patentes[30][7];
    int dias_alquier[30],dia,mes,anio,validacion,x,cont=0;
    float cotizacion_dia,precio_alquier[30],porcentaje;
    do
    {
        printf("Ingrese un anio: ");
        scanf("%d",&anio);
        printf("\nIngrese un mes: ");
        scanf("%d",&mes);
        printf("\nIngrese un dia: ");
        scanf("%d",&dia);
        validacion=ValidarFecha(anio,mes,dia);
        if(validacion!=1)
            printf("\nFecha Invalida");
    }while(validacion!=1);
    while(validacion==1&&x<30)
    {
        printf("\nIngrese la cotizacion del dolar de ese dia: ");
        scanf("%f",&cotizacion_dia);
        x=0;
        validacion=0;
        printf("\nIngrese la patente del auto: ");
        fflush(stdin);
        gets(patentes[x]);
        while((strcmpi(patentes[x],"FINDIA"))!=0)
        {
            x++;
            cont++;
            do
            {
                printf("\nIngrese la cantidad de dias que desea alquilar: ");
                scanf("%d",&dias_alquier[x-1]);
            }while(dias_alquier[x-1]<0);
            do
            {
                printf("\nIngrese el precio diario del alquiler en dolares: ");
                scanf("%f",&precio_alquier[x-1]);
            }while(precio_alquier[x-1]<0);
            printf("\nIngrese la patente del auto: ");
            fflush(stdin);
            gets(patentes[x]);
        }
        porcentaje=(float)(cont*30)/100;
        printf("\nEl porcentaje de autos alquilados durante el dia fue de: %0.2f ",porcentaje);
        punto_b(patentes,dias_alquier,precio_alquier,dia,mes,anio,x,cotizacion_dia);
    }
    return 0;
}

void punto_b(char nrodeauto[30][7], int dias[],float precio_dolar[],int dia,int mes,int anio,int n,float dolar)
{
    float precio_pesos[30],total_pesos=0,total_dolar=0;
    int x,sen,dia2,d[30],m[30],a[30];
    for(x=0;x<n;x++)
    {
        precio_pesos[x]=(precio_dolar[x]*dolar)*dias[x];
        sen=DIAS(anio,mes);
        dia2=dia+dias[x];
        while(sen<dia2)
        {
            dia2-=sen;
            if(mes==12)
            {
                mes=1;
                anio++;
            }
            else mes++;
            sen=DIAS(mes,anio);
        }
        d[x]=dia2;
        m[x]=mes;
        a[x]=anio;
    }
    printf("\n\t\t\tALQUIER DE AUTOS AL DIA:%d/%d/%d\t\n",dia,mes,anio);
    printf("\n\t\tCOTIZACION DEL DOLAR:%0.2f\n",dolar);
    printf("\nNRO DE AUTO:  DIAS DE ALQUILER  PRECIO DE ALQUILER EN PESOS  FECHA DE DEVOLUCION");
    for(x=0;x<n+1;x++)
    {
        if((strcmpi(nrodeauto[x],"findia"))==0)//hacer con biblioteca
            printf(" ");
        else
        printf("\n%s              %d                   %0.2f                  %d/%d/%d", nrodeauto[x],dias[x], precio_pesos[x],d[x], m[x], a[x]);
        total_pesos+=precio_pesos[x];
        total_dolar+=precio_dolar[x]*dias[x];
    }

    printf("\nTOTAL RECUADADO EN PESOS:%0.2f",total_pesos);
    printf("\nTOTAL RECUADADO EN DOLARES:%0.2f",total_dolar);
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
