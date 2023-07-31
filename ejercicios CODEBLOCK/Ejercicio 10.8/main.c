/*Se dispone de un archivo denominado INSCRIPTOS.dat que contiene la información de los inscriptos a un curso de programación.
El curso tiene una capacidad máxima para 60 personas. El archivo aún no está completo ya que la inscripción se realiza por partes.
Por cada inscripto se tiene la siguiente información:
• DNI (entero)
• Apellido y Nombres (texto de 20 caracteres máximo)
• Pagado (campo entero donde 1 indica que pagó y 0 que aún adeuda la matrícula)
Se desea realizar un programa que cumpla con dos funciones:
a. Registrar los pagos de los alumnos ya inscriptos.
b. SI hay cupo, agregar nuevos inscriptos.
El programa solicitará el ingreso del DNI y lo buscará entre los inscriptos, en caso de que lo encuentre dará la
 opción para registrar el pago (si es que no está pago ya). En caso de que no lo encuentre dará la opción para
 inscribirlo al curso (el pago se realiza luego). En el momento que ya no quede cupo en el curso si llega un nuevo
 inscripto se le preguntará si desea quedar registrado para un curso futuro, y en caso afirmativo se le solicitará
 el teléfono y se guardará el nombre, DNI y teléfono en un archivo Interesados.dat.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int dni;
    char nomb_apell[21];
    int pagado;
}inscriptos;

typedef struct
{
    int dni;
    char nombre_apell[21];
    int telefono;
}interesados;

int RecuperarInscriptos(inscriptos[], int);
int buscar(inscriptos[],int,int);
void ListarInscriptos(inscriptos[], int);
void ListarInteresados(interesados[], int );

int main()
{
    int dni_a_buscar,cant,x=0,pos,cont=0;
    char opcion[3];
    inscriptos inscrip[60];
    interesados inter[60];
    FILE*fp;
    cant=RecuperarInscriptos(inscrip,60);
    ListarInscriptos(inscrip,cant);
    printf("\nIngrese el DNI[Salida=0]: ");
    scanf("%d",&dni_a_buscar);
    pos=buscar(inscrip,dni_a_buscar,cant);
    while(dni_a_buscar!=0)
    {
        if(pos!=-1)
        {
            if(inscrip[pos].pagado!=1)
            {
                do
                {
                    printf("\nDesea Ingresar el pago?[SI/NO]");
                    fflush(stdin);
                    gets(opcion);
                }while((((strcmpi(opcion,"SI"))!=0)&&(strcmpi(opcion,"NO"))!=0));
                if((strcmpi(opcion,"SI"))==0)
                    inscrip[pos].pagado=1;
                else
                    inscrip[pos].pagado=0;
            }
            else
                printf("\nEl alumno con dni %d ya ha pagado su inscripcion ",dni_a_buscar);
            ListarInscriptos(inscrip,cant);
        }

        if(pos==-1)
        {
            if(cant<60)
            {
                do
                {
                    printf("\nUsted no se encuentra registrado");
                    printf("\nDesea inscribirse[SI/NO]: ");
                    fflush(stdin);
                    gets(opcion);
                }while(((strcmpi(opcion,"SI"))!=0)&&(strcmpi(opcion,"NO"))!=0);
                if((strcmpi(opcion,"SI"))==0)
                {
                    fp=fopen("inscriptos.dat","ab");
                    if(fp==NULL)
                    {
                        printf("\n Hay un error con el archivo 1");
                        exit(1);
                    }
                    inscrip[cant].dni=dni_a_buscar;
                    do
                    {
                        printf("\nIngrese el nombre y apellido: ");
                        fflush(stdin);
                        gets(inscrip[cant].nomb_apell);
                    }while(strlen(inscrip[cant].nomb_apell)<1||strlen(inscrip[cant].nomb_apell)>20);
                    inscrip[cant].pagado=0;
                    fwrite(&inscrip[cant],sizeof(inscriptos),1,fp);
                    fclose(fp);
                    cant=RecuperarInscriptos(inscrip,60);
                }
                ListarInscriptos(inscrip,cant);
            }
            else
            {
                 cont++;
                 printf("\nEL CURSO ESTA LLENO");
                 do
                 {
                     printf("\nDesea quedar registrado para un curso futuro[SI/NO]: ");
                     fflush(stdin);
                     gets(opcion);
                 }while(((strcmpi(opcion,"SI"))!=0)&&(strcmpi(opcion,"NO"))!=0);
                 if((strcmpi(opcion,"SI"))==0)
                 {
                    ListarInteresados(inter,cont);
                    FILE*fp2;
                    fp2=fopen("interesados.dat","ab");
                    if(fp2==NULL)
                    {
                        printf("\n Hay un error con el archivo 2");
                        exit(1);
                    }
                    inter[x].dni=dni_a_buscar;
                    printf("\nDeje su numero de telefono: ");
                    scanf("%d",&inter[x].telefono);
                    printf("\nDeje su nombre y apellido: ");
                    fflush(stdin);
                    gets(inter[x].nombre_apell);
                    fwrite(&inter[x],sizeof(interesados),1,fp2);
                    x++;
                    fclose(fp2);
                 }
            }
        }
        ListarInscriptos(inscrip,cant);
        printf("\nIngrese el DNI[Salida=0]: ");
        scanf("%d",&dni_a_buscar);
        pos=buscar(inscrip,dni_a_buscar,cant);
    }
    ListarInscriptos(inscrip,cant);
    ListarInteresados(inter,cont);
    return 0;
}

int RecuperarInscriptos(inscriptos inscrip[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("inscriptos.dat","rb");
    if (fp!=NULL)
    {
        fread(&inscrip[i], sizeof(inscriptos),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&inscrip[i], sizeof(inscriptos),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int buscar(inscriptos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].dni==cod)
           p=i;
      else
          i++;
  }
  return p;
}

void ListarInscriptos(inscriptos vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE INSCRIPTOS\n");
    printf("--------------------\n\n");
    printf("%-21s %s         %s\n","NOMBRE", "DNI","PAGADO");
    printf("%-21s %s    %s\n","------", "--------","---------");
    for (i=0;i<ce;i++)
    {
        if(vc[i].pagado==1)
            printf("%-21s %d    %s\n", vc[i].nomb_apell, vc[i].dni,"SI");
        else
            printf("%-21s %d    %s\n", vc[i].nomb_apell, vc[i].dni,"NO");
    }


    printf("\n");
    system("Pause");
}

void ListarInteresados(interesados vc[], int ce)
{
    int i;
    system("cls");
    printf("LISTADO DE INTERESADOS A CURSOS FUTUROS\n");
    printf("--------------------\n\n");
    printf("%-21s %s         %s\n","NOMBRE", "DNI","TELEFONO");
    printf("%-21s %s    %s\n","------", "--------","---------");
    for (i=0;i<ce;i++)
    {
        if(ce==1)
            printf("      ");
        else
            printf("%-21s %d    %d\n", vc[i].nombre_apell, vc[i].dni,vc[i].telefono);
    }
    printf("\n");
}

