#include <iostream>
#include <utility>
#include <climits>

using namespace std;

const int MAX_LEVEL = 10001;
const int MAX_N = 10000;

int count = 1;
int leftCol[MAX_LEVEL + 1];
int rightCol[MAX_LEVEL + 1];
pair<int, int> tree[MAX_N + 1];

void inorder(int node, int level) {
    // 왼쪽
    if (tree[node].first != -1) inorder(tree[node].first, level + 1);

    // 중간
    if (count < leftCol[level]) leftCol[level] = count;
    if (count > rightCol[level]) rightCol[level] = count;
    count++;

    // 오른쪽
    if (tree[node].second != -1) inorder(tree[node].second, level + 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);
    fill(leftCol, leftCol + MAX_LEVEL + 1, 99999);
    fill(rightCol, rightCol + MAX_LEVEL + 1, -1);

    bool isChild[N + 1];
    fill(isChild, isChild + N + 1, false);

    for (int i = 0; i < N; ++i)
    {
        int node, left, right;
        scanf("%d %d %d", &node, &left, &right);
        tree[node] = {left, right};
        isChild[left] = true;
        isChild[right] = true;
    }

    int root;

    for (int i = 1; i <= N; ++i)
    {
        if (!isChild[i])
        {
            root = i;
        }
    }

    inorder(root, 1);
    int maxWidth = -1;
    int maxLevel = 0;

    for (int i = 1; i <= MAX_LEVEL; ++i)
    {
        int width = rightCol[i] - leftCol[i] + 1;
        if (width > maxWidth)
        {
            maxWidth = width;
            maxLevel = i;
        }
    }

    printf("%d %d\n", maxLevel, maxWidth);

    return 0;
}