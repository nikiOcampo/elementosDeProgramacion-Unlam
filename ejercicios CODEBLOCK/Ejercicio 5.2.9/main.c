/*Se desea realizar un programa para calcular el sueldo final a pagar a
cada empleado de una empresa. De cada uno se tiene, sueldo básico, antigüedad,
 cantidad de hijos y estudios superiores (‘S’ o ‘N’). Además, se conocen los porcentajes de
 aumento del sueldo que dependen de los siguientes factores:
• Si el empleado tiene más de 10 años de antigüedad: aumento del 10%
• Si el empleado tiene más de 2 hijos: aumento del 10%, si solo tiene uno 5%
• Si el empleado posee estudios superiores: aumento del 5%
Luego de ingresar los datos de un empleado se debe preguntar si se desea ingresar
otro empleado o no. Se termina la carga cuando no se deseen ingresar más empleados.
Determinar:
a. Por cada empleado: número de empleado, el sueldo básico y el nuevo sueldo.
b. Sueldo nuevo promedio de la empresa.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sueldo_basico,antiguedad,hijos,num_empleado,cont=0;
    float aumento1, aumento2, aumento3,new_sueldo,sueldo_promedio,sum_sueldos=0;
    char estudios,otro_empleado;
    do
    {
        printf("Ingrese el numero de empleado: ");
        scanf("%d",&num_empleado);
        cont++;
        printf("Ingrese el sueldo basico de su empleado: ");
        scanf("%d",&sueldo_basico);
        printf("\nIngrese la antiguedad de su empleado: ");
        scanf("%d",&antiguedad);
        printf("\nIngrese la cantidad de hijos de su empleado: ");
        scanf("%d",&hijos);
        printf("\nIngrese si su empleador tiene estudios superiores con'S'para si,'N' para no(RESPETAR MAYUSCULA): ");
        fflush(stdin);
        scanf("%c",&estudios);
        if(antiguedad>10)
            aumento1=sueldo_basico*0.1;
        else
            aumento1=0;
        if(hijos>=2)
            aumento2=sueldo_basico*0.1;
        else
        {
            if(hijos==1)
            aumento2=sueldo_basico*0.05;
            else
            aumento2=0;
        }
        if(estudios=='S')
            aumento3=sueldo_basico*0.05;
        else
            aumento3=0;
        new_sueldo=sueldo_basico+aumento1+aumento2+aumento3;
        sum_sueldos+=new_sueldo;
        printf("\n\nNum de empleado:%d \nSueldo basico:%d \nNuevo sueldo:%f",num_empleado,sueldo_basico,new_sueldo);
        printf("\n\nDesea ingresar otro empleado 's'para si, 'n'para no (RESPETAR MINUSCULA): ");
        fflush(stdin);
        scanf("%c",&otro_empleado);
    }while(otro_empleado!='n');
    sueldo_promedio=sum_sueldos/cont;
    printf("\nSueldo nuevo promedio de la empresa: %f",sueldo_promedio);
    return 0;
}
