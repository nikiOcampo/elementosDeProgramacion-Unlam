#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    printf("Ingrese un caracter alfanumerico: ");
    scanf("%c",&c);
    if (c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
        printf("VOCAL, con valor en ASCCI de: %d",c);
    else
        printf("\nNo es vocal, su valor en ASCII es de: %d ",c);
    return 0;
}
