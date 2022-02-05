#include <iostream>

using namespace std;

void printPreorder(int in[], int post[], int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart == inEnd)
    {
        return;
    }

    int root = post[postEnd - 1];
    printf("%d ", root);

    int leftTreeSize;

    for (int i = inStart; i < inEnd; ++i)
    {
        if (in[i] == root)
        {
            leftTreeSize = i - inStart;
        }
    }

    printPreorder(in, post, inStart, inStart + leftTreeSize, postStart, postStart + leftTreeSize);
    printPreorder(in, post, inStart + leftTreeSize + 1, inEnd, postStart + leftTreeSize, postEnd - 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    int in[N];
    int post[N];

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", in + i);
    }

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", post + i);
    }

    printPreorder(in, post, 0, N, 0, N);

    return 0;
}