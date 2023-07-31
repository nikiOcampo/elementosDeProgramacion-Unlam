/*El archivo temperaturas.dat contiene información de las temperaturas registradas en 5 localidades a
lo largo del primer trimestre del año con la siguiente estructura:
• Código Localidad (alfanumérico 10 caracteres)
• Mes (entero 1 a 12)
• Temperatura (float)
Por cada localidad pueden existir varias mediciones para un mismo mes, pero no se sabe la cantidad.
Además, se dispone de un segundo archivo llamado localidades.dat que contiene 5 registros con la información
 de las localidades:
• Código Localidad (alfanumérico 10 caracteres)
• Descripción
Se desea realizar un programa que basado en la información del archivo temperaturas.dat:
a. Genere un listado de temperaturas promedio en cada localidad en cada mes con el siguiente formato
(para ello usar una matriz), es posible que para una localidad mes no se tengan lecturas de temperaturas por lo
 tanto deberá mostrarse con un signo de interrogación.
Localidad Ene Feb Mar Variación Térmica
Mar del Plata 23 32 31 8
Chilecito 30 35 37 7
Mendoza 27 ? ? 0
Calafate ? 11 9 2
b. Grabar un archivo llamado promedios.dat que guarde por cada localidad y cada mes el promedio de temperaturas donde
cada registro contenga: código de localidad, mes y promedio.
c. Grabar un archivo llamado variaciones.dat que por cada localidad guarde la variación térmica (temperatura máxima -
temperatura mínima). Los registros de este archivo contendrán dos datos código de localidad y el valor de la variación.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char Cod_Loc[10];
    int Mes;
    float Temp;
}temperatura;

typedef struct
{
    char Cod_Loc[10];
    char Descrip[30];
}localidad;

typedef struct
{
    char Cod_Loc[10];
    float varia;
}varia;

typedef struct
{
    char Cod_Loc[10];
    int Mes;
    float Prom;
}promedio;

int RecuperarLocalidades(localidad[],int);
int RecuperarTemperaturas(temperatura[],int );
void mostra_local(localidad[],int);
void mostra_temp(temperatura[],int);
void cargar_matriz(float m[][3],localidad[],temperatura[],int,int,promedio[][3]);
int buscar(localidad[],char[],int);

int main()
{
    float m[5][3]={{0}};
    temperatura temp[100];
    localidad local[5];
    promedio prom[5][3];
    int cant1,cant2,x,i;
    cant1=RecuperarLocalidades(local,5);
    cant2=RecuperarTemperaturas(temp,100);
    mostra_local(local,cant1);
    mostra_temp(temp,cant2);
    cargar_matriz(m,local,temp,cant1,cant2,prom);
    FILE*fp3;
    fp3=fopen("promedio.dat","wb");
    if(fp3==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    for(x=0;x<5;x++)
    {
        for(i=0;i<3;i++)
        {
            strcpy(prom[x][i].Cod_Loc,local[x].Cod_Loc);
            prom[x][i].Mes=i+1;
            prom[x][i].Prom=m[x][i];
            fwrite(&prom[x][i],sizeof(promedio),1,fp3);
        }
    }
    fclose(fp3);
    return 0;
}

int RecuperarLocalidades(localidad local[],int n)
{
    FILE*fp;
    int i =0;
    fp=fopen("localidades.dat","rb");
    if (fp!=NULL)
    {
        fread(&local[i], sizeof(localidad),1, fp);
        while (!feof(fp) && i<n)
        {
            i++;
            if (i<n)
                fread(&local[i], sizeof(localidad),1, fp);
        }
        fclose(fp);
    }
    return i;
}

int RecuperarTemperaturas(temperatura temp[],int n)
{
    FILE*fp2;
    int i =0;
    fp2=fopen("temperatura.dat","rb");
    if (fp2!=NULL)
    {
        fread(&temp[i], sizeof(temperatura),1, fp2);
        while (!feof(fp2) && i<n)
        {
            i++;
            if (i<n)
                fread(&temp[i], sizeof(temperatura),1, fp2);
        }
        fclose(fp2);
    }
    return i;
}

void mostra_local(localidad local[],int n)
{
    int x;
    printf("\nLOCALIDADES");
    for(x=0;x<n;x++)
    {
        printf("\nCODIGO:%s   DESCRIPCION:%s",local[x].Cod_Loc,local[x].Descrip);
    }
}

void mostra_temp(temperatura temp[],int n)
{
    int x;
    printf("\nTEMPERATURAS");
    for(x=0;x<n;x++)
    {
        printf("\nCODIGO:%s   MES:%d   TEMPERATURA:%f",temp[x].Cod_Loc,temp[x].Mes,temp[x].Temp);
    }

}

void cargar_matriz(float m[][3],localidad local[],temperatura temp[],int cant_local,int cant_temp,promedio prom[][3])
{
    int x,pos,cont[5][3]={{0}},i;
    float min[5]={0},max[5]={0};
    varia variaciones[5];
    FILE*fp5;
    fp5=fopen("variaciones.dat","wb");
    if(fp5==NULL)
    {
        printf("\n Hay un error con el archivo 5");
        exit(1);
    }
    for(x=0;x<cant_temp;x++)
    {
        if((strcmpi(temp[x].Cod_Loc,"MARDEL")==0)&&(min[0]==0&&max[0]==0))
        {
            min[0]=temp[x].Temp;
            max[0]=temp[x].Temp;
        }
        if((strcmpi(temp[x].Cod_Loc,"CHILE")==0)&&(min[1]==0&&max[1]==0))
        {
            min[1]=temp[x].Temp;
            max[1]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"MENDO")==0&&min[2]==0&&max[2]==0)
        {
            min[2]=temp[x].Temp;
            max[2]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"CALAFA")==0&&min[3]==0&&max[3]==0)
        {
            min[3]=temp[x].Temp;
            max[3]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"BARI")==0&&min[4]==0&&max[4]==0)
        {
            min[4]=temp[x].Temp;
            max[4]=temp[x].Temp;
        }
    }
    for(x=0;x<cant_temp;x++)
    {
        if(strcmpi(temp[x].Cod_Loc,"MARDEL")==0)
        {
            if(temp[x].Temp<min[0])
                min[0]=temp[x].Temp;
            if(temp[x].Temp>max[0])
                max[0]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"CHILE")==0)
        {
            if(temp[x].Temp<min[1])
                min[1]=temp[x].Temp;
            if(temp[x].Temp>max[1])
                max[1]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"MENDO")==0)
        {
            if(temp[x].Temp<min[2])
                min[2]=temp[x].Temp;
            if(temp[x].Temp>max[2])
                max[2]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"CALAFA")==0)
        {
            if(temp[x].Temp<min[3])
                min[3]=temp[x].Temp;
            if(temp[x].Temp>max[3])
                max[3]=temp[x].Temp;
        }
        if(strcmpi(temp[x].Cod_Loc,"BARI")==0)
        {
            if(temp[x].Temp<min[4])
                min[4]=temp[x].Temp;
            if(temp[x].Temp>max[4])
                max[4]=temp[x].Temp;
        }
    }
    //---------------------------------
    printf("\nMAXIMO   MINIMO");//para ver si funciona
    for(x=0;x<cant_local;x++)
    {
        printf("\n%0.2f\t%0.2f",max[x],min[x]);
    }
    //--------------------------------
    for(x=0;x<cant_local;x++)
    {
        strcpy(variaciones[x].Cod_Loc,local[x].Cod_Loc);
        variaciones[x].varia=max[x]-min[x];
        fwrite(&variaciones[x],sizeof(varia),1,fp5);
        //----------------------------------------------
        printf("\nLA LOCALIDAD %s",variaciones[x].Cod_Loc);
        printf("\nPRESENTA UNA VARIACION DE %0.2f",variaciones[x].varia);
        //----------------------------------------------
    }
    fclose(fp5);
    for(x=0;x<cant_temp;x++)
    {
        pos=buscar(local,temp[x].Cod_Loc,cant_local);
        m[pos][temp[x].Mes-1]+=temp[x].Temp;
        cont[pos][temp[x].Mes-1]++;
    }
    printf("\n");
    printf("\nSUMA DE TEMPERATURAS POR MES:");
    printf("\nENERO: FEBRERO: MARZO:\n");
    for(x=0;x<5;x++)
    {
        for(i=0;i<3;i++)
        {
            if(m[x][i]==0)
                printf("  ?  \t");
            else
                printf("%0.2f\t",m[x][i]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\nCANTIDAD DE TEMPRATURAS CARGADAS POR MES:");
    printf("\nENERO: FEBRERO: MARZO:\n");
    for(x=0;x<5;x++)
    {
        for(i=0;i<3;i++)
        {
            if(cont[x][i]==0)
                printf(" ? \t");
            else
                printf("%d\t",cont[x][i]);
        }
        printf("\n");
    }

    printf("\n");
    printf("\nPROMEDIO DE TEMPERATURAS POR MES: ");
    printf("\nENERO: FEBRERO: MARZO:\n");
    for(x=0;x<5;x++)
    {
        for(i=0;i<3;i++)
        {
            if(cont[x][i]!=0)
            {
                m[x][i]=(float)m[x][i]/cont[x][i];
                printf("%0.2f\t",m[x][i]);
            }
            else
            {
                printf("  ?  \t");
            }
        }
        printf("\n");
    }
}

int buscar(localidad local[],char cod[],int n)
{
  int p=-1,i=0;
  while(p==-1&&i<n)
  {
      if(strcmpi(local[i].Cod_Loc,cod)==0)
           p=i;
      else
          i++;
  }
  return p;
}

