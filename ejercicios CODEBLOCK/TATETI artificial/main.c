#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

//
// struct tateti
//
// matrix    = Matriz de caracteres
// letras[0] = Letra que usa la persona
// letras[1] = Letra que usa la computadora
// jugador   = Jugador actual, 0=Persona, 1=Computadora
// ganador   = Jugador que ganó, -1 = Ninguno, 0 = Persona, 1 = Computadora
//

struct tateti
{
    int matrix[3][3];
    int letras[2];
    int jugador;
    int ganador;
};
void print_tateti(struct tateti* t)
{
    int i,j;
    system("cls");
    printf("   | A | B | C |\n");
    printf("---+---+---+---|\n");
    for(i = 0; i < 3; i++)
    {
        printf(" %d |", i+1);
        for(j = 0; j < 3; j++)
        {
            if(j < 3)
            {
                printf(" %c |", t->matrix[i][j]);
            }
            else
            {
                printf (" %c ", t->matrix[i][j]);
            }
        }
        if(i < 2)
            printf("\n---+---+---+---|\n");
        else
            printf("\n---------------|\n");
    }
}
int check_tateti(struct tateti* t, int c)
{
    int i;

    // Comprobar filas
    for(i = 0; i < 3; i++)
    {
        if(t->matrix[i][0] == c && t->matrix[i][1] == c && t->matrix[i][2] == c)
            return 1;
    }
    // Comprobar columnas
    for(i = 0; i < 3; i++)
    {
        if(t->matrix[0][i] == c && t->matrix[1][i] == c && t->matrix[2][i] == c)
            return 1;
    }
    // Comprobar diagonales
    if(t->matrix[0][0] == c && t->matrix[1][1] == c && t->matrix[2][2] == c)
        return 1;
    if(t->matrix[2][0] == c && t->matrix[1][1] == c && t->matrix[0][2] == c)
        return 1;

    return 0;
}
int jugar_tateti(struct tateti* t)
{
    int c;
    int ok;
    int col = -1;
    int row = -1;

    // Jugar
    if(t->jugador == 0)
    {
        ok = 0;
        do
        {
            col = -1;
            row = -1;
            printf("Ingrese las coordenadas:");
            while(col == -1)
            {
                printf("\nFila: ");
                c = getch();
                printf("%c", c);
                if(c >= '1' && c <= '3')
                {
                    col = (c-'1');
                }
            }
            while(row == -1)
            {
                printf("\nColumna: ");
                c = toupper(getch());
                printf("%c", c);
                if(c >= 'A' && c <= 'C')
                {
                    row = (c-'A');
                }
            }
            printf("\n");
            if(t->matrix[col][row] == ' ')
            {
                ok = 1;
                t->matrix[col][row] = t->letras[0];
                getch();
            }
            else
            {
                printf("Celda ocupada, intentelo otra vez\n");
                getch();
                print_tateti(t);
            }
        }
        while(!ok);
    }
    else
    {
        ok = 0;
        do
        {
            row = rand()%3;
            col = rand()%3;
            if(t->matrix[col][row] == ' ')
            {
                ok = 1;
                t->matrix[col][row] = t->letras[1];
            }
        }
        while(!ok);
    }
    //
    // Comprobar si ganó el usuario
    //
    if(check_tateti(t, t->letras[0]))
    {
        t->ganador = 0;
        return 0;
    }
    //
    // Comprobar si ganó la computadora
    //
    if(check_tateti(t, t->letras[1]))
    {
        t->ganador = 1;
        return 0;
    }
    //
    // Comprobar si se llegó al final y no hay ganadores
    //
    ok = 1;
    for(col = 0; col < 3 && ok; col++)
    {
        for(row = 0; row < 3 && ok; row++)
        {
            if(t->matrix[col][row] == ' ')
            {
                ok = 0;
            }
        }
    }
    if(ok)
    {
        t->ganador = -1;
        return 0;
    }
    // Cambiar de jugador
    t->jugador = !t->jugador;
    return 1;
}
void iniciar_tateti(struct tateti* t)
{
    int n;
    int i,j;

    srand(time(NULL));
    //
    // Iniciar matrix
    //
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            t->matrix[i][j] = ' ';
        }
    }
    //
    // Seleccionar jugador inicial, computadora o persona, y caracter por jugador
    //
    n = rand()%2;
    t->letras[n] = 'X';
    t->letras[!n] = 'O';
    t->jugador = rand()%2;
    printf("Usted juega con la \'%c\'\n", t->letras[0]);
    printf("La computadora juega con la \'%c\'\n", t->letras[1]);
    if(t->jugador == 0)
    {
        printf("\nUsted comienza el juego. ");
    }
    else// if(t->jugador == 1)
    {
        printf("\nLa Computadora comienza el juego. ");
        jugar_tateti(t);
    }
    printf("Presione una tecla para continuar ...");
    getch();
    print_tateti(t);
}

void main()
{
    int c;
    struct tateti t;

    printf("......Bienvenido al Juego TA-TE-TI......\n\n");
    getch();
    do
    {
        system("cls");
        iniciar_tateti(&t);
        while(jugar_tateti(&t))
        {
            print_tateti(&t);
        }
        print_tateti(&t);
        switch(t.ganador)
        {
            case 0:
                printf("\nGanastes\n");
                break;
            case 1:
                printf("\nGano la computadora\n");
                break;
            case -1:
                printf("\nNo hay ganadores\n");
                break;
            default:
                printf("\nError\n");
                break;
        }
        getch();
        system("cls");
        printf("Quieres jugar otra vez?\nS = Si\nN = No\n");
        do
        {
            c = toupper(getch());
            if(c == 'S')
                break;
            else if(c == 'N')
                return;
        }
        while(1);
    }
    while(1);
}
