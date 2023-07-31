#include <stdio.h>
#include <stdlib.h>

int IngresoValor(int);
int ValidarFecha (int,int,int);
int DIAS(int, int );
int LeerYValidar (int, int);
int esFechaCorrecta (FECHA fecha);

//VECTORES
void carga(float [],int);
void blanco(int [],int);
void mostrar(float [],int);
void mostrarLista(int[],int);
void concatenarVectores (int[],int[],int);
void intercalarVectores (int[],int[],int);
void ordenamiento (int[], int);//de menor a mayor
void maximo (int[],int[],int);//numeros no correlativos
void maximo (int[],int);//numeros correlativos
int busqueda_secuencial (int[],int,int);
void minimo (int[], float[], int);
int comparar_vectores( int [], int[], int);

//------------------------------------

//MATRICES//CAMBIAR SUBINDICES
void carga (int[5][4]);
void suma_por_columnas (int[][3],int,int);
void suma_por_filas (int[][3],int,int);
void suma_total (int[][3],int,int);
void promedio_total (int[][3],int,int);
void promedio_columna (int[][3],int,int);
void valormaximo (int[][3],int,int);
void valorminimo_por_columna (int[][3],int,int);
void ordenar (int[],int[],int);//de mayor a menor
void minimo(int[][120],int[],int,int);

//--------------------------------------------

//STRINGS
int carga(char[][25],int[]);
int buscar (char[][25],char[25],int);
void ordenar(char[][25],int);//un solo string
void ordenar(char [][10],float [], int);//dos cosas
void mostrar(char[][25],int);

//ESTRUCTURAS Y ARCHVIOS

//FUNCIONES

int IngresoValor(int x)
{
    int n;
    if (x==1)
        system("cls");
    printf("Ingrese el Nro %d: ",x);
    scanf("%d", &n);
    return n;
};

int main()//usar para validar fecha
{
    int dia,mes,anio,validacion;
    printf("Ingrese un anio: ");
    scanf("%d",&anio);
    printf("Ingrese un mes: ");
    scanf("%d",&mes);
    printf("Ingrese un dia: ");
    scanf("%d",&dia);
    validacion=ValidarFecha(anio,mes,dia);
    if(validacion==1)
        printf("Fecha Valida");
    else
        printf("Fecha Invalida");
    return 0;
}
//para sumar cierta cantidad de dias
else
        {
            printf("Ingrese la cantidad de dias a sumar: ");
            scanf("%d",&sumar);
            validacion=CantidadDias(mes,anio);
            dia2=dia+sumar;
            while(validacion<dia2)
            {
             dia2-=validacion;
             if(mes==12)
             {
                 mes=1;
                 anio++;
             }
             else mes++;
             validacion=CantidadDias(mes,anio);
            }
            printf("La fecha nueva queda: %d/%d/%d\n",dia2,mes,anio);
        }

int DIAS (int a, int m)
{
    int d;
    switch(m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            d=31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            d=30;
            break;
        case 2:
            if((a%4==0&&a%100!=0)||(a%400==0))
                d=29;
            else
                d=28;
            break;
    }
    return d;
}

int ValidarFecha (int a, int m, int d)
{
    int c,dias;
    if (m<1||m>12)
        c=0;
    dias=DIAS(a,m);
    if(d<=dias)
        c=1;
    else
        c=0;
    return c;
}

int esFechaCorrecta (FECHA fecha)
{
    int retorno, bisiesto, cantidaddiasmes;
    retorno = 0;
    if((fecha.anio%4==0 && fecha.a %100!=0) || fecha.a %400==0)
        bisiesto=1;
    else
        bisiesto =0;
    if(fecha.m==4|| fecha.m ==6|| fecha.m ==9|| fecha.m ==11)
        cantidaddiasmes =30;
    else
    {
        if(fecha.m ==2)
            cantidaddiasmes =28+ bisiesto;
        else
            cantidaddiasmes =31;
    }
    if(fecha.a >=1950&& fecha.a<=2019 && fecha.m>=1&& fecha.m <=12&& fecha.d>=1&& fecha.d<= cantidaddiasmes )
        retorno =1;
    else
        retorno =0;
    return retorno;
}

int LeerYValidar(int x ,int y)
{
    int n;
    do
    {
        printf("\nIngrese un valor positivo entre 1 y 50: ");
        scanf("%d",&n);
        if((n<x||n>y)&& (n!=-10))
            printf("\nEl numero no respeta el rango vuelva a ingresarlo");
        if(n==-10)
            printf("\nFIN DEL PROGRAMA");
    }while((n<x||n>y)&&(n!=-10));
    return n;
}





//-----------------------------------VECTORES--------------------------
void carga(float v1[],int n)
{
    int x;
    system("cls");
    for(x=0; x<n; x++)
    {
        printf("\n Ingrese valor %d:",x+1);
        scanf("%f",&v1[x]);
    }
}

void blanco(int a[],int n)
{
    int x;
    for(x=0;x<n;x++)
    {
    a[x]=0;
    }
}

