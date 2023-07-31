/*9.5. De una persona se conoce los siguientes datos:
• Número de Legajo (int, entre 1 y 10.000)
• Apellido (string, 15 caracteres)
• Nombre (string, 15 caracteres)
• Altura (float, mayor de 0)
• Sexo (char, F o M)
• Día de Nacimiento (int, entre 1 y 31
• Mes de Nacimiento (int, ente 1 y 12)
• Año de Nacimiento (int, ente 1950 y 2019)
Se solicita realizar los siguientes procesos:
a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados anteriormente y llamarla PERSONA.
b. Mostrar los datos de la Estructura de Datos del punto a.
c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año utilizarla en una nueva Estructurad de Datos llamada PERSONA2.
d. Mostrar los datos de la Estructura de Datos del punto c.
e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos al programa principal(main).
f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c. y agregarle
un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a ser hasta 36 materias)
y llamarla PERSONA3.
g. Crear una FUNCION que realice el punto f.
h. Mostrar los datos de la Lista creada en el punto f.
i. Crear una FUNCION que realice el punto h.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int num_legajo;
    char apellido[15];
    char nombre[15];
    float altura;
    char sexo;
    int dia_nac;
    int mes_nac;
    int anio_nac;
}PERSONA;

typedef struct
{
    char apellido[15];
    char nombre[15];
}NOMBREYAPELLIDO;

typedef struct
{
    int d;
    int m;
    int a;
}FECHA;

typedef struct
{
    int num_legajo;
    NOMBREYAPELLIDO nom_apel;
    float altura;
    char sexo;
    FECHA nacimiento;
}PERSONA2;

typedef struct
{
    int num_legajo;
    NOMBREYAPELLIDO nom_apel;
    float altura;
    char sexo;
    FECHA nacimiento;
    int materias[36];
}PERSONA3;

void carga_p1 (PERSONA);
PERSONA2 carga_p2 (PERSONA2,FECHA);
int esFechaCorrecta(FECHA);// Prototipo de la función
void carga_p3(PERSONA3,FECHA);
void mostrar_persona3(PERSONA3,int);

int main()
{
    PERSONA persona1;
    PERSONA2 persona2;
    FECHA fech;
    PERSONA3 persona3;
    carga_p1(persona1);
    persona2=carga_p2(persona2,fech);
    printf("\n\n\nDATOS DE LA PERSONA 2: ");
    printf("\nNro de legajo:%d\nApellido:%s\nNombre:%s",persona2.num_legajo,persona2.nom_apel.apellido,persona2.nom_apel.nombre);
    printf("\nAltura:%0.2f\nSexo:%c\nDia de Nacimiento:%d",persona2.altura,persona2.sexo,persona2.nacimiento.d);
    printf("\nMes de Nacimiento:%d\nAnio de Nacimiento:%d",persona2.nacimiento.m,persona2.nacimiento.a);
    carga_p3(persona3,fech);
    return 0;
}

void carga_p1(PERSONA persona1)
{
    do
    {
        printf("\nIngrese el nro de legajo de la persona: ");
        scanf("%d",&persona1.num_legajo);
    }while(persona1.num_legajo<1||persona1.num_legajo>10000);
    do
    {
        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(persona1.apellido);
    }while(strlen(persona1.apellido)<1||strlen(persona1.apellido)>14);
    do
    {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(persona1.nombre);
    }while(strlen(persona1.nombre)<1||strlen(persona1.nombre)>14);
    do
    {
        printf("\nIngrese la altura: ");
        scanf("%f",&persona1.altura);
    }while(persona1.altura<0);
    do
    {
        printf("\nIngrese el sexo[F=femenino/M=masculino]: ");
        fflush(stdin);
        scanf("%c",&persona1.sexo);
        persona1.sexo=toupper(persona1.sexo);
    }while(persona1.sexo!='F'&&persona1.sexo!='M');
    do
    {
        printf("\nIngrese el dia de nacimiento: ");
        scanf("%d",&persona1.dia_nac);
    }while(persona1.dia_nac<1||persona1.dia_nac>31);
    do
    {
        printf("\nIngrese el mes de nacimiento: ");
        scanf("%d",&persona1.mes_nac);
    }while(persona1.mes_nac<1||persona1.mes_nac>12);
    do
    {
        printf("\nIngrese el anio de nacimiento: ");
        scanf("%d",&persona1.anio_nac);
    }while(persona1.anio_nac<1950||persona1.anio_nac>2019);
    system("cls");
    //Mostrar los datos de la Estructura de Datos del punto a.
    printf("\nDATOS DE LA PERSONA 1: ");
    printf("\nNro de legajo:%d\nApellido:%s\nNombre:%s",persona1.num_legajo,persona1.apellido,persona1.nombre);
    printf("\nAltura:%0.2f\nSexo:%c\nDia de Nacimiento:%d",persona1.altura,persona1.sexo,persona1.dia_nac);
    printf("\nMes de Nacimiento:%d\nAnio de Nacimiento:%d",persona1.mes_nac,persona1.anio_nac);
}

PERSONA2 carga_p2 (PERSONA2 per2,FECHA fech)
{
    int retorno;
    do
    {
        printf("\n\n\nIngrese el nro de legajo de la persona: ");
        scanf("%d",&per2.num_legajo);
    }while(per2.num_legajo<1||per2.num_legajo>10000);
    do
    {
        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(per2.nom_apel.apellido);
    }while(strlen(per2.nom_apel.apellido)<1||strlen(per2.nom_apel.apellido)>14);
    do
    {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(per2.nom_apel.nombre);
    }while(strlen(per2.nom_apel.nombre)<1||strlen(per2.nom_apel.nombre)>14);
    do
    {
        printf("\nIngrese la altura: ");
        scanf("%f",&per2.altura);
    }while(per2.altura<0);
    do
    {
        printf("\nIngrese el sexo[F=femenino/M=masculino]: ");
        fflush(stdin);
        scanf("%c",&per2.sexo);
        per2.sexo=toupper(per2.sexo);
    }while(per2.sexo!='F'&&per2.sexo!='M');
    do
    {
        //fech= IngresoDeFecha(per2);
        printf("\nIngrese el Dia de Nacimiento:");
        scanf("%d",&fech.d);
        printf("\nIngrese el Mes de Nacimiento:");
        scanf("%d",&fech.m);
        printf("\nIngrese el Anio de Nacimiento:");
        scanf("%d",&fech.a);
        retorno=esFechaCorrecta(fech);
    }while(retorno!=1);
    per2.nacimiento.d=fech.d;
    per2.nacimiento.m=fech.m;
    per2.nacimiento.a=fech.a;
    //Mostrar los datos de la Estructura de Datos del punto c.
   /* printf("\nDATOS DE LA PERSONA 2: ");
    printf("\nNro de legajo:%d\nApellido:%s\nNombre:%s",per2.num_legajo,per2.nom_apel.apellido,per2.nom_apel.nombre);
    printf("\nAltura:%0.2f\nSexo:%c\nDia de Nacimiento:%d",per2.altura,per2.sexo,per2.nacimiento.d);
    printf("\nMes de Nacimiento:%d\nAnio de Nacimiento:%d",per2.nacimiento.m,per2.nacimiento.a);*/
    return per2;
}

