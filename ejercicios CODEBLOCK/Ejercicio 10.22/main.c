#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//ESTRUCTURAS
typedef struct
{
    char codigo[4];
    char nombre_provincia[31];
}sProvincias;

typedef struct
{
    char codigo_provincia[4];
    int nacionalidad;
    int cant_habitantes;
}sCenso;

typedef struct
{
    char cod_modificacion;
    char cod_provincia[4];
    int Nacionalidad;
    int cantidad_hab;
}sModif_Censo;

//PROTOTIPO FUNCIONES
int Carga_Provincias (sProvincias[], int);
void Listar_Provincias(sProvincias[], int);
int Cargar_Censos(sCenso [], int , sProvincias [], int );
void Modificaciones(sCenso[], sProvincias[], int);
void PuntoC(sCenso[], int);
int Buscar(sProvincias[], char[], int);

//MAIN
int main()
{
    sProvincias provincias[24];
    int cant_provincias=0, cant_censos=0;
    cant_provincias=Carga_Provincias(provincias, 24);
    sCenso censo[24];
    cant_censos=Cargar_Censos(censo, 24, provincias, cant_provincias);
    Modificaciones(censo, provincias, cant_provincias);
    PuntoC(censo, cant_censos);
    return 0;
}

//FUNCIONES
int Carga_Provincias (sProvincias prov[], int tam)
{
    int i=0;
    FILE* provincias;
    provincias=fopen("Provincias.dat","wb");
    if (provincias == NULL)
    {
        printf("ERROR\n");
        getch();
        exit(1);
    }

    do{
        printf("Ingrese el codigo de la provincia (SALIDA=FIN): ");
        fflush(stdin);
        gets(prov[i].codigo);

    }while(strlen(prov[i].codigo)<1 || strlen(prov[i].codigo)>3);
    while(strcmpi(prov[i].codigo, "FIN") !=0 && i<tam)
    {
        do{
        printf("Ingrese el nombre de la provincia: ");
        fflush(stdin);
        gets(prov[i].nombre_provincia);

    }while(strlen(prov[i].nombre_provincia)<1 || strlen(prov[i].nombre_provincia)>31);
        fwrite(&prov[i], sizeof(sProvincias), 1, provincias);

        i++;
        do{
        printf("Ingrese el codigo de la provincia (SALIDA=FIN): ");
        gets(prov[i].codigo);

        }while(strlen(prov[i].codigo)<1 || strlen(prov[i].codigo)>3);
    }
    fclose(provincias);
return i; //cant provincias = i
}

void Listar_Provincias(sProvincias vp[], int tam)
{
    int i;
    system("cls");
    printf("LISTADO DE PROVINCIAS\n");
    printf("--------------------\n\n");
    printf("%s %-21s\n","CODIGO", "NOMBRE PROVINCIA");
    printf("%s %-21s\n","------", "----------------");
    for (i=0;i<tam;i++)
    {
        printf("%s       %s\n", vp[i].codigo, vp[i].nombre_provincia);
    }

    printf("\n");
    system("Pause");
}

int Cargar_Censos(sCenso vc[], int tam, sProvincias prov[], int CantProv)
{
    int i=0, pos;
    char codigo[4];
    FILE* censo;
    censo=fopen("sCenso.dat", "wb");
    if (censo == NULL)
    {
        printf("ERROR\n");
        getch();
        exit(1);
    }

    do{
        Listar_Provincias(prov, CantProv);
        printf("Ingrese el codigo de provincia: ");
        fflush(stdin);
        gets(codigo);
    pos=Buscar(prov, codigo, CantProv);

    }while(pos==-1 && strcmpi(codigo,"FIN") !=0);

    while(strcmpi (codigo, "FIN") !=0 && i<tam)
    {
        strcpy(vc[i].codigo_provincia,codigo);
        printf("Ingrese la nacionalidad: ");
        scanf("%d", &vc[i].nacionalidad);

        printf("Ingrese cantidad de habitantes: ");
        scanf("%d", &vc[i].cant_habitantes);

        fwrite(&vc[i], sizeof(sCenso), 1, censo);
        i++;

        do{
        Listar_Provincias(prov, CantProv);
        printf("Ingrese el codigo de provincia: ");
        fflush(stdin);
        gets(codigo);
    pos=Buscar(prov, codigo, CantProv);

    }while(pos==-1 && strcmpi(codigo,"FIN") !=0);
    }
    fclose(censo);

    return i;
}

