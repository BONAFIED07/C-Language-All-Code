#include <stdio.h>

int stepcount = 0;

int fibo(int a)
{
    if (a == 0 || a == 1)
    {
        stepcount = stepcount + 1;
        return 1;
    }
    else
    {
        int c;

        c = fibo(a - 1) + fibo(a - 2);
        stepcount = stepcount + 1;
        return c;
    }
}

int main()
{
    int x;
    scanf("%d", &x);           // For taking Input
    printf("%d ", fibo(x));    // For Output Fibo
    printf("%d\n", stepcount); // For Output Stepcount
}