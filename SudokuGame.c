#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define size 3

void generate(int);
void genRandom(int a[size][size]);
void theGame(int);
int check(int);
int main()
{
    int a[size][size], i, j, r, c, d, e, count = 0, ch;
    char b, name[20], cha;
    printf("Welcome to the game\n");
    for (j = 0; j < size; j++)
    {
        printf("----");
    }
    printf("\n");
    generate(a);

    theGame(a);
    printf("\nPress N to start a new game\n");
    scanf("%c", &b);
    if (b == 'N' || b == 'n')
        clrscr();
    printf("Starting  new game");
    printf("\nEnter player name:\n");
    scanf("%s", name);
    clrscr();
    printf("welcome,%s\n", name);
    printf("press S to start:");
    scanf("%c", &b);
    if (b == 's' || b == 'S')
    {
        clrscr();
        genRandom(a);
        theGame(a);
    }
    while (1)
    {
        do
        {
            printf("Enter row and column to enter your number:");
            scanf("%d %d", &r, &c);
            if ((r < 1 || r > size) || (c < 1 || c > size))
            {
                printf("invalid!enter again\n");
            }
        } while ((r < 1 || r > size) || (c < 1 || c > size));
        printf("Enter your number:");
        scanf("%d", &d);
        a[r - 1][c - 1] = d;
        count = 0;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                e = a[i][j];
                if (e == 0)
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            clrscr();
            theGame(a);
            printf("do you want to lock(y\\n)?");
            scanf("%c", &cha);
            if (cha == 'y' || cha == 'Y')
            {
                break;
            }
        }
        clrscr();
        theGame(a);
    }
    clrscr();
    theGame(a);
    ch = check(a);
    if (ch == 1)
    {
        printf("congrats");
    }
    else
    {
        printf("sorry");
    }

    getch();
    return 0;
}

void generate(int a[size][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            a[i][j] = 0;
        }
    }
}

void genRandom(int a[size][size])
{
    int i, j, b;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j = j + 2)
        {
            b = random() % size;
            if (b == 0)
                b = size;
            a[i][j] = b;
        }
    }
}

void theGame(int a[size][size])
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (a[i][j] == 0)
            {

                printf("[.]\t");
            }

            else
            {
                printf("[%d]\t", a[i][j]);
            }
        }
        printf("\n");
        for (j = 0; j < size; j++)
        {
            printf("----");
        }
        printf("\n");
    }
}

int check(int a[size][size])
{
    int i, j, ch = 0, ch2 = 0, k;
    for (k = 0; k < size; k++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (a[i][k] == a[i][j])
                    ch++;
            }
        }
    }
    for (k = 0; k < size; k++)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (a[k][i] == a[j][i])
                    ch2++;
            }
        }
    }
    if ((ch == size * size) && (ch2 == size * size))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}