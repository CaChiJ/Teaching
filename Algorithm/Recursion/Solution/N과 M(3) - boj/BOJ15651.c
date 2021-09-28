#include <stdio.h>

int N, M;

void printSequence(int cnt, int bucket[])
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

    for (int i = 1; i <= N; ++i)
    {
        bucket[cnt] = i;
        printSequence(cnt + 1, bucket);
    }
}

int main(void)
{
    scanf("%d %d", &N, &M);
    int bucket[7];
    printSequence(0, bucket);
    return 0;
}