int Buscar(sProvincias prov[], char cod[4], int ce)
{
    int pos=-1, i=0;
    while(pos==-1 && i<ce)
    {
        if(strcmpi(prov[i].codigo,cod)==0)
        {
            pos=i;
        }
        else{
            i++;
        }
    }
    return pos;
}

void Modificaciones(sCenso vc[], sProvincias prov[], int CantProv)
{
    char codigo[4];
    int pos;
    sModif_Censo modif_c;
    FILE* mod_censo;
    FILE* Censo;
    mod_censo=fopen("Modif_Censo.dat", "wb");
    if (mod_censo == NULL)
    {
        printf("ERROR\n");
        getch();
        exit(1);
    }
    Censo=fopen("Censo.dat","ab");
    if (Censo == NULL)
    {
        printf("ERROR\n");
        getch();
        exit(1);
    }

    do
    {
        printf("Ingrese codigo de modificacion ('A o M // F (salir)'): ");
        fflush(stdin);
        gets(&modif_c.cod_modificacion);

    }while(modif_c.cod_modificacion != 'M' && modif_c.cod_modificacion != 'A' && modif_c.cod_modificacion != 'F');

    while(modif_c.cod_modificacion != 'F')
          {
    do{
        Listar_Provincias(prov, CantProv);
        printf("Ingrese el codigo de provincia: ");
        fflush(stdin);
        gets(codigo);
        pos=Buscar(prov, codigo, CantProv);
    }while(pos==-1);

    modif_c.Nacionalidad=vc[pos].nacionalidad;//para no sobreescribir la nacionalida dya estrita
    printf("Ingrese la cantidad de habitantes: ");
    scanf("%d", &modif_c.cantidad_hab);

    if(modif_c.cod_modificacion=='A')
    {
        vc[pos].cant_habitantes+= modif_c.cantidad_hab;
        fwrite(&vc[pos],sizeof(sCenso), 1, Censo);
        fwrite(&modif_c,sizeof(sModif_Censo), 1, mod_censo);
    }
    else
    {
        vc[pos].cant_habitantes= modif_c.cantidad_hab;
        fwrite(&vc[pos],sizeof(sCenso), 1, Censo);
        fwrite(&modif_c,sizeof(sModif_Censo), 1, mod_censo);
    }
    do
    {
        printf("Ingrese codigo de modificacion ('A o M // F (salir)'): ");
        fflush(stdin);
        gets(&modif_c.cod_modificacion);

    }while(modif_c.cod_modificacion != 'M' && modif_c.cod_modificacion != 'A' && modif_c.cod_modificacion != 'F');
    }
    fclose(Censo);
    fclose(mod_censo);
}

void PuntoC(sCenso vc[], int tam)
{
	int flag=0,i;
	sCenso aux;
	while(flag==0)
	{
		flag=1;
		for(i=0;i<tam-1;i++)
		{
			if(vc[i].cant_habitantes<vc[i+1].cant_habitantes)
			   {
                aux=vc[i];
                vc[i]=vc[i+1];
                vc[i+1]=aux;
			   	flag=0;
			   }
		}
    }
   printf("\n Listado Ordenado CANTIDAD HABITANTES POR PROVINCIAS \n: ");
   printf("\n Provincia   Cantidad \n");
   for(i=0;i<tam;i++)
     {
     	printf("\n%s     %d",vc[i].codigo_provincia,vc[i].cant_habitantes);
	 }
}
