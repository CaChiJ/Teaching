#include <stdio.h>

void put(int from, int to, int count)
{
    if (count == 1)
    {
        printf("%d -> %d\n", from, to);
        return;
    }

    put(from, 6 - from - to, count - 1);
    put(from, to, 1);
    put(6 - from - to, to, count - 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    put(1, 3, N);
    return 0;
}