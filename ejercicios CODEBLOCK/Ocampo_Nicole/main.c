#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void carga(int[],int,char[][13],float[][20]);
int busqueda_secuencial (int[],int,int);
void cargasectores(char[5][13]);
int buscar(char[][13], char [], int);
void mostrar(char [][13],int );
void ordenamiento (float [], int ,char [5][13]);
void mostrar_lista(float[],char [][13],int );

int main()
{
    int num_vend[20]={0},x,i;
    int fil, col,sec_menos_venta,vend_mayor_imp,y,cont;
    char sectores[5][13],sect_mayor_imp[13];
    float m[5][20]={{0}},suma_fila[5]={0},max,min,suma_colum[20]={0};
    cargasectores(sectores);
    carga(num_vend,20,sectores,m);
    system("cls");
    for(x=0;x<5;x++)
    {
        for(i=0;i<20;i++)
        {
            suma_fila[x]+=m[x][i];
        }
    }
    ordenamiento(suma_fila,5,sectores);
    for(x=0;x<5;x++)
    {
        for(i=0;i<20;i++)
        {
            if(m[x][i]>=max)
            {
                max=m[x][i];
                fil=x;
                col=i;
            }
        }
    }
    printf("\nEl mayor importe vendido es de %0.2f",max);
    strcpy(sect_mayor_imp, sectores[fil]);
    vend_mayor_imp = num_vend[col];
    printf("\nQue se encuentra en el sector %s y cod de vendedor %d",sect_mayor_imp,vend_mayor_imp);
    min=suma_fila[0];
    for(x=0;x<5;x++)
    {
        if(suma_fila[x]<min) {
            min=suma_fila[x];
            sec_menos_venta=x;
        }
    }
    printf("\nEl sector que realizo menos cantidad de ventas fue %s", sectores[sec_menos_venta]);
    for(x=0;x<20;x++)
    {
        for(i=0;i<5;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    for(y=0;y<20;y++) {
        if(suma_colum[y] == 0) {
            cont++;
        }
    }
    printf("\n%d vendedores no registraron ventas", cont);
    return 0;
}

void carga(int v1[],int n,char sectores[][13], float m[][20])
{
    int x=0,pos,vendedor,pos1,cod,posicion,cant_vendida,pos2;
    char sec[13],sec_x_vend[20][13],continuar[4],sect[13];
    float precio_unidad;
    while(x<n&&(strcmpi(continuar,"No"))!=0)
    {
        system("cls");
        do
        {
            printf("\n Ingrese el numero de vendedor[1000 a 9999]:");
            scanf("%d",&vendedor);
            pos=busqueda_secuencial(v1,n,vendedor);
            v1[x]=vendedor;
            if(pos!=-1)
                printf("\nNumero de vendedor ya existente,vuelva a intentarlo");
        }while((v1[x]<1000||v1[x]>9998)|| pos!=-1);
        do
        {
            mostrar(sectores,5);
            printf("\nIngrese el sector: ");
            fflush(stdin);
            gets(sec);
            pos1=buscar(sectores,sec,5);
        }while(pos1==-1);
        strcpy(sec_x_vend[x], sec);
        x++;
        do
        {
            printf("\nDesea Continuar con la carga [SI o NO]: ");
            fflush(stdin);
            gets(continuar);
        }while(((strcmpi(continuar,"SI"))!=0)&&(strcmpi(continuar,"NO"))!=0);
    }
    system("cls");
    do
    {
        printf("\nIngrese el codigo de vendedor[salida=9999]:");
        scanf("%d",&cod);
        posicion=busqueda_secuencial(v1,x,cod);
    }while(posicion==-1&&cod!=9999);
    while(cod!=9999)
    {
        do
        {
            printf("\nIngrese la cantidad vendida");
            scanf("%d",&cant_vendida);
        }while(cant_vendida<0);
        do
        {
            printf("\nIngrese el precio unitario: ");
            scanf("%f",&precio_unidad);
        }while(precio_unidad<0);
        strcpy(sect,sec_x_vend[posicion]);
        pos2=buscar(sectores,sect,5);
        m[pos2][posicion]+=(float)cant_vendida*precio_unidad;
        do
        {
            printf("\nIngrese el codigo de vendedor[salida=9999]:");
            scanf("%d",&cod);
            posicion=busqueda_secuencial(v1,x,cod);
        }while(posicion==-1&&cod!=9999);
    }
}

int buscar(char m[][13], char sec[13], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(m[x],sec))==0)
            pos=x;
        else
            x++;
    }
    return pos;
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

//“Mostrador -  Capital  -  Gran Bs.As.  -   Interior  -  Terceros”
void cargasectores(char sectores[5][13])
{
    strcpy(sectores[0], "Mostrador");
    strcpy(sectores[1], "Capital");
    strcpy(sectores[2], "Gran Bs.As.");
    strcpy(sectores[3], "Interior");
    strcpy(sectores[4], "Terceros");
}

void mostrar(char vn[][13],int cant)
{
    int i;
    //system("cls");
    for (i=0; i<cant; i++)
        puts(vn[i]);
}

void ordenamiento (float monto[], int c,char sector[5][13])
{
    int x,i,aux;
    char aux1[13];
    for(x=0;x<c;x++)
    {
        for(i=0;i<c-1-x;i++)
        {
            if(monto[i]<monto[i+1])
            {
                aux=monto[i];
                monto[i]=monto[i+1];
                monto[i+1]=aux;

                strcpy(aux1,sector[i]);
                strcpy(sector[i],sector[i+1]);
                strcpy(sector[i+1],aux1);
            }
        }
    }
    mostrar_lista(monto,sector,c);
}

void mostrar_lista(float monto[],char sector[][13],int c)
{
    int x;
    printf("\nLISTADO DE SUELDOS ABONADOS ORDENADO:");
    printf("\nSECTOR:\t\tIMPORTE:");
    for(x=0;x<c;x++)
    {
        if(monto[x]!=0)
            printf("\n%s\t\t%0.2f",sector[x],monto[x]);
    }
}