void mostrar(float KK[],int n)
{
    int x;
    for(x=0; x<n; x++)
    {
        printf("\n el contenido %d es = %.2f",x+1,KK[x]);
    }

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

void concatenarVectores (int v1[],int v2[], int n)
{
    int x,y;
    int result[10];
    int c = 0;
    for (x=0; x<n/2; x++)
    {
       result[c] = v1[x];
       c++;
    }
    for (y=0; y<n/2; y++)
    {
        result[c] = v2[y];
        c++;
    }
    mostrar(result, n);
}

void intercalarVectores (int v1[],int v2[],int n)
{
    int x;
    int resultado[10];
    for(x=0;x<n;x++)
    {
        resultado[x*2]= v1[x];
        resultado[(x*2)+1]= v2[x];
    }
    mostrar(resultado,10);
}

//menor a mayor
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
/*
void ordenamiento(int total[],float porcentaje[],int lista[],int n)//de menor a mayor
{
    int x,j,aux;
    float auxf;
    for(x=0;x<n-1;x++)
    {
        for(j=0;j<n-1-x;j++)
        {
            if(total[j]<total[j+1])
            {
                aux=total[j];
                total[j]=total[j+1];
                total[j+1]=aux;

                auxf=porcentaje[j];
                porcentaje[j]=porcentaje[j+1];
                porcentaje[j+1]=auxf;

                aux=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=aux;
            }
        }
    }
    system("cls");
    printf("\nTOTAL DE VOTOS:  PORCENTAJES:  LISTA: ");
    for(x=0;x<n;x++)
    {
        printf("\n  %d\t\t%f\t\t%d ",total[x],porcentaje[x],lista[x]);
    }
}
*/

void maximo (int st[],int cp[],int n)//numeros no correlativos
{
    int max,i,j;
    max=st[0];
    for (i=1;i<n;i++)
    {
        if (st[i]>max)
            max=st[i];
    }
    printf("\nEl stock mas alto es de %d, y lo tienen el/los producto/s de codigo:",max);
    for(j=0;j<n;j++)
    {
        if(st[j]==max)
            printf("\n%d",cp[j]);
    }
}
void maximo ( int sueldos[], int n)//numeros correlativos
{
    int max,i,j;
    max=sueldos[0];
    for (i=1;i<n;i++)
    {
        if (sueldos[i]>max)
            max=sueldos[i];
    }
    printf("\n\nEl mayor sueldo es de %d, de el/los empleados: ",max);
    for(j=0;j<n;j++)
    {
        if(sueldos[j]==max)
            printf("\n%d",j+1);
    }
}

int busqueda_secuencial (int v[], int cant, int elem)
{
    int i, pos;
    i = 0;
    pos = -1;
    while(i < cant && pos == -1)
    {
        if(v[i] == elem)
            pos = i;
        else
            i++;
    }
    return pos;
}

void minimo( int dni[], float asis[], int n )
{
	int x;
	float min;
	min=asis[0];
	for(x=1;x<n;x++)
    {
        if(asis[x]<min)
            min=asis[x];
    }
    printf("\nLa menor asistencia fue de %f, dada por el/los alumnos con DNI: ",min);
    for(x=0;x<n;x++)
    {
        if(asis[x]==min)
        printf("\n%d",dni[x]);
    }
}

int comparar_vectores(int v1[], int v2[], int n)
{
    int igual;
    int i=0;
    while(i<n)
    {
        if(v1[i]==v2[i])
            i++;
        else
            i=n+1;
    }
    if (i==n)
        igual=1;
    else
        igual=0;
    return igual;
}





//-------------------------------------------MATRICES-----------------------------------
void carga (int m[][3],int f,int c)
{
    int x,i;
    for (x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            printf("Ingrese el valor de la fila %d y columna %d: ",x+1,i+1);
            scanf("%d",&m[x][i]);
        }
    }
}

void suma_por_columnas(int m[][3],int f,int c)
{
    int suma_colum[3]={0},x,i;
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    for(x=0;x<c;x++)
    {
        printf("\nLa suma de la columna nro %d es de: %d ",x+1,suma_colum[x]);
    }
}

void suma_por_filas(int m[][3],int f,int c)
{
    int suma_fila[5]={0},x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            suma_fila[x]+=m[x][i];
        }
    }
    for(x=0;x<f;x++)
    {
        printf("\nLa suma de la fila nro %d es de: %d ",x+1,suma_fila[x]);
    }
}

void suma_total(int m[][3],int f,int c)
{
    int total=0,x,i;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            total+=m[x][i];
        }
    }
    printf("\nLa suma total de los numeros cargados es de: %d",total);
}

void promedio_total(int m[][3],int f,int c)
{
    int total=0,x,i;
    float promedio;
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            total+=m[x][i];
        }
    }
    promedio=(float)total/15;
    printf("\nEl valor promedio de los numeros cargados es de: %0.2f",promedio);
}

void promedio_columna(int m[][3],int f,int c)
{
    int suma_colum[3]={0},x,i;
    float prom_colum[3]={0};
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            suma_colum[x]+=m[i][x];
        }
    }
    for(x=0;x<c;x++)
    {
        prom_colum[x]=suma_colum[x]/f;
        printf("\nEl valor promedio de la columna nro %d es de: %0.2f",x+1,prom_colum[x]);
    }
}

