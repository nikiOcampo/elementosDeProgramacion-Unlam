/*Una f�brica produce como m�ximo 20 productos diferentes y necesita un reporte de la producci�n realizada durante el a�o.
Para ello se dispone del archivo �ARTICULOS.dat�, el cual contiene:
� C�digo de art�culo (entero de 4 cifras no correlativo)
� Descripci�n del art�culo (30 caracteres m�ximo)
� Cantidad de stock remanente del a�o anterior (entero)
A continuaci�n, se procesa por teclado, la informaci�n correspondiente a todo el a�o:
� N�mero del mes de producci�n. Ingresar y controlar mediante la Funci�n LEE_CONTROL.
� C�digo de art�culo (entero de 4 cifras no correlativo) Ingresar y controlar un n�mero de 4 cifras. Funci�n LEE_CONTROL.
� Cantidad de unidades que se produjeron en ese mes. Controlar si el n�mero es mayor que 0. Funci�n MAYOR_CERO.
Esta informaci�n no se encuentra ordenada, y termina con n�mero de mes igual a 0.
Se solicita construir un programa que determine e informe:
a. Para cada art�culo, la cantidad de unidades producidas en cada uno de los 12 meses del a�o, de acuerdo con el siguiente modelo:
b. Confeccionar un listado con el/los c�digos y descripci�n de aquellos art�culos que NO se produjeron en todo el a�o.
c. Generar el archivo actualizado llamado �ARTI_ACTUALIZADO.dat� con la suma del stock remanente del a�o anterior m�s la
cantidad producida en el primer trimestre del presente a�o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int cod_articulo;
    char descripcion[31];
    int cant_stock;
}articulos;

typedef struct
{
    int mes;
    int cod_articulo;
    int cant_producida;
}infoanio;

typedef struct
{
    int cod_arti;
    char descripcion[30];
    int stock_actualizado;
}articulos_actual;

void cargaarticulos(articulos[],int);
int lee_control(int,int,int);
int mayor_cero(int);
int cargadelanio(articulos[],infoanio[],int [][14]);
void ListarCodigos (articulos[],int);
int buscar(articulos[],int,int);
void mostrarpuntoA(articulos[],infoanio[],int[][14],int,int);

int main()
{
    articulos art[20];
    infoanio anio[100000];
    articulos_actual actu[/*20*/5];
    int cant,m[/*20*/5][14]={{0}},cont=0,x,i,suma_fila[5]={0};;
    FILE*fp2;
    cargaarticulos(art,20);
    cant=cargadelanio(art,anio,m);
    mostrarpuntoA(art,anio,m,5,14);
    //Confeccionar un listado con el/los c�digos y descripci�n de aquellos art�culos que NO se produjeron en todo el a�o.
    printf("\nLISTA DE PRODUCTOS QUE NO SE PRODUJERON DURANTE EL ANIO");
    for(x=0;x<5;x++)
    {
        cont=0;
        for(i=2;i<14;i++)
        {
            if(m[x][i]==0)
              cont++;
        }
        if(cont==12)printf("\n%d  %s",art[x].cod_articulo,art[x].descripcion);
    }
    /*Generar el archivo actualizado llamado �ARTI_ACTUALIZADO.dat� con la suma del stock remanente del a�o anterior m�s la
    cantidad producida en el primer trimestre del presente a�o.*/
    fp2=fopen("arti_actualizado.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 2");
        exit(1);
    }

    for(x=0;x<5;x++)
    {
        for(i=2;i<5;i++)
        {
            suma_fila[x]+=m[x][i];
        }
        actu[x].stock_actualizado=suma_fila[x]+art[x].cant_stock;
        actu[x].cod_arti=art[x].cod_articulo;
        strcpy(actu[x].descripcion,art[x].descripcion);
        fwrite(&actu[x],sizeof(articulos_actual),1,fp2);
    }
    //--------------------PRUEBA------------------------
    printf("\nLISTA DE STOCKS ACTUALIZADOS AL TERCER TRIMESTRE:");
    for(x=0;x<5;x++)
    {
        printf("\n%d %d",actu[x].cod_arti,actu[x].stock_actualizado);
    }
    //-------------------------------------------------
    fclose(fp2);
    return 0;
}

void cargaarticulos(articulos art[],int n)
{
    int x;
    FILE*fp;
    fp=fopen("articulos.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    for(x=0;x<5/*n*/;x++)
    {
        art[x].cod_articulo=lee_control(1000,9999,1);
        do
        {
            printf("\nIngrese la descripcion del articulo nro %d: ",x+1);
            fflush(stdin);
            gets(art[x].descripcion);
        }while(strlen(art[x].descripcion)<1||strlen(art[x].descripcion)>30);
        art[x].cant_stock=mayor_cero(1);
        fwrite(&art[x],sizeof(articulos),1,fp);
    }
    fclose(fp);
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el codigo del articulo: ");
        if(n==2)printf("\nIngrese el mes: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

int mayor_cero(int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el stock remitente del anio pasado: ");
        if(n==2)printf("\nIngrese la cantidad producida: ");
        scanf("%d",&dato);
    }while(dato<0);
    return dato;
}

int cargadelanio(articulos art[], infoanio info[],int m[][14])
{
    int x=0,pos;
    system("cls");
    printf("\nCARGA DEL ANIO: ");
    info[x].mes=lee_control(0,12,2);
    while(info[x].mes!=0)
    {
        do
        {
            ListarCodigos(art,/*20*/5);
            info[x].cod_articulo=lee_control(1000,9999,1);
            pos=buscar(art,info[x].cod_articulo,/*20*/5);
        }while(pos==-1);
        info[x].cant_producida=mayor_cero(2);
        m[pos][info[x].mes+1]+=info[x].cant_producida;
        x++;
        system("cls");
        info[x].mes=lee_control(0,12,2);
    }
    return x;
}

int buscar(articulos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod_articulo==cod)
           p=i;
      else
          i++;
  }
  return p;
}

void ListarCodigos (articulos vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE CODIGOS DE ARTICULOS\n");
    printf("--------------------\n\n");
    printf("CODIGO DESCRIPCION STOCK S/ACT\n");

    for (i=0;i<5/*ce*/;i++)
    {
            printf("%d     %s        %d\n", vc[i].cod_articulo, vc[i].descripcion,vc[i].cant_stock);
    }
    printf("\n");
}

void mostrarpuntoA(articulos art[],infoanio info[],int m[][14],int f,int c)
{
    int x,i;
    system("cls");
    printf("\nLISTADO DE PRODUCCION DE ARTICULOS\n");
    printf("--------------------\n\n");
    printf("CODIGO DESCRIPCION  ENE     FEB     MAR     ABR     MAY     JUN     JUL     AGO     SEP     OCT     NOV     DIC.\n");
   /* for(x=0;x<5;x++)
    {
        m[x][0]=art[x].cod_articulo;
    }*/
    //NO ANDA EL FOR(?????)
    m[0][0]=art[0].cod_articulo;
    m[1][0]=art[1].cod_articulo;
    m[2][0]=art[2].cod_articulo;
    m[3][0]=art[3].cod_articulo;
    m[4][0]=art[4].cod_articulo;
    m[0][1]=-1;
    m[1][1]=-1;
    m[2][1]=-1;
    m[3][1]=-1;
    m[4][1]=-1;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]!=-1)
                printf("%d       ",m[x][i]);
            else printf("%s      ",art[x].descripcion);
        }
        printf("\n");
    }
}
