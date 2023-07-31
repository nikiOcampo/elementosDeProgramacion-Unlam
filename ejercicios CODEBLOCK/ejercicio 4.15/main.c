#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Cant_DVD, Subprecio, precio, caja_10,caja_50,R1,R2,R3,R4,R5;
    printf("Ingrese la cantidad de DVDs que compro: ");
    scanf("%d", &Cant_DVD);
    if(Cant_DVD<10)
        precio=Cant_DVD*15;
    else
    {
        if(Cant_DVD<50)
        {
            caja_10=Cant_DVD/10;
            R1=Cant_DVD%10;
            precio=caja_10*120+R1*15;

        }
        else
        {
            if(Cant_DVD<100)
            {
                caja_50=Cant_DVD/50;
                R2=Cant_DVD%50;
                caja_10=R2/10;
                R3=R2%10;
                precio=caja_50*500+caja_10*120+R3*15;
            }

            else
            {
                if(Cant_DVD<500)
                {
                    caja_50=Cant_DVD/50;
                    R4=Cant_DVD%50;
                    caja_10=R4/10;
                    R5=R4%10;
                    Subprecio=caja_50*500+caja_10*120+R5*15;
                    precio=Subprecio-(Subprecio*0.1);
                }
                else
                    printf("NO SE ACEPTA LA COMPRA");
            }
        }
    }
    printf("\nEl precio es de %d",precio);
    return 0;
}
