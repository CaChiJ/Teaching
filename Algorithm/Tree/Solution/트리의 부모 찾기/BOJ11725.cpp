#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void)
{
    // input
    int N;
    scanf("%d", &N);
    vector<int> graph[N + 1];

    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool visit[N + 1];
    fill(visit, visit + N + 1, false);

    // dfs
    stack<int> stk;
    stk.push(1);
    int parent[N + 1];

    while (!stk.empty())
    {
        int top = stk.top();
        stk.pop();

        for (int i = 0; i < graph[top].size(); ++i)
        {
            int child = graph[top][i];

            if (!visit[child])
            {
                visit[child] = true;
                parent[child] = top;
                stk.push(child);
            }
        }
    }

    for (int i = 2; i <= N; ++i)
    {
        printf("%d\n", parent[i]);
    }

    return 0;
}