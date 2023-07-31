/*Un Laboratorio de medicamentos quiere actualizar las ventas acumuladas a la fecha,
 dispone para este trabajo de un archivo llamado “VENTAS.dat” con las ventas acumuladas del año,
  hasta la fecha de proceso con los siguientes datos:
• Número de visitador médico de 1 a 15 (entero)
• Código del medicamento de 1 a 30 (entero)
• Cantidad de unidades vendidas (entero)
Este archivo está clasificado y ordenado en forma ascendente por número de visitador médico y luego por el
código del medicamento. Pueden NO estar todos los códigos de medicamentos ni todos los visitadores médicos “activos”.
La información que se registra por teclado de las ventas del día NO está ordenada y para finalizar se ingresa un número
de cliente igual a 0. Los datos disponibles son:
• Número de Cliente (entero entre 1 y 50000)
• Número de Visitador Médico (entero)
• Código de medicamento (entero)
• Cantidad vendida (entero)
• Importe facturado (float)
Se solicita escribir un programa que permita:
a. Leer el archivo “VENTAS.dat” y los cargue en la matriz TOTAL de 15 por 30 elementos.
b. Ingresar por teclado, la fecha de proceso (día, mes, año).
c. Procesar las ventas del día.
d. Actualizar los acumulados de la matriz TOTAL y al finalizar actualizar el archivo “VENTAS.dat”.
e. Imprimir un listado con el siguiente diseño:
f. Al finalizar el proceso informe el número de Visitador Médico que en el día vendió el mayor importe. (Total Facturado).*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int nro_visitador;
    int cod_medi;
    int cant_vend;
}anio;

typedef struct
{
    int nro_clien;
    int nro_visitador;
    int cod_medi;
    int cant_vend;
    float importe;
}dia;

int lee_control(int,int,int);
int mayor_cero();
float validarfloat();
int ValidarFecha (int,int,int);
int DIAS(int, int );
int cargarventasanuales(anio[]);
void cargamatriz(anio[],int [][30],int);
int cargaventasdeldia(dia[],float[],float[]);
void actualizarmatriz(int[][30],dia[],int);
void mostrarinforme(float[],int,int,int,int);
void informarmayor(float[],int);

int main()
{
    dia venta_dia[1000];
    anio ventas_anio[10000];
    int cant,TOTAL[15][30]={{0}},d,mes,anio,validacion,cant_dia;
    float imp_x_medicamento[30]={0},imp_x_visitador[15]={0};
    cant=cargarventasanuales(ventas_anio);
    cargamatriz(ventas_anio,TOTAL,cant);
    system("cls");
    printf("\nCARGA DEL DIA: ");
    do
    {
        printf("\nIngrese un dia: ");
        scanf("%d",&d);
        printf("Ingrese un mes: ");
        scanf("%d",&mes);
        printf("Ingrese un anio: ");
        scanf("%d",&anio);
        validacion=ValidarFecha(anio,mes,d);
    }while(validacion!=1);
    cant_dia=cargaventasdeldia(venta_dia,imp_x_medicamento,imp_x_visitador);
    actualizarmatriz(TOTAL,venta_dia,cant_dia);
    system("cls");
    mostrarinforme(imp_x_medicamento,d,mes,anio,30);
    informarmayor(imp_x_visitador,15);
    return 0;
}

int cargarventasanuales(anio ventas_anio[])
{
    int x=0,i,j,aux;
    FILE*fp;
    fp=fopen("Ventas.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    ventas_anio[x].nro_visitador=lee_control(0,15,1);
    while(ventas_anio[x].nro_visitador!=0)
    {
        ventas_anio[x].cod_medi=lee_control(1,30,2);
        ventas_anio[x].cant_vend=mayor_cero();
        x++;
        ventas_anio[x].nro_visitador=lee_control(0,15,1);
    }
    //ordenado en forma ascendente por número de visitador médico y luego por el código del medicamento.
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-1;j++)
        {
            if(ventas_anio[j].nro_visitador>ventas_anio[j+1].nro_visitador)
            {
                aux=ventas_anio[j].nro_visitador;
                ventas_anio[j].nro_visitador=ventas_anio[j+1].nro_visitador;
                ventas_anio[j+1].nro_visitador=aux;

                aux=ventas_anio[j].cant_vend;
                ventas_anio[j].cant_vend=ventas_anio[j+1].cant_vend;
                ventas_anio[j+1].cant_vend=aux;

                aux=ventas_anio[j].cod_medi;
                ventas_anio[j].cod_medi=ventas_anio[j+1].cod_medi;
                ventas_anio[j+1].cod_medi=aux;
            }
        }
    }
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-1-x;j++)
        {
            if(ventas_anio[j].nro_visitador==ventas_anio[j+1].nro_visitador&&ventas_anio[j].cod_medi>ventas_anio[j+1].cod_medi)
            {
                aux=ventas_anio[j].cod_medi;
                ventas_anio[j].cod_medi=ventas_anio[j+1].cod_medi;
                ventas_anio[j+1].cod_medi=aux;

                aux=ventas_anio[j].nro_visitador;
                ventas_anio[j].nro_visitador=ventas_anio[j+1].nro_visitador;
                ventas_anio[j+1].nro_visitador=aux;

                aux=ventas_anio[j].cant_vend;
                ventas_anio[j].cant_vend=ventas_anio[j+1].cant_vend;
                ventas_anio[j+1].cant_vend=aux;

                fwrite(&ventas_anio[j],sizeof(anio),1,fp);
            }
        }
    }
    fclose(fp);
    return x;
}

void cargamatriz(anio ventas_anio[],int m[][30],int n)
{
    int x;
    FILE*fp;
    fp=fopen("Ventas.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    for(x=0;x<n;x++)
    {
        fread(&ventas_anio[x],sizeof(anio),1,fp);
        m[ventas_anio[x].nro_visitador-1][ventas_anio[x].cod_medi-1]+=ventas_anio[x].cant_vend;
    }
    //-----------------------------------
    /*int i;
    printf("  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");
    for(x=0;x<15;x++)
    {
        printf("%d",x+1);
        for(i=0;i<30;i++)
        {
            printf(" %d ",m[x][i]);
        }
        printf("\n");
    }
    //-----------------------------------*/
    fclose(fp);
}

