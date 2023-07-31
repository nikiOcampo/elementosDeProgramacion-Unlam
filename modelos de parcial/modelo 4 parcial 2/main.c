#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define AGREGARPROD 1
#define AGREGARMOVI 2
#define LISTAR 3
#define GENERREP 4
#define SALIR 5

typedef struct
{
    int cod_arti;
    char descripcion[35];
    int estado;
    int cant_uni;
}articulos;

typedef struct
{
    int cod_arti;
    int estado;
    int fecha;
    char marca;
}produccion;

int menu(int,int);
int RecuperarProductos(articulos[],int);
int agregarProductos(articulos[],int,int);
void ListarProductos(articulos[],int);
void AgregarProduccion(articulos[],int,int[]);
int buscar(articulos[],int,int);
int lee_control(int,int,int);
void listarproduccion();
void generarreportes(int[]);

int main()
{
    articulos prod[60];
    int cant_productos=0,opcion,cant_movi=0,prod_x_dia[31]={0};
    //if(cant_productos>0)
    cant_productos=RecuperarProductos(prod,60);
    opcion=menu(cant_productos,cant_movi);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case AGREGARPROD:
            cant_productos=agregarProductos(prod,60,cant_productos);
            break;

        case AGREGARMOVI:
            AgregarProduccion(prod,cant_productos,prod_x_dia);
            cant_movi++;
            break;

        case LISTAR:
            listarproduccion();
            break;

        case GENERREP:
            generarreportes(prod_x_dia);
            break;
        }
        opcion=menu(cant_productos,cant_movi);
    }
    return 0;
}

int agregarProductos(articulos prod[], int cantidaMaxima,int cantidadActual)
{
    int cod,pos;
    FILE*archivo;
    char opcion;
    if(cantidadActual>0)
    {
        do
        {
            ListarProductos(prod,cantidadActual);
            printf("\nIngrese A si quiere agregar productos a los existentes");
            printf("\nIngrese N si quiere crear una nueva lista de productos y borrar los anteriores:");
            fflush(stdin);
            opcion = getchar();
            opcion = toupper(opcion);
        }while(opcion !='A' && opcion!='N');
    }
    else
        opcion = 'N';
    if(opcion=='A')
        archivo = fopen("articulos.dat","ab");
    else
    {
        archivo = fopen("articulos.dat","wb");
        cantidadActual=0;
    }
    if (archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo de productos.\n");
        system("pause");
        exit(1);
    }
    do
    {
        ListarProductos(prod,cantidadActual);
        printf("\nIngrese el codigo de producto[de 2500 a 20000/SALIDA=0]: ");
        scanf("%d",&cod);
        pos=buscar(prod,cod,cantidadActual);
        if(pos!=-1)
        {
            printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
            system("pause");
        }
    }while((cod<2500||cod>20000||pos!=-1)&&cod!=0);
    while(cantidadActual<cantidaMaxima && cod!=0)
    {
        prod[cantidadActual].cod_arti=cod;
        do
        {
            printf("Ingrese la descripcion del producto:");
            fflush(stdin);
            gets(prod[cantidadActual].descripcion);
        }while(strlen(prod[cantidadActual].descripcion)<1||strlen(prod[cantidadActual].descripcion)>35);
        do
        {
            printf("\nIngrese el estado de produccion[1=PREPARACION/2=ARMADO/3=TERMINADO]:");
            scanf("%d",&prod[cantidadActual].estado);
        }while(prod[cantidadActual].estado<1||prod[cantidadActual].estado>3);
        prod[cantidadActual].cant_uni=lee_control(1,4000,2);
        fwrite(&prod[cantidadActual], sizeof(articulos),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            do
            {
                ListarProductos(prod,cantidadActual);
                printf("\nIngrese el codigo de producto[de 2500 a 20000/SALIDA=0]: ");
                scanf("%d",&cod);
                pos=buscar(prod,cod,cantidadActual);
                if(pos!=-1)
                {
                    printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
                    system("pause");
                }
            }while((cod<2500||cod>20000||pos!=-1)&&cod!=0);
        }
        else
            printf("\nSe llego a la cantidad maxima de los produtos permitidos.\n");
    }
    fclose(archivo);
    return cantidadActual;
}

