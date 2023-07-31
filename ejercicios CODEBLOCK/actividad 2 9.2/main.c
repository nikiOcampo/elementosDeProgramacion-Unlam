//Trabajo con Ejercicio 9.2
// solo modificar
// 1) Cargarlo en CODE BLOCK y en pantalla siempre debe verse Alumno Nombre ________ Apellido_________
// 2) Este programa tiene validaciones, con (do while) que se pueden realizar con funciones que validen, permitiendo mejorarlo
// 3) Cuando termine envie por Mensaje el .c para probar los cambios, controle que funcione Gracias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int   Codigo;
  float Precio;
  int   Stock;
}medicamento;

int INGRESO(medicamento [],int);
int BUSQUEDA_MEDI(int ,medicamento [],int);
void INFORME(medicamento[],int);
int validar_int (int,int,int);

int main()
{
    medicamento a[50];
    int cant,cod,pos;
    char op[3]="SI";
    printf("                                                    OCAMPO NCIOLE");
    cant=INGRESO(a,50);
    while(strcmpi(op,"SI")==0)
    {
     system("cls");
     printf("                                                    OCAMPO NCIOLE");
     printf("\n Ingrese Codigo de Medicamento a Buscar :");
     scanf("%d",&cod);
     pos = BUSQUEDA_MEDI(cod,a,cant);
     if(pos!=-1)
        printf("\n El Medicamento con Codigo = %d tien un precio de %6.2f",a[pos].Codigo,a[pos].Precio);
     else
        printf ("\n Codigo Medicamente Inexistente  ");
     do{
       printf("\n\n Continua con la Consulta [SI o NO]");
       fflush(stdin);
       scanf("%s",op);
       }while(strcmpi(op,"SI")==0&&strcmpi(op,"NO")==0);
    }
    INFORME(a,cant);
    return 0;
}

int INGRESO(medicamento a[],int n)
{
  char continua[3]="SI";
  int x=0;
  while(strcmpi(continua,"SI")==0)
  {
      a[x].Codigo=validar_int(100,999,1);
   /*do
   {
    printf("\n Ingrese Codigo Medicamento :");
    scanf("%d",&a[x].Codigo);
   }while(a[x].Codigo<100||a[x].Codigo>999);*/
   do
   {
    printf("\n Ingrese Precio Medicamento :");
    scanf("%f",&a[x].Precio);
   }while(a[x].Precio<1);
   do
   {
    printf("\n Ingrese stock  Medicamento :");
    scanf("%d",&a[x].Stock);
   }while(a[x].Stock<1);
   do
   {
    printf("\n \n \n       Continua Con la Carga:");
    fflush(stdin);
    gets(continua);
   }while(strcmpi(continua,"SI")!=0&&strcmpi(continua,"NO")!=0);
   system("cls");
   printf("                                                    OCAMPO NCIOLE");
   x++;
  }
  return x;
};
int BUSQUEDA_MEDI(int c,medicamento m[],int n)
{
  int pos=-1,i=0;
  while(pos==-1&&i<n)
  {
      if(c==m[i].Codigo) pos=i;
      else i++;
  }
  return pos;
};
void INFORME(medicamento a[],int can)
{
  int i;
  printf("\n   LISTADO DE MEDICAMENTOS CON STOCK MENOR A 10 UNIDADES  \n");
  printf("\n   CODIGO      PRECIO     STOCK ");
  for(i=0;i<can;i++)
  {
   if(a[i].Stock<10)
       printf("\n   %d       %8.2f         %d",a[i].Codigo,a[i].Precio,a[i].Stock);
  }

};

int validar_int (int i,int s,int n);
{
    int dato;
    if(n==1)printf("\nIngrese el codigo del medicamento:");
    scanf("%d",&dato);
    return dato;
}
