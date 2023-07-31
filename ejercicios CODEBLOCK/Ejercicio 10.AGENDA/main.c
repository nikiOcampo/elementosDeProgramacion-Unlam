//==================================================================
//===================AGENDA==========================================
//===================================================================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SALIR 4
#define AGREGAR 1
#define LISTAR 2
#define BUSCAR 3

typedef struct
{
    char nombre[21];
    int telefono;
    char domicilio[31];
}sContacto;

int menu();
int AgregarContactos(sContacto[], int, int);
int BuscarContacto(sContacto[], char[], int);
int RecuperarContactos(sContacto[], int);
void LeerTexto(char[], int);
void ListarContactos(sContacto[], int);

int main()
{
    int cant, op, pos;
    char nombreABuscar[21];
    sContacto contactos[100];
    cant = RecuperarContactos(contactos,100);
    op=menu(cant);
    while(op!=SALIR)
    {
        switch(op)
        {
            case AGREGAR:
                cant = AgregarContactos(contactos,cant,100);
                break;

            case LISTAR:
                ListarContactos(contactos, cant);
                break;

            case BUSCAR:
                printf("Ingrese el nombre a buscar:");
                LeerTexto(nombreABuscar,21);
                pos = BuscarContacto(contactos,nombreABuscar,cant);
                if (pos!=-1)
                {
                    printf ("\nEl telefono de %s es %d\n", contactos[pos].nombre, contactos[pos].telefono);
                    printf("\nEl domicilio de %s es %s\n\n",contactos[pos].nombre,contactos[pos].domicilio);
                }
                else
                    printf("\nNo se encontro el contacto en la agenda.\n\n");

                system("Pause");

                break;
        }
        op=menu(cant);
    }
    return 0;
}

int RecuperarContactos(sContacto vc[], int ce)
{
    FILE * archivo;
    int i =0;

    archivo = fopen("contactos.dat","rb");
    if (archivo!=NULL)
    {
        fread(&vc[i], sizeof(sContacto),1, archivo);
        while (!feof(archivo) && i<ce)
        {
            i++;
            if (i<ce)
                fread(&vc[i], sizeof(sContacto),1, archivo);
        }
        fclose(archivo);
    }

    return i;
}

int AgregarContactos(sContacto vc[], int cantidadActual, int cantidaMaxima)
{
    FILE * archivo;

    char nombre[21];
    char opcion;
    if (cantidadActual>0)
    {
        do
        {
            printf("\nIngrese A si quiere agregar contactos a los existentes");
            printf("\nIngrese N si quiere agregar crear una nueva lista de contactos y borrar los anteriores:");
            fflush(stdin);
            opcion = getchar();
            opcion = toupper(opcion);
        }while(opcion !='A' && opcion!='N');
    }
    else
        opcion = 'N';
    if(opcion=='A')
        archivo = fopen("contactos.dat","ab");
    else
    {
        archivo = fopen("contactos.dat","wb");
        cantidadActual=0;
    }
    if (archivo==NULL)
    {
        printf("\nNo se pudo abrir el archivo de contactos.\n");
        system("pause");
        exit(1);
    }
    printf("\nIngrese el nombre del nuevo contacto (SALIR para terminar):");
    LeerTexto(vc[cantidadActual].nombre,21);
    while(cantidadActual<cantidaMaxima && strcmpi(vc[cantidadActual].nombre, "SALIR")!=0)
    {
        printf("Ingrese el numero de telefono:");
        scanf("%d", &vc[cantidadActual].telefono);
        printf("Ingrese el domicilio: ");
        fflush(stdin);
        gets(vc[cantidadActual].domicilio);
        fwrite(&vc[cantidadActual], sizeof(sContacto),1,archivo);
        cantidadActual++;
        if (cantidadActual<cantidaMaxima)
        {
            printf("\nIngrese el nombre del nuevo contacto (SALIR para terminar):");
            LeerTexto(vc[cantidadActual].nombre,21);
        }
        else
            printf("\nSe llego a la cantidad maxima de contactos permitidos.\n");
    }
    fclose(archivo);

    return cantidadActual;
}

int menu(int hayContactos)
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES\n");
    printf("----------------\n");
    printf("1. Agregar nuevos contactos\n");

    if (hayContactos)
    {
        printf("2. Mostrar contactos\n");
        printf("3. Buscar Contacto\n");
    }
    printf("4. Salir\n");
    do
    {
        printf("Ingrese su opcion:");
        scanf("%d", &opcion);
    }while(opcion <1 || opcion >4);
    return opcion;
}


void ListarContactos(sContacto vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE CONTACTOS\n");
    printf("--------------------\n\n");
    printf("%-21s %s  %s\n","NOMBRE", "TELEFONO","DOMICILIO");
    printf("%-21s %s  %s\n","------", "--------","---------");
    for (i=0;i<ce;i++)
        printf("%-21s %d %s\n", vc[i].nombre, vc[i].telefono,vc[i].domicilio);

    printf("\n");
    system("Pause");
}

void LeerTexto(char s[], int cantMax)
{
    int i=0;
    fflush(stdin);
    fgets(s, cantMax, stdin);
    while (s[i]!='\0')
        i++;

    if (s[i-1]=='\n')
        s[i-1]='\0';
}

int BuscarContacto(sContacto vc[], char nombreBuscado[], int ce)
{
    int i=0, pos=-1;
    while(pos ==-1 && i<ce)
    {
        if (strcmpi(nombreBuscado,vc[i].nombre)==0)
            pos =i;
        else
            i++;
    }

    return pos;
}
