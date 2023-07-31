/*Realizar un programa que permite actualizar una lista de precios en forma masiva, ingresando un porcentaje de incremento.
El archivo original se llama precios.dat y fue generado utilizando la siguiente estructura:
• Código (entero)
• Precio (float)
• Descripción (de hasta 50 caracteres)
No se sabe la cantidad de registros del archivo.
Se solicita generar un nuevo archivo llamado Precios_actualizados.dat.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int codigo;
    float precio;
    char descripcion[50];
}producto;

void mostrarlistas(int, producto[]);
void datosactualizados(producto[], int, int);
int Datos(producto[]);

int main()
{
    //FILE*fp;
    producto pro[100];
    int cant, incremento;
    cant=Datos(pro);
    printf("\n Ingrese el porcentaje de incremento deseado:");
    scanf("%d", &incremento);
    datosactualizados(pro, cant, incremento);
    mostrarlistas(cant, pro);
    return 0;
}
int Datos(producto pro[])
{
    int i=0;
    FILE*fp;
    fp=fopen("Precios.dat", "wb");
    if(fp==NULL)
    {
        printf("\n El archivo tiene algun error");
        exit(1);
    }
    printf("\n Ingrese el codigo del producto[use 0 para salir]:");
    scanf("%d", &pro[i].codigo);
    while(pro[i].codigo!=0)
    {
        do
        {
            printf("\n Ingrese el precio del producto:");
            scanf("%f", &pro[i].precio);
        }while(pro[i].precio<0);
        do
        {
            printf("\n Ingrese la descripcion del producto:");
            getchar();
            gets(pro[i].descripcion);
        }while(strlen(pro[i].descripcion)<1||strlen(pro[i].descripcion)>50);
        fwrite(&pro[i], sizeof(producto), 1, fp);
        i++;
        printf("\n Ingrese el codigo del producto[use 0 para salir]:");
        scanf("%d", &pro[i].codigo);
    }
    fclose(fp);
    return i;
}
void datosactualizados(producto pro[], int n, int b)
{
    int i;
    FILE*fp2;
    fp2=fopen("precios_actualizados.dat", "wb");
    if(fp2==NULL)
    {
        printf("\n El archivo tiene algun error");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        pro[i].precio+=(pro[i].precio*b)/100;
        fwrite(&pro[i], sizeof(producto), 1, fp2);
    }
    fclose(fp2);
}
void mostrarlistas(int n, producto pro[])
{
    int i=0;
    FILE*fp2;
    FILE*fp;
    fp=fopen("Precios.dat", "rb");
    if(fp==NULL)
    {
        printf("\n El archivo tiene algun error");
        exit(1);
    }
    fp2=fopen("precios_actualizados.dat", "rb");
    if(fp2==NULL)
    {
        printf("\n El archivo tiene algun error");
        exit(1);
    }
    fread(&pro[i], sizeof(producto), 1, fp);
    printf("\nLista de precios sin actualizar:\n\n ");
    while(!feof(fp))
    {
        printf("\n CODIGO    : %d", pro[i].codigo);
        printf("\n PRECIO    : %.2f", pro[i].precio);
        printf("\n DESCRIPCION : %s", pro[i].descripcion);
        i++;
        printf("\n\n\n\n");
        fread(&pro[i], sizeof(producto), 1, fp);
    }
    fclose(fp);
    system("pause");
    system("cls");
    i=0;
    fread(&pro[i], sizeof(producto), 1, fp2);
    printf("\nLista de precios actualizados:\n\n ");
    while(!feof(fp2))
    {
        printf("\n CODIGO    : %d", pro[i].codigo);
        printf("\n PRECIO    : %.2f", pro[i].precio);
        printf("\n DESCRIPCION : %s", pro[i].descripcion);
        i++;
        printf("\n\n\n\n");
        fread(&pro[i], sizeof(producto), 1, fp2);
    }
}
