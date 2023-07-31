#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

int muestra(char [],char [],char );
void hombre(int);
int verifica(char [], char [], int );

int main()
{
    int s2=1;
    while(s2==1)
    {
    system("cls");
    HANDLE hConsoleOutput;
    COORD coord;
    hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    coord.X = 25; coord.Y = 1;
    SetConsoleCursorPosition (hConsoleOutput, coord);
    printf("Ahorcado V1.4 Edgardo");

    char Pal[40],L,Pul[40],F,Pol[40],S2;
    int V=0,g=0,i=0,s=0,c=0,t=0,v=0,o=0,acuc=0;

    printf("\n\n Jugador 1 ingrese Palabra: ");
    fflush(stdin);
    scanf("%s",&Pal);

    system("cls");
    hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    coord.X = 25; coord.Y = 1;
    SetConsoleCursorPosition (hConsoleOutput, coord);
    printf("Ahorcado V1.1 Edgardo\n\n");
    g=strlen(Pal);

    for(i=0;i<g;i++)
    {
        Pal[i]=toupper(Pal[i]);
    }

    hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    coord.X = 30; coord.Y = 3;
    SetConsoleCursorPosition (hConsoleOutput, coord);
    for(i=0;i<g;i++)
    {
        printf("*");
        Pul[i]='*';
    }

    while(t==0)
    {
        printf("\n\n Jugador 2 por que va a preguntar?");
        printf("\n A) Letra \n B) Palabra \n Ingrese: ");
        fflush(stdin);
        scanf("%c",&F);
        F=toupper(F);
        if(F=='A')
        {
                system("cls");
                hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
                coord.X = 25; coord.Y = 1;
                SetConsoleCursorPosition (hConsoleOutput, coord);
                printf("Ahorcado V1.1 Edgardo\n\n");

                printf("\n\n Jugador 2 Ingrese letra: ");
                fflush(stdin);
                scanf("%c",&L);
                L=toupper(L);
                o=muestra(Pal,Pul,L);
                if(o!=1)
                {
                    v++;
                }
                hombre(v);
                if(v==6)
                {
                    t=1;
                }

                s=verifica(Pal,Pul,g);

                if(s==1)
                    t=2;
        }
        if(F=='B')
        {
            system("cls");
            hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
            coord.X = 25; coord.Y = 1;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("Ahorcado V1.1 Edgardo\n\n");

            printf("\n\n Jugador 2 Ingrese Palabra: ");
            fflush(stdin);
            scanf("%s",&Pol);

            for(i=0;i<g;i++)
            {
                Pol[i]=toupper(Pol[i]);
            }

            s=strcmp(Pal,Pol);

            if(s==0)
            {
                system("cls");
                hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
                coord.X = 25; coord.Y = 1;
                SetConsoleCursorPosition (hConsoleOutput, coord);
                printf("Ahorcado V1.1 Edgardo\n\n");
                hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
                coord.X = 30; coord.Y = 3;
                SetConsoleCursorPosition (hConsoleOutput, coord);
                printf("%s",Pal);

                t=2;
            }
            else
            {
                system("cls");
                hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
                coord.X = 25; coord.Y = 1;
                SetConsoleCursorPosition (hConsoleOutput, coord);
                printf("Ahorcado V1.1 Edgardo\n\n");
                hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
                coord.X = 30; coord.Y = 3;
                SetConsoleCursorPosition (hConsoleOutput, coord);
                for(i=0;i<g;i++)
                {
                printf("%c",Pul[i]);
                }
                v++;
                hombre(v);
                if(v==6)
                {
                    t=1;
                }
            }
        }
    }
    if(t==2)
    {
        printf("\n\n Jugador 2 Has Acertado! :D \n Has Ganadado el Juego! \n Felicitaciones! :D");
    }
    if(t==1)
    {
        coord.X = 30; coord.Y = 10;
        SetConsoleCursorPosition (hConsoleOutput, coord);
        printf("\n\n\t\t\t Jugador 2 Has perdido :( \n\t\t\t  AHORCADO X-( \n\t\t\t  Fin del Juego");
    }

    getch();

    system("cls");
    printf("\n\n Quieren volver a jugar?(s/n): ");
    fflush(stdin);
    scanf("%c",&S2);
    S2=tolower(S2);
    if(S2=='s')
        s2=1;
    if(S2=='n')
        s2=0;

    }

getch();
}

int muestra(char a[],char b[],char x)
 {
    int i,g,o=0,c=0;
    system("cls");
    HANDLE hConsoleOutput;
    COORD coord;
    hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    coord.X = 25; coord.Y = 1;
    SetConsoleCursorPosition (hConsoleOutput, coord);
    printf("Ahorcado V1.1 Edgardo");

    g=strlen(a);
    for(i=0;i<g;i++)
       {
        if(x==a[i])
        {
            b[i]=a[i];
            c++;
        }
       }

    if(c!=0)
        o=1;

    hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
    coord.X = 30; coord.Y = 3;
    SetConsoleCursorPosition (hConsoleOutput, coord);
    for(i=0;i<g;i++)
    {
        printf("%c",b[i]);
    }
 return (o);
 }

 void hombre(int v)
 {
     HANDLE hConsoleOutput;
    COORD coord;
     HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
     hConsoleOutput = GetStdHandle (STD_OUTPUT_HANDLE);
     switch(v)
    {
        case 0: printf("\n |--- \n |  | \n | \n | \n | \n | \n |\n ---");
        break;
        case 1: printf("\n |--- \n |  | \n |  O \n | \n | \n | \n |\n ---");
        break;
        case 2: printf("\n |--- \n |  | \n |  O \n |  | \n |  |\n | \n | \n ---");
        break;
        case 3: printf("\n |--- \n |  | \n |  O \n | /| \n |  | \n | \n | \n ---");
        break;
        case 4: printf("\n |--- \n |  | \n |  O \n | /|\\ \n |  | \n | \n | \n ---");
        break;
        case 5: printf("\n |--- \n |  | \n |  O \n | /|\\ \n |  | \n | / \n | \n ---");
        break;
        case 6:
            printf("\n |--- \n |  |  \n |  \n | \n | \n | \n | \n ---");
            coord.X = 4; coord.Y = 6;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            SetConsoleTextAttribute (hConsoleHandle, 4);
            printf("o");
            coord.X = 4; coord.Y = 7;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("|");
            coord.X = 4; coord.Y = 8;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("|");
            coord.X = 3; coord.Y = 7;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("/");
            coord.X = 5; coord.Y = 7;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("\\");
            coord.X = 3; coord.Y = 9;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("/");
            coord.X = 5; coord.Y = 9;
            SetConsoleCursorPosition (hConsoleOutput, coord);
            printf("\\");
            SetConsoleTextAttribute (hConsoleHandle, 7);
        break;
    }
 }

int verifica(char A[40], char B[40], int g)
 {
     int i=0,c=0,s=0;
     for(i=0;i<g;i++)
     {
         if(A[i]==B[i])
         {
             c++;
         }
     }

     if(c==g)
     {
         s=1;
     }

return (s);
 }
