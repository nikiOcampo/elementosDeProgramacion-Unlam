/*7.2.8 Un consorcio desea controlar la cobranza de las expensas en un edificio de 5
pisos donde existen 15 departamentos en cada piso. El valor de las expensas es de $ 1000.
 Para registrar la cobranza se ingresa el número de piso (1 a 5) y el número de departamento
 (correlativo de 1 a 15 en cada piso). El ingreso finaliza con un piso igual a 99.
Al finalizar mostrar el dinero total recaudado y una tabla con una X indicando aquellos
departamentos deudores de la siguiente manera:
*/

#include <stdio.h>
#include <stdlib.h>

void carga(char[][15],int,int);
void mostrar (char[][15],int,int );

int main()
{
    char m[5][15];
    carga(m,5,15);
    mostrar(m,5,15);
    return 0;
}

void carga(char m[5][15], int f,int c)
{
    int cont,piso,dep,x,i;
    do
    {
        printf("Ingrese el numero de piso: ");
        scanf("%d",&piso);
        if((piso<1||piso>5)&& piso!=99)
            printf("\nEl piso ingresado no existe");
    }while((piso<1||piso>5)&& piso!=99);
    while(piso!=99)
    {
        do
        {
            printf("\nIngrese el numero de departamente que abono la expensa: ");
            scanf("%d",&dep);
            cont++;
            if(dep<1||dep>15)
                printf("\nEl departamento ingresado no existe");
        }while(dep<1||dep>15);
        m[piso-1][dep-1]='P';
        do
        {
            printf("\nIngrese el numero de piso: ");
            scanf("%d",&piso);
            if((piso<1||piso>5)&& piso!=99)
                printf("\nEl piso ingresado no existe");
        }while((piso<1||piso>5)&& piso!=99);
    }
        for(x=0;x<f;x++)
        {
            for(i=0;i<c;i++)
            {
                if(m[x][i]!='P')
                    m[x][i]='X';
            }
        }
        printf("\nEl dinero total recaudado fue de: %d", cont*1000);

}

void mostrar(char m[][15], int f, int c)
{
    int x,i;
    //system("cls");
    printf("\n             Departamentos deudores:\n");
    printf("       ");
    for(x=0;x<c;x++)
    {
        printf("%d ",x+1);
    }
    for(x=0;x<f;x++)
    {
        printf("\nPISO:%d ",x+1);
        for(i=0;i<c;i++)
        {
            if(m[x][i]=='P')
                printf("  ");
            else
                printf("%2c ",m[x][i]);
        }
    }
}
