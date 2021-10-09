#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int getNthNum(int num, int n)
{
    return num / (int)pow(10, n - 1) % 10;
}

bool checkPrime(int n)
{
    for (int i = 2; i < sqrt(n) + 1; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int start = 0;
    int goal = 0;

    scanf("%d %d", &start, &goal);

    if (start == goal)
    {
        printf("0\n");
        return 0;
    }

    int q[10000][2];
    q[0][0] = start;
    q[0][1] = 0;
    int head = 0;
    int tail = 0;

    bool isVisited[10000];
    memset(isVisited, false, sizeof(isVisited));
    isVisited[start] = true;

    while (head <= tail)
    {
        int now = q[head][0];
        int dist = q[head][1];
        head++;

        // 각 자리수를 일의 자리 정수로 나누기
        int nums[4];

        {
            int tmp = now;

            for (int i = 0; i < 4; ++i)
            {
                nums[i] = tmp % 10;
                tmp /= 10;
            }
        }

        // 각 자릿수에 대해 하나씩 바꿔가면서 유효하면 큐에 넣기
        int ten = 1;

        for (int place = 0; place < 4; ++place)
        {
            int base = now - nums[place] * ten;

            for (int i = 0; i < 10; ++i)
            {
                int next = base + i * ten;

                if (next == goal)
                {
                    printf("%d\n", dist + 1);
                    place = 4;
                    tail = head - 1;
                    break;
                }

                // 유효하면 큐에 넣기
                if (1000 <= next && next < 10000 && !isVisited[next] && checkPrime(next))
                {
                    isVisited[next] = true;
                    tail++;
                    q[tail][0] = next;
                    q[tail][1] = dist + 1;
                }
            }

            ten *= 10;
        }
    }

    return 0;
}