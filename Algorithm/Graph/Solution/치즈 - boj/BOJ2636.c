#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ySize;
int xSize;

bool isValidPos(int x, int y)
{
    return 0 <= x && x < xSize && 0 <= y && y < ySize);
}

int main(void)
{
    const int dx = {0, 1, 0, -1};
    const int dy = {1, 0, -1, 0};

    scanf("%d %d", &ySize, &xSize);

    int queue[(ySize + 2) * (xSize + 2)][2];
    int head = 0;
    int tail = 0;

    int map[ySize][xSize];

    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            scanf("%d", &map[y][x]);
        }
    }

    for (int i = 0; i < xSize; ++i)
    {
        queue[tail][0] = -1;
        queue[tail][1] = i;
        tail++;
        queue[tail][0] = ySize;
        queue[tail][1] = i;
        tail++;
    }

    for (int i = 0; i < ySize; ++i)
    {
        queue[tail][0] = i;
        queue[tail][1] = -1;
        tail++;
        queue[tail][0] = i;
        queue[tail][1] = xSize;
        tail++;
    }

    while (tail <= head)
    {
        int y = queue[head][0];
        int x = queue[head][1];
        head++;

        for (int d = 0; d < 4; ++d)
        {
            int nextY = y + dy[d];
            int nextX = x + dx[d];

            if (isValidPos(nextX, nextY))
            {
            }
        }
    }

    return 0;
}