int esFechaCorrecta (FECHA fecha)
{
    int retorno, bisiesto, cantidaddiasmes;
    retorno = 0;
    if((fecha.a%4==0 && fecha.a %100!=0) || fecha.a %400==0)
        bisiesto=1;
    else
        bisiesto =0;
    if(fecha.m==4|| fecha.m ==6|| fecha.m ==9|| fecha.m ==11)
        cantidaddiasmes =30;
    else
    {
        if(fecha.m ==2)
            cantidaddiasmes =28+ bisiesto;
        else
            cantidaddiasmes =31;
    }
    if(fecha.a >=1950&& fecha.a<=2019 && fecha.m>=1&& fecha.m <=12&& fecha.d>=1&& fecha.d<= cantidaddiasmes )
        retorno =1;
    else
        retorno =0;
    return retorno;
}

void carga_p3(PERSONA3 per3,FECHA fech)
{
    int retorno,x=0;
    do
    {
        printf("\n\n\nIngrese el nro de legajo de la persona: ");
        scanf("%d",&per3.num_legajo);
    }while(per3.num_legajo<1||per3.num_legajo>10000);
    do
    {
        printf("\nIngrese el apellido: ");
        fflush(stdin);
        gets(per3.nom_apel.apellido);
    }while(strlen(per3.nom_apel.apellido)<1||strlen(per3.nom_apel.apellido)>14);
    do
    {
        printf("\nIngrese el nombre: ");
        fflush(stdin);
        gets(per3.nom_apel.nombre);
    }while(strlen(per3.nom_apel.nombre)<1||strlen(per3.nom_apel.nombre)>14);
    do
    {
        printf("\nIngrese la altura: ");
        scanf("%f",&per3.altura);
    }while(per3.altura<0);
    do
    {
        printf("\nIngrese el sexo[F=femenino/M=masculino]: ");
        fflush(stdin);
        scanf("%c",&per3.sexo);
        per3.sexo=toupper(per3.sexo);
    }while(per3.sexo!='F'&&per3.sexo!='M');
    do
    {
        printf("\nIngrese el Dia de Nacimiento:");
        scanf("%d",&fech.d);
        printf("\nIngrese el Mes de Nacimiento:");
        scanf("%d",&fech.m);
        printf("\nIngrese el Anio de Nacimiento:");
        scanf("%d",&fech.a);
        retorno=esFechaCorrecta(fech);
    }while(retorno!=1);
    per3.nacimiento.d=fech.d;
    per3.nacimiento.m=fech.m;
    per3.nacimiento.a=fech.a;
    printf("\nIngrese el codigo de la materia %d aprobada[Salida=0]: ",x+1);
    scanf("%d",&per3.materias[x]);
    while(per3.materias[x]!=0&&x<36)
    {
        x++;
        printf("\nIngrese el codigo de la materia %d aprobada[Salida=0]: ",x+1);
        scanf("%d",&per3.materias[x]);
    }
    mostrar_persona3(per3,x);
}

void mostrar_persona3(PERSONA3 per3,int n)
{
    int x;
    printf("\n\n\nDATOS DE LA PERSONA 3: ");
    printf("\nNro de legajo:%d\nApellido:%s\nNombre:%s",per3.num_legajo,per3.nom_apel.apellido,per3.nom_apel.nombre);
    printf("\nAltura:%0.2f\nSexo:%c\nDia de Nacimiento:%d",per3.altura,per3.sexo,per3.nacimiento.d);
    printf("\nMes de Nacimiento:%d\nAnio de Nacimiento:%d",per3.nacimiento.m,per3.nacimiento.a);
    printf("\nLISTA DE MATERIAS APROBADAS:");
    for(x=0;x<n;x++)
    {
       printf("\n%d",per3.materias[x]);
    }
}


