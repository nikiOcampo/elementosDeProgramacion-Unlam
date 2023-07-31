/*Se ingresan datos de los empleados de una empresa. Por cada empleado se ingresa:
• Legajo (entero entre 1000 y 5000)
• Sueldo básico (float mayor a 1000)
• Antigüedad en años (mayor o igual a 0)
• Sexo (‘M' o 'F')
• Categoría (entero entre 1 a 5)
Por cada empleado ingresado se debe calcular el sueldo final a abonar sabiendo que:
• Las Categorías 2 y 3 tienen $500 de bonificación.
• La Categoría 4 tiene 10% de bonificación.
• La Categoría 5 tiene 30% de bonificación.
• Si la antigüedad es mayor a 10 años recibe una bonificación del 10% adicional.
Todos los datos ingresados deben ser validados. El ingreso finaliza con un legajo igual a cero.
Informar:
• El sueldo a abonar a cada empleado.
• Cantidad de empleados de más de 10 años de antigüedad.
• El mayor sueldo y el legajo del empleado que cobra dicho sueldo.
• Cantidad de hombres y de mujeres.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int legajo, antiguedad, categoria, mayor_legajo ;
    int cont_antiguedad,cont_mujeres, cont_hombres ;
    float sueldo_basico, sueldo_nuevo, sueldo_final, mayor_sueldo;
    mayor_sueldo=cont_antiguedad=cont_mujeres=cont_hombres=0;
    char sexo;
    do
    {
        printf("Ingrese el legajo del empleado[0 para finalizar]:\n");
        scanf("%d",&legajo);
        if (legajo!=0 && (legajo<1000||legajo>5000))
            printf("\nLEGAJO DEBE ESTAR ENTRE 1000 Y 5000\n ");
        if(legajo==0)
            printf("FIN DEL PROGRAMA");
    }while(legajo!=0 && (legajo<1000 || legajo>5000));
    while(legajo!=0)
    {
        do
        {
            printf("\n\nIngrese el sueldo basico del empleado:");
            scanf("%f",&sueldo_basico);
            if(sueldo_basico<=1000)
                printf("\nEL SUELDO DEBE SER MAYOR A $1000");
        }while(sueldo_basico<=1000);
        do
        {
            printf("\nIngrese la antiguedad del empleado: ");
            scanf("%d",&antiguedad);
            if (antiguedad<0)
                printf("LA ANTIGUEDAD DEBE SER MAYOR O IGUAL A CERO");
        }while(antiguedad<0);
        do
        {
            printf("Ingrese el sexo del empleado [F=femenino/M=masculino]: ");
            fflush(stdin);
            scanf("%c",&sexo);
            sexo=toupper(sexo);
            if(sexo!='M'&& sexo!='F')
                printf("INGRESE UN SEXO VALIDO\n");
        }while(sexo!='M'&& sexo!='F');
        do
        {
            printf("\nIngrese la categoria del empleado: ");
            scanf("%d",&categoria);
            if(categoria<1||categoria>5)
                printf("\nRECUERDE INGRESAR UNA CATEGORIA ENTRE 1 Y 5");
        }while(categoria<1||categoria>5);
        switch(categoria)
        {
            case 2:
            case 3:
                sueldo_nuevo= sueldo_basico+500;
                break;
            case 4:
                sueldo_nuevo=sueldo_basico+(sueldo_basico*0.1);
                break;
            case 5:
                sueldo_nuevo=sueldo_basico+(sueldo_basico*0.3);
                break;
            case 1:
                sueldo_nuevo=sueldo_basico;
                break;
        }
        sueldo_final=sueldo_nuevo;
        if(antiguedad>10)
            {
                sueldo_final+=(sueldo_nuevo*0.1);
                cont_antiguedad++;
            }
        else
            sueldo_final=sueldo_nuevo;
        printf("\nEl sueldo a abonar a dicho empleado es de %f",sueldo_final);
        if (sueldo_final>mayor_sueldo)
        {
            mayor_sueldo=sueldo_final;
            mayor_legajo=legajo;
        }
        if(sexo=='M')
            cont_hombres++;
        else
            cont_mujeres++;
        do
        {
            printf("\nIngrese el legajo del empleado[0 para finalizar]:\n");
            scanf("%d",&legajo);
            if (legajo!=0 && (legajo<1000||legajo>5000))
                printf("\nLEGAJO DEBE ESTAR ENTRE 1000 Y 5000\n ");
            if(legajo==0)
                printf("\nFIN DEL PROGRAMA");
        }while(legajo!=0 && (legajo<1000 || legajo>5000));

    }
    printf("\n\nLa cantidad de empleados de mas de 10 años de antiguedad son: %d", cont_antiguedad);
    printf("\nEl mayor sueldo es de %f correspondiente al empleado de legajo: %d", mayor_sueldo,mayor_legajo);
    printf("\nLa cantidad de empleados masculinos es de %d , y femeninas es de %d", cont_hombres,cont_mujeres);
    return 0;
}
