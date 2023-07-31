#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num1, Num2, Suma, Producto, Resto;
    float Cociente;
    printf("Ingrese el primer numero: ");
    scanf("%d",&Num1);
    printf("\nIngrese el segundo numero: ");
    scanf("%d", &Num2);
    Suma= Num1+Num2;
    Producto= Num1*Num2;
    Cociente= (float) Num1/Num2;
    Resto= Num1%Num2;
    printf("\n\nLa suma es: %d ",Suma);
    printf("\n\nEl producto es: %d",Producto);
    printf("\n\nEl cociente es: %f", Cociente);
    printf("\n\nEl resto es: %d", Resto);
    return 0;
}
