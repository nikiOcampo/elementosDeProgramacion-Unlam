/*Se ingresan las ventas de un comercio de insumos de computación. Por cada venta se ingresa:
• Número de cliente (entero de 4 dígitos no correlativos).
• Importe (mayor a cero).
• Número de vendedor (entero de 1 a 10).
El ingreso de datos finaliza con un número de cliente 999.
Se sabe que no son más de 100 clientes, la carga de los clientes se debe realizar al inicio del programa
 con la función CARGA_CLIENTE () y para cada uno se ingresa:
• Código de cliente (entero de 4 dígitos no correlativos).
• Nombre y Apellido (50 caracteres máximo).
Se solicita:
a. Determinar la cantidad de ventas realizadas por cliente.
b. La cantidad de ventas realizadas por vendedor.
c. Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada cliente, informando:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int cod_cliente;
    char nom_apel[50];
}cliente;

int carga_cliente(cliente[],int);
int buscar(cliente[], int ,int);
void ordenamiento(int[],float[],char [100][50],int);
int validar_entero (int,int);
float validar_float(int);

int main()
{
    cliente clien[100];
    int cant,cod,pos,cont_x_cliente[100]={0},cont_x_vendedor[10]={0},nro_vende,nro_cliente[100]={0};
    int i;
    float monto,importe[100]={0};
    char nombre[100][50];
    printf("                                                    OCAMPO NCIOLE");
    cant=carga_cliente(clien,100);
    system("cls");
    printf("                                                    OCAMPO NCIOLE");
    printf("\nDatos de las ventas:");
    do
    {
        printf("\nIngrese el numero de cliente que realizo la venta[Salida=999]: ");
        scanf("%d",&cod);
        pos=buscar(clien,cod,cant);
        if(pos==-1)
            printf("\nEl cliente con dicho codigo no existe");
    }while(pos==-1&&cod!=999);
    while(cod!=999)
    {
        nro_cliente[pos]=cod;
        cont_x_cliente[pos]++;
        strcpy(nombre[pos],clien[pos].nom_apel);
        monto=validar_float(0);
        importe[pos]+=monto;
        nro_vende=validar_entero(1,10);
        cont_x_vendedor[nro_vende-1]++;
        do
        {
            printf("\nIngrese el numero de cliente que realizo la venta[Salida=999]: ");
            scanf("%d",&cod);
            pos=buscar(clien,cod,cant);
            if(pos==-1)
                printf("\nEl cliente con dicho codigo no existe");
        }while(pos==-1&&cod!=999);
    }
    system("cls");
    printf("                                                    OCAMPO NCIOLE");
    //Determinar la cantidad de ventas realizadas por cliente.
    for(i=0;i<cant;i++)
    {
        if(cont_x_cliente[i]!=0)
            printf("\nEl cliente con codigo %d realizo %d ventas",nro_cliente[i],cont_x_cliente[i]);
    }
    //La cantidad de ventas realizadas por vendedor.
    for(i=0;i<10;i++)
    {
        if(cont_x_vendedor[i]!=0)
            printf("\nEl vendedor nro %d realizo %d ventas",i+1,cont_x_vendedor[i]);
        else
            printf("\nEl vendedor nro %d NO REALIZO VENTAS",i+1);
    }
    //Informar en forma ordenada por total facturado (modo descendente), el total facturado a cada cliente, informando:
    ordenamiento(nro_cliente,importe,nombre,cant);
    printf("\nListado ordenado por importes:");
    printf("\nCOD.DE CLIENTE\tNOMBRE Y APELLIDO\tTOTAL FACTURADO");
    for(i=0;i<cant;i++)
    {
        if(importe[i]!=0)
            printf("\n%d\t\t%s\t\t%0.2f",nro_cliente[i],nombre[i],importe[i]);
    }
    return 0;
}

int carga_cliente(cliente clie[],int max)
{
    int x=0,pos,dato;
    printf("\nCarga de clientes:");
    do
    {
        printf("\nIngrese el codigo del cliente[Salida=999]: ");
        scanf("%d",&dato);
        pos=buscar(clie,dato,x);
        if(pos!=-1)
            printf("Ya se han registrado datos para este cliente.\n");
    }while(dato<999||dato>9999||pos!=-1);
    while(dato!=999&&x<max)
    {
        clie[x].cod_cliente=dato;
        do
        {
            printf("\nIngrese el nombre y apellido del cliente: ");
            fflush(stdin);
            gets(clie[x].nom_apel);
        }while(strlen(clie[x].nom_apel)<1||strlen(clie[x].nom_apel)>49);
        x++;
        do
        {
            printf("\nIngrese el codigo del cliente[Salida=999]: ");
            scanf("%d",&dato);
            pos=buscar(clie,dato,x);
            if(pos!=-1)
                printf("Ya se han registrado datos para este cliente.\n");
        }while(dato<999||dato>9999||pos!=-1);
    }
    return x;
}

int buscar(cliente v[], int dato, int tam)
{
    int i=0, pos=-1;
    while (pos==-1 && i<tam)
    {
        if (v[i].cod_cliente == dato)
            pos =i;
        else
            i++;
    }
    return pos;
}

void ordenamiento(int codigos[],float importes[],char nombres[][50],int n)
{
	int sen=0,i,aux;
	float aux1;
	char aux2[50];
	while(sen==0)
	{
		sen=1;
		for(i=0;i<n-1;i++)
		{
			if(importes[i]<importes[i+1])
			   {
			   	aux1=importes[i];
			   	importes[i]=importes[i+1];
			   	importes[i+1]=aux1;

			   	aux=codigos[i];
			   	codigos[i]=codigos[i+1];
			   	codigos[i+1]=aux;

			   	strcpy(aux2,nombres[i]);
                strcpy(nombres[i],nombres[i+1]);
                strcpy(nombres[i+1],aux2);

			   	sen=0;
			   }
		}
    }
}

int validar_entero(int i,int s)
{
    int dato;
    do
    {
        printf("\nIngrese el numero de vendedor[ENTRE 1 Y 10]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

float validar_float(int i)
{
    int dato;
    do
    {
        printf("\nIngrese el importe de dicha venta: ");
        scanf("%d",&dato);
    }while(dato<i);
    return dato;
}

