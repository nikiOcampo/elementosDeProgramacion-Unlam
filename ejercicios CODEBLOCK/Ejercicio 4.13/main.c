#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_cat;
    printf("Ingrese el numero de catalogo: ");
    scanf("%d", &num_cat);
    if (num_cat>=1200&&num_cat<=90000)
    {
        if(num_cat>=12121&&num_cat<=18081)
            printf("El catalogo es defectuoso");
        else
        {
            if(num_cat>=30012&&num_cat<=45565)
                printf("El catalogo es defectuoso");
            else
            {
                if(num_cat>=67000&&num_cat<=68000)
                    printf("El catalogo es defectuoso");
                else
                    printf("El catalogo NO es deftuoso");
            }
        }
    }
    else
        printf("FUERA DE CATALOGO");
    return 0;
}
