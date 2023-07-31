/*Realizar una función que permita restar 1 día a una fecha válida mostrando la fecha resultante.
Si la fecha recibida no es válida informarlo con un mensaje (validar utilizando la función del punto 9).*/

#include <stdio.h>
#include <stdlib.h>

int ValidarFecha (int,int,int);
int DIAS(int, int );
int restadias (int,int,int );
int restames (int,int);
int restaanio (int,int,int);


int main()
{
    int dia,mes,anio,validacion;
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    printf("Ingrese un mes: ");
    scanf("%d",&mes);
    printf("Ingrese un dia: ");
    scanf("%d",&dia);
    validacion=ValidarFecha(anio,mes,dia);
    if(validacion==0)
        printf("Fecha Invalida");
    else
    {
        dia=restadias(dia,mes,anio);
        mes=restames(dia,mes);
        anio=restaanio(mes,anio,dia);
        printf("La Fecha decrementada en uno: %d %d %d",dia,mes,anio);
    }
 return 0;
}

int restaanio(int m, int a,int d)
{
    int anio;
    if(m==1&&d==1)
        anio=a-1;
    else
        anio=a;
    return anio;
}


int restames(int d, int m)
{
    int cant;
    if(m==1&&d==1)
        cant=12;
    else
    {
        if(d==1)
            cant=m-1;
    }
    if(d!=1)
        cant=m;
    return cant;
}

int restadias(int d, int m, int a)
{
    int cant, num, cont, sen=0, ban=0, men=0;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        sen=1;
    if(sen==1)
    {
        if(d==31)
            cant=30;
        else
            cant=d-1;
    }
    if(m==4||m==6||m==9||m==11)
        ban=1;
    if(ban==1)
    {
        if(d==30)
            cont=29;
        else
            cont=d-1;
    }
    if(m==2)
        men=1;
    if((men==1) && ((a%4==0&&a%100!=0)||(a%400==0)))
    {
        if(d==29)
            num=28;
        else
            num=d-1;
    }
    else
    {
       if(d==28)
        num=27;
       else
        num=d-1;
    }
    if(sen==1)
        return cant;
    if(ban==1)
        return cont;
    if(men==1)
        return num;
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
