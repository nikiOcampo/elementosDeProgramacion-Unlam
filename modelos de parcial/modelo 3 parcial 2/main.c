#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CARGACAM 1
#define CARGATRANS 2
#define LISTAROCUP 3
#define LISTARMOV 4
#define GENERARREP 5
#define SALIR 6

typedef struct
{
    int cod_camion;
    char nombr_chofer[50];
    int capacidad;
    float importes;
}camiones;

typedef struct
{
    char nombr_campo[60];
    char dirreccion[50];
    int codi_camion;
    int peso_animal;
}transportes;

int menu(int,int,int);
int RecuperarCamiones(camiones[],int);
void ListarCamiones(camiones[], int);
int CargarCamiones(camiones[],int,int);
int lee_control(int,int,int);
void CargarMovimientos(camiones[],transportes,int);
int buscar(camiones [],int,int);
void listarOcupacion(camiones[],int,transportes);
void ListarMovimientos(transportes);
void ListarSinTransp(transportes);

int main()
{
    camiones cam[30];
    transportes transp;
    transportes sintrasp;
    int cant_camiones=0,opcion,cant_transp=0,sen=0;
    cant_camiones=RecuperarCamiones(cam,30);
    opcion=menu(cant_camiones,cant_transp,sen);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case CARGACAM:
            cant_camiones=CargarCamiones(cam,cant_camiones,30);
            break;

        case CARGATRANS:
            CargarMovimientos(cam,transp,cant_camiones);
            cant_transp=1;
            sen=1;
            break;

        case LISTAROCUP:
            listarOcupacion(cam,cant_camiones,transp);
            break;

        case LISTARMOV:
            ListarMovimientos(transp);
            break;

        case GENERARREP:
            ListarSinTransp(sintrasp);
            break;
        }
        opcion=menu(cant_camiones,cant_transp,sen);
    }
    return 0;
}

int CargarCamiones(camiones cam[], int cantidadActual, int cantidaMaxima)
{
    int cod,pos;
    FILE*archivo;
    char opcion;
    if(cantidadActual>0)
    {
        do
        {
            ListarCamiones(cam,cantidadActual);
            printf("\nIngrese A si quiere agregar camiones a los existentes");
            printf("\nIngrese N si quiere crear una nueva lista de camiones y borrar los anteriores:");
            fflush(stdin);
            opcion = getchar();
            opcion = toupper(opcion);
        }while(opcion !='A' && opcion!='N');
    }
    else
        opcion = 'N';
    if(opcion=='A')
        archivo = fopen("MisCamiones.dat","ab");
    else
    {
        archivo = fopen("MisCamiones.dat","wb");
        cantidadActual=0;
    }
    if (archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo de contactos.\n");
        system("pause");
        exit(1);
    }
    do
    {
        ListarCamiones(cam,cantidadActual);
        cod=lee_control(0,30,1);
        pos=buscar(cam,cod,cantidadActual);
        if(pos!=-1)
        {
            printf("\nYA SE CRAGARON DATOS DE ESTE CAMION");
            system("pause");
        }
    }while(pos!=-1);
    while(cantidadActual<cantidaMaxima && cod!=0)
    {
        cam[cantidadActual].cod_camion=cod;
        do
        {
            printf("Ingrese el nombre del chofer:");
            fflush(stdin);
            gets(cam[cantidadActual].nombr_chofer);
        }while(strlen(cam[cantidadActual].nombr_chofer)<1||strlen(cam[cantidadActual].nombr_chofer)>50);
        do
        {
            printf("\nIngrese la capacidad del camion: ");
            scanf("%d",&cam[cantidadActual].capacidad);
        }while(cam[cantidadActual].capacidad<0);
        cam[cantidadActual].importes=0;
        fwrite(&cam[cantidadActual], sizeof(camiones),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            do
            {
                ListarCamiones(cam,cantidadActual);
                cod=lee_control(0,30,1);
                pos=buscar(cam,cod,cantidadActual);
                if(pos!=-1)
                {
                    printf("\nYA SE CRAGARON DATOS DE ESTE CAMION");
                    system("pause");
                }
            }while(pos!=-1);
        }
        else
            printf("\nSe llego a la cantidad maxima de camiones permitidos.\n");
    }
    fclose(archivo);
    return cantidadActual;
}

