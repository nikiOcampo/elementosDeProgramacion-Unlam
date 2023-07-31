/*5.1.12 Calcular el factorial de un número ingresado por teclado.
 El factorial se calcula como el producto de todos los enteros positivos desde 1 hasta el número. En matemática
el factorial se expresa con el símbolo. Por ejemplo, el factorial de 5 es 120 ya que 5! = 1 x 2 x 3 x 4 x 5 =120*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,num,factorial;
    printf("Ingrese un numero: ");
    scanf("%d",&num);
    for(i=1;i<=num;i++)
    {
        if(i==1)
        factorial=1;
        else
        factorial=i*factorial;
    }
    printf("El factorial de %d es = %d",num,factorial);
    return 0;
}
