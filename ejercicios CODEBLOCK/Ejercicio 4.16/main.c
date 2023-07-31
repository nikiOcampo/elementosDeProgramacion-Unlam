#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cod,cant,caja_10,unidad,sen=0;
    float imp_a_pagar;
    printf("Ingrese el codigo de su compra: ");
    scanf("%d",&cod);
    printf("\nIngrese la cantidad comprada: ");
    scanf("%d",&cant);
    switch(cod)
    {
    case 1:
    case 10:
    case 100:
        imp_a_pagar=cant*10;
        break;
    case 2:
    case 22:
    case 222:
        caja_10=cant/10;
        unidad= cant%10;
        imp_a_pagar=caja_10*65 + unidad*7;
        break;
    case 3:
    case 33:
        imp_a_pagar=cant*3;
        if(cant>10)
            imp_a_pagar=imp_a_pagar*0.9;
        break;
    case 4:
    case 44:
        imp_a_pagar=cant*1;
    default: sen=1;
    printf("\n Codigo no correspondiente");
    }
    if (sen==0) printf("\n\n ARTICULO %d CANTIDAD %d IMPORTE A PAGAR %0.2f",cod,cant,imp_a_pagar);
    return 0;
}