void CargarMovimientos(camiones cam[],transportes trans,int cant_camiones)
{
    int cod_a_buscar,pos;
    transportes Notransp;
    FILE*fp1;
    FILE*fp2;
    FILE*fp3;
    fp1=fopen("MisCamiones.dat","ab");
    if(fp1==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    fp2=fopen("Transportes.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 2 ");
        exit(1);
    }
    fp3=fopen("Sin_Transporte.dat","wb");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo 3");
        exit(1);
    }
    do
    {
        ListarCamiones(cam,cant_camiones);
        printf("\nIngrese el nombre del campo[SALIDA='FIN']: ");
        fflush(stdin);
        gets(trans.nombr_campo);
    }while(strlen(trans.nombr_campo)<1||strlen(trans.nombr_campo)>60);
    while(strcmpi(trans.nombr_campo,"FIN")!=0)
    {
        do
        {
            printf("\nIngrese su direccion: ");
            fflush(stdin);
            gets(trans.dirreccion);
        }while(strlen(trans.dirreccion)<1||strlen(trans.dirreccion)>50);
        do
        {
            printf("\nIngrese el codigo del camion: ");
            scanf("%d",&cod_a_buscar);
            pos=buscar(cam,cod_a_buscar,cant_camiones);
            trans.codi_camion=cod_a_buscar;
            if(pos==-1)
            {
                printf("\nCAMION INEXISTENTE");
                system("pause");
            }
        }while(pos==-1);
        do
        {
            printf("\nIngrese el peso del animal: ");
            scanf("%d",&trans.peso_animal);
        }while(trans.peso_animal<0);
        if(cam[pos].capacidad>trans.peso_animal)
        {
            cam[pos].capacidad-=trans.peso_animal;
            cam[pos].importes=trans.peso_animal*500;
            fwrite(&cam[pos],sizeof(camiones),1,fp1);
            fwrite(&trans,sizeof(transportes),1,fp2);
        }
        else
        {
            printf("\nEl camion se quedo sin capacidad para ese peso, sin embargo te enviaremos otro camion luego");
            system("pause");
            Notransp=trans;
            fwrite(&Notransp,sizeof(transportes),1,fp3);
        }
        do
        {
            ListarCamiones(cam,cant_camiones);
            printf("\nIngrese el nombre del campo[SALIDA='FIN']: ");
            fflush(stdin);
            gets(trans.nombr_campo);
        }while(strlen(trans.nombr_campo)<1||strlen(trans.nombr_campo)>60);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

void listarOcupacion(camiones cam[],int cant_camiones,transportes trans)
{
    int i;
    system("cls");
    printf("LISTADO DE OCUPACION DE CAMIONES\n");
    printf("--------------------\n\n");
    printf("%s  %-15s  %s  %s\n","CAMION","CHOFER","TOTAL ANIMALES","MONTO");
    printf("%s  %-15s  %s  %s\n","------","------","--------------","-----");
    for (i=0;i<cant_camiones;i++)
    {
        if(cam[i].importes!=0&&cam[i].cod_camion<30)
            printf("%d   %-15s    %d        %0.2f\n",cam[i].cod_camion,cam[i].nombr_chofer,cam[i].capacidad,cam[i].importes);
    }
    printf("\n");
    system("Pause");
}

void ListarMovimientos(transportes trans)
{
    FILE*fp5;
    fp5=fopen("Transportes.dat","rb");
    if(fp5==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("LISTADO DE MOVIMIENTOS\n");
    printf("--------------------\n\n");
    printf("%-21s  %s  %s\n","NOMBRE DEL CAMPO","CODIGO DE CAMION","PESO DEL ANIMAL");
    printf("%-21s  %s  %s\n","----------------","----------------","---------------");
    fread(&trans,sizeof(transportes),1,fp5);
    while(!feof(fp5))
    {
        printf("%s        %d          %d\n",trans.nombr_campo,trans.codi_camion,trans.peso_animal);
        fread(&trans,sizeof(transportes),1,fp5);
    }
    system("pause");
    fclose(fp5);
}

void ListarSinTransp(transportes sintransp)
{
    FILE*fp5;
    fp5=fopen("Sin_Transporte.dat","rb");
    if(fp5==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("LISTADO DE SIN TRANSPORTE\n");
    printf("--------------------\n\n");
    printf("%-21s  %s   %s   %s\n","NOMBRE DEL CAMPO","DIRECCION","CODIGO DE CAMION","PESO DEL ANIMAL");
    printf("%-21s  %s   %s   %s\n","----------------","---------","----------------","---------------");
    fread(&sintransp,sizeof(transportes),1,fp5);
    //printf("%s        %d          %d\n",trans.nombr_campo,trans.codi_camion,trans.peso_animal);
    while(!feof(fp5))
    {
        printf("%s        %s        %d          %d\n",sintransp.nombr_campo,sintransp.dirreccion,sintransp.codi_camion,sintransp.peso_animal);
        fread(&sintransp,sizeof(transportes),1,fp5);
    }
    system("pause");
    fclose(fp5);
}

int menu(int hayCamiones,int hayNoTransportes,int sen)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Carga de Camiones\n");
    if (hayCamiones)
        printf("2. Carga de Transportes\n");
    if(sen==1)
    {
        printf("3. Listar Ocupacion de Camiones\n");
        printf("4. Listar movimientos Transportes\n");
    }
    if(hayNoTransportes)
        printf("5. Generar reporte Sin_Transporte\n");
    printf("6. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >6);
    return opcion;
}

int RecuperarCamiones(camiones cam[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("MisCamiones.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp!=NULL)
    {
        fread(&cam[i], sizeof(camiones),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&cam[i], sizeof(camiones),1, fp);
        }
        fclose(fp);
    }
    return i;
}

void ListarCamiones(camiones vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE CAMIONES\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s  %s\n","CODIGO", "NOMBRE CHOFER","CAPACIDAD","IMPORTE");
    printf("%s %-21s  %s  %s\n","------", "-------------","---------","-------");
    for (i=0;i<ce;i++)
    {
        //if(vc[i].cod_camion<30)
         printf("%d        %s            %d         %0.2f\n", vc[i].cod_camion, vc[i].nombr_chofer,vc[i].capacidad,vc[i].importes);
    }
    printf("\n");
    system("Pause");
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el codigo de camion [1 a 30/Salida=0]: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

int buscar(camiones pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod_camion==cod)
           p=i;
      else
          i++;
  }
  return p;
}

