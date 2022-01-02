#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int map[50][50];
int h, w;
const int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int r, int c)
{
    map[r][c] = 0;

    for (int i = 0; i < 8; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (0 <= nr && nr < h && 0 <= nc && nc < w && map[nr][nc] == 1)
        {
            dfs(nr, nc);
        }
    }
}

int main(void)
{
    while (true)
    {
        scanf("%d %d", &w, &h);

        if (w == 0 && h == 0)
        {
            break;
        }

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                scanf("%d", &(map[i][j]));
            }
        }

        int count = 0;

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (map[i][j] == 1)
                {
                    dfs(i, j);
                    count++;
                }
            }
        }

        printf("%d\n", count);
    }
}