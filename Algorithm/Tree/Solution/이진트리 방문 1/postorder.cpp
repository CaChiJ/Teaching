#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> tree[21];

void preOrder(int node)
{
    // 왼쪽
    int left;
    scanf("%d", &left);
    if (left != -1)
    {
        tree[node].push_back(left);
        preOrder(left);
    }

    // 오른쪽
    int right;
    scanf("%d", &right);
    if (right != -1)
    {
        tree[node].push_back(right);
        preOrder(right);
    }
}

void postOrder(int node)
{
    for (int i = 0; i < tree[node].size(); ++i)
    {
        postOrder(tree[node][i]);
    }

    printf("%d ", node);

    return;
}

int main(void)
{
    int root;
    scanf("%d", &root);
    preOrder(root);
    postOrder(root);

    return 0;
}