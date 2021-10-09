#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int q[1000000][2];
int map[1000][1000];

int main(void)
{
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    int N, M;
    scanf("%d %d", &M, &N);

    int head = 0;
    int tail = -1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            scanf("%d", &(map[i][j]));

            if (map[i][j] == 1)
            {
                tail++;
                q[tail][0] = i;
                q[tail][1] = j;
            }
        }
    }

    int day = -1;

    while (head <= tail)
    {
        day++;

        int qSize = tail - head + 1;

        for (int i = 0; i < qSize; ++i)
        {
            int row = q[head][0];
            int col = q[head][1];
            head++;

            for (int d = 0; d < 4; ++d)
            {
                int nextR = row + dr[d];
                int nextC = col + dc[d];

                if (0 <= nextR && nextR < N && 0 <= nextC && nextC < M && map[nextR][nextC] == 0)
                {
                    map[nextR][nextC] = 1;
                    tail++;
                    q[tail][0] = nextR;
                    q[tail][1] = nextC;
                }
            }
        }
    }

    bool allRipe = true;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == 0)
            {
                allRipe = false;
                i = N;
                break;
            }
        }
    }

    if (allRipe)
    {
        printf("%d\n", day);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}