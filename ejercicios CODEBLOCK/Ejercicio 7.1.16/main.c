/*Una empresa textil desea realizar un informe sobre los sueldos de cada sección
para lo cual dispone de los siguientes datos:
• La fecha del día del proceso, que debe ser ingresada al comienzo del programa
y controlarse que sea válida. De no serlo, reingresarla hasta que lo sea.
• Los sueldos de cada empleado:
i. Legajo (entero, mayor a cero).
ii. Sección (carácter, desde ‘A’ hasta ‘H’).
iii. Sueldo (real, mayor a cero).
Los datos de cada empleado deben validarse y en caso de que alguno
sea incorrecto, debe ignorarse los tres y reingresarse nuevamente.
 El fin de datos es cuando aparece un legajo igual a cero. Se pide:
a. Emitir un informe que indique por sección, el total de sueldos de
la misma, ordenado en forma descendente por total de sueldos:
Sueldos al: XX/XX/XXXX
Sección
Total de sueldos por sección
H
B
…
TOTAL SUELDOS
XXXXX,XX
XXXXX,XX
…………
XXXXXXX,XX
b. El legajo del empleado con mayor sueldo consignando legajo, sección y sueldo.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );
void mostrar_puntoA (char[],float[],int,int,int,int);
void mostrar_puntoB (int[],char[],float[],int);

int main()
{
    int dia,mes,anio,validacion;
    int legajo[100],x=0,a=0;
    float sueldo[100];
    char seccion[100];
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
            printf("Ingrese el lejago del empleado:");
            scanf("%d",&legajo[x]);
            if(legajo[x]==0)
                a=1;
        }while(legajo[x]<0);
        while(legajo[x]!=0)
        {
            do
            {
                printf("Ingrese la seccion en la que trabaja el empleado: ");
                fflush(stdin);
                scanf("%c",&seccion[x]);
                seccion[x]=toupper(seccion[x]);
                printf("Ingrese el sueldo del empleado: ");
                scanf("%f",&sueldo[x]);
                if(seccion[x]<'A'||seccion[x]>'H'||sueldo[x]<0)
                    printf("\nERROR DE CARGA,VUELVA A CARGAR LOS DATOS:");
            }while(seccion[x]<'A'||seccion[x]>'H'||sueldo[x]<0);
            x++;
            do
            {
                printf("Ingrese el legajo del empleado:");
                scanf("%d",&legajo[x]);
                if(legajo[x]==0)
                    a=1;
            }while(legajo[x]<0);
        }
        mostrar_puntoA(seccion,sueldo,x,dia,mes,anio);
        mostrar_puntoB(legajo,seccion,sueldo,x);
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

void mostrar_puntoA(char secc[],float suel[], int n,int d,int m, int a)
{
    int x,j,k;
    char sec_ordenadas[8]={'A','B', 'C', 'D','E', 'F', 'G', 'H'},aux1;
    float suel_orden[8],totalsueldo,aux2;
    float contA,contB,contC,contD,contE,contF,contG,contH;
    contA=contB=contC=contD=contE=contF=contG=contH=0;
    for(x=0;x<n;x++)
    {
        switch(secc[x])
        {
        case 'A':
            contA+=suel[x];
            suel_orden[0]=contA;
            break;
        case 'B':
            contB+=suel[x];
            suel_orden[1]=contB;
            break;
        case 'C':
            contC+=suel[x];
            suel_orden[2]=contC;
            break;
        case 'D':
            contD+=suel[x];
            suel_orden[3]=contD;
            break;
        case 'E':
            contE+=suel[x];
            suel_orden[4]=contE;
            break;
        case 'F':
            contF+=suel[x];
            suel_orden[5]=contF;
            break;
        case 'G':
            contG+=suel[x];
            suel_orden[6]=contG;
            break;
        case 'H':
            contH+=suel[x];
            suel_orden[7]=contH;
            break;
        }
    }
    for(k=0;k<n-1;k++)
    {
        for(j=0;j<n-1-k;j++)
        {
            if(suel_orden[j]>suel_orden[j+1])
            {
                aux1=sec_ordenadas[j];
                sec_ordenadas[j]=sec_ordenadas[j+1];
                sec_ordenadas[j+1]=aux1;

                aux2=suel_orden[j];
                suel_orden[j]=suel_orden[j+1];
                suel_orden[j+1]=aux2;
            }
        }
    }
    printf("\nSUELDO AL: %d/%d/%d",d,m,a);
    printf("\nSECCION:\tTOTAL DE SUELDO POR SECCION:\n");
    for(x=0;x<n;x++)
    {
        printf("\n%c\t\t%f",sec_ordenadas[x],suel_orden[x]);
    }
    printf("\nTOTAL SUELDOS:");
    totalsueldo=contA+contB+contC+contD+contE+contF+contG+contH;
    printf("\t\t\t%f",totalsueldo);
}

void mostrar_puntoB(int leg[],char sec[],float suel[],int n)
{
    int max,i,j;
    max=suel[0];
    for (i=1;i<n;i++)
    {
        if (suel[i]>max)
            max=suel[i];
    }
    printf("\nEl sueldo mas alto es de %d, y lo tienen el/los empleados: ",max);
    for(j=0;j<n;j++)
    {
        if(suel[j]==max)
            printf("\n%d del sector %c",leg[j],sec[j]);
    }
}


