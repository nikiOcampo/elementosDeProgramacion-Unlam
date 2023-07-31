/*Ingresar diversos quintetos de números positivos de 1 cifra c/u,
finalizando cuando las cinco cifras leídas sean iguales a cero.
Determinar e informar cuantos de los quintetos ingresados
 han formado números capicúas 'triples' y cuantos 'quíntuples'.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cifra1,cifra2,cifra3,cifra4,cifra5,contcapicua3=0,contcapicua5=0;
    do
    {
        printf("\n\nIngrese un quinteto de numeros positivos de 1 cifra: "),
        scanf("%d %d %d %d %d",&cifra1,&cifra2,&cifra3,&cifra4,&cifra5);
        if(cifra1==0&&cifra2==0&&cifra3==0&&cifra4==0&&cifra5==0)
            printf("FIN DEL PROGRAMA");
        else
        {
            if(cifra1==cifra5&&cifra2==cifra4)
            contcapicua5++;
            else
            {
                if(cifra1==cifra3||cifra2==cifra4||cifra3==cifra5)
            contcapicua3++;
            }
        }
    }while(cifra1!=0&&cifra2!=0&&cifra3!=0&&cifra4!=0&&cifra5!=0);
    printf("\n%d de los quintentos ingresados han formado capicuas triples", contcapicua3);
    printf("\n%d de los quintentos ingresados han formado capicuas quintuples", contcapicua5);
    return 0;
}
