/*Confeccionar un programa que pueda ingresar una secuencia de caracteres hasta que se digite un *.
Se desea obtener e informar cuantos caracteres ingresados son numéricos y cuantos alfabéticos.
Estos últimos tienen que mostrarse separados por mayúsculas y minúsculas.
También informar la cantidad de otros símbolos que no sean ni letras ni números.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mayusc=0,minusc=0,simb=0,num=0;
    char variable='0';
    do{
        printf("\n\nIngrese una secuencia de caracteres: ");
        scanf("%c",&variable);
        getchar();
        printf("\nEl codigo asociado es de %d",variable);
        if(variable<=57&&variable>=48)/*rango de digitos*/
            num++;
        else
        {
            if(variable<=90&&variable>=65)/*rango de las mayusculas*/
                mayusc++;
            else
            {
                if(variable>=97&&variable<=122)/*rango de las minusculas*/
                    minusc++;
                else
                    simb++;/*si no esta en ningun otro rango es porque es un simbolo*/
            }
        }
    }while(variable!='*');
    printf("\n\nLa cantidad de caracteres numericos es de: %d",num);
    printf("\nLa cantidad de carcteres alfabeticos es de: %d", mayusc+minusc);
    printf("\nLa cantidad de MAYUSCULAS en los caracteres alfabeticos es de:%d ", mayusc);
    printf("\nLa cantidad de MINUSCULAS en los carcateres alfabeticos es de: %d",minusc);
    printf("\nLa cantidad de simbolos ingresados es de: %d",simb);
    return 0;
}
