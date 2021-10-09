#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <vector>
#include <algorithm>

using namespace std;

bool isVisited[100001];
vector<vector<int>> edges(100001);

void dfs(int n)
{
    printf("%d ", n);
    isVisited[n] = true;

    for (int i = 0; i < edges[n].size(); ++i)
    {
        if (!isVisited[edges[n][i]])
        {
            dfs(edges[n][i]);
        }
    }
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(1);

    return 0;
}