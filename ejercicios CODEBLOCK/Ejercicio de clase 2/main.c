#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validarLegajo(int,int,int);
char ValidaChar(char,char,int);
int ValidarTec(int,int);
int ValidarAnio (int);

int main()
{
    int LegAlu,TecHog,AnioI;
    char Respon,AcceInt;
    int CanAlu_20=0,Ban=0,AnioI_Mayor=0,LegAlu_Mayor=0,ConResp=0,ConMuyAcep=0;
    int Senial= 0;
    float Porcentaje;
    LegAlu=validarLegajo(0,10000,100000);
    while(LegAlu!=0)
    {
        Respon=ValidaChar('N','S',0);
        if(Respon=='S')
        {
            AcceInt=ValidaChar('N','S',1);
            TecHog=ValidarTec(0,9);
            AnioI= ValidarAnio (1919);

            printf(" \nEl Legajo %d Tiene grado de Tecnologia :",LegAlu);
            if(AcceInt=='S'&&TecHog>=6)
            {
                Senial=1;
                printf(" MUY ACEPTABLE ");
            }
            else
                printf(" INVIABLE ");
            if(AnioI==2020) printf(" - alumno ingresante - ");
            else
            {
                if(AnioI>2018) printf(" - alumno nuevo - ");
                else
                    printf(" - alumno cursante - ");
            }
            if(AnioI==2020&&AcceInt=='N') CanAlu_20 ++;
            if((Ban==0&&TecHog<4)||(TecHog<4&&AnioI_Mayor>AnioI))
            {
                LegAlu_Mayor=LegAlu;
                AnioI_Mayor=AnioI;
                Ban=1;
            }

            if(AnioI>=2015&&Senial==1)
            {
                Senial=0;
                ConMuyAcep++;
            }
            ConResp++;
        }
        else
            printf(" El Legajo = %d no respondio Encuesta", LegAlu);

        LegAlu=validarLegajo(0,10000,100000);
    }
    Porcentaje=(float) ConMuyAcep/ConResp*100;
    printf("\n\n\nPunto 2) Ingresaron 2020 y no tienen Conexion = %d", CanAlu_20);
    printf("\nPunto 3) Leg.Alumno con mas Anio y Tecnologia debajo 4 es : %d - %d",LegAlu_Mayor,AnioI_Mayor);
    printf("\nPunto 4) Porsentaje Alumnos Muy Aceptable desde 2015 a la fecha es de:%8.2f",Porcentaje);
    return 0;
}
int validarLegajo(int a,int b,int c)
{
    int dato;
    do
    {
        printf("\n Ingrese Legajo de Alumno :");
        scanf("%d",&dato);
    }
    while((dato!=a)&&(dato<b||dato>c));
    return dato;
}

char ValidaChar(char i,char f, int n)
{
    char letra;
    do
    {
        if(n==1) printf("\n Tiene Acceso a Internet? [S/N]:");
        else printf("\n Respondio Encuesta? [S/N]:");
        fflush(stdin);
        scanf("%c",&letra);
        letra=toupper(letra);
    }
    while(letra!=i &&letra!=f);
    return letra;
}

int ValidarTec(int li, int ls)
{
    int tecnologia;
    do
        {
            printf("\n Tecnologia en el Hogar de 0 a 9 ?:");
            scanf("%d",&tecnologia);
        }
    while(tecnologia<li||tecnologia>ls);
    return tecnologia;
}

int ValidarAnio(int a)
{
    int anio_ingr;
    do
        {
            printf("\n Anio de Ingreso en la Universidad?:");
            scanf("%d",&anio_ingr);
        }
    while(anio_ingr<a);
    return anio_ingr;
}
