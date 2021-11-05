#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int cache[N + 1];
    memset(cache, 0, sizeof(cache));
    cache[0] = 1;
    cache[1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            cache[i] += cache[j] * cache[i - j - 1];
        }
    }

    printf("%d\n", cache[N]);

    return 0;
}