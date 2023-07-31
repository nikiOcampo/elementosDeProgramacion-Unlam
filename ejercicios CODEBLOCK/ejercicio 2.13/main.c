#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Num, Cifra1, Resto1, Cifra2, Resto2, Cifra3, Cifra4, New_num1, Cifra5, Cifra6, New_num2, Cifra7, Cifra8, Num_final;
    printf("Ingrese un numero de 4 cifras: ");
    scanf("%d", &Num);
    Cifra1= Num/1000;
    Resto1= Num%1000;
    Cifra2= Resto1/100;
    Resto2= Resto1%100;
    Cifra3= Resto2/10;
    Cifra4= Resto2%10;
    New_num1= Cifra1+Cifra2+Cifra3+Cifra4;
    Cifra5= New_num1/10;
    Cifra6= New_num1%10;
    New_num2= Cifra5+Cifra6;
    Cifra7= New_num2/10;
    Cifra8= New_num2%10;
    Num_final= Cifra7+Cifra8;
    printf("\nEl numero final es: %d",Num_final);
    return 0;
}
