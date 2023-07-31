/*La municipalidad de Marina del Mar desea efectuar un control de la cobranza del impuesto Municipal en los 6
bimestres del año. Existen 50 contribuyentes, numerados de 1 a 50.
• El primer dato para ingresar es el número del año a procesar (xxxx)
Se suministra el archivo “IMPORTES.dat”, ordenado por año-bimestre, con 18 ítems, que contienen los importes de
los impuestos de los últimos 3 años, cada ítem contiene:
• Año del impuesto (entero)
• Bimestre (entero)
• Importe (real)
Se dispone además de un segundo archivo, llamado “CONTROL.dat”, ordenado por número de contribuyente,
con un registro por cada cobro efectuado, con los siguientes datos (solo considerar los del año en estudio).
• Número de contribuyente (entero)
• Año del impuesto (entero)
• Bimestre (entero)
Se solicita confeccionar un programa para determinar e informar:
a. El importe total recaudado en el año.
b. Las deudas de cada contribuyente según el siguiente formato de impresión:*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int anio_impuesto;
    int bimestre;
    float importe;
}importes;

typedef struct
{
    int num_contri;
    int anio_impuesto;
    int bimestre;
    float cobro;
}control;

void cargaimportes(importes[],int,int);
int lee_control(int,int,int);
float mayor_cero();
void cargacontrol(importes[],control[],int,int);
int buscar2(importes[],int,int);
int buscar(importes[],int,int );

int main()
{
    importes imp[5/*18*/]={0};
    control contr[50]={0};
    int anio_a_procesar;//,i,x,bus,pos;
    //float m[50][8]={0};
    anio_a_procesar=lee_control(1000,9999,1);
    cargaimportes(imp,5/*18*/,anio_a_procesar);
    cargacontrol(imp,contr,anio_a_procesar,50);

    /*printf("\n\t\tDEUDAS REGISTRADAS EN EL ANIO: %d",anio_a_procesar);
    printf("\nCONTRIBUYENTE       BIMESTRES          IMPORTE ADEUDADO");
    printf("\n              1   2   3   4   5   6\n");
    for(x=0;x<50;x++)
    {
        m[x][0]=x+1;
        for(i=1;i<7;i++)
        {
            if(contr[x].bimestre!=0)
                m[x][contr[x].bimestre]=0;
            else
            {
                bus=contr[x].bimestre;
                pos=buscar2(imp,bus,5);
                m[x][pos]=imp[pos].importe;
            }
        }
    }
    int suma_colum[50]={0};
    for(x=0;x<7;x++)
    {
        for(i=0;i<50;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    for(x=0;x<50;x++)
    {
        m[x][8]=suma_colum[x];
    }
    for(x=0;x<50;x++)
    {
        for(i=0;i<8;i++)
        {
            printf("%0.2f  ",m[x][i]);
        }
        printf("\n");
    }*/
    return 0;
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el anio a procesar: ");
        if(n==2)printf("\nIngrese el anio del impuesto: ");
        if(n==3)printf("\nIngrese el bimestre: ");
        if(n==4)printf("\nIngrese el numero de contriuyente[Salida=0]:");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

void cargaimportes (importes imp[],int n,int anio)
{
    int x,j,aux;
    float auxf;
    FILE*fp;
    fp=fopen("importes.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    for(x=0;x<n;x++)
    {
        imp[x].anio_impuesto=lee_control(1000,anio+1,2);
        imp[x].bimestre=lee_control(1,6,3);
        imp[x].importe=mayor_cero();
    }
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(imp[j].anio_impuesto<imp[j+1].anio_impuesto)
            {
                aux=imp[j].anio_impuesto;
                imp[j].anio_impuesto=imp[j+1].anio_impuesto;
                imp[j+1].anio_impuesto=aux;

                aux=imp[j].bimestre;
                imp[j].bimestre=imp[j+1].bimestre;
                imp[j+1].bimestre=aux;

                auxf=imp[j].importe;
                imp[j].importe=imp[j+1].importe;
                imp[j+1].importe=auxf;
            }
        }
    }
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(imp[j].anio_impuesto==imp[j+1].anio_impuesto&&imp[j].bimestre>imp[j+1].bimestre)
            {
                aux=imp[j].bimestre;
                imp[j].bimestre=imp[j+1].bimestre;
                imp[j+1].bimestre=aux;

                aux=imp[j].anio_impuesto;
                imp[j].anio_impuesto=imp[j+1].anio_impuesto;
                imp[j+1].anio_impuesto=aux;

                auxf=imp[j].importe;
                imp[j].importe=imp[j+1].importe;
                imp[j+1].importe=auxf;

                fwrite(&imp[j],sizeof(importes),1,fp);
            }
        }
    }
    //-----------------------------------
    for(x=0;x<n;x++)
    {
        printf("\n%d   %d    %0.2f",imp[x].anio_impuesto,imp[x].bimestre,imp[x].importe);
    }
    //-----------------------------------
    fclose(fp);
}

void cargacontrol(importes imp[],control contr[],int ANIO,int n)
{
    int x=0,pos,anio,aux,j,i,pos2,bimestre,num;
    float auxf,total=0;
    FILE*fp2;
    fp2=fopen("control.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 2");
        exit(1);
    }
    num=lee_control(0,50,4);
    while(num!=0)
    {
        contr[num].num_contri=num;
        do
        {
           anio=lee_control(1000,ANIO+1,2);
           pos=buscar(imp,anio,5/*18*/);
        }while(pos==-1);
        contr[num].anio_impuesto=anio;
        do
        {
            bimestre=lee_control(1,6,3);
            pos2=buscar2(imp,bimestre,5/*18*/);
        }while(pos2==-1);
        contr[num].bimestre=imp[pos2].bimestre;
        contr[num].cobro=imp[pos2].importe;
        x++;
        num=lee_control(0,50,4);
    }
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-1-x;j++)
        {
            if(contr[j].num_contri<contr[j+1].num_contri)
            {
                aux=contr[j].num_contri;
                contr[j].num_contri=contr[j+1].num_contri;
                contr[j+1].num_contri=aux;

                aux=contr[j].anio_impuesto;
                contr[j].anio_impuesto=contr[j+1].anio_impuesto;
                contr[j+1].anio_impuesto=aux;

                aux=contr[j].bimestre;
                contr[j].bimestre=contr[j+1].bimestre;
                contr[j+1].bimestre=aux;

                auxf=contr[j].cobro;
                contr[j].cobro=contr[j+1].cobro;
                contr[j+1].cobro=auxf;

                fwrite(&contr[j],sizeof(control),1,fp2);
            }
        }
    }
    fclose(fp2);
    for(i=0;i<x;i++)
    {
        if(contr[i].anio_impuesto==ANIO)
            total+=contr[i].cobro;
    }
    printf("\nEl importe total recaudado es de: %0.2f",total);

    //--------------------------------

}

int buscar(importes pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].anio_impuesto==cod)
           p=i;
      else
          i++;
  }
  return p;
}

int buscar2(importes pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].bimestre==cod)
           p=i;
      else
          i++;
  }
  return p;
}

float mayor_cero()
{
    float dato;
    do
    {
        printf("\nIngrese el importe: ");
        scanf("%f",&dato);
    }while(dato<0);
    return dato;
}
