#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    int queue[300003][2];
    queue[0][0] = N;
    queue[0][1] = 0;
    int head = 0;
    int tail = 0;

    bool isVisited[100001];
    memset(isVisited, false, sizeof(isVisited));

    while (head <= tail)
    {
        int pos = queue[head][0];
        int time = queue[head][1];
        head++;

        // if pos is invalid
        if (pos < 0 || pos > 100000 || isVisited[pos])
        {
            continue;
        }

        // if pos is K
        if (pos == K)
        {
            printf("%d\n", time);
            break;
        }

        isVisited[pos] = true;

        // case 1 : +1
        tail++;
        queue[tail][0] = pos + 1;
        queue[tail][1] = time + 1;

        // case 2 : -1
        tail++;
        queue[tail][0] = pos - 1;
        queue[tail][1] = time + 1;

        // case 3 : *2
        tail++;
        queue[tail][0] = pos * 2;
        queue[tail][1] = time + 1;
    }

    return 0;
}