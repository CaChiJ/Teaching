#include <stdio.h>

void printMt(int x, int n)
{
    if (x == n)
    {
        printf("%d", x);
        return;
    }

    printf("%d", x);
    printMt(x + 1, n);
    printf("%d", x);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    printMt(1, N);
    return 0;
}