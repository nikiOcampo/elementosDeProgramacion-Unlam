#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define AGREGARCLIENTE 1
#define PAGARCUOTAS 2
#define CONSULTAR 3
#define LISTAR 4
#define SALIR 5

typedef struct
{
    char ApelyNom[31];
    char patente[9];
    char domicilio[31];
    char localidad[21];
    char telefono[21];
    int categoria_vehi;
    int anio_fabri;
}clientes;

typedef struct
{
    char patente[9];
    float importe01;
    float importe02;
    float importe03;
    float importe04;
    float importe05;
    float importe06;
    float importe07;
    float importe08;
    float importe09;
    float importe10;
    float importe11;
    float importe12;
}importes;

typedef struct
{
    char ApelyNom[31];
    char patente[9];
    float importe_abonado;
    int mes;
}pagocuotas;

int RecuperarClientes(clientes[],int);
int CargaClientes(clientes[],int,int,importes[]);
int menu(int);
void ListarClientes(clientes[],int);
int buscar(clientes[], char[30], int);
int lee_control(int,int,int);
void pagos(clientes[],int,importes[],int[][12]);
void consultas(importes[],clientes[],int,int[][12]);
void listardeudores(clientes[],int[][12],int);

int main()
{
    clientes clien[1000];
    importes imp[1000];
    int cant_clientes=0,opcion,mesespagados[1000][12]={0};
    //if(cant_clientes!=0)
    cant_clientes=RecuperarClientes(clien,1000);
    opcion=menu(cant_clientes);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case AGREGARCLIENTE:
            cant_clientes=CargaClientes(clien,1000,cant_clientes,imp);
            break;

        case PAGARCUOTAS:
            pagos(clien,cant_clientes,imp,mesespagados);
            break;

        case CONSULTAR:
            consultas(imp,clien,cant_clientes,mesespagados);
            break;

        case LISTAR:
            listardeudores(clien,mesespagados,cant_clientes);
            break;
        }
        opcion=menu(cant_clientes);
    }
    return 0;
}

