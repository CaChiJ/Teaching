#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    bool edges[N + 1][N + 1];
    memset(edges, false, sizeof(edges));

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        edges[a][b] = true;
        edges[b][a] = true;
    }

    int stack[100];
    stack[0] = 1;
    int top = 0;
    int cnt = 0;

    bool isVisited[N + 1];
    memset(isVisited, false, sizeof(isVisited));
    isVisited[1] = true;

    while (top >= 0)
    {
        int node = stack[top];
        top--;

        for (int i = 1; i <= N; ++i)
        {
            if (edges[node][i] && !isVisited[i])
            {
                isVisited[i] = true;
                top++;
                stack[top] = i;
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}