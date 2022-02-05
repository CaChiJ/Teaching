#include <iostream>
#include <vector>

using namespace std;

pair<int, int> tree[26];

void preorder(int node)
{
    printf("%c", node + 'A');
    if (tree[node].first != -1)  preorder(tree[node].first);
    if (tree[node].second != -1) preorder(tree[node].second);
}


void inorder(int node)
{
    if (tree[node].first != -1)  inorder(tree[node].first);
    printf("%c", node + 'A');
    if (tree[node].second != -1) inorder(tree[node].second);
}


void postorder(int node)
{
    if (tree[node].first != -1)  postorder(tree[node].first);
    if (tree[node].second != -1) postorder(tree[node].second);
    printf("%c", node + 'A');
}


int main(void)
{
    int N;
    scanf("%d ", &N);

    for (int i = 0; i < N; ++i)
    {
        char parent, left, right;
        scanf(" %c", &parent);
        scanf(" %c", &left);
        scanf(" %c", &right);

        if (left != '.') tree[parent - 'A'].first = left - 'A';
        else             tree[parent - 'A'].first = -1;

        if (right != '.') tree[parent - 'A'].second = right - 'A';
        else              tree[parent - 'A'].second = -1;
    }

    preorder(0);
    printf("\n");
    inorder(0);
    printf("\n");
    postorder(0);

    return 0;
}