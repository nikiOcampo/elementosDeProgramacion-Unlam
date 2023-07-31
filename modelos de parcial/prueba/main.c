/*#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int DIAS(int, int )

int main()
{
    int anio,mes,dias;
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    do
    {
        printf("\nIngrese un mes [del 1 al 12]: ");
        scanf("%d",&mes);
        if(mes<1||mes>12)
            printf("\nEl mes ingresado es inexistente");
    }while(mes<1||mes>12);
    dias=DIAS(anio,mes);
    printf("\El mes cargado tiene %d dias", dias);
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
            if(a%4)
                d=28;
            else
                d=29;
            break;
    }
    return d;
}*/

/*#include <stdio.h>
#include <stdlib.h>
int CantidadDias(int,int);
int ValidaFecha(int,int,int);

int main ()
{
    int dia,dia2,mes,anio,validacion,sumar;
    printf("Ingrese un dia: ");
    scanf("%d",&dia);
    printf("Ingrese un mes: ");
    scanf("%d",&mes);
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    validacion=ValidaFecha(dia,mes,anio);
    if (validacion==0)
        printf("La fecha ingresada %d/%d/%d es incorrecta.\n\n",dia,mes,anio);
    else
        {
            printf("Ingrese la cantidad de dias a sumar: ");
            scanf("%d",&sumar);
            validacion=CantidadDias(mes,anio);
            dia2=dia+sumar;
            while(validacion<dia2)
            {
             dia2-=validacion;
             if(mes==12)
             {
                 mes=1;
                 anio++;
             }
             else mes++;
             validacion=CantidadDias(mes,anio);
            }
            printf("La fecha nueva queda: %d/%d/%d\n",dia2,mes,anio);
        }
    return 0;
}
int CantidadDias(int mes, int anio)
{
    switch(mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31; break;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30; break;
        case 2:
            if((anio%4==0&&anio%100!=0)||anio%400==0)
                return 29;
            else
                return 28;
            break;
        default: return 0;
    }
}
int ValidaFecha(int dd,int mm,int aa)
{
    int dias;
    dias=CantidadDias(mm,aa);
    if(dd>dias)
        return 0;
    else
        if(dd<=dias&&dd>0)
            return 1;
        else
            return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int dni;
    char nomyape[20];
    int pago;
}inscriptos;

typedef struct
{
    int dni;
    char nomyape[20];
    int numtele;
}intersados;

int leerarchivo(inscriptos[]);
int posicion(int, inscriptos[], int);
int main()
{
    int dni, x=0, posi, cant;
    char psino[3], ingreso[3], interesado[3];
    FILE*fp;
    FILE*fp2;
    inscriptos in[60];//={0, " ", 0};
    intersados is[60];//={0, " ", 0};
    cant=leerarchivo(in);
    fp=fopen("inscriptos.dat", "ab");
    if(fp==NULL)
    {
        printf("error 1");
        exit(1);
    }
     printf("%d", cant);
    do{
    printf("\n Ingrese el dni de la persona inscripta [use -2 para salir]:");
    scanf("%d", &dni);
    posi=posicion(dni, in, cant);
    }while(dni!=-2&&dni<1);
    while(dni!=-2)
    {
         printf("%d", cant);
        if(cant<60){
        if(posi!=-1&&in[posi].pago==0)
        {
            printf("\n Desea realizar el pago del ingresante %s [Ingrese si o no]", in[posi].nomyape);
            getchar();
            gets(psino);
            if(strcmpi(psino, "SI")==0)
                in[posi].pago=1;
        }
        else
            if(posi!=-1&&in[posi].pago==1)
        {
            printf("\n El ingresantes %s ya realizo el pago del ingreso", in[posi].nomyape);
        }
        else
        {
            if(posi==-1)
            {
                printf("\n Desea ingresar a la persona de dni %d al concurso [Si o no]:", dni);
                getchar();
                gets(ingreso);
                if(strcmpi(ingreso,"SI")==0)
                {
                    printf("\n Ingrese el nombre y apellido de la persona:");
                    getchar();
                    gets(in[cant].nomyape);
                    in[cant].dni=dni;
                    fwrite(&in[cant], sizeof(ingreso), 1, fp);
                    cant++;
                }
            }
        }
         do{
    printf("\n Ingrese el dni de la persona inscripta [use -2 para salir]:");
    scanf("%d", &dni);
    posi=posicion(dni, in, cant);
    }while(dni!=-2&&dni<1);
    }
    else
    {
        printf("\n Desea agregar a la persona a la lista de interesados:");
                getchar();
                gets(interesado);
                if(strcmpi(interesado,"SI")==0)
                {
                    printf("\n Ingrese el numero de telefono de la persona:");
                    scanf("%d", &is[x].numtele);
                    printf("\n Ingrese el nombre y apellido de la persona:");
                    getchar();
                    gets(is[x].nomyape);
                    is[x].dni=dni;
                    x++;
                }
       do{
    printf("\n Ingrese el dni de la persona inscripta [use -2 para salir]:");
    scanf("%d", &dni);
    posi=posicion(dni, in, cant);
    }while(dni!=-2&&dni<1);
    }
    }
    fclose(fp);
    return 0;
}
int posicion(int a, inscriptos in[], int n)
{
    int x=0, pos=-1;
    while(pos==-1&&x<n)
    {
       if(in[x].dni==a)
            pos=x;
       else
        x++;
    }
    return pos;
}
int leerarchivo(inscriptos in[])
{
   int x=0;
    FILE*fp;
    fp=fopen("inscriptos.dat", "rb");
    if(fp==NULL)
    {
        printf("error 1");
        exit(1);
    }
    fread(&in[x], sizeof(inscriptos), 1, fp);
    while(!feof(fp))
    {
        x++;
        if(x<60)
       fread(&in[x], sizeof(inscriptos), 1, fp);
    }
    fclose(fp);
    return x;
}
