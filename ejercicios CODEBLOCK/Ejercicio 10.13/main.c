/*Se desean procesar las transacciones bancarias de las Cuentas Corrientes del BANCO NACIÓN. Se solicita:
a. Leer los archivos “SALDOS.dat” con el saldo del día anterior de cada cliente y lo almacene en la memoria. El archivo está ordenado por número de cuenta y está formado por registros con el siguiente diseño (máximo 300 clientes)
• Número de cuenta (8 dígitos)
• Razón Social (28 caracteres)
• Crédito máximo (real)
• Saldo (real, que puede contener signo -)
b. Ingresar la fecha del día de proceso, controlando que sean valores “lógicos”, confeccionando y utilizando una función, llamada LeerValorLogico y utilizarla para el ingreso y validación. (día, mes y Año). Utilizar una estructura.
c. También se dispone de otro archivo “MOVIM.dat” con los movimientos del día para actualizar los saldos de las cuentas. Cada registro consta de:
• Número de Cuenta
• Código de Operación (R: retiro / D: depósito)
• Importe (real)
d. Si el cliente no se encuentra en el archivo, puede ser una CUENTA NUEVA (Nro. De cuenta mayor al último número existente en el archivo Saldos.dat.) o debido a un error. Esta verificación de búsqueda, realizarla confeccionando y utilizando una Función llamada VeriCuenta. Si hay error se muestra y rechaza la operación, si es cuenta nueva, solo puede ser un depósito, en cuyo caso se solicita por teclado el ingreso de la Razón Social y se lo agrega al final, con el doble del importe como crédito máximo y con el importe como saldo.
e. Listar las Cuentas Nuevas, con el siguiente diseño:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int num_cuenta;
    char razon_social[28];
    float credito_max;
    float saldo;
}saldos;

typedef struct
{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct
{
    int num_cuenta;
    char cod_operacion;
    float importe;
}movimientos;

typedef struct
{
    int num_cuenta;
    float credito_max;
    float saldo;
}nuevas;

int cargarsaldos(saldos[],int);
void LeerValorLogico(fecha[]);
int lee_control(int,int,int);
void ListarCuentas(saldos[],int,fecha[]);
int cargarmovimientos(saldos[],movimientos[],int,nuevas[],fecha[]);
int buscar(saldos[],int,int);
void listarCuentasNuevas(nuevas[],int,fecha[]);
int VeriCuenta(saldos[],int,int);
int DIAS (fecha[]);
int ValidarFecha (fecha[]);

int main()
{
    saldos sald[300];
    fecha fech[1];
    movimientos mov[300];
    nuevas nuev[300];
    int cant,cant_nuevas;
    cant=cargarsaldos(sald,300);
    system("cls");
    LeerValorLogico(fech);
    ListarCuentas(sald,cant,fech);
    cant_nuevas=cargarmovimientos(sald,mov,cant,nuev,fech);
    ListarCuentas(sald,cant,fech);
    listarCuentasNuevas(nuev,cant_nuevas,fech);
    return 0;
}

int cargarsaldos(saldos sald[],int n)
{
    FILE*fp;
    int x=0,i,j,aux;
    float auxf;
    char auxc[28];
    fp=fopen("saldos.dat","wb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    do
    {
        printf("\nIngrese el numero de cuenta[8 digitos/SALIDA=0]: ");
        scanf("%d",&sald[x].num_cuenta);
    }while((sald[x].num_cuenta<10000000||sald[x].num_cuenta>99999999)&&sald[x].num_cuenta!=0);
    while(sald[x].num_cuenta!=0&&x<300)
    {
        do
        {
            printf("\nIngrese la razon social: ");
            fflush(stdin);
            gets(sald[x].razon_social);
        }while(strlen(sald[x].razon_social)<1||strlen(sald[x].razon_social)>27);
        do
        {
            printf("\nIngrese el credito maximo: ");
            scanf("%f",&sald[x].credito_max);
        }while(sald[x].credito_max<0);
        printf("\nIngrese el saldo: ");
        scanf("%f",&sald[x].saldo);
        x++;
        do
        {
            printf("\nIngrese el numero de cuenta[8 digitos/SALIDA=0]: ");
            scanf("%d",&sald[x].num_cuenta);
        }while((sald[x].num_cuenta<10000000||sald[x].num_cuenta>99999999)&&sald[x].num_cuenta!=0);
    }
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-1;j++)
        {
            if(sald[j].num_cuenta>sald[j+1].num_cuenta)
            {
                aux=sald[j].num_cuenta;
                sald[j].num_cuenta=sald[j+1].num_cuenta;
                sald[j+1].num_cuenta=aux;

                auxf=sald[j].credito_max;
                sald[j].credito_max=sald[j+1].credito_max;
                sald[j+1].credito_max=auxf;

                auxf=sald[j].saldo;
                sald[j].saldo=sald[j+1].saldo;
                sald[j+1].saldo=auxf;

                strcpy(auxc,sald[j].razon_social);
                strcpy(sald[j].razon_social,sald[j+1].razon_social);
                strcpy(sald[j+1].razon_social,auxc);

                fwrite(&sald[j],sizeof(saldos),1,fp);
            }
        }
    }
    fclose(fp);
    return x;
}

void LeerValorLogico(fecha fech[])
{
    int validacion;
    do
    {
        printf("\nIngrese un dia: ");
        scanf("%d",&fech[0].dia);
        printf("Ingrese un mes: ");
        scanf("%d",&fech[0].mes);
        printf("Ingrese un anio: ");
        scanf("%d",&fech[0].anio);
        validacion=ValidarFecha(fech);
    }while(validacion!=1);
}

int DIAS (fecha fech[])
{
    int d;
    switch(fech[0].mes)
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
            if((fech[0].anio%4==0&&fech[0].anio%100!=0)||(fech[0].anio%400==0))
                d=29;
            else
                d=28;
            break;
    }
    return d;
}

int ValidarFecha (fecha fech[])
{
    int c,dias;
    if (fech[0].mes<1||fech[0].mes>12)
        c=0;
    dias=DIAS(fech);
    if(fech[0].dia<=dias)
        c=1;
    else
        c=0;
    return c;
}

int lee_control(int i,int s,int n)
{
    int dato;
    do
    {
        if(n==1)printf("\nIngrese el dia: ");
        if(n==2)printf("\nIngrese el mes: ");
        if(n==3)printf("\nIngrese el anio: ");
        scanf("%d",&dato);
    }while(dato<i||dato>s);
    return dato;
}

void ListarCuentas(saldos vc[], int ce,fecha fech[])
{
    int i;
    system("cls");
    printf("FECHA INGRESADA: %d/%d/%d",fech[0].dia,fech[0].mes,fech[0].anio);
    printf("\n\nLISTADO DE CUENTAS\n");
    printf("--------------------\n\n");
    printf("%-21s %s         %s     %s\n","NUMERO DE CUENTA", "RAZON SOCIAL","CREDITO MAX","SALDO");
    printf("%-21s %s    %s    %s\n","----------------", "------------","-----------","-----");
    for (i=0;i<ce;i++)
    {
        printf("%d           %s          %0.2f          %0.2f\n", vc[i].num_cuenta, vc[i].razon_social,vc[i].credito_max,vc[i].saldo);
    }
    printf("\n");
    system("Pause");
}

int cargarmovimientos(saldos sald[],movimientos mov[],int n,nuevas nuev[],fecha fech[])
{
    int dato,pos,x=0,i=0,nueva;
    FILE*fp2;
    fp2=fopen("MOVIM.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo");
        exit(1);
    }
    printf("\nIngrese el numero de cuenta[8 digitos/SALIDA=0]: ");
    scanf("%d",&dato);
    while(dato!=0)
    {
        pos=buscar(sald,dato,n);
        if(pos!=-1)
        {
            mov[x].num_cuenta=dato;
            do
            {
                printf("\nIngrese el codigo de operacion[R=retiro/D=deposito]: ");
                fflush(stdin);
                scanf("%c",&mov[x].cod_operacion);
                mov[x].cod_operacion=toupper(mov[x].cod_operacion);
            }while(mov[x].cod_operacion!='R'&&mov[x].cod_operacion!='D');
            do
            {
                printf("\nIngrese el importe: ");
                scanf("%f",&mov[x].importe);
            }while(mov[x].importe<0);
            if(mov[x].cod_operacion=='R')
                sald[pos].saldo-=mov[x].importe;
            else
                sald[pos].saldo+=mov[x].importe;
            fwrite(&mov[x],sizeof(movimientos),1,fp2);
            x++;
        }
        else
        {
            nueva=VeriCuenta(sald,n,dato);
            if(nueva==1)
            {
                mov[x].num_cuenta=nuev[i].num_cuenta=dato;
                mov[x].cod_operacion='D';
                do
                {
                    printf("\nIngrese la razon social: ");
                    fflush(stdin);
                    gets(sald[n].razon_social);
                }while(strlen(sald[n].razon_social)<1||strlen(sald[n+1].razon_social)>27);
                do
                {
                    printf("\nIngrese el importe: ");
                    scanf("%f",&mov[x].importe);
                }while(mov[x].importe<0);
                nuev[i].credito_max=2*mov[x].importe;
                nuev[i].saldo=mov[x].importe;
                i++;
                n++;
            }
            else
                {
                    printf("Su numero de cuenta no existe y tampco puede ser agregada");
                    system("pause");
                }
            fwrite(&mov[x],sizeof(movimientos),1,fp2);
        }
        ListarCuentas(sald,n,fech);
        printf("\nIngrese el numero de cuenta[8 digitos/SALIDA=0]: ");
        scanf("%d",&dato);
    }
    fclose(fp2);
    return i;
}

int VeriCuenta(saldos sald[],int n,int dato)
{
    int verificacion;
    if(dato>sald[n-1].num_cuenta)
        verificacion=1;
    else
        verificacion=0;
    return verificacion;
}

void listarCuentasNuevas(nuevas nuev[],int n,fecha fech[])
{
    int x;
    printf("\n\n\n   CUENTAS NUEVAS DEL %d/%d/%d ",fech[0].dia,fech[0].mes,fech[0].anio);
    printf("\nNRO.DE CUENTA    CREDITO MAX    SALDO");
    for(x=0;x<n;x++)
    {
        printf("\n%d            %0.2f            %0.2f",nuev[x].num_cuenta,nuev[x].credito_max,nuev[x].saldo);
    }
}

int buscar(saldos pr[],int cod,int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(pr[i].num_cuenta==cod)
           p=i;
      else
          i++;
  }
  return p;
}

