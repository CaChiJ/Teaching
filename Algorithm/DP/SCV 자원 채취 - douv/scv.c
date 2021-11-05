#include <stdio.h>
#include <string.h>

int N;
int cache[100][100];
int map[100][100];

int getMax(int r, int c)
{
    if (r < 0 || c < 0)
    {
        return 0;
    }

    if (cache[r][c] == -1)
    {
        int tmp1 = getMax(r - 1, c);
        int tmp2 = getMax(r, c - 1);
        cache[r][c] = map[r][c] + (tmp1 > tmp2 ? tmp1 : tmp2);
    }

    return cache[r][c];
}

int main(void)
{
    memset(cache, -1, sizeof(cache));

    scanf("%d", &N);

    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < N; ++c)
        {
            scanf("%d", &map[r][c]);
        }
    }

    printf("%d\n", getMax(N - 1, N - 1));

    return 0;
}