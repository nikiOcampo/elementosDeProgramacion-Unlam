/*El Video Club The Green Book, necesita realizar estadísticas de los pedidos en alquiler de sus películas,
para definir la reposición de los Títulos. Para tal fin nos proporciona la siguiente información registrada durante el año 2020.
Un Listado con los géneros en Alquiler:
                                          Acción, Comedia, Drama, Thriller, Infantiles, Terror, Documental.
Por otro lado, los datos mes (1 a 12), género y Cantidad alquilada.
El fin de los datos es indicado con mes =0.
Confeccionar un programa, diagrama y codificación que permita, a partir de dicha información,
•	Informar el Total de Películas Alquiladas en el año 2018.
•	Informar el Promedio de Películas Alquiladas  por Genero.(no tomar en cuenta si el mes está en 0 para promediar)
•	Informar el Total de Películas por Mes.
Ejemplo:
  Listado Total de Películas Alquiladas por Mes Ordenado de Menor  a Meyor
                                                       Mes         Total Alquileres
2	               23.44
--                    xx.xxx
•	Que cantidad de Meses y Géneros no registraron alquiler.

•	 función validar, Carga Géneros, ordenar y buscar.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LeerYValidar (int, int);
void cargaGeneros (char [][15],int);
int buscar (char[][15],char[15],int);
void mostrar(char[][15],int);
void punto_A (int[],int);
void punto_B(char[][15],int[],int);
void punto_C(int[],int);
void punto_D(int[],int[],int,int);

int main()
{
    char m[7][15],genero[15];
    int mes,cantidad[12]={0},x,pos,cant,cant_x_genero[7]={0};
    cargaGeneros(m,7);
    mes=LeerYValidar(0,12);
    x=0;
    while(mes!=0)
    {
        do
        {
            mostrar(m,7);
            printf("\nIngrese el genero: ");
            fflush(stdin);
            gets(genero);
            pos=buscar(m,genero,7);
            if(pos==-1)
                printf("\nEl genero ingresado no es valido\n");
        }while(pos==-1);
        do
        {
            printf("\nIngrese la cantidad vendida: ");
            scanf("%d",&cant);
        }while(cant<0);
        cantidad[mes-1]+=cant;
        if((strcmpi(genero,"Accion"))==0) cant_x_genero[0]+=cant;
        if((strcmpi(genero,"Comedia"))==0) cant_x_genero[1]+=cant;
        if((strcmpi(genero,"Drama"))==0) cant_x_genero[2]+=cant;
        if((strcmpi(genero,"Thriller"))==0) cant_x_genero[3]+=cant;
        if((strcmpi(genero,"Infantiles"))==0) cant_x_genero[4]+=cant;
        if((strcmpi(genero,"Terror"))==0) cant_x_genero[5]+=cant;
        if((strcmpi(genero,"Documental"))==0) cant_x_genero[6]+=cant;
        x++;
        mes=LeerYValidar(0,12);
    }
    punto_A(cantidad,12);
    punto_B(m,cant_x_genero,7);
    punto_C(cantidad,12);
    punto_D(cantidad,cant_x_genero,12,7);
    return 0;
}

void mostrar(char vn[][15],int cant)
{
    int i;
    //system("cls");
    for (i=0; i<cant; i++)
        puts(vn[i]);
}

// Acción, Comedia, Drama, Thriller, Infantiles, Terror, Documental.
void cargaGeneros(char m[][15],int n)
{
    strcpy(m[0], "Accion");
    strcpy(m[1], "Comedia");
    strcpy(m[2], "Drama");
    strcpy(m[3], "Thriller");
    strcpy(m[4], "Infantiles");
    strcpy(m[5], "Terror");
    strcpy(m[6], "Documental");
}

int LeerYValidar(int x ,int y)
{
    int dato;
    do
    {
        printf("\nIngrese el mes: ");
        scanf("%d",&dato);
        if(dato<x||dato>y)
            printf("\nEl mes no existe, vuelva a intentarlo");
    }while(dato<x||dato>y);
    return dato;
}

int buscar(char m[][15], char generos[15], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(m[x],generos))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}
//Informar el Total de Películas Alquiladas en el año 2018.
void punto_A(int cant_x_mes[],int n)
{
    int x,total=0;
    for(x=0;x<n;x++)
    {
        total+=cant_x_mes[x];
    }
    printf("\nEl total de peliculas alquiladas durante el anio fue de: %d",total);
}

//Informar el Promedio de Películas Alquiladas  por Genero.(no tomar en cuenta si el mes está en 0 para promediar)
void punto_B(char m[][15],int cantidad[],int n)
{
    int x,total=0;
    float promedios[7];
    for(x=0;x<n;x++)
    {
        total+=cantidad[x];
    }
    for(x=0;x<n;x++)
    {
        promedios[x]=(cantidad[x]*100)/total;
    }
    printf("\nPROMEDIOS DE PELICULAS ALQUILADAS POR GENERO:");
    printf("\nGENERO            PROMEDIO:");
    for(x=0;x<n;x++)
    {
        printf("\n%s             %0.2f",m[x],promedios[x]);
    }
}
//Listado Total de Películas Alquiladas por Mes Ordenado de Menor  a Meyor
void punto_C(int cant_x_mes[],int n)
{
    int meses[12]={1,2,3,4,5,6,7,8,9,10,11,12},sen=0,aux,i;
    while(sen==0)
	{
		sen=1;
		for(i=0;i<n-1;i++)
		{
			if(cant_x_mes[i]>cant_x_mes[i+1])
			   {
			   	aux=cant_x_mes[i];
			   	cant_x_mes[i]=cant_x_mes[i+1];
			   	cant_x_mes[i+1]=aux;
			   	aux=meses[i];
			   	meses[i]=meses[i+1];
			   	meses[i+1]=aux;
			   	sen=0;
			   }
		}
    }
    printf("\n\t\tLISTADO DE PELICULAS ALQUILADAS POR MES:");
    printf("\n MES:        TOTAL ALQUILERES:");
    for(i=0;i<12;i++)
     {
         if(cant_x_mes[i]!=0)
            printf("\n %d\t\t%d",meses[i],cant_x_mes[i]);
	 }
}

//Que cantidad de Meses y Géneros no registraron alquiler.
void punto_D(int cant_x_mes[],int cant_x_genero[],int a,int n)
{
    int x,cont=0,cont1=0;
    for(x=0;x<a;x++)
    {
        if(cant_x_mes[x]==0)
            cont++;
    }
    for(x=0;x<n;x++)
    {
        if(cant_x_genero[x]==0)
            cont1++;
    }
    printf("\n\n%d meses no registraron alquiler",cont);
    printf("\n%d generos no registraron alquiler",cont1);
}
