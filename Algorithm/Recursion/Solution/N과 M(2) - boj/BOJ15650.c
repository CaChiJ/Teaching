#include <stdio.h>

int N, M;

void printSequence(int cnt, int last, int bucket[])
{
    if (cnt == M)
    {
        for (int i = 0; i < M; ++i)
        {
            printf("%d ", bucket[i]);
        }

        printf("\n");

        return;
    }

    for (int i = last + 1; i <= N; ++i)
    {
        bucket[cnt] = i;
        printSequence(cnt + 1, i, bucket);
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    int bucket[M];
    printSequence(0, 0, bucket);
    return 0;
}