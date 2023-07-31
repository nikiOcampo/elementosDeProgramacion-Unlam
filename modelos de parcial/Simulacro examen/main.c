/*Una cooperativa Yerbatera, “Pepe Mujica” de la provincia de Misiones, está formada por 25 productores importantes de la zona.
 Los mismos realizaron descargas de sus cosechas, durante el año pasado, quedando registradas la siguiente información:
o	Numero Productor (int 1 a 25)
o	Mes de Entrega      (char [10])
o	Dia de Entrega       (int 1 a 31)
o	Kilos                (Flotante > 0)
(Finaliza la carga de datos con un Mes = ”Termino”)
Para la carga de Mes de Entrega, (la cual indica fin de carga con “Termino”),  Validar que se cargue el mes correctamente
a través de una función que controle el texto correcto: Enero, Febrero, Marzo…..Diciembre y Termino.
Desarrollar el diagrama de lógica y su correspondiente codificación C para que permita:
a)	Cual fue el Número de Productor que más Kilos entrego en este periodo.
b)	Informar tomando todo este periodo, cuanto fue la cantidad de kilos Almacenados.
c)	Informar de mayor a menor cantidad de Kilos entregados por día.
                     LISTADO ORDENADO POR Kilos ENTREGADO DIA
                                        Dia                 Cant. Kilos
                                        21                    23.450
                                        18	                  21.490
                                                      ---                     -----
      (Si el día no tiene Kilos no mostrar)
d)	Menor entrega en todo el periodo, informar Dia y Productor- (No tomar 0 entrega)
e)	Cuantos días no se efectuaron entregas de Kilos.
FUNCIONES:  1 - Validar el Ingreso de Número de Productor y Dia de Entrega con la misma Función.
            2 - Para Obtener la cantidad de Días sin Entrega. (Punto e).
            3 - Ordenar los Kilos Entregados de Mayor a Menor (Punto c).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar (char[][11],char[11],int);
void cargameses (char [][11],int );
void mostrar(char[][11],int);
int LeerYValidar (int, int,int );
float validarfloat(int);
void punto_A (float[][25],int,int);
void punto_B (float[][25],int,int);
void punto_CyE(float[][25],int,int);
void punto_D(float[][25],int,int);

int main()
{
    char meses[12][11],me[100][11];
    int dia,num_prod,pos,x=0;
    float m[31][25]={{0}},kilos;
    cargameses(meses,12);
    do
    {
        mostrar(meses,12);
        printf("\nIngrese el mes: ");
        fflush(stdin);
        gets(me[x]);
        pos=buscar(meses,me[x],12);
        if(pos==-1&&((strcmpi(me[x],"Termino"))!=0))
                printf("\nEl mes ingresado no es valido\n");
    }while(pos==-1&&((strcmpi(me[x],"Termino"))!=0));
    while((strcmpi(me[x],"Termino"))!=0)
    {
        num_prod=LeerYValidar(1,25,1);
        dia=LeerYValidar(1,31,2);
        kilos=validarfloat(0);
        m[dia-1][num_prod-1]+=kilos;
        x++;
        do
        {
            mostrar(meses,12);
            printf("\nIngrese el mes: ");
            fflush(stdin);
            gets(me[x]);
            pos=buscar(meses,me[x],12);
            if(pos==-1&&((strcmpi(me[x],"Termino"))!=0))
                printf("\nEl mes ingresado no es valido\n");
        }while(pos==-1&&((strcmpi(me[x],"Termino"))!=0));
    }
    system("cls");
    punto_A(m,31,25);
    punto_B(m,31,25);
    punto_CyE(m,31,25);
    punto_D(m,31,25);
    return 0;
}

void cargameses(char m[12][11],int n)
{
    strcpy(m[0], "Enero");
    strcpy(m[1], "Febrero");
    strcpy(m[2], "Marzo");
    strcpy(m[3], "Abril");
    strcpy(m[4], "Mayo");
    strcpy(m[5], "Junio");
    strcpy(m[6], "Julio");
    strcpy(m[7], "Agosto");
    strcpy(m[8], "Septiembre");
    strcpy(m[9], "Octubre");
    strcpy(m[10], "Noviembre");
    strcpy(m[11], "Diciembre");
}

int buscar(char m[][11], char me[12], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(m[x],me))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}

void mostrar(char vn[][11],int cant)
{
    int i;
    system("cls");
    for (i=0; i<cant; i++)
        puts(vn[i]);
    printf("Salida= Termino");
}

int LeerYValidar(int x ,int y,int n)
{
    int dato;
    do
    {
        if(n==1) printf("\nIngrese el numero de productor: ");
        if(n==2) printf("\nIngrese el dia: ");
        scanf("%d",&dato);
    }while(dato<x||dato>y);
    return dato;
}


float validarfloat (int n)
{
    float dato;
    do
    {
        printf("\nIngrese la cantidad de kilos: ");
        scanf("%f",&dato);
    }while(dato<n);
    return dato;
}

//a)	Cual fue el Número de Productor que más Kilos entrego en este periodo.
void punto_A(float m[][25],int f,int c)
{
    int x,i,j;
    float suma_colum[25]={0},max;
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    max=suma_colum[0];
    for (i=1;i<c;i++)
    {
        if (suma_colum[i]>max)
            max=suma_colum[i];
    }
    printf("\n\n\nLa mayor cantidad de kilos entregados fue de %0.2f, realizado por el/los productor/es:",max);
    for(j=0;j<c;j++)
    {
        if(suma_colum[j]==max)
            printf("\n%d",j+1);
    }
}

//b)	Informar tomando todo este periodo, cuanto fue la cantidad de kilos Almacenados.
void punto_B(float m[][25],int f,int c)
{
    int x,i;
    float total=0;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            total+=m[x][i];
        }
    }
    printf("\n\n\nEl total de kilos almacenados durante todo el periodo fue de: %0.2f",total);
}

/*c)	Informar de mayor a menor cantidad de Kilos entregados por día.
                     LISTADO ORDENADO POR Kilos ENTREGADO DIA
                                        Dia                 Cant. Kilos
                                        21                    23.450
                                        18	                  21.490*/
