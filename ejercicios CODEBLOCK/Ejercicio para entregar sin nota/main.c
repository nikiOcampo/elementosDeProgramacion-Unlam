/*La veterinaria “Don Ramon” necesita llevar las fichas de las 2000 mascotas que atiende.
Por cada mascota se ingresan los siguientes datos:
- Código (entero entre 1 y 2000 correspondiente al dueño.)
- Tipo: P = Perro, G = Gato, T = Tortuga, A = aves, R= Animales raros
- Esta vacunado S/N (carácter)
- Tiene enfermedades declaradas S/N (carácter)
Finaliza la carga con un tipo = a ‘X’
Validar todos los datos que se ingresan por teclado.
Se nos pide informar:
- Qué Tipo de mascota es la que más atienden.
- Que cantidad de animales raros y con Enfermedades declaradas ‘S’.
- Promedio de edad de los Perros y Gatos que atienden sobre el total de mascotas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int codigo;
    int cont_perros, cont_gatos, cont_tortugas, cont_aves, cont_raros, cont_pyg, cont_rarosenfermos,cont_total;
    char tipo, vacunacion, enfermedad;
    float promedio;
    cont_aves=cont_gatos=cont_perros=cont_pyg=cont_raros=cont_rarosenfermos=cont_tortugas=cont_total=0;

        do
        {
            printf("\nIngrese el tipo de su mascota: ");
            fflush(stdin);
            scanf("%c",&tipo);
            tipo=toupper(tipo);
            if(tipo!='P' && tipo!='G' && tipo!='T'&& tipo!='A'&& tipo!='R'&& tipo!='X')
                printf("\nEL TIPO INGRESADO ES INCORRECTO");
            if(tipo=='X')
                printf("\nFIN DE LA CARGA");
        }while(tipo!='P'&& tipo!='G'&& tipo!='T'&& tipo!='A'&& tipo!='R'&& tipo!='X');

        while(tipo!='X')
        {
            do
            {
                printf("\nIngrese el codgio de su mascota: [ENTRE 1 Y 2000]: ");
                scanf("%d",&codigo);
                if(codigo<1||codigo>2000)
                    printf("CODIGO INCORRECTO, RESPETE EL RANGO");
            }while(codigo<1||codigo>2000);
            do
            {
                printf("\nIndique si su mascota esta vacunada[S=si/N=no]: ");
                fflush(stdin);
                scanf("%c",&vacunacion);
                vacunacion=toupper(vacunacion);
                if (vacunacion!='S'&& vacunacion!='N')
                    printf("RECUERDE UTILIZAR S PARA SI Y N PARA NO");
            }while(vacunacion!='S'&& vacunacion!='N');
            do
            {
                printf("Indique si mascota tiene una enfermedad [S=si/N=no]: ");
                fflush(stdin);
                scanf("%c",&enfermedad);
                enfermedad=toupper(enfermedad);
                if (enfermedad!='S' && enfermedad!='N')
                    printf("RECUERDE UTILIZAR S PARA SI Y N PARA NO");
            }while(enfermedad!='S' && enfermedad!='N');
            switch(tipo)
            {
                case 'P':
                    cont_perros++;
                    break;
                case 'G':
                    cont_gatos++;
                    break;
                case 'T':
                    cont_tortugas++;
                    break;
                case 'A':
                    cont_aves++;
                    break;
                case 'R':
                    cont_raros++;
                    break;
            }
            if(tipo=='R' && enfermedad=='S')
                cont_rarosenfermos++;
            do
            {
                printf("\nIngrese el tipo de su mascota: ");
                fflush(stdin);
                scanf("%c",&tipo);
                tipo=toupper(tipo);
                if(tipo!='P' && tipo!='G' && tipo!='T'&& tipo!='A'&& tipo!='R'&& tipo!='X')
                        printf("\nEL TIPO INGRESADO ES INCORRECTO");
                if(tipo=='X')
                        printf("\nFIN DE LA CARGA");
            }while(tipo!='P'&& tipo!='G'&& tipo!='T'&& tipo!='A'&& tipo!='R'&& tipo!='X');
        }

        if(cont_perros>cont_gatos && cont_perros>cont_tortugas && cont_perros>cont_aves && cont_perros>cont_raros)
            printf("\n\nEl animal mas atendido fue el PERRO");
            else
            {
                if(cont_gatos>cont_perros && cont_gatos>cont_tortugas && cont_gatos>cont_aves && cont_gatos>cont_raros)
                    printf("\n\nEl animal mas atendido fue el GATO");
                else
                {
                    if(cont_tortugas>cont_perros&&cont_tortugas>cont_gatos&&cont_tortugas>cont_aves&&cont_tortugas>cont_raros)
                        printf("\n\nEl animal mas atendido fue la TORTUGA");
                    else
                    {
                        if(cont_aves>cont_perros&&cont_aves>cont_gatos&&cont_aves>cont_tortugas&&cont_aves>cont_raros)
                            printf("\n\nEl animal mas atendido fueron las AVES");
                        else
                            printf("\n\nEl animal mas atendido fueron los RAROS");
                    }
                }
            }
    cont_total=cont_aves+cont_gatos+cont_perros+cont_raros+cont_tortugas;
    cont_pyg=cont_perros+cont_gatos;
    promedio=(cont_pyg*100)/cont_total;
    printf("\n\nLa cantidad de animales raros con efermedad es de %d",cont_rarosenfermos);
    printf("\n\nEl porcentaje de perros y gatos atendidos sobre el total de animales atendidos es de: %f",promedio);
    return 0;
}
