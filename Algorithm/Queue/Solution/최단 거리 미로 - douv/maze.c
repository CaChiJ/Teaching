#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    int N, M;
    scanf("%d %d", &N, &M);

    int maze[N][M];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            scanf("%1d", &(maze[i][j]));
        }
    }

    int q[2000][3];
    q[0][0] = N - 1; // 행 번호
    q[0][1] = 0;     // 열 번호
    q[0][2] = 1;     // 지나친 블록 수
    int head = 0;
    int tail = 0;

    bool isVisited[N][M];
    memset(isVisited, false, sizeof(isVisited));

    bool canEscape = false;

    // while the q has at least one element
    while (head <= tail)
    {
        int row = q[head][0];
        int col = q[head][1];
        int blockCount = q[head][2];
        head++;

        if (row < 0 || row >= N || col < 0 || col >= M || maze[row][col] == 1 || isVisited[row][col])
        {
            continue;
        }

        if (row == 0 && col == M - 1)
        {
            printf("%d\n", blockCount);
            canEscape = true;
            break;
        }

        isVisited[row][col] = true;

        for (int d = 0; d < 4; d++)
        {
            tail++;
            q[tail][0] = row + dr[d];
            q[tail][1] = col + dc[d];
            q[tail][2] = blockCount + 1;
        }
    }

    if (!canEscape)
    {
        printf("-1\n");
    }

    return 0;
}