void punto_CyE(float m[][25],int f,int c)
{
    int x,i,dias[31]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31},sen=0,aux1,cont=0;
    float suma_fila[31]={0},aux;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            suma_fila[x]+=m[x][i];
        }
    }
    while(sen==0)
	{
		sen=1;
		for(i=0;i<c-1;i++)
		{
			if(suma_fila[i]<suma_fila[i+1])
			   {
			   	aux=suma_fila[i];
			   	suma_fila[i]=suma_fila[i+1];
			   	suma_fila[i+1]=aux;
			   	aux1=dias[i];
			   	dias[i]=dias[i+1];
			   	dias[i+1]=aux1;
			   	sen=0;
			   }
		}
    }
    printf("\n\n\nLISTADO ORDENADO POR Kilos ENTREGADO DIA");
    printf("\n DIA:        CANT.KILOS:");
    for(i=0;i<31;i++)
    {
        if(suma_fila[i]!=0)
            printf("\n %d\t\t%0.2f",dias[i],suma_fila[i]);
        else
            cont++;
    }
    ////e)	Cuantos días no se efectuaron entregas de Kilos.
    printf("\n\n\n%d dias no se efectuaron entregas de kilos",cont);
}

//d)	Menor entrega en todo el periodo, informar Dia y Productor- (No tomar 0 entrega)
void punto_D(float m[][25],int f,int c)
{
    int x,i,fil,col;
    float min;
    min=m[0][0];
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]<=min&&m[x][i]!=0)
            {
                min=m[x][i];
                fil=x+1;
                col=i+1;
            }
        }
    }
    printf("\n\n\nLa menor cantidad de kilos entregados es de %0.2f",min);
    printf("\n Que se entrego el dia %d por el productor nro %d",fil,col);
}

