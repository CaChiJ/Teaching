#include <iostream>
#include <vector>
#include <utility>
#include <stack>

using namespace std;

const int MAX_V = 100000;

vector<pair<int, int>> tree[MAX_V];

pair<int, int> dfs(int node, bool visit[])
{
    visit[node] = true;
    pair<int, int> farNode = {node, 0};

    for (int i = 0; i < tree[node].size(); ++i)
    {
        if (!visit[tree[node][i].first])
        {
            pair<int, int> newNode = dfs(tree[node][i].first, visit);

            if (farNode.second < newNode.second + tree[node][i].second)
            {
                farNode.first = newNode.first;
                farNode.second = newNode.second + tree[node][i].second;
            }
        }
    }

    return farNode;
}

int main(void)
{
    int V;
    scanf("%d", &V);

    bool visit[MAX_V];
    fill(visit, visit + MAX_V, false);

    for (int i = 0; i < V; ++i)
    {
        int node;
        scanf("%d", &node);
        node--;

        while (true)
        {
            int other;
            scanf("%d", &other);
            other--;

            if (other == -2)
            {
                break;
            }

            int dist;
            scanf("%d", &dist);

            tree[node].push_back({other, dist});
            tree[other].push_back({node, dist});
        }
    }

    pair<int, int> node1 = dfs(0, visit);
    fill(visit, visit + MAX_V, false);
    pair<int, int> node2 = dfs(node1.first, visit);
    printf("%d\n", node2.second);
    return 0;
}