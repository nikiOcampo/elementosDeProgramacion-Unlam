/*Se dispone de un archivo llamado Rating.dat que guarda la información de los puntos obtenidos de rating en
 los distintos programas de canales de cable a lo largo del día. Cada registro contiene:
• Número de canal (entero)
• Programa (texto de 35 caracteres máximo)
• Rating (float)
El archivo se encuentra ordenado por canal.
Se solicita informar:
a. Aquellos canales que obtengan menos de 15 puntos en total.
b. El canal más visto.
c. Generar un archivo con el promedio de rating de cada canal que incluya dos campos:
• Número de canal.
• Promedio.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num_canal;
    char descripcion[35];
    float raiting;
}raitings;

typedef struct
{
    int num_canal;
    float promedio;
}promedios;

int main()
{
    //SUPONIENDO QUE TENEMOS UN ARCHIVO YA CARGADO
    FILE*fp;
    FILE*fp2;
    raitings registro;
    promedios prom[100];
    int i=0,cont,anterior,canalmayor;
    float acumul=0,mayor;
    fp=fopen("Raitings.dat","rb");
    if(fp==NULL)
    {
        printf("\n Hay un error con el archivo 1");
        exit(1);
    }
    fp2=fopen("promedios.dat","wb");
    if(fp2==NULL)
    {
        printf("\n Hay un error con el archivo 2");
        exit(1);
    }
    fread(&registro,sizeof(raitings),1,fp);
    while(!feof(fp))
    {
        acumul=0;
        cont=0;
        anterior=registro.num_canal;
        while(anterior==registro.num_canal&&!feof(fp))
        {
            acumul+=registro.raiting;
            cont++;
            fread(&registro,sizeof(raitings),1,fp);
        }
        if(acumul<15)
            printf("\nEl canal %d tiene menos de 15 puntos",registro.num_canal);
        if(i==0||acumul>mayor)
        {
            mayor=acumul;
            canalmayor=i;
        }
        prom[i].num_canal=anterior;
        prom[i].promedio=acumul/cont;
        fwrite(&prom[i],sizeof(promedios),1,fp2);
        i++;
    }
    printf("\nEl canal con mayor raiting fue %d con un puntaje de %0.2f",canalmayor,mayor);
    fclose(fp);
    fclose(fp2);
    return 0;
}
