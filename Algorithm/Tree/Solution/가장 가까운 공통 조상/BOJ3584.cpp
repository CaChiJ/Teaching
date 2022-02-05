#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int number;
    Node *parent;
    vector<Node *> children;
};

int hasNode(Node *parent, int a, int b)
{
    int count = 0;

    if (parent->number == a || parent->number == b)
    {
        count++;
    }

    for (int i = 0; i < parent->children.size(); ++i)
    {
        int subResult = hasNode(parent->children[i], a, b);

        if (subResult == 2)
        {
            return 2;
        }
        else if (subResult == 1)
        {
            count++;
            if (count == 2)
            {
                printf("%d\n", parent->number + 1);
                return 2;
            }
        }
    }

    return count;
}

int main(void)
{
    int TC;
    scanf("%d", &TC);

    for (int tcCnt = 0; tcCnt < TC; ++tcCnt)
    {
        int N;
        scanf("%d", &N);

        Node nodes[N];

        for (int i = 0; i < N; ++i)
        {
            nodes[i].number = i;
            nodes[i].parent = NULL;
        }

        for (int i = 0; i < N - 1; ++i)
        {
            int p, c;
            scanf("%d %d", &p, &c);
            p--;
            c--;
            nodes[c].parent = nodes + p;
            nodes[p].children.push_back(nodes + c);
        }

        int a, b;
        scanf("%d %d", &a, &b);
        a--;
        b--;

        int root = -1;

        for (int i = 0; i < N; ++i)
        {
            if (nodes[i].parent == NULL)
            {
                root = i;
                break;
            }
        }

        hasNode(nodes + root, a, b);
    }
    return 0;
}