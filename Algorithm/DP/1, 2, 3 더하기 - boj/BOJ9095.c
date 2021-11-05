#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);

    for (int tcCnt = 0; tcCnt < T; ++tcCnt)
    {

        int N;
        scanf("%d", &N);

        int cache[N];
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 4;

        for (int i = 4; i <= N; ++i)
        {
            cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
        }

        printf("%d\n", cache[N]);
    }

    return 0;
}