#include <stdio.h>

int getNumOfCase(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return getNumOfCase(n - 1) + getNumOfCase(n - 2);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    printf("%d", getNumOfCase(N));
    return 0;
}