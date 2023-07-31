#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CARGARSTOCK 1
#define CARGAPED 2
#define INFORME 3
#define LISTAR 4
#define SALIR 5

typedef struct
{
    int codigo;
    char descripcion[31];
    float precio;
    int punto_pedido;
    int stock;
}productos;

typedef struct
{
    int codigo;
    int cant_pedidos;
    int num_cliente;
    int num_pedido;
    int dia_fecha;
}pedidos;

int menu(int,int);
void ListarProductos(productos[], int);
int RecuperarProductos(productos[],int);
int lee_control(int,int,int);
int buscar(productos[],int,int);
int CargarProductos(productos[], int,int);
void AgregarPedidos(productos[],int,int[]);
void GenerarInforme(int[]);
void ListarArchivos(productos[],int);

int main()
{
    productos prod[3500];
    int cant_productos=0,opcion,cant_ped=0,prod_x_dia[31]={0};
    //if(cant_productos>0)
    cant_productos=RecuperarProductos(prod,3500);
    opcion=menu(cant_productos,cant_ped);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case CARGARSTOCK:
            cant_productos=CargarProductos(prod,3500,cant_productos);
            break;

        case CARGAPED:
            AgregarPedidos(prod,cant_productos,prod_x_dia);
            cant_ped=1;
            break;

        case INFORME:
            GenerarInforme(prod_x_dia);
            break;

        case LISTAR:
            ListarArchivos(prod,cant_productos);
            break;
        }
        opcion=menu(cant_productos,cant_ped);
    }
    return 0;
}

int CargarProductos(productos prod[], int cantidaMaxima,int cantidadActual)
{
    FILE*archivo;
    char opcion;
    if(cantidadActual>0)
    {
        do
        {
            ListarProductos(prod,cantidadActual);
            printf("\nIngrese C si quiere agregar productos a los existentes");
            printf("\nIngrese I si quiere crear una nueva lista de productos y borrar los anteriores");
            printf("\nIngrese S si desea salir y volver al menu: ");
            fflush(stdin);
            opcion = getchar();
            opcion = toupper(opcion);
        }while(opcion !='C' && opcion!='I'&&opcion!= 'S');
    }
    else
        opcion = 'I';
    if(opcion=='C')
        archivo = fopen("Stock.dat","ab");
    if(opcion=='I')
    {
        archivo = fopen("Stock.dat","wb");
        cantidadActual=0;
    }
    if (archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo de productos.\n");
        system("pause");
        exit(1);
    }
    /*
    do
        {
            ListarProductos(prod,cantidadActual);
            printf("Ingrese la descripcion del producto[SALIDA='FIN']:");
            fflush(stdin);
            gets(prod[cantidadActual].descripcion);
        }while(strlen(prod[cantidadActual].descripcion)<1||strlen(prod[cantidadActual].descripcion)>30);*/
    while(opcion!='S'&&strcmpi(prod[cantidadActual].descripcion,"FIN")!=0) //AL PEDOOOO
    {
        do
        {
            ListarProductos(prod,cantidadActual);
            printf("Ingrese la descripcion del producto[SALIDA='FIN']:");
            fflush(stdin);
            gets(prod[cantidadActual].descripcion);
        }while(strlen(prod[cantidadActual].descripcion)<1||strlen(prod[cantidadActual].descripcion)>30);
        while(opcion!='S'&&cantidadActual<cantidaMaxima && strcmpi(prod[cantidadActual].descripcion,"FIN")!=0)
        {
            do
            {
                printf("Ingrese el codigo del producto:");
                scanf("%d",&prod[cantidadActual].codigo);
            }while(prod[cantidadActual].codigo<1000||prod[cantidadActual].codigo>10000);
            do
            {
                printf("\nIngrese el precio del producto:");
                scanf("%f",&prod[cantidadActual].precio);
            }while(prod[cantidadActual].precio<0);
            do
            {
                printf("\nIngrese el punto de pedido:");
                scanf("%d",&prod[cantidadActual].punto_pedido);
            }while(prod[cantidadActual].punto_pedido<0);
            do
            {
                printf("\nIngrese el stock del producto:");
                scanf("%d",&prod[cantidadActual].stock);
            }while(prod[cantidadActual].stock<0);
            fwrite(&prod[cantidadActual], sizeof(productos),1,archivo);
            cantidadActual++;
            if (cantidadActual<cantidaMaxima)
            {
                do
                {
                    ListarProductos(prod,cantidadActual);
                    printf("Ingrese la descripcion del producto[SALIDA='FIN':");
                    fflush(stdin);
                    gets(prod[cantidadActual].descripcion);
                }while(strlen(prod[cantidadActual].descripcion)<1||strlen(prod[cantidadActual].descripcion)>30);
            }
            else
                printf("\nSe llego a la cantidad maxima de los produtos permitidos.\n");
        }
        fclose(archivo);
    }
    return cantidadActual;
}

