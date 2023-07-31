/*El gobierno de la Ciudad de Buenos Aires realiza una encuesta a los estudiantes de los colegios secundarios.
Los primeros datos a ingresar son la fecha (día, mes y año) y
la cantidad de colegios de la ciudad en que se realizó la encuesta.
De cada colegio se conoce: número de escuela, la cantidad de alumnos inscriptos
 y la especialidad (‘T’: técnico, ‘N’: no técnico).
De cada alumno del colegio que respondió la encuesta se conoce:
DNI, fecha de nacimiento (día, mes y año), sexo (‘M’ o ‘F’),
opinión con respecto a los conocimientos adquiridos (‘B’: buenos, ‘M’: malos).
Se identifica el fin de ingreso de datos de los alumnos que respondieron
 la encuesta por cada colegio con ingreso 0 en el DNI del estudiante.
Validar todos los datos que se ingresan por teclado.
Informar:
a. Por cada colegio, el porcentaje de alumnos que contestaron la encuesta sobre la cantidad de alumnos inscriptos del colegio.
b. Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta.
c. Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron la encuesta.
d. Porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados.
e. Mayor edad de los estudiantes encuestados.
f. Número del colegio con mayor opinión buena sobre los conocimientos adquiridos.*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dd,mm,aaaa,cant_colegios,nro_escuela,cant_alumnos,dni,dia_nac,mes_nac,anio_nac,i,posbueno;
    int contbuenos_mayor,edad,cont_buenos,cont_malos,cont_encuestados,cont_notecnico,cont_mujeres,edadmayor,total_encuestados;
    char especialidad,sexo,opinion;
    float porcentaje_mujeres,porcentaje_malos;
    cont_encuestados=cont_malos=cont_mujeres=cont_notecnico=edadmayor=cont_buenos=contbuenos_mayor=total_encuestados=0;
    do
    {
        printf("Ingrese el dia en que se realizo la encuesta: ");
        scanf("%d",&dd);
        if(dd<1||dd>31)
            printf("DIA INEXISTENTE\n");
    }while(dd<1||dd>31);
    do
    {
        printf("\nIngrese el mes en el que se realizo la encuesta: ");
        scanf("%d",&mm);
        if(mm<1 || mm>12)
            printf("MES INEXISTENTE\n");
    }while(mm<1||mm>12);
    do
    {
        printf("\nIngrese el anio en el que se realizo la encuesta: ");
        scanf("%d",&aaaa);
        if(aaaa>2020)
            printf("ANIO INEXISTENTE\n");
    }while(aaaa>2020);
    printf("\n\nIngrese la cantidad de colegios de la ciudad que fueron encuestados: ");
    scanf("%d",&cant_colegios);
    for(i=0;i<=cant_colegios;i++)
    {
        do
        {   printf("\n\nIngrese el numero de escuela: ");
            scanf("%d",&nro_escuela);
            if(nro_escuela<0)
                printf("\nNro.escuela inexistente");
        }while(nro_escuela<0);
        do
        {   printf("\nIngrese la cantidad de alumnos inscriptos en dicha escuela: ");
            scanf("%d",&cant_alumnos);
            if(cant_alumnos<0)
                printf("CANTIDAD NO REAL\n");
        }while(cant_alumnos<0);
        do
        {   printf("\nIngrese la especialidad('T' = tecnico/ 'N'=no tecnico): ");
            fflush(stdin);
            scanf("%c",&especialidad);
            if(especialidad!='T'&& especialidad!='N')
                printf("ESPECIALIDAD NO IDENTIFICADA");
        }while(especialidad!='T'&&especialidad!='N');
        do
        {
            printf("\n\nIngrese el DNI del alumno que hizo la encuesta: ");
            scanf("%d",&dni);
            if(dni>0)
                cont_encuestados++;
            /*IF(DNI==0) BREAK;*/
        }while(dni<0);
        while(dni!=0)
        {
            do
            {
                printf("Ingrese el dia del nacimiento del alumno: ");
                scanf("%d",&dia_nac);
                if(dia_nac<1||dia_nac>31)
                    printf("DIA INEXISTENTE\n");
            }while(dia_nac<1||dia_nac>31);
            do
            {
                printf("Ingrese el mes del nacimiento del alumno: ");
                scanf("%d", &mes_nac);
                if(mes_nac<1||mes_nac>12)
                    printf("MES INEXISTENTE\n");
            }while(mes_nac<1||mes_nac>12);
            do
            {
                printf("Ingrese el anio del nacimiento del alumno: ");
                scanf("%d",&anio_nac);
                if(anio_nac>2020)
                    printf("ANIO INEXISTENTE\n");
            }while(anio_nac>2020);
            edad=aaaa-anio_nac;
            if(mm<mes_nac)
                edad=edad-1;
                else
            {
                if(mm>mes_nac)
                    edad=edad;
                    else
                    if(dd>dia_nac)
                        edad=edad;
                    else
                        edad=edad-1;
            }
            do
            {
              printf("\nIngrese el sexo del alumno ('M'=masculino/'F'=femenino): ");
              fflush(stdin);
              scanf("%c",&sexo);
              if(sexo!='M'&&sexo!='F')
                    printf("SEXO NO IDENTIFICADO\n, indique un sexo");
            }while(sexo!='M'&&sexo!='F');
            do
            {
                printf("\nIngrese la opinion con respecto a los conocimientos adquiridos‘(B’: buenos, ‘M’: malos): ");
                fflush(stdin);
                scanf("%c",&opinion);
                if(opinion!='B'&&opinion!='M')
                    printf("OPNION NO REGISTRADA, RESPETE LA INDICACION\n");
                if(opinion=='B')
                    cont_buenos++;
            }while(opinion!='B'&&opinion!='M');
            if(cant_alumnos>cont_encuestados)
            {
                do
                {
                    printf("\n\nIngrese el DNI del alumno que hizo la encuesta: ");
                    scanf("%d",&dni);
                    if(dni>0)
                        cont_encuestados++;
                }while(dni<0);
            }
        }
        printf("\n%d alumnos fueron encuestados de los %d alumnos que hay en la escuela\n",cont_encuestados,cant_alumnos);
        if(especialidad=='N')
            cont_notecnico++;
        if(sexo=='F')
            cont_mujeres++;
        if(opinion=='M')
            cont_malos++;
        if(edad>edadmayor)
            edadmayor=edad;
        if(cont_buenos>contbuenos_mayor)
        {
            contbuenos_mayor=cont_buenos;
            posbueno=nro_escuela;
        }
    }
    porcentaje_mujeres=(cont_mujeres*100)/cont_encuestados;
    porcentaje_malos=(cont_malos*100)/cont_encuestados;
    printf("\nLa Cantidad de estudiantes de colegio no técnicos que respondieron la encuesta: %d ",cont_notecnico);
    printf("\nEl Porcentaje de mujeres de escuelas técnicas sobre la cantidad de estudiantes que respondieron la encuesta: %f",porcentaje_mujeres);
    printf("\nEl Porcentaje de estudiantes que respondieron que los conocimientos adquiridos eran malos, sobre el total de encuestados es de: %f",porcentaje_malos);
    printf("\nLa Mayor edad de los estudiantes encuestados fue de: %d",edadmayor);
    printf("\nEl Número del colegio con mayor opinión buena sobre los conocimientos adquiridos: %d",posbueno);
    return 0;
}
