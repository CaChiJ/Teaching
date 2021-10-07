#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int stack[N][2]; // 0: height of cow, 1: number of cow
    int stackCnt = 0;

    int counter[N];
    memset(counter, 0, sizeof(counter));

    for (int i = 0; i < N; ++i)
    {
        int cow;
        scanf("%d", &cow);

        while (stackCnt > 0 && stack[stackCnt - 1][0] <= cow)
        {
            sum += i - stack[stackCnt - 1][1] - 1;
            stackCnt--;
        }

        stack[stackCnt][0] = cow;
        stack[stackCnt][1] = i;
        stackCnt++;
    }

    while (stackCnt > 0)
    {
        counter[stack[stackCnt - 1][1]] = N - stack[stackCnt - 1][1] - 1;
        stackCnt--;
    }

    int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        sum += counter[i];
    }

    printf("%d\n", sum);

    return 0;
}