void AgregarPedidos(productos prod[],int cant_prod,int prod_x_dia[])
{
    int cod,pos;
    pedidos ped;
    pedidos nostock;
    FILE*fp2;
    FILE*fp3;
    FILE*fp4;
    fp2=fopen("Pedidos.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp3=fopen("Stock.dat","ab");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp4=fopen("No_stock.dat","wb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        ListarProductos(prod,cant_prod);
        printf("\nIngrese el codigo del producto[SALIDA=99]: ");
        scanf("%d",&cod);
        pos=buscar(prod,cod,cant_prod);
        if(prod[pos].stock==0&&pos!=-1)
        {
            printf("\nNo tenemos stock de este producto, ingrese otro");
            system("pause");
        }
        if(pos==-1&&cod!=99)
        {
            printf("\nCODIGO DE PRODUCTO NO EXISTENTE");
            system("pause");
        }
    }while((pos==-1&&cod!=99)||(prod[pos].stock==0&&cod!=99));
    while(cod!=99)
    {
        ped.codigo=cod;
        ped.num_cliente=lee_control(1,3000,1);
        ped.num_pedido=lee_control(1,2000,2);
        ped.dia_fecha=lee_control(1,31,3);
        do
        {
            printf("\nIngrese la cantidad de unidades que desea: ");
            scanf("%d",&ped.cant_pedidos);
            if(ped.cant_pedidos>prod[pos].stock)
            {
                printf("\nLa cantidad solicitada de este producto es mayor que la cantidad disponible");
                printf("\nVuelva a intentarlo: ");
                nostock=ped;
                prod_x_dia[ped.dia_fecha-1]+=ped.cant_pedidos;
                fwrite(&nostock,sizeof(productos),1,fp4);
                system("pause");
            }
        }while(ped.cant_pedidos<0||ped.cant_pedidos>prod[pos].stock);
        prod[pos].stock-=ped.cant_pedidos;
        fwrite(&prod[pos].stock,sizeof(productos),1,fp3);
        fwrite(&ped,sizeof(pedidos),1,fp2);
        do
        {
            ListarProductos(prod,cant_prod);
            printf("\nIngrese el codigo del producto[SALIDA=99]: ");
            scanf("%d",&cod);
            pos=buscar(prod,cod,cant_prod);
            if(prod[pos].stock==0&&pos!=-1)
            {
                printf("\nNo tenemos stock de este producto, ingrese otro");
                system("pause");
            }
            if(pos==-1&&cod!=99)
            {
                printf("\nCODIGO DE PRODUCTO NO EXISTENTE");
                system("pause");
            }
        }while((pos==-1&&cod!=99)||(prod[pos].stock==0&&cod!=99));
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}

void GenerarInforme(int prod_x_dia[])
{
    int cant_pedidos=0,x,sen=0,aux,i;
    int dias[31]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
    pedidos nostock;
    FILE*fp4;
    fp4=fopen("No_stock.dat","rb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp4!=NULL)
    {
        fread(&nostock, sizeof(pedidos),1, fp4);
        while (!feof(fp4))
        {
            //prod_x_dia[nostock.dia_fecha-1]+=nostock.cant_pedidos;
            cant_pedidos++;
            fread(&nostock, sizeof(pedidos),1, fp4);
        }
    }
    while(sen==0)
	{
		sen=1;
		for(i=0;i<31-1;i++)
		{
			if(prod_x_dia[i]<prod_x_dia[i+1])
            {
			   	aux=prod_x_dia[i];
			   	prod_x_dia[i]=prod_x_dia[i+1];
			   	prod_x_dia[i+1]=aux;

			   	aux=dias[i];
			   	dias[i]=dias[i+1];
			   	dias[i+1]=aux;

			   	sen=0;
            }
		}
    }
    system("cls");
    printf("LISTADO DE PEDIDOS NO CUMPLIDOS POR DIA\n");
    printf("---------------------------------------\n\n");
    printf("%s  %s\n","DIA","CANT PRODUCTOS");
    printf("%s  %s\n","---","--------------");
    for(x=0;x<31;x++)
    {
        if(prod_x_dia[x]!=0)
            printf("%d       %d\n",dias[x],prod_x_dia[x]);
    }
    system("pause");
    fclose(fp4);
}

void ListarArchivos(productos prod[],int cant_prod)
{
    char opcion;
    pedidos ped;
    FILE*archivo;
    archivo=fopen("Pedidos.dat","rb");
    if(archivo==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        system("cls");
        printf("\nIngrese 'A' si desea visualizar el stock de los productos ");
        printf("\nIngrese 'B' si desea visualizar la lista de pedidos: ");
        fflush(stdin);
        //opcion=toupper(opcion);
        scanf("%c",&opcion);
        opcion=toupper(opcion);
    }while(opcion!='A'&&opcion!='B');
    if(opcion=='A')
        ListarProductos(prod,cant_prod);
    else
    {
        system("cls");
        printf("LISTADO DE PEDIDOS\n");
        printf("--------------------\n\n");
        printf("%s  %s   %s   %s\n","CODIGO","CANT.PEDIDA","NUM.CLIENTE","FECHA");
        printf("%s  %s   %s   %s\n","------","-----------","-----------","-----");
        fread(&ped,sizeof(pedidos),1,archivo);
        //printf("%d        %d        %d          %d\n",ped.codigo,ped.cant_pedidos,ped.num_cliente,ped.dia_fecha);
        while(!feof(archivo))
        {
            printf("%d        %d        %d          %d\n",ped.codigo,ped.cant_pedidos,ped.num_cliente,ped.dia_fecha);
            fread(&ped,sizeof(pedidos),1,archivo);
        }
        system("pause");
    }
    fclose(archivo);

}

void ListarProductos(productos vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE PRODUCTOS\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s  %s  %s\n","CODIGO", "DESCRIPCION","PRECIO","PUNTO DE PEDIDO","STOCK");
    printf("%s %-21s  %s  %s  %s\n","------", "-----------","------","---------------","-----");
    for (i=0;i<ce;i++)
    {
        if(vc[i].codigo>=1000&&vc[i].codigo<=10000)
            printf("%d        %s            %0.2f           %d        %d\n", vc[i].codigo, vc[i].descripcion,vc[i].precio,vc[i].punto_pedido,vc[i].stock);
    }
    printf("\n");
    system("Pause");
}

int RecuperarProductos(productos prod[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("Stock.dat","rb");
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

int menu(int hayProd,int hayPed)
{
    int opcion;
    system("cls");
    printf("\n                                  OCAMPO NICOLE\n");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Carga Archivo Stock\n");
    if (hayProd)
        printf("2. Carga de Pedidos\n");
    if(hayPed)
    {
        printf("3. Informe de Pedidos\n");
        printf("4. Listado de Archivos Productos o Pedidos\n");
    }
    printf("5. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >5);
    return opcion;
}

int buscar(productos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].codigo==cod)
           p=i;
      else
          i++;
  }
  return p;
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el numero de cliente[entre 1 y 3000]: ");
        if(n==2)printf("\nIngrese el numero de pedido [entre 1 y 2000]: ");
        if(n==3)printf("\nIngrese el dia[entre 1 y 31]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

