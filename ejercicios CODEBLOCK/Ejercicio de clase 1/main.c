#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int ValidarNum (int, int);
float ValidarTemp (int, int);
char ValidarChar (char,char,int);

int main()
{
    int NumCel, EdadCiu,ban,sen,ContPunto2,Con2Sin,MayCelu,CanGen;
    char DolGar,TosCiu;
    float TemCiu,Por,Mayor;
    sen=ban=ContPunto2=Con2Sin=Mayor=MayCelu=CanGen=0;
    NumCel=ValidarNum(0,0);
    while(NumCel!=0)
    {
        EdadCiu=ValidarNum(12,1);
        TemCiu=ValidarTemp(34,44);
        DolGar=ValidarChar('S','N',0);
        TosCiu=ValidarChar('S','N',1);

       printf("\n Celular Nro. %d",NumCel);
       if(EdadCiu>=65)
              {
               printf(" ALTO RIESGO");
               sen++;
              }
         else printf(" RIESGO  MODERADO");
        if(ban==0||Mayor<TemCiu)
               {
                 Mayor=TemCiu;
                 MayCelu=NumCel;
                 ban=1;
               }
        if(TemCiu>=37.5&&DolGar=='S'&&TosCiu=='S')
                        printf(" - MUY SOSPECHOSO");
        else
         {
             if(TemCiu<37.5&&DolGar!='S'&&TosCiu!='S')
             {
                        printf(" - LIBRE DE SOSPECHA");
                        sen++;
             }
             else
                       printf(" - EN SEGUIMIENTO");
         }
         if(sen==2) ContPunto2++;
         sen=0;
         CanGen++;
         if((TemCiu>=37.5&&TosCiu=='S')||(TemCiu>=37.5&&DolGar=='S')||(DolGar=='S'&&TosCiu=='S'))
                    Con2Sin++;
        NumCel=ValidarNum(0,0);

    }
    printf("\n\n Encuestados > 65 y Sin Sintomas =%d",ContPunto2);
    printf("\n Celular Encuestado < 65 y Mayor Temperatura :%d - %f5.2",MayCelu,Mayor);
    Por=Con2Sin*100/CanGen;
    printf("\n Porcentaje de Sin Dos Sintomas =%f5.2",Por);
    return 0;
}

int ValidarNum (int a,int s)
{
    int numero_cel;
    do
    {
        if (s==1)printf ("\n Ingrese la edad del ciudadano: ");
        else printf("\n Ingrese Numero de Celular : ");
        scanf("%d",&numero_cel);
    }while(numero_cel<a);
    return numero_cel;
}

float ValidarTemp(int c, int d)
{
    float temperatura;
    do
       {
        printf("\n Ingrese Temperatura:");
        scanf("%f",&temperatura);
       }while(temperatura<c||temperatura>d);
       return temperatura;
}

char ValidarChar (char s, char n, int num)
{
    char letra;
    do
    {
        if(num==1) printf("\n Tiene Tos  [S/N]  :");
        else printf("\n Dolor de Garganta[S/N] :");
        fflush(stdin);
        scanf("%c",&letra);
        letra=toupper(letra);
    }while(letra!=s && letra!=n );
       return letra;
}
