#include <stdio.h>

void printMt(int x)
{
    if (x == 1)
    {
        printf("%d", x);
        return;
    }

    printMt(x - 1);
    printf("%d", x);
    printMt(x - 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    printMt(N);
    return 0;
}