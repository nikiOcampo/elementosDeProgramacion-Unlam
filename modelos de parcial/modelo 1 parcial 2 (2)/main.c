#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CARGACUR 1
#define CARGAINS 2
#define LISTAR 3
#define GENERARREP 4
#define SALIR 5

typedef struct
{
    int cod_curso;
    char descripcion[50];
    int capacidad;
    float precio;
}cursos;

typedef struct
{
    char nombre[60];
    char email[50];
    int cod_curso;
    int cant;
}alumnos;

int menu(int,int,int);
int RecuperarCursos(cursos[],int);
int CargarCursos(cursos[], int, int);
int lee_control(int,int,int);
float validarfloat();
int CargaInscriptos(alumnos[],cursos[],int,int[],int);
void ListarCursos(cursos[], int);
int buscar(cursos[],int,int);
void listarOcupacion(cursos[],int,int[],alumnos[]);
void mostrarNoInscriptos(int);

int main()
{
    cursos curso[20];
    alumnos alum[10000];
    int cant_cursos=0,opcion,cant_noInscrip=0,cantidades[20]={0},sen=0;
    //if(cant_cursos>0)
    cant_cursos=RecuperarCursos(curso,20);
    opcion=menu(cant_cursos,cant_noInscrip,sen);
    while(opcion!=SALIR)
    {
        switch(opcion)
        {
        case CARGACUR:
            cant_cursos=CargarCursos(curso,cant_cursos,20);
            break;

        case CARGAINS:
            cant_noInscrip=CargaInscriptos(alum,curso,cant_cursos,cantidades,cant_noInscrip);
            sen=1;
            break;

        case LISTAR:
            listarOcupacion(curso,cant_cursos,cantidades,alum);
            break;

        case GENERARREP:
            mostrarNoInscriptos(cant_noInscrip);
            break;
        }
        opcion=menu(cant_cursos,cant_noInscrip,sen);
    }
    //printf("\n%d %d",cant_cursos,cant_noInscrip);
    return 0;
}

