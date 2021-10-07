#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    long long sum = 0;

    int stack[N];
    int size = 0;

    for (int i = 0; i < N; ++i)
    {
        int h;
        scanf("%d", &h);

        while (size > 0 && stack[size - 1] <= h)
        {
            size--;
        }

        sum += size;
        stack[size] = h;
        size++;
    }

    printf("%lld\n", sum);
    return 0;
}