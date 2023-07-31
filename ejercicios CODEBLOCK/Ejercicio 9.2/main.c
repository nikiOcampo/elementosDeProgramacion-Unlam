/*9.2. Un laboratorio dispone de una lista con sus 50 medicamentos. De cada uno conoce:
• Código del medicamento (entero, de 3 cifras).
• Precio (real).
• Stock (entero).
Se solicita:
a. Declarar un tipo de dato que contenga la información del medicamento.
b. Declarar un vector de estructura de tipo de datos creado en a.
c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/

#include <stdio.h>
#include <stdlib.h>
//a. Declarar un tipo de dato que contenga la información del medicamento.
typedef struct
{
    int codigo;
    float precio;
    int stock;
}medicamento;

int ingreso (medicamento[],int );
int buscar_medi(medicamento[],int,int);
void informe (medicamento[],int);
int validar_entero (int,int);
int validar_int(int,int);

int main()
{
    //b. Declarar un vector de estructura de tipo de datos creado en a.
    medicamento med[50];
    int cant,cod=0,pos;
    printf("                                                    OCAMPO NCIOLE");
    cant=ingreso(med,50);
    system("cls");
    printf("                                                    OCAMPO NCIOLE");
    while(cod!=-9)
    {
        do
        {
            printf("\nIngrese el producto del que desea averiguar el precio[Salida=-9]: ");
            scanf("%d",&cod);
            pos=buscar_medi(med,cod,cant);
        }while(pos==-1&&cod!=-9);
        if(cod!=-9)
            printf("\nEl precio del producto %d es de: %0.2f",med[pos].codigo,med[pos].precio);
    }
    system("cls");
    printf("                                                    OCAMPO NCIOLE");
    informe(med,cant);
    return 0;
}

//c. Cargar en un sector de estructuras, los datos referentes a los medicamentos. Función INGRESO.
int ingreso(medicamento med[],int max)
{
    int i=0;
    med[i].codigo=validar_entero(100,1000);
    while(i<max&&med[i].codigo!=1000)
    {
        med[i].precio=validar_int(0,1);
        med[i].stock=validar_int(0,2);
        i++;
        med[i].codigo=validar_entero(100,1000);
    }
    return i;
}

//d. Consultar el precio según código del medicamento. Función BUSQUEDA_MEDI.
int buscar_medi( medicamento v[], int dato, int tam)
{
    int i=0, pos=-1;
    while (pos==-1 && i<tam)
    {
        if (v[i].codigo == dato)
            pos =i;
        else
            i++;
    }
    return pos;
}

//e. Informar los códigos de los medicamentos cuyo stock es inferior a 10 unidades. Función INFORME.*/
void informe(medicamento med[],int n)
{
    int x;
    printf("\nCODIGO DE LOS MEDICAMENTOS QUE TIENEN UN STOCK MENOR A 10 UNIDADES:");
    for(x=0;x<n;x++)
    {
        if(med[x].stock<10)
            printf("\n%d",med[x].codigo);
    }
}

int validar_entero(int i,int s)
{
    int dato;
    do
    {
        printf("\nIngrese el codigo del medicamento[Salida=1000]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

int validar_int(int i, int a)
{
    int dato;
    do
    {
        if(a==1)printf("\nIngrese el precio del medicamento: ");
        if(a==2)printf("\nIngrese el stock del medicamento: ");
        scanf("%d",&dato);
    }while(dato<i);
    return dato;
}
