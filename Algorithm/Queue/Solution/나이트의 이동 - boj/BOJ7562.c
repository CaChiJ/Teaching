#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    const int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};

    int TC;
    scanf("%d", &TC);

    for (int tcCnt = 0; tcCnt < TC; ++tcCnt)
    {
        int I;
        scanf("%d", &I);

        int q[100000][3];
        scanf("%d %d", &(q[0][0]), &(q[0][1]));
        q[0][2] = 0;
        int head = 0;
        int tail = 0;

        int goalR;
        int goalC;
        scanf("%d %d", &goalR, &goalC);

        bool isVisited[I][I];
        memset(isVisited, false, sizeof(isVisited));
        isVisited[q[0][0]][q[0][1]];

        while (head <= tail)
        {
            int row = q[head][0];
            int col = q[head][1];
            int dist = q[head][2];
            head++;

            // 목표지점에 도달한 경우
            if (row == goalR && col == goalC)
            {
                printf("%d\n", dist);
                break;
            }

            for (int d = 0; d < 8; ++d)
            {
                int nextRow = row + dr[d];
                int nextCol = col + dc[d];

                // 올바르지 않은 경우
                if (nextRow < 0 || nextRow >= I || nextCol < 0 || nextCol >= I || isVisited[nextRow][nextCol])
                {
                    continue;
                }

                isVisited[nextRow][nextCol] = true;

                tail++;
                q[tail][0] = nextRow;
                q[tail][1] = nextCol;
                q[tail][2] = dist + 1;
            }
        }
    }

    return 0;
}