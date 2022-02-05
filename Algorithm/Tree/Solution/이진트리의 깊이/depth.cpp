#include <iostream>
#include <vector>

using namespace std;

int count = 0;

int preorder(int node)
{
    // 왼쪽
    int left;
    int leftDepth = -1;
    scanf("%d", &left);
    if (left != -1)
    {
        leftDepth = preorder(left) + 1;
    }

    // 오른쪽
    int right;
    int rightDepth = -1;
    scanf("%d", &right);
    if (right != -1)
    {
        rightDepth = preorder(right) + 1;
    }

    if (left != -1 && right != -1)
    {
        count++;
    }

    return max(leftDepth, rightDepth);
}

int main(void)
{
    int root;
    scanf("%d", &root);
    int depth = preorder(root) + 2;

    printf("%d\n%d", count, depth);

    return 0;
}