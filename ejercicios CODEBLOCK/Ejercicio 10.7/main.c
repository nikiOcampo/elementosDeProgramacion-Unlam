/*Se dispone de un archivo que contiene información de los vuelos realizados por las distintas aerolíneas
 lo largo del mes. El archivo se denomina Vuelos.dat y guarda los registros con la siguiente estructura:
• Código Aerolínea (alfanumérico de 10 caracteres máximo)
• Día (entero)
• Número de Vuelo (entero)
• Costo del pasaje (real)
• Pasajeros (inicialmente en el archivo viene en 0)
El mes tiene 30 días y se sabe que como máximo cada aerolínea realiza 5 vuelos diarios.
Luego se dispone de un segundo archivo llamado Pasajeros.dat que incluye la información de los viajeros del mes
para la aerolínea con código “Aero1”, el archivo contiene los siguientes campos:
• DNI (entero)
• Número de Vuelo (entero)
Se desea realizar un programa que actualice la cantidad de pasajeros de la aerolínea con código “Aero1”
 con la información de los pasajeros que realizar los viajes. Al finalizar, grabar la información en un
  nuevo archivo llamado Aero1.dat. Agregar la opción para exportar el archivo Aero1 a formato csv.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char cod_aerolinea[11];
    int dia;
    int nro_vuelo;
    float costo_pasaj;
    int cant_pasaj=0;
}vuelos;

typedef struct
{
    int dni;
    int nro_vuelo;
}pasajeros;

int carga_vuelos(vuelos[],char [][11], int);
void cargaaerolineas(char[][11]);

int main()
{
    vuelos vuel[1000];
    int cant;
    char aerolineas[5][11];
    cargaaerolineas(aerolineas);
    cant=carga_vuelos(vuel,aerolineas,1000);
    return 0;
}

int carga_vuelos (vuelos vuel[],char aerolineas[][11] ,int n)
{
    FILE*fp;
    int x=0,cont=0;
    fp=fopen("vuelos.dat","wb");
    if(fp==NULL)
    {
        printf("\nEl archivo tiene algun error");
        exit(1);
    }
    do
    {
        printf("\nIngrese el codigo de Aerolinea[Salida:'FIN']: ");
        gets(vuel[x].cod_aerolinea);
        pos=buscar(aerolineas,vuel[x].cod_aerolinea,5);
    }while(pos==-1&&(strcmpi(vuel[x].cod_aerolinea,"FIN"))!=0);
    while((strcmpi(vuel[x].cod_aerolinea,"FIN"))!=0)
    {
        cont++;
        do
        {
            printf("\nIngrese el dia[1 a 30]: ");
            scanf("%d",&vuel[x].dia);
        }while(vuel[x].dia<1||vuel[x].dia>30);
        printf("\nIngrese el numero de vuelo: ");
        scanf("%d",&vuel[x].nro_vuelo);
        do
        {
            printf("\nIngrese el costo del pasaje: ");
            scanf("%f",&vuel[x].costo_pasaj);
        }while(vuel[x].costo_pasaj<0);
        //la cantidad de pasajeros es cero al inicio osea no cargo pasajeros??
    }
}

void cargaaerolineas(char aerolineas[5][11])
{
    strcpy(aerolineas[0], "Aero1");
    strcpy(aerolineas[1], "Aero2");
    strcpy(aerolineas[2], "Aero3");
    strcpy(aerolineas[3], "Aero4");
    strcpy(aerolineas[4], "Aero5");
}

int buscar(char m[][11], char sec[11], int n)
{
    int pos=-1,x=0;
    while(pos==-1&&x<n)
    {
        if((strcmpi(m[x],sec))==0)
            pos=x;
        else
            x++;
    }
    return pos;
}


