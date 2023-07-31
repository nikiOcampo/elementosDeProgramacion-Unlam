#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CARGACUR 1
#define CARGAINS 2
#define LISTAROCUP 3
#define GENERREP 4
#define SALIR 5

typedef struct
{
    int codigo;
    char descripcion[50];
    int capacidad;
    float precio;
}cursos;

typedef struct
{
    char apel_nom[60];
    char email[50];
    int codigo;
    int cantidad;
}inscriptos;

int RecuperarCursos(cursos[],int);
int menu(int,int);
int CargaCursos(cursos[], int,int);
void ListarCursos(cursos[], int);
int buscar(cursos[],int,int);
void CargaInscriptos(cursos[],int,int[]);
void ListarOcupacion(cursos[],int,int[]);
void ListarSinInscrip();

int main()
{
    cursos cur[20];
    int cant_cursos=0,opcion,cant_alum=0,cant_x_curso[20]={0};
    //if(cant_cursos>0)
    cant_cursos=RecuperarCursos(cur,20);
    opcion=menu(cant_cursos,cant_alum);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case CARGACUR:
            cant_cursos=CargaCursos(cur,20,cant_cursos);
            break;

        case CARGAINS:
            CargaInscriptos(cur,cant_cursos,cant_x_curso);
            cant_alum=1;
            break;

        case LISTAROCUP:
            ListarOcupacion(cur,cant_cursos,cant_x_curso);
            break;

        case GENERREP:
            ListarSinInscrip();
            break;
        }
        opcion=menu(cant_cursos,cant_alum);
    }
    return 0;
}

int menu(int hayCursos,int hayInscriptos)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Agregar Cursos\n");
    if (hayCursos)
        printf("2. Agregar Inscriptos\n");
    if(hayInscriptos)
    {
        printf("3. Listar Ocupacion de cursos\n");
        printf("4. Generar Reportes\n");
    }
    printf("5. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >5);
    return opcion;
}