int cargaventasdeldia(dia ventas_dia[],float imp_medicamento[],float imp_visitador[])
{
    int x=0;
    ventas_dia[x].nro_clien=lee_control(0,50000,3);
    while(ventas_dia[x].nro_clien!=0)
    {
        ventas_dia[x].nro_visitador=lee_control(1,15,4);
        ventas_dia[x].cod_medi=lee_control(1,30,2);
        ventas_dia[x].cant_vend=mayor_cero();
        ventas_dia[x].importe=validarfloat();
        imp_medicamento[ventas_dia[x].cod_medi]+=ventas_dia[x].importe;
        imp_visitador[ventas_dia[x].nro_visitador]+=ventas_dia[x].importe;
        x++;
        ventas_dia[x].nro_clien=lee_control(0,50000,3);
    }
    return x;
}

void actualizarmatriz(int m[][30],dia ventas_dia[],int n)
{
    int x;
    FILE*fp;
    fp=fopen("Ventas.dat","ab");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    for(x=0;x<n;x++)
    {
        m[ventas_dia[x].nro_clien-1][ventas_dia[x].cod_medi-1]+=ventas_dia[x].cant_vend;
        fwrite(&ventas_dia[x],sizeof(dia),1,fp);
    }
    fclose(fp);
    //-----------------------------------
    /*int i;
    printf("  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");
    for(x=0;x<15;x++)
    {
        printf("%d",x+1);
        for(i=0;i<30;i++)
        {
            printf(" %d ",m[x][i]);
        }
        printf("\n");
    }
    //-----------------------------------*/
}

void mostrarinforme(float imp_x_medicamento[],int dia,int mes,int anio,int n)
{
    int x;
    float total=0;
    printf("\n      VENTAS DEL %d/%d/%d ",dia,mes,anio);
    printf("\nCODIGO DE MEDICAMENTO   IMPORTES DE LA FACTURACION");
    for(x=0;x<n;x++)
    {
        total+=imp_x_medicamento[x];
        printf("\n      %d                        %0.2f",x+1,imp_x_medicamento[x]);
    }
    printf("\n---------------------    --------------------------");
    printf("\nTOTAL VENDIDO:                         %0.2f",total);
}

void informarmayor(float imp_x_visitador[],int n)
{
    int x,visitador;
    float max;
    max=imp_x_visitador[0];
    for(x=1;x<n;x++)
    {
        if(max<imp_x_visitador[x])
        {
            max=imp_x_visitador[x];
            visitador=x;
        }
    }
    printf("\nEl visitador nro %d fue quien vendio el mayor importe(%0.2f) en el dia",visitador,max);
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el numero de visitador medico[1 a 15/Salida=0]: ");
        if(n==2)printf("\nIngrese el codigo de medicamento[1 a 30]: ");
        if(n==3)printf("\nIngrese el numero de cliente[1 a 50000/Salida=0]: ");
        if(n==4)printf("\nIngrese el numero de visitador medico[1 a 15]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

int mayor_cero()
{
    int dato;
    do
    {
        printf("\nIngrese la cantidad de unidades vendidas: ");
        scanf("%d",&dato);
    }while(dato<0);
    return dato;
}

float validarfloat()
{
    float dato;
    do
    {
        printf("\nIngrese el importe: ");
        scanf("%f",&dato);
    }while(dato<0);
    return dato;
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

