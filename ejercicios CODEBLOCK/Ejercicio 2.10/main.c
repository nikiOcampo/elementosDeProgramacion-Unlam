#include <stdio.h>
#include <stdlib.h>

int main()
{
    float Radio, Pi, Superficie, Perimetro, Volumen;
    printf("Ingrese el Radio del circulo: ");
    scanf ("%f", &Radio);
    Pi= 3.141592;
    Superficie= Pi*Radio*Radio;
    Perimetro= 2*Pi*Radio;
    Volumen= 4/3 * Pi * Radio*Radio*Radio;
    printf("\nLa superficie es: %f",Superficie);
    printf("\nEl perimetro es: %f",Perimetro);
    printf("\nEl volumen es: %f", Volumen);
    return 0;
}