void AgregarProduccion(articulos prod[],int cant_prod,int prod_x_dia[])
{
    int cod,pos;
    produccion movi;
    FILE*fp2;
    FILE*fp3;
    fp2=fopen("produccion.dat","ab");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp3=fopen("articulos.dat","ab");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        ListarProductos(prod,cant_prod);
        printf("\nIngrese el codigo del producto[SALIDA=0]: ");
        scanf("%d",&cod);
        pos=buscar(prod,cod,cant_prod);
        if(pos==-1&&cod!=0)
        {
            printf("\nCODIGO DE PRODUCTO NO EXISTENTE");
            system("pause");
        }
    }while(pos==-1&&cod!=0);
    while(cod!=0)
    {
        movi.cod_arti=cod;
        do
        {
            printf("\nIngrese el estado de produccion[1=PREPARACION/2=ARMADO/3=TERMINADO]:");
            scanf("%d",&movi.estado);
        }while(movi.estado<1||movi.estado>3);
        prod[pos].estado=movi.estado;
        movi.fecha=lee_control(1,31,3);
        movi.marca='N';
        prod_x_dia[movi.fecha-1]+=prod[pos].cant_uni;
        fwrite(&prod[pos].estado,sizeof(articulos),1,fp3);
        fwrite(&movi,sizeof(produccion),1,fp2);
        do
        {
            ListarProductos(prod,cant_prod);
            printf("\nIngrese el codigo del producto[SALIDA=0]: ");
            scanf("%d",&cod);
            pos=buscar(prod,cod,cant_prod);
            if(pos==-1&&cod!=0)
            {
                printf("\nCODIGO DE PRODUCTO NO EXISTENTE");
                system("pause");
            }
        }while(pos==-1&&cod!=0);
    }
    fclose(fp2);
    fclose(fp3);
}

void ListarProductos(articulos vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE PRODUCTOS\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s  %s\n","CODIGO", "DESCRIPCION","ESTADO","CANTIDAD");
    printf("%s %-21s  %s  %s\n","------", "-----------","------","--------");
    for (i=0;i<ce;i++)
    {
        if(vc[i].cod_arti>=2500&&vc[i].cod_arti<=20000)
            printf("%d        %s            %d           %d\n", vc[i].cod_arti, vc[i].descripcion,vc[i].estado,vc[i].cant_uni);
    }

    printf("\n");
    system("Pause");
}

void listarproduccion()
{
    produccion prod;
    FILE*fp4;
    fp4=fopen("produccion.dat","rb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("LISTADO DE PRODUCCION EN EL MES DE MAYO\n");
    printf("--------------------\n\n");
    printf("%-21s  %-12s  %s  %s\n","COD. PRODUCTO","ESTADO","DIA","MARCA");
    printf("%-21s  %-12s  %s  %s\n","-------------","------","---","-----");
    fread(&prod,sizeof(produccion),1,fp4);
    while(!feof(fp4))
    {
        if(prod.estado==1)
            printf("%d                 %-12s         %d     %c\n",prod.cod_arti,"PREPARACION",prod.fecha,prod.marca);
        if(prod.estado==2)
            printf("%d                 %-12s         %d     %c\n",prod.cod_arti,"ARMADO",prod.fecha,prod.marca);
        if(prod.estado==3)
            printf("%d                 %-12s         %d     %c\n",prod.cod_arti,"TERMINADO",prod.fecha,prod.marca);
        fread(&prod,sizeof(produccion),1,fp4);
    }
    system("pause");
    fclose(fp4);
}

void generarreportes(int prod_x_cliente[])
{
    int cant_pedidos=0,x;
    produccion prod;
    FILE*fp4;
    fp4=fopen("produccion.dat","rb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp4!=NULL)
    {
        fread(&prod, sizeof(produccion),1, fp4);
        while (!feof(fp4))
        {
            cant_pedidos++;
            fread(&prod, sizeof(produccion),1, fp4);
        }
    }
    system("cls");
    printf("LISTADO DE PEDIDOS POR DIA\n");
    printf("--------------------\n\n");
    printf("%s  %s\n","DIA","CANT PRODUCTOS");
    printf("%s  %s\n","---","--------------");
    for(x=0;x<30;x++)
    {
        printf("%d       %d\n",x+1,prod_x_cliente[x]);
    }
    system("pause");
    fclose(fp4);
}

int menu(int hayProd,int hayProduccion)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Agregar Productos\n");
    if (hayProd)
        printf("2. Agregar Produccion\n");
    if(hayProduccion)
    {
        printf("3. Listar Contenido de Archivo Produccion\n");
        printf("4. Generar Reportes\n");
    }
    printf("5. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >5);
    return opcion;
}

int RecuperarProductos(articulos prod[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("articulos.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp!=NULL)
    {
        fread(&prod[i], sizeof(articulos),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&prod[i], sizeof(articulos),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el codigo de producto[de 2500 a 20000/SALIDA=0]: ");
        if(n==2)printf("\nIngrese la cantidad de unidades[entre 1 y 4000]: ");
        if(n==3)printf("\nIngrese el dia: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

int buscar(articulos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod_arti==cod)
           p=i;
      else
          i++;
  }
  return p;
}

