/*Se dispone de un archivo “EXPENSAS.dat” con los importes según cada uno de las 5 categorías de un complejo de edificios.
Este archivo consta de un (1) solo registro con los 5 importes correspondientes en forma correlativa a la categoría 1,
 categoría 2 hasta la 5.
Además, se dispone del archivo “PROPIETARIO.dat” con los datos de cada propietario:
• DNI (entero)
• Apellido y Nombre (50 caracteres)
• Domicilio (50 caracteres)
Se sabe que existen como MÁXIMO 100 PROPIETARIOS.
También se dispone del archivo “PAGOS.dat” con los efectuados por cada propietario que ha pagado la expensa:
• DNI (entero)
• Mes de pago (entero)
• Categoría (entero de 1 a 5)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    float importe;
}categorias;

typedef struct
{
    int dni;
    char apel_nom[51];
    char domicilio[51];
}propietarios;

typedef struct
{
    int dni;
    int mes;
    int categoria;
}pagos;

typedef struct
{
    int dni;
    int mes;
    int categoria;
}errores;

void CargarImportes(categorias[],int);
int CargaPropietarios(propietarios[],int);
int buscar(propietarios[],int,int);
void CargarPagos(propietarios[],pagos[],int,char[][12],errores[],float[],categorias[]);
void ListarPropietarios(propietarios[], int);
void inicializar(char[][12],int, int);
void MostrarMatriz(char[][12],int,int,propietarios[]);
void MostrarPagado(float[],int n,propietarios[]);
void cargarDeudas(char[][12],int,propietarios[]);

int main()
{
    propietarios prop[100];
    pagos pag[100];
    categorias importes[5];
    errores error[100];
    CargarImportes(importes,5);
    int cant_prop;
    char m[100][12];
    float pagado_x_prop[100]={0};
    cant_prop=CargaPropietarios(prop,100);
    inicializar(m,cant_prop,12);
    CargarPagos(prop,pag,cant_prop,m,error,pagado_x_prop,importes);
    cargarDeudas(m,cant_prop,prop);
    MostrarMatriz(m,cant_prop,12,prop);
    system("Pause");
    MostrarPagado(pagado_x_prop,cant_prop,prop);

    return 0;
}

void CargarImportes(categorias imp[],int n)
{
    int x;
    FILE*fp;
    fp=fopen("EXPENSAS.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    printf("\nCARGA DE LOS IMPORTES POR CATEGORIA");
    for(x=0;x<n;x++)
    {
        printf("\nIngrese el importe de la categoria nro %d:",x+1);
        scanf("%f",&imp[x].importe);
        fwrite(&imp[x].importe,sizeof(categorias),1,fp);
    }
    fclose(fp);
}

int CargaPropietarios(propietarios prop[],int n)
{
    int x=0,dni,pos;
    FILE*fp2;
    fp2=fopen("propietarios.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("\nCARGA DE LOS PROPIETARIOS");
    do
    {
        printf("\nIngrese el dni del propietario nro %d[SALIDA=0]:",x+1);
        scanf("%d",&dni);
    }while((dni<10000000||dni>99999999)&&dni!=0);
    while(dni!=0&&x<n)
    {
        prop[x].dni=dni;
        do
        {
            printf("\nIngrese Apellido y Nombre del propietario: ");
            fflush(stdin);
            gets(prop[x].apel_nom);
        }while(strlen(prop[x].apel_nom)<1||strlen(prop[x].apel_nom)>50);
        do
        {
            printf("\nIngrese el domicilio del propietario: ");
            fflush(stdin);
            gets(prop[x].domicilio);
        }while(strlen(prop[x].domicilio)<1||strlen(prop[x].domicilio)>50);
        fwrite(&prop[x],sizeof(propietarios),1,fp2);
        x++;
        do
        {
            printf("\nIngrese el dni del propietario nro %d[SALIDA=0]:",x+1);
            scanf("%d",&dni);
            pos=buscar(prop,dni,x);
            if(pos!=-1)
                printf("\nYa se cargaron datos de este propietario");
        }while((dni<10000000||dni>99999999||pos!=-1)&&dni!=0);
    }
    fclose(fp2);
    return x;
}

int buscar(propietarios pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].dni==cod)
           p=i;
      else
          i++;
  }
  return p;
}

void ListarPropietarios (propietarios vc[], int ce)
{
    int i;
    system("cls");
    printf("\n\nLISTADO DE PROPIETARIOS\n");
    printf("--------------------\n\n");
    printf("%-21s %s         %s\n","DNI", "APELLIDO Y NOMBRE","DOMICILIO");
    printf("%-21s %s    %s\n","----------", "-------------------","-----------");
    for (i=0;i<ce;i++)
    {
        printf("%d           %s          %s\n", vc[i].dni, vc[i].apel_nom,vc[i].domicilio);
    }
    printf("\n");
    system("Pause");
}

void CargarPagos(propietarios prop[],pagos pag[],int n,char m[][12],errores error[],float pagado_x_prop[],categorias importes[])
{
    int x=0,dni,pos,i=0;
    FILE*fp3;
    FILE*fp4;
    fp3=fopen("pagos.dat","wb");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp4=fopen("error.dat","wb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    printf("\nCARGA DE PAGOS");
    ListarPropietarios(prop,n);
    printf("\nIngrese su dni[SALIDA=0]: ");
    scanf("%d",&dni);
    while(dni!=0)
    {
        pos=buscar(prop,dni,n);
        if(pos!=-1)
        {
            pag[x].dni=dni;
            do
            {
                printf("\nIngrese el mes que desea pagar:");
                scanf("%d",&pag[x].mes);
                if(m[pos][pag[x].mes-1]=='P')
                    printf("\nEste mes ya fue pagado");
            }while(pag[x].mes<1||pag[x].mes>12||m[pos][pag[x].mes-1]=='P');
            do
            {
                printf("\nIngrese la categoria que desea pagar: ");
                scanf("%d",&pag[x].categoria);
            }while(pag[x].categoria<1||pag[x].categoria>5);
            m[pos][pag[x].mes-1]='P';
            pagado_x_prop[pos]+=importes[pag[x].categoria].importe;
            fwrite(&pag[x],sizeof(pagos),1,fp3);
            x++;
        }
        else
        {
            printf("\nDNI NO ENCONTRADO");
            error[i].dni=dni;
            do
            {
                printf("\nIngrese el mes que desearia pagar:");
                scanf("%d",&error[i].mes);
            }while(error[i].mes<1||error[i].mes>12);
            do
            {
                printf("\nIngrese la categoria que desearia pagar: ");
                scanf("%d",&error[i].categoria);
            }while(error[i].categoria<1||error[i].categoria>5);
            fwrite(&error[i],sizeof(errores),1,fp4);
            i++;
        }
        ListarPropietarios(prop,n);
        printf("\nIngrese su dni[SALIDA=0]: ");
        scanf("%d",&dni);
    }
    fclose(fp3);
    fclose(fp4);
}

void inicializar(char m[][12],int f, int c)
{
    int x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            m[x][i]='X';
        }
    }
}

void cargarDeudas(char m[][12],int n,propietarios prop[])
{
    FILE*fp5;
    int cont,sen,x,i;
    fp5=fopen("deudas.dat","wb");
    if(fp5==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    for(x=0;x<n;x++)
    {
        sen=0;
        cont=0;
        for(i=0;i<12;i++)
        {
            if(m[x][i]=='X')
                cont++;
            if(cont>6&&sen==0)
            {
                sen=1;
                fwrite(&prop[x],sizeof(propietarios),1,fp5);
                //printf("\n%s",prop[x].apel_nom);
            }
        }
    }
    fclose(fp5);
}

void MostrarMatriz(char m[][12],int f,int c,propietarios prop[])
{
    int x,i;
    //system("cls");
    printf("LISTADO DE MESES QUE FALTAN PAGAR:");
    printf("\nNOMBRE Y APELLIDO      1  2  3  4  5  6  7  8  9  10  11  12");
    for(x=0;x<f;x++)
    {
        printf("\n%s               ",prop[x].apel_nom);
        for(i=0;i<c;i++)
        {
            if(m[x][i]=='P')
                m[x][i]=' ';
            printf(" %c ",m[x][i]);
        }
        printf("\n");
    }
}

void MostrarPagado(float total[],int n, propietarios prop[])
{
    int x;
    printf("\n\nTOTAL DE IMPORTES PAGADOS POR CADA PROPIETARIO");
    printf("\nAPELLIDO Y NOMBRE     TOTAL");
    for(x=0;x<n;x++)
    {
        printf("\n%s        %0.2f",prop[x].apel_nom,total[x]);
    }
}

