#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <vector>
#include <algorithm>

using namespace std;

int stack[1000000];
bool isVisited[100001];
vector<vector<int>> edges(100001);

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

    stack[0] = 1;
    int top = 0;

    memset(isVisited, false, sizeof(isVisited));

    while (top >= 0)
    {
        int node = stack[top];
        top--;

        if (isVisited[node])
        {
            continue;
        }

        printf("%d ", node);
        isVisited[node] = true;

        for (int i = edges[node].size() - 1; i >= 0; --i)
        {
            top++;
            stack[top] = edges[node][i];
        }
    }

    return 0;
}