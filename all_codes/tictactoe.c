#include <stdio.h>
int main()
{
    char a[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            a[i][j] = ' ';
        }
    }
    int d = 0;

    while (1)
    {
        printf("%c | %c | %c\n", a[0][0], a[0][1], a[0][2]);
        printf("---------\n");
        printf("%c | %c | %c\n", a[1][0], a[1][1], a[1][2]);
        printf("---------\n");
        printf("%c | %c | %c\n", a[2][0], a[2][1], a[2][2]);

        int r, c;
        printf("Write Row Number    0/1/2 : ");
        scanf("%d", &r);
        printf("Write Column Number 0/1/2 : ");
        scanf("%d", &c);

        if (d % 2 == 0)
        {
            a[r][c] = 'X';
        }
        else
        {
            a[r][c] = 'O';
        }

        d = d + 1;

        if (a[0][0] == a[0][1] && a[0][0] == a[0][2])
        {
            if (a[0][0] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[0][0] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }
        else  if (a[1][0] == a[1][1] && a[1][0] == a[1][2])
        {
            if (a[1][0] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[1][0] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }
        else if (a[2][0] == a[2][1] && a[2][0] == a[2][2])
        {
            if (a[2][0] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[2][0] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }

        else if (a[0][0] == a[1][0] && a[0][0] == a[2][0])
        {
            if (a[0][0] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[0][0] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }

        else if (a[0][1] == a[1][1] && a[0][1] == a[2][1])
        {
            if (a[0][1] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[0][1] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }

        else if (a[0][2] == a[1][2] && a[0][2] == a[2][2])
        {
            if (a[0][2] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[0][2] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }

        else if (a[0][0] == a[1][1] && a[0][0] == a[2][2])
        {
            if (a[0][0] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[0][0] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }
        else if (a[0][2] == a[1][1] && a[0][2] == a[2][0])
        {
            if (a[0][2] == 'X')
            {
                printf("X Wins\n");
                break;
            }
            else if (a[0][2] == 'O')
            {
                printf("O Wins\n");
                break;
            }
        }
        else if(d==8){
            printf("DRAW !!\n");
            break;
        }
    }
}