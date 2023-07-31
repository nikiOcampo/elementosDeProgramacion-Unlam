#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Precio_Prod, Cod_Desc;
    float Desc, Precio_final;
    printf("Ingrese el precio original: ");
    scanf("%d", &Precio_Prod);
    printf("\nIngrese el codigo de descuento: ");
    scanf("%d", &Cod_Desc);
    Desc= (float) Precio_Prod*0.2;
    Precio_final= (float) Precio_Prod-(Desc*Cod_Desc);
    printf("\nEl precio final es de: $%f", Precio_final);
    return 0;
}
