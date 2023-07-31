/*Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa.
 Se sabe que como máximo la empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante
la función CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.
d. Volver a mostrar el listado de cantidad de empleados por sector,
pero esta vez ordenado de menor a mayor por cantidad de empleados en cada sector.*/

#include <stdio.h>
#include <stdlib.h>

int carga (int[], int[], int[],int);
void cuentaPorSector (int [], int);
void mostrarLista(int[],int);
int totalAPagar (int[],int);
void ordenamiento (int[], int);

int main()
{
    int dni_empleados[100],sector_empleados[100],sueldos_empleados[100],cant,totalsuedo/*,sectores[5]={1,2,3,4,5}*/;
    cant=carga(dni_empleados,sector_empleados,sueldos_empleados,100);
    cuentaPorSector(sector_empleados,cant);
    totalsuedo= totalAPagar(sueldos_empleados,cant);
    printf("\nEl importe total a pagar de sueldos es de: %d\n",totalsuedo);
    ordenamiento(sector_empleados,cant);
    return 0;
}

int carga(int dni_emp[], int sec_emp[], int suel_emp[] ,int n)
{
    int i=0,x=0,j=0,dni,sector,sueldo;
    printf("Ingrese el DNI del empleado: ");
    scanf("%d",&dni);
    while(dni!=99 && i<n)
    {
        dni_emp[i]=dni;
        i++;
        do
        {
            printf("Ingrese el sector en el que trabaja el empleado ");
            scanf("%d",&sector);
            if(sector<1||sector>5)
                printf("El sector ingresado no existe\n");
        }while(sector<1||sector>5);
        sec_emp[x]=sector;
        x++;
        printf("Ingrese el sueldo del empleado: ");
        scanf("%d",&sueldo);
        suel_emp[j]=sueldo;
        j++;
        if(i<n)
        {
            printf("Ingrese el DNI del empleado: ");
            scanf("%d",&dni);
        }

    }
    return i;
}

void cuentaPorSector(int sec[],int i)
{
    int x,cantPorSector[5]={0};
    for (x=0;x<i;x++)
    {
        if (sec[x]==1)
            cantPorSector[0]++;
        if (sec[x]==2)
            cantPorSector[1]++;
        if (sec[x]==3)
            cantPorSector[2]++;
        if (sec[x]==4)
            cantPorSector[3]++;
        if (sec[x]==5)
            cantPorSector[4]++;
    }
    mostrarLista(cantPorSector, 5);
}

void mostrarLista(int cant[], int n)
{
    int x;
    printf("SECTOR: \t Cantidad de empleados: ");
    for (x=0;x<n;x++)
    {
        printf("\n%d\t\t%d",x+1 ,cant[x]);
    }
}

int totalAPagar( int suel[], int n)
{
    int x,z=0;
    for(x=0;x<n;x++)
    {
        z+=suel[x];
    }
    return z;
}

/*void ordenamiento( int sector[], int n)
{
    int aux,cota=n-1,i,desordenado=1;
    while(desordenado==1)
    {
        desordenado=0;
        for(i=0;i<cota;i++)
        {
            if(sector[i]>sector[i+1])
            {
                aux=sector[i];
                sector[i]=sector[i+1];
                sector[i+1]=aux;
                desordenado=i;
            }
        }
        cota=desordenado;
    }
    mostrarLista(sector,5);
}*/

void ordenamiento(int se[],int n)
{
	int Nsec[5]={1,2,3,4,5};
	int sen=0,i,aux;
	while(sen==0)
	{
		sen=1;
		for(i=0;i<n-1;i++)
		{
			if(se[i]>se[i+1])
			   {
			   	aux=se[i];
			   	se[i]=se[i+1];
			   	se[i+1]=aux;
			   	aux=Nsec[i];
			   	Nsec[i]=Nsec[i+1];
			   	Nsec[i+1]=aux;
			   	sen=0;
			   }
		}
    }
   printf("\n Listado Ordenado Cantidad de Empleados por Sector \n");
   printf("\n Sector   Cantidad \n");
   for(i=0;i<5;i++)
     {
     	printf("\n %d     %d",Nsec[i],se[i]);
	 }

}