void valormaximo(int m[][3],int f,int c)
{
    int x,i,max,fil,col;
    max=m[0][0];
    for(x=0;x<f;x++)
    {
        for(i=0;i<c;i++)
        {
            if(m[x][i]>=max)
            {
                max=m[x][i];
                fil=x+1;
                col=i+1;
            }
        }
    }
    printf("\nEl maximo valor de los numeros cargados es de %d",max);
    printf("\nQue se encuentra en la fila %d y columna %d",fil,col);
}

void valorminimo_por_columna(int m[][3],int f,int c)
{
    int min[3]={0},x,i,fil,col;
    min[0]=m[0][0];
    min[1]=m[0][1];
    min[2]=m[0][2];
    for(x=0;x<c;x++)
    {
        for(i=0;i<f;i++)
        {
            if(min[x]>=m[i][x])
            {
                min[x]=m[i][x];
                fil=i+1;
                col=x+1;
            }
        }
        printf("\nEl valor minimo de la columna nro %d es %d, cargado en la fila %d y columna %d",x+1,min[x],fil,col);
    }
}
if (iguales==1)///USAR CON EL ANTERIOR
        printf("Los vectores ingresados son iguales");
    else
        printf("Los vectores ingresados son distintos");

void ordenar(int colum[], int butacas[], int c)
{
    int x,i,aux;
    for(x=0;x<c;x++)
    {
        for(i=0;i<c-1-x;i++)
        {
            if(colum[i]<colum[i+1])
            {
                aux=colum[i];
                colum[i]=colum[i+1];
                colum[i+1]=aux;

                aux=butacas[i];
                butacas[i]=butacas[i+1];
                butacas[i+1]=aux;
            }
        }
    }
    /*Butaca Cantidad
1 20
3 15
2 10*/
    printf("\nBUTACA:\t\tCANTIDAD:");
    for(x=0;x<c;x++)
    {
        printf("\n%d\t\t%d",butacas[x],colum[x]);
    }
}

////b. Cuál fue la sucursal que pidió la menor cantidad en total (puede haber varias sucursales que tienen el mismo valor mínimo).
void minimo(int m[][120], int cantporsucursal[],int f,int c)
{
    int x,min;
    min=cantporsucursal[0];
    for(x=1;x<f;x++)
    {
        if(cantporsucursal[x]<min)
        {
            min=cantporsucursal[x];
        }
    }
    printf("\nLa menor cantidad de unidades pedidas fue de %d, de la/s sucursal/es nro:",min);
    for(x=0;x<f;x++)
    {
        if(cantporsucursal[x]==min)
            printf("\n%d",x+1);
    }
}




//-------------------------------------STRINGS---------------------------------
int carga(char nom[][25], int d[])
{
    int f=0;
    printf("Ingrese el nombre del alumno: ");
    fflush(stdin);
    gets(nom[f]);
    while((strcmpi(nom[f],"FIN"))!=0)
    {
        printf("\nIngrese el DNI del alumno: ");
        scanf("%d",&d[f]);
        f++;
        printf("\nIngrese el nombre del alumno: ");
        fflush(stdin);
        gets(nom[f]);
    }
    return f;
}

int buscar(char nombres[][25], char nom[25], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(nombres[x],nom))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}

void ordenar(char vn[][25],int cant)
{
    int i,j;
    char aux[11];
    for (i=0; i<cant-1; i++)
    {
        for(j=0; j<cant-1-i; j++)
        {
            if(strcmpi(vn[j],vn[j+1])>0)
            {
                strcpy(aux,vn[j]);
                strcpy(vn[j],vn[j+1]);
                strcpy(vn[j+1],aux);
            }
        }
    }
}

void ordenar(char c[][10],float p [], int n)
{
  int sen=0, x=0;
  char Aux[10];
  float aux;
  while(sen==0)
  {
     sen=1;
     for(x=0;x<n-1;x++)
     {
         if(strcmpi(c[x],c[x+1])>0)
         {   strcpy(Aux,c[x]);
             strcpy(c[x],c[x+1]);
             strcpy(c[x+1],Aux);
             aux=p[x];
             p[x]=p[x+1];
             p[x+1]=aux;
         }
     }
  }
  printf("\nPRODUCTO:\tPRECIO:");
  for(x=0;x<n;x++)
  {
      printf("\n%s\t\t%f",c[x],p[x]);
  }
}

void mostrar(char vn[][25],int cant)
{
    int i;
    system("cls");
    for (i=0; i<cant; i++)
        puts(vn[i]);
}

/*otra forma de mostrar
void mostrar(char Nom[][25],int n)
{
    int x;
    system("cls");
    for(x=o;x<n;x++)
    {
        if((strcmpi(nrodeauto[x],"findia"))==0)//hacer con biblioteca//para cuando no queres que se muestre algo
            printf(" ");
        else
        printf("%s\n",Nom[x];
    }
}*/