int RecuperarClientes(clientes clie[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("CLIENTES.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp!=NULL)
    {
        fread(&clie[i], sizeof(clientes),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&clie[i], sizeof(clientes),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int menu(int hayClientes)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Agregar Clientes\n");
    if (hayClientes)
    {
        printf("2. Pagar cuotas\n");
        printf("3. Consultar deuda cliente\n");
        printf("4. Listado deudores\n");
    }
    printf("5. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >5);
    return opcion;
}

int CargaClientes(clientes clien[], int cantidaMaxima,int cantidadActual,importes imp[])
{
    int pos;
    FILE*archivo;
    FILE*pagos;
    pagos= fopen("PAGOS.dat","ab");
    if (pagos==NULL)
    {
        printf("\nNo se pudo abrir el archivo de pagos.\n");
        system("pause");
        exit(1);
    }
    char opcion,nombre_a_buscar[30];
    if(cantidadActual>0)
    {
        do
        {
            ListarClientes(clien,cantidadActual);
            printf("\nIngrese A si quiere agregar clientes a los existentes");
            printf("\nIngrese N si quiere crear una nueva lista de clientes y borrar los anteriores:");
            fflush(stdin);
            opcion = getchar();
            opcion = toupper(opcion);
        }while(opcion !='A' && opcion!='N');
    }
    else
        opcion = 'N';
    if(opcion=='A')
        archivo = fopen("CLIENTES.dat","ab");
    else
    {
        archivo = fopen("CLIENTES.dat","wb");
        cantidadActual=0;
    }
    if (archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo de clientes.\n");
        system("pause");
        exit(1);
    }
    do
    {
        ListarClientes(clien,cantidadActual);
        printf("\nIngrese el Apellido y Nombre del cliente [SALIDA='FIN']: ");
        fflush(stdin);
        gets(nombre_a_buscar);
        pos=buscar(clien,nombre_a_buscar,cantidadActual);
        if(pos!=-1)
        {
            printf("\nYA SE CRAGARON DATOS DE ESTE CLIENTE");
            system("pause");
        }
    }while(strlen(nombre_a_buscar)<1||strlen(nombre_a_buscar)>30||pos!=-1);
    while(cantidadActual<cantidaMaxima && strcmpi(nombre_a_buscar,"FIN")!=0)
    {
        strcpy(clien[cantidadActual].ApelyNom,nombre_a_buscar);
        do
        {
            printf("Ingrese el nro de patente:");
            fflush(stdin);
            gets(clien[cantidadActual].patente);
        }while(strlen(clien[cantidadActual].patente)<1||strlen(clien[cantidadActual].patente)>8);
        do
        {
            printf("Ingrese el domicilio:");
            fflush(stdin);
            gets(clien[cantidadActual].domicilio);
        }while(strlen(clien[cantidadActual].domicilio)<1||strlen(clien[cantidadActual].domicilio)>30);
        do
        {
            printf("Ingrese la localidad:");
            fflush(stdin);
            gets(clien[cantidadActual].localidad);
        }while(strlen(clien[cantidadActual].localidad)<1||strlen(clien[cantidadActual].localidad)>20);
        do
        {
            printf("Ingrese el nro de telefono:");
            fflush(stdin);
            gets(clien[cantidadActual].telefono);
        }while(strlen(clien[cantidadActual].telefono)<1||strlen(clien[cantidadActual].telefono)>20);
        clien[cantidadActual].categoria_vehi=lee_control(1,25,1);
        clien[cantidadActual].anio_fabri=lee_control(1000,2022,2);
        strcpy(imp[cantidadActual].patente,clien[cantidadActual].patente);
        imp[cantidadActual].importe01=0;
        imp[cantidadActual].importe02=0;
        imp[cantidadActual].importe03=0;
        imp[cantidadActual].importe04=0;
        imp[cantidadActual].importe05=0;
        imp[cantidadActual].importe06=0;
        imp[cantidadActual].importe07=0;
        imp[cantidadActual].importe08=0;
        imp[cantidadActual].importe09=0;
        imp[cantidadActual].importe10=0;
        imp[cantidadActual].importe11=0;
        imp[cantidadActual].importe12=0;
        fwrite(&imp[cantidadActual],sizeof(importes),1,pagos);
        fwrite(&clien[cantidadActual], sizeof(clientes),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            do
            {
                ListarClientes(clien,cantidadActual);
                printf("\nIngrese el Apellido y Nombre del cliente [SALIDA='FIN']: ");
                fflush(stdin);
                gets(nombre_a_buscar);
                pos=buscar(clien,nombre_a_buscar,cantidadActual);
                if(pos!=-1)
                {
                    printf("\nYA SE CRAGARON DATOS DE ESTE CLIENTE");
                    system("pause");
                }
            }while(strlen(nombre_a_buscar)<1||strlen(nombre_a_buscar)>30||pos!=-1);
        }
        else
            printf("\nSe llego a la cantidad maxima de los clientes permitidos.\n");
    }
    fclose(archivo);
    fclose(pagos);
    return cantidadActual;
}

void pagos(clientes clien[],int cantidad_clien,importes imp[],int meses_pagados[][12])
{
    pagocuotas pag;
    FILE*fp1;
    char nombre_a_buscar[31];
    int pos;
    fp1=fopen("PAGOS.dat","ab");
    if (fp1==NULL)
    {
        printf("\nNo se pudo abrir el archivo de pagos.\n");
        system("pause");
        exit(1);
    }
    do
    {
        ListarClientes(clien,cantidad_clien);
        printf("\nIngrese el Apellido y Nombre del cliente [SALIDA='FIN']: ");
        fflush(stdin);
        gets(nombre_a_buscar);
        pos=buscar(clien,nombre_a_buscar,cantidad_clien);
        if(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0)
        {
            printf("\nDATOS INEXISTENTES");
            system("pause");
        }
    }while(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0);
    while(strcmpi(nombre_a_buscar,"FIN")!=0)
    {
        strcpy(pag.ApelyNom,nombre_a_buscar);
        strcpy(pag.patente,clien[pos].patente);
        printf("\nSu codigo de patente es: %s ",clien[pos].patente);
        do
        {
            printf("\nIngrese el importe abonado en el mes: ");
            scanf("%f",&pag.importe_abonado);
        }while(pag.importe_abonado<0);
        pag.mes=lee_control(1,12,3);
        switch(pag.mes)
        {
        case 1:
            imp[pos].importe01+=pag.importe_abonado;
            meses_pagados[pos][0]=1;
            break;
        case 2:
            imp[pos].importe02+=pag.importe_abonado;
            meses_pagados[pos][1]=1;
            break;
        case 3:
            imp[pos].importe03+=pag.importe_abonado;
            meses_pagados[pos][2]=1;
            break;
        case 4:
            imp[pos].importe04+=pag.importe_abonado;
            meses_pagados[pos][3]=1;
            break;
        case 5:
            imp[pos].importe05+=pag.importe_abonado;
            meses_pagados[pos][4]=1;
            break;
        case 6:
            imp[pos].importe06+=pag.importe_abonado;
            meses_pagados[pos][5]=1;
            break;
        case 7:
            imp[pos].importe07+=pag.importe_abonado;
            meses_pagados[pos][6]=1;
            break;
        case 8:
            imp[pos].importe08+=pag.importe_abonado;
            meses_pagados[pos][7]=1;
            break;
        case 9:
            imp[pos].importe09+=pag.importe_abonado;
            meses_pagados[pos][8]=1;
            break;
        case 10:
            imp[pos].importe10+=pag.importe_abonado;
            meses_pagados[pos][9]=1;
            break;
        case 11:
            imp[pos].importe11+=pag.importe_abonado;
            meses_pagados[pos][10]=1;
            break;
        case 12:
            imp[pos].importe12+=pag.importe_abonado;
            meses_pagados[pos][11]=1;
            break;
        }
        fwrite(&imp[pos],sizeof(importes),1,fp1);
         do
        {
            ListarClientes(clien,cantidad_clien);
            printf("\nIngrese el Apellido y Nombre del cliente [SALIDA='FIN']: ");
            fflush(stdin);
            gets(nombre_a_buscar);
            pos=buscar(clien,nombre_a_buscar,cantidad_clien);
            if(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0)
            {
                printf("\nDATOS INEXISTENTES");
                system("pause");
            }
        }while(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0);
    }
}

void consultas(importes imp[],clientes clien[],int cantidad_clien,int meses_pagados[][12])
{
    int pos,x;
    char nombre_a_buscar[31];
    do
    {
        ListarClientes(clien,cantidad_clien);
        printf("\nIngrese el Apellido y Nombre del cliente que desea consultar [SALIDA='FIN']: ");
        fflush(stdin);
        gets(nombre_a_buscar);
        pos=buscar(clien,nombre_a_buscar,cantidad_clien);
        if(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0)
        {
            printf("\nDATOS INEXISTENTES");
            system("pause");
        }
    }while(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0);
    while(strcmpi(nombre_a_buscar,"FIN")!=0)
    {
        printf("\nNro Patente: %s ",clien[pos].patente);
        printf("\nMESES ADEUDADOS:");
        for(x=0;x<12;x++)
        {
            if(meses_pagados[pos][x]==0)
                printf("\t %d ",x+1);
        }
        system("pause");
        do
        {
            ListarClientes(clien,cantidad_clien);
            printf("\nIngrese el Apellido y Nombre del cliente que desea consultar [SALIDA='FIN']: ");
            fflush(stdin);
            gets(nombre_a_buscar);
            pos=buscar(clien,nombre_a_buscar,cantidad_clien);
            if(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0)
            {
                printf("\nDATOS INEXISTENTES");
                system("pause");
            }
        }while(pos==-1&&strcmpi(nombre_a_buscar,"FIN")!=0);
    }
}

void listardeudores(clientes clien[],int meses_pagados[][12],int cant_clientes)
{
    int x,i;
    system("cls");
    printf("Listado de Deudores");
    for(x=0;x<cant_clientes;x++)
    {
        printf("\nNro de Patente: %s",clien[x].patente);
        printf("\nApellido y Nombre: %s",clien[x].ApelyNom);
        printf("\nTelefono: %s ",clien[x].telefono);
        printf("\nNro meses adeudados:");
        for(i=0;i<12;i++)
        {
            if(meses_pagados[x][i]==0)
                printf(" %d ",i+1);
        }
        printf("\n\n\n");
    }
    system("pause");
}

void ListarClientes(clientes vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE CLIENTES\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s  %s\n","APELLIDO Y NOMBRE", "PATENTE","NRO TELEFONO","CAT.VEHICULO");
    printf("%s %-21s  %s  %s\n","-----------------", "-------","------------","------------");
    for (i=0;i<ce;i++)
    {
            printf("%s        %s            %s           %d\n", vc[i].ApelyNom, vc[i].patente,vc[i].telefono,vc[i].categoria_vehi);
    }

    printf("\n");
    system("Pause");
}

int buscar(clientes clien[], char nom[30], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(clien[x].ApelyNom,nom))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese la categoria del vehiculo[de 1 a 25]: ");
        if(n==2)printf("\nIngrese el anio de fabricacion: ");
        if(n==3)printf("\nIngrese el mes que desea abonar: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

