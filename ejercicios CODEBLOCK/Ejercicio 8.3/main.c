/*8.3. Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos.
La carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y
sino informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int carga(char[][25],int[]);
int buscar (char[][25],char[25],int);
void ordenar(char[][25],int);
void mostrar(char[][25],int);

int main()
{
    int dni[50],cant,pos;
    char nombres[50][25],nom[50];
    cant=carga(nombres,dni);
    system("cls");
    printf("\nIngrese el nombre a buscar: ");
    fflush(stdin);
    gets(nom);
    while((strcmpi(nom,"NOBUSCARMAS"))!=0)
    {
        pos=buscar(nombres,nom,cant);
        if(pos!=-1)
            printf("\nEl dni es de: %d",dni[pos]);
        else
            printf("\nNO ESTA CARGADO ESE NOMBRE");
        printf("\nIngrese el nombre a buscar: ");
        fflush(stdin);
        gets(nom);
    }
    ordenar(nombres,cant);
    mostrar(nombres,cant);
    return 0;
}

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
        printf("%s\n",Nom[x];
    }
}*/