int RecuperarCursos(cursos curs[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("CursoOfe.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    if (fp!=NULL)
    {
        fread(&curs[i], sizeof(cursos),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&curs[i], sizeof(cursos),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int menu(int hayCursos,int hayNoInscriptos,int sen)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Carga de Cursos\n");
    if (hayCursos)
        printf("2. Carga de Inscriptos\n");
    if(sen==1)
        printf("3. Listar Ocupacion de Cursos\n");
    if(hayNoInscriptos)
        printf("4. Generar Reportes\n");
    printf("5. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >5);
    return opcion;
}

int CargarCursos(cursos curs[], int cantidadActual, int cantidaMaxima)
{
    int cod,pos;
    FILE*archivo;
    char opcion;
    if(cantidadActual>0)
    {
        do
        {
            ListarCursos(curs,cantidadActual);
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
        archivo = fopen("CursoOfe.dat","ab");
    else
    {
        archivo = fopen("CursoOfe.dat","wb");
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
        ListarCursos(curs,cantidadActual);
        cod=lee_control(99,1000,1);
        pos=buscar(curs,cod,cantidadActual);
        if(pos!=-1)
        {
            printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
            system("pause");
        }
    }while(pos!=-1);
    while(cantidadActual<cantidaMaxima && cod!=99)
    {
        curs[cantidadActual].cod_curso=cod;
        do
        {
            printf("Ingrese la descripcion del curso:");
            fflush(stdin);
            gets(curs[cantidadActual].descripcion);
        }while(strlen(curs[cantidadActual].descripcion)<1||strlen(curs[cantidadActual].descripcion)>50);
        curs[cantidadActual].capacidad=lee_control(1,50,2);
        curs[cantidadActual].precio=validarfloat();
        fwrite(&curs[cantidadActual], sizeof(cursos),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            do
            {
                ListarCursos(curs,cantidadActual);
                cod=lee_control(99,1000,1);
                pos=buscar(curs,cod,cantidadActual);
                if(pos!=-1)
                {
                    printf("\nYA SE CRAGARON DATOS DE ESTE CURSO");
                    system("pause");
                }
            }while(pos!=-1);
        }
        else
            printf("\nSe llego a la cantidad maxima de cursos permitidos.\n");
    }
    fclose(archivo);
    return cantidadActual;
}

int CargaInscriptos(alumnos inscrip[],cursos cur[],int cant_cursos,int cantidades[],int cant_noinscrp)
{
    int cod_a_buscar,x=0,pos;
    alumnos noinscriptos;
    FILE*fp1;
    FILE*fp2;
    FILE*fp3;
    fp1=fopen("CursoOfe.dat","ab");
    if(fp1==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp2=fopen("Inscripcion.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    fp3=fopen("Sin_Inscrip.dat","ab");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        ListarCursos(cur,cant_cursos);
        printf("\nIngrese el codigo de curso al que desea inscibirse[SALIDA=0]: ");
        scanf("%d",&cod_a_buscar);
        pos=buscar(cur,cod_a_buscar,cant_cursos);
        if(pos==-1&&cod_a_buscar!=0)
        {
            printf("\nCURSO INEXISTENTE");
            system("pause");
        }
    }while(pos==-1&&cod_a_buscar!=0);
    while(cod_a_buscar!=0)
    {
        inscrip[x].cod_curso=cod_a_buscar;
        do
        {
            printf("Ingrese su nombre y apellido:");
            fflush(stdin);
            gets(inscrip[x].nombre);
        }while(strlen(inscrip[x].nombre)<1||strlen(inscrip[x].nombre)>60);
        do
        {
            printf("Ingrese su direccion de email:");
            fflush(stdin);
            gets(inscrip[x].email);
        }while(strlen(inscrip[x].email)<1||strlen(inscrip[x].email)>50);
        do
        {
            printf("\nIngrese la cantidad a inscribir: ");
            scanf("%d",&inscrip[x].cant);
        }while(inscrip[x].cant<0);
        if(cur[pos].capacidad>=inscrip[x].cant)
        {
            cur[pos].capacidad-=inscrip[x].cant;
            cantidades[pos]+=inscrip[x].cant;
            fwrite(&cur[pos].capacidad,sizeof(cursos),1,fp1);
            fwrite(&inscrip[x],sizeof(alumnos),1,fp2);
        }
        else
        {
            printf("\nEl curso no acepta la capacidad solicitada o se encuentra lleno, lo anotaremos y le mandaremos un mail para un proximo curso.");
            system("pause");
            noinscriptos=inscrip[x];
            fwrite(&noinscriptos,sizeof(alumnos),1,fp3);
            cant_noinscrp++;
        }
        x++;
        do
        {
            ListarCursos(cur,cant_cursos);
            printf("\nIngrese el codigo de curso al que desea inscibirse[SALIDA=0]: ");
            scanf("%d",&cod_a_buscar);
            pos=buscar(cur,cod_a_buscar,cant_cursos);
            if(pos==-1&&cod_a_buscar!=0)
            {
                printf("\nCURSO INEXISTENTE");
                system("pause");
            }
        }while(pos==-1&&cod_a_buscar!=0);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return cant_noinscrp;
}

void listarOcupacion(cursos cur[],int cant_cursos,int cant[],alumnos inscrip[])
{
    int i;
    system("cls");
    printf("LISTADO DE OCUPACION DE CURSOS\n");
    printf("--------------------\n\n");
    printf("%-21s  %s  %s\n","DESCRIPCION","INSCRIPTOS","PRECIO");
    printf("%-21s  %s  %s\n","-----------","----------","------");
    for (i=0;i<cant_cursos;i++)
    {
        if(cant[i]!=0)
            printf("%s                   %d      %0.2f\n",cur[i].descripcion,cant[i],cur[i].precio);
    }
    printf("\n");
    system("Pause");
}

void mostrarNoInscriptos(int cant)
{
    alumnos noinscrip;
    FILE*fp4;
    fp4=fopen("Sin_Inscrip.dat","rb");
    if(fp4==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    system("cls");
    printf("LISTADO DE NO INSCRIPTOS\n");
    printf("--------------------\n\n");
    printf("%-21s  %-30s  %s  %s\n","APELLIDO Y NOMBRE","DIRECCION DE EMAIL","COD.CURSO","CANTIDAD");
    printf("%-21s  %-30s  %s  %s\n","-----------------","------------------","---------","--------");
    fread(&noinscrip,sizeof(alumnos),1,fp4);
    printf("%s        %s          %d            %d\n",noinscrip.nombre,noinscrip.email,noinscrip.cod_curso,noinscrip.cant);
    while(!feof(fp4))
    {
        fread(&noinscrip,sizeof(alumnos),1,fp4);
        printf("%s        %s          %d            %d\n",noinscrip.nombre,noinscrip.email,noinscrip.cod_curso,noinscrip.cant);
    }
    system("pause");
    fclose(fp4);
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
        printf("%d        %s            %d           %0.2f\n", vc[i].cod_curso, vc[i].descripcion,vc[i].capacidad,vc[i].precio);
    printf("\n");
    system("Pause");
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el codigo de curso [100 a 1000/Salida=99]: ");
        if(n==2)printf("\nIngrese la capacidad del curso[1 a 50]: ");

        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

float validarfloat()
{
    float dato;
    do
    {
        printf("\nIngrese el precio del curso: ");
        scanf("%f",&dato);
    }while(dato<0);
    return dato;
}

int buscar(cursos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].cod_curso==cod)
           p=i;
      else
          i++;
  }
  return p;
}

