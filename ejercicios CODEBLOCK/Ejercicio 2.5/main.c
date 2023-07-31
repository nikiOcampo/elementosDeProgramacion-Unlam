#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Cant_tarros, T_1Lt, T_4Lt, T_20Lt;
    printf("Ingrese la cantidad de tarros: ");
    scanf("%d",&Cant_tarros);
    T_1Lt= Cant_tarros*0.5;
    T_4Lt= Cant_tarros*0.3;
    T_20Lt= Cant_tarros-T_1Lt-T_4Lt;
    printf("\n\nTarros de 1 litro:%d",T_1Lt);
    printf("\n\nTarros de 4 litros: %d",T_4Lt);
    printf("\n\nTarros de 20 litros: %d",T_20Lt);
    return 0;
}
