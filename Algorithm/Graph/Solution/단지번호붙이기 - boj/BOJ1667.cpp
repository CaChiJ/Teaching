#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int map[25][25];
int N;

int dfs(int r, int c)
{
    map[r][c] = 0;
    int count = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];

        if (0 <= nr && nr < N && 0 <= nc && nc < N && map[nr][nc] == 1)
        {
            count += dfs(nr, nc);
        }
    }

    return count;
}

int main(void)
{
    scanf("%d", &N);
    vector<int> groupSize;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%1d", &(map[i][j]));
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] == 1)
            {
                groupSize.push_back(dfs(i, j));
            }
        }
    }

    sort(groupSize.begin(), groupSize.end());

    printf("%lu\n", groupSize.size());

    for (int i = 0; i < groupSize.size(); ++i)
    {
        printf("%d\n", groupSize[i]);
    }

    return 0;
}