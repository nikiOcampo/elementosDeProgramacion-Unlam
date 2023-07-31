#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_h,imp,sen=0;
    char cod_p;
    printf("Ingrese el codigo de prestacion: ");
    scanf("%c",&cod_p);
    printf("Ingrese el numero de historia: ");
    scanf("%d",&num_h);
    switch(cod_p)
    {
    case 'A' :
        imp=20;
        break;
    case 'D' :
        imp=40;
        break;
    case 'F' :
        imp=60;
        break;
    case 'M' :
    case 'T' :
        imp=150;
        break;
    default: sen=1;
    printf("El codigo NO corresponde");
    }
    if(sen==0)
        printf("Numero de historia %d Codigo de paciente: %c Importe a pagar: %d",num_h,cod_p,imp);
    return 0;
}
