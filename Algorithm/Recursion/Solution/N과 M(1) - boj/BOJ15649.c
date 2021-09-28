#include <stdio.h>

int N, M;

void printSequence(int cnt, int bucket[], int isUsed[])
{
    if (cnt == M)
    {
        for (int i = 0; i < M; ++i)
        {
            printf("%d ", bucket[i]);
        }

        printf("\n");
    }

    for (int i = 1; i <= N; ++i)
    {
        if (isUsed[i])
        {
            continue;
        }

        isUsed[i] = 1;
        bucket[cnt] = i;
        printSequence(cnt + 1, bucket, isUsed);
        isUsed[i] = 0;
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    int bucket[M];
    int isUsed[N + 1];

    for (int i = 0; i < N + 1; ++i)
    {
        isUsed[i] = 0;
    }

    printSequence(0, bucket, isUsed);
    return 0;
}