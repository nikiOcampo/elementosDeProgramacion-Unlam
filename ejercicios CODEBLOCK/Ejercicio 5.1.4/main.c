#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    int i,contvocal=0;
    for(i=1;i<=100;i++)
    {
    printf("Ingrese una letra: ");
    fflush(stdin);
    scanf("%c",&letra);
        if(letra== 'A'||letra== 'E'||letra=='I'||letra=='O'||letra=='U'||letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u')
            contvocal++;
    }
    if (contvocal>0)
        printf("Se ingresaron %d vocales", contvocal);
    else
        printf("No se ingresaron vocales");
    return 0;
}