int RecuperarCursos(cursos cur[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("CursosOfe.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp!=NULL)
    {
        fread(&cur[i], sizeof(cursos),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&cur[i], sizeof(cursos),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int CargaCursos(cursos cur[], int cantidaMaxima,int cantidadActual)
{
    int cod,pos;
    FILE*archivo;
    char opcion;
    if(cantidadActual>0)
    {
        do
        {
            ListarCursos(cur,cantidadActual);
            printf("\nIngrese A si quiere agregar cursos a los existentes");
            printf("\nIngrese N si quiere crear una nueva lista de cursos y borrar los anteriores:");
            fflush(stdin);
            opcion = getchar();
            opcion = toupper(opcion);
        }while(opcion !='A' && opcion!='N');
    }
    else
        opcion = 'N';
    if(opcion=='A')
        archivo = fopen("CursosOfe.dat","ab");
    else
    {
        archivo = fopen("CursosOfe.dat","wb");
        cantidadActual=0;
    }
    if (archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo de cursos.\n");
        system("pause");
        exit(1);
    }
    do
    {
        pos=0;
        ListarCursos(cur,cantidadActual);
        printf("\nIngrese el codigo de curso[de 100 a 1000/SALIDA=99]: ");
        scanf("%d",&cod);
        pos=buscar(cur,cod,cantidadActual);
        if(pos!=-1)
        {
            printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
            system("pause");
        }
    }while((cod<100||cod>1000||pos!=-1)&&cod!=99);
    while(cantidadActual<cantidaMaxima && cod!=99)
    {
        cur[cantidadActual].codigo=cod;
        do
        {
            printf("Ingrese la descripcion del curso:");
            fflush(stdin);
            gets(cur[cantidadActual].descripcion);
        }while(strlen(cur[cantidadActual].descripcion)<1||strlen(cur[cantidadActual].descripcion)>50);
        do
        {
            printf("\nIngrese la capacidad del curso: ");
            scanf("%d",&cur[cantidadActual].capacidad);
        }while(cur[cantidadActual].capacidad<1||cur[cantidadActual].capacidad>50);
        do
        {
            printf("\nIngrese el precio del curso: ");
            scanf("%f",&cur[cantidadActual].precio);
        }while(cur[cantidadActual].precio<0);
        fwrite(&cur[cantidadActual], sizeof(cursos),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            do
            {
                ListarCursos(cur,cantidadActual);
                printf("\nIngrese el codigo de curso[de 100 a 1000/SALIDA=99]: ");
                scanf("%d",&cod);
                pos=buscar(cur,cod,cantidadActual);
                if(pos!=-1)
                {
                    printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
                    system("pause");
                }
            }while((cod<100||cod>1000||pos!=-1)&&cod!=99);
        }
        else
            printf("\nSe llego a la cantidad maxima de los produtos permitidos.\n");
    }
    fclose(archivo);
    return cantidadActual;
}

void CargaInscriptos(cursos cur[],int cant_cursos,int cant_x_curso[])
{
    int cod,pos;
    inscriptos inscrip;
    inscriptos noinscrip;
    FILE*fp2;
    FILE*fp3;
    FILE*fp4;
    fp2=fopen("Inscripcion.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp3=fopen("CursosOfe.dat","ab");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp4=fopen("SinInscrip.dat","wb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        ListarCursos(cur,cant_cursos);
        printf("\nIngrese el codigo del curso[SALIDA=0]: ");
        scanf("%d",&cod);
        pos=buscar(cur,cod,cant_cursos);
        if(pos==-1&&cod!=0)
        {
            printf("\nCODIGO DE CURSO NO EXISTENTE");
            system("pause");
        }
    }while(pos==-1&&cod!=0);
    while(cod!=0)
    {
        inscrip.codigo=cod;
        do
        {
            printf("\nIngrese el Apellido y Nombre: ");
            fflush(stdin);
            gets(inscrip.apel_nom);
        }while(strlen(inscrip.apel_nom)<1||strlen(inscrip.apel_nom)>60);
        do
        {
            printf("\nIngrese el mail: ");
            fflush(stdin);
            gets(inscrip.email);
        }while(strlen(inscrip.email)<1||strlen(inscrip.email)>50);
        do
        {
            printf("\nIngrese la cantidad de alumnos que desea inscribir: ");
            scanf("%d",&inscrip.cantidad);
        }while(inscrip.cantidad<0);
        if(inscrip.cantidad<=cur[pos].capacidad)
        {
            cant_x_curso[pos]+=inscrip.cantidad;
            cur[pos].capacidad-=inscrip.cantidad;
            fwrite(&cur[pos].capacidad,sizeof(cursos),1,fp3);
            fwrite(&inscrip,sizeof(inscriptos),1,fp2);
        }
        else
        {
            printf("\nLa cantidad solicitada es mayor que la disponible, te enviaremos informacion de proximos cursos");
            system("pause");
            noinscrip=inscrip;
            fwrite(&noinscrip,sizeof(inscriptos),1,fp4);
        }
        do
        {
            ListarCursos(cur,cant_cursos);
            printf("\nIngrese el codigo del curso[SALIDA=0]: ");
            scanf("%d",&cod);
            pos=buscar(cur,cod,cant_cursos);
            if(pos==-1&&cod!=0)
            {
                printf("\nCODIGO DE CURSO NO EXISTENTE");
                system("pause");
            }
        }while(pos==-1&&cod!=0);
    }
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}

void ListarOcupacion(cursos cur[],int cant_cursos,int cant_x_curso[])
{
    int i;
    system("cls");
    printf("LISTADO DE OCUPACION DE CURSOS\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s\n","DESCRIPCION","CANT INSCRIPTOS","MONTO");
    printf("%s %-21s  %s\n","-----------","---------------","-----");
    for (i=0;i<cant_cursos;i++)
    {
        if(cant_x_curso[i]!=0)
            printf("%s        %d            %0.2f\n", cur[i].descripcion,cant_x_curso[i],cur[i].precio);
    }

    printf("\n");
    system("Pause");
}

void ListarCursos(cursos vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE CURSOS\n");
    printf("--------------------\n\n");
    printf("%s %-21s  %s  %s\n","CODIGO", "DESCRIPCION","CAPACIDAD","PRECIO");
    printf("%s %-21s  %s  %s\n","------", "-----------","---------","------");
    for (i=0;i<ce;i++)
    {
        if(vc[i].codigo>=100&&vc[i].codigo<=1000)
            printf("%d        %s            %d           %0.2f\n", vc[i].codigo, vc[i].descripcion,vc[i].capacidad,vc[i].precio);
    }

    printf("\n");
    system("Pause");
}

void ListarSinInscrip()
{
    inscriptos SinInscrp;
    FILE*fp5;
    fp5=fopen("SinInscrip.dat","rb");
    if(fp5==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("LISTADO DE SIN INSCRIPCION\n");
    printf("--------------------\n\n");
    printf("%-21s  %-20s  %s  %s\n","APELLIDO Y NOMBRE","DIRECCION DE EMAIL","COD CURSO","CANTIDAD");
    printf("%-21s  %-20s  %s\n","----------------","----------------","---------------");
    fread(&SinInscrp,sizeof(inscriptos),1,fp5);
    while(!feof(fp5))
    {
        printf("%s        %s            %d        %d\n",SinInscrp.apel_nom,SinInscrp.email,SinInscrp.codigo,SinInscrp.cantidad);
        fread(&SinInscrp,sizeof(inscriptos),1,fp5);
    }
    system("pause");
    fclose(fp5);
}

int buscar(cursos cur[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(cur[i].codigo==cod)
           p=i;
      else
          i++;
  }
  return p;
}


