#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define AGREGARPROD 1
#define AGREGARPED 2
#define LISTAR 3
#define GENERREP 4
#define SALIR 5

typedef struct
{
    int cod_prod;
    char descripcion[35];
    int stock;
    float precio_uni;
}productos;

typedef struct
{
    int cod_prod;
    int cant;
    int num_clien;
    int dia;
}pedidos;

int menu(int,int);
int RecuperarProductos(productos[],int);
void ListarProductos(productos[],int);
int agregarProductos(productos[],int,int);
int buscar(productos[],int,int);
int mayor_cero(int);
float validarfloat();
void AgregarPedidos(productos[],pedidos,int,int[]);
int lee_control(int,int,int);
void listarpedidos();
void generarreportes(int[]);

int main()
{
    productos prod[100];
    pedidos ped;
    int cant_prod=0,opcion,cant_pedidos=0,prod_x_dia[30]={0};
    cant_prod=RecuperarProductos(prod,100);
    opcion=menu(cant_prod,cant_pedidos);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case AGREGARPROD:
            cant_prod=agregarProductos(prod,100,cant_prod);
            break;

        case AGREGARPED:
            AgregarPedidos(prod,ped,cant_prod,prod_x_dia);
            cant_pedidos++;
            break;

        case LISTAR:
            listarpedidos();
            break;

        case GENERREP:
            generarreportes(prod_x_dia);
            break;
        }
        opcion=menu(cant_prod,cant_pedidos);
    }
    return 0;
}

int agregarProductos(productos prod[], int cantidaMaxima,int cantidadActual)
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
        archivo = fopen("Productos.dat","ab");
    else
    {
        archivo = fopen("Productos.dat","wb");
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
        printf("\nIngrese el codigo del producto[SALIDA=0]: ");
        scanf("%d",&cod);
        pos=buscar(prod,cod,cantidadActual);
        if(pos!=-1)
        {
            printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
            system("pause");
        }
    }while(pos!=-1);
    while(cantidadActual<cantidaMaxima && cod!=0)
    {
        prod[cantidadActual].cod_prod=cod;
        do
        {
            printf("Ingrese la descripcion del producto:");
            fflush(stdin);
            gets(prod[cantidadActual].descripcion);
        }while(strlen(prod[cantidadActual].descripcion)<1||strlen(prod[cantidadActual].descripcion)>35);
        prod[cantidadActual].stock=mayor_cero(1);
        prod[cantidadActual].precio_uni=validarfloat();
        fwrite(&prod[cantidadActual], sizeof(productos),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            do
            {
                ListarProductos(prod,cantidadActual);
                printf("\nIngrese el codigo del producto[SALIDA=0]: ");
                scanf("%d",&cod);
                pos=buscar(prod,cod,cantidadActual);
                if(pos!=-1)
                {
                    printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
                    system("pause");
                }
            }while(pos!=-1);
        }
        else
            printf("\nSe llego a la cantidad maxima de los produtos permitidos.\n");
    }
    fclose(archivo);
    return cantidadActual;
}

void AgregarPedidos(productos prod[],pedidos ped,int cant_prod,int prod_x_dia[])
{
    int cod,pos;
    FILE*fp2;
    FILE*fp3;
    fp2=fopen("Pedidos.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp3=fopen("Productos.dat","ab");
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
        ped.cod_prod=cod;
        do
        {
            ped.cant=mayor_cero(2);
            if(ped.cant>prod[pos].stock)
            {
                printf("\nLa cantidad solicitada no puede ser entregada debido a falta de stock");
                printf("\nIngrese otra cantidad");
            }
        }while(ped.cant>prod[pos].stock);
        ped.num_clien=lee_control(1,350,1);
        ped.dia=lee_control(1,30,2);
        prod_x_dia[ped.dia-1]+=ped.cant;
        prod[pos].stock-=ped.cant;
        fwrite(&prod[pos].stock,sizeof(productos),1,fp3);
        fwrite(&ped,sizeof(pedidos),1,fp2);
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

void listarpedidos()
{
    pedidos ped;
    FILE*fp4;
    fp4=fopen("Pedidos.dat","rb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("LISTADO DE PEDIDOS\n");
    printf("--------------------\n\n");
    printf("%-21s  %s  %s  %s\n","COD. PRODUCTO","CANT UNIDADES","NUM CLIENTE","DIA");
    printf("%-21s  %s  %s  %s\n","-------------","-------------","-----------","---");
    fread(&ped,sizeof(pedidos),1,fp4);
    while(!feof(fp4))
    {
        printf("%d                       %d             %d     %d\n",ped.cod_prod,ped.cant,ped.num_clien,ped.dia);
        fread(&ped,sizeof(pedidos),1,fp4);
    }
    system("pause");
    fclose(fp4);
}

void generarreportes(int prod_x_cliente[])
{
    int cant_pedidos=0,max,cliente_max,x;
    pedidos ped;
    FILE*fp4;
    fp4=fopen("Pedidos.dat","rb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp4!=NULL)
    {
        fread(&ped, sizeof(pedidos),1, fp4);
        while (!feof(fp4))
        {
            if(cant_pedidos==0)
            {
                max=ped.cant;
                cliente_max=ped.num_clien;
            }
            else
            {
                if(max<ped.cant)
                {
                    max=ped.cant;
                    cliente_max=ped.num_clien;
                }
            }
            cant_pedidos++;
            fread(&ped, sizeof(pedidos),1, fp4);
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
    printf("EL cliente que realizo el pedido de producto con mayor cantidad fue el cliente nro %d con una cantidad de %d\n",cliente_max,max);
    system("pause");
    fclose(fp4);
}

void ListarProductos(productos vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE PRODUCTOS\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s  %s\n","CODIGO", "DESCRIPCION","STOCK","PRECIO");
    printf("%s %-21s  %s  %s\n","------", "-----------","-----","------");
    for (i=0;i<ce;i++)
    {
        if(vc[i].cod_prod>1000&&vc[i].cod_prod<10000)
            printf("%d        %s            %d           %0.2f\n", vc[i].cod_prod, vc[i].descripcion,vc[i].stock,vc[i].precio_uni);
    }

    printf("\n");
    system("Pause");
}

int menu(int hayProd,int hayPedidos)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Agregar Productos\n");
    if (hayProd)
    {
        printf("2. Agregar Pedidos\n");
        printf("3. Listar Contenido de archivos\n");
    }
    if(hayPedidos)
        printf("4. Generar Reportes\n");
    printf("5. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >5);
    return opcion;
}

int RecuperarProductos(productos prod[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("Productos.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp!=NULL)
    {
        fread(&prod[i], sizeof(productos),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&prod[i], sizeof(productos),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int buscar(productos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod_prod==cod)
           p=i;
      else
          i++;
  }
  return p;
}

int mayor_cero(int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el stock del producto: ");
        if(n==2)printf("\nIngrese la cantidad de unidades pedidas: ");
        scanf("%d",&dato);
    }while(dato<0);
    return dato;
}

float validarfloat()
{
    float dato;
    do
    {
        printf("\nIngrese el precio por unidad: ");
        scanf("%f",&dato);
    }while(dato<0);
    return dato;
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el numero de cliente[entre 1 y 350]: ");
        if(n==2)printf("\nIngrese el dia[entre 1 y 30]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}


