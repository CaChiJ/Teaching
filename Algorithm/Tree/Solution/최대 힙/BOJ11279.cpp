#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void push_heap(vector<int> &heap, int value)
{
    heap.push_back(value);

    int idx = heap.size() - 1;

    while (idx > 0 && heap[(idx - 1) / 2] < heap[idx])
    {
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

int pop_heap(vector<int> &heap)
{
    int result = heap[0];
    heap[0] = heap.back();
    heap.pop_back();

    int idx = 0;
    while (true)
    {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;

        if (left >= heap.size())
        {
            break;
        }

        int next = idx;
        if (heap[left] > heap[idx])
        {
            next = left;
        }
        if (right < heap.size() && heap[next] < heap[right])
        {
            next = right;
        }

        if (next == idx)
        {
            break;
        }

        swap(heap[next], heap[idx]);
        idx = next;
    }

    return result;
}

int main(void)
{
    int N;
    scanf("%d", &N);

    vector<int> heap;

    for (int i = 0; i < N; ++i)
    {
        int x;
        scanf("%d", &x);

        if (x == 0)
        {
            if (heap.size() == 0)
            {
                printf("0\n");
            }
            else
            {
                printf("%d\n", pop_heap(heap));
            }
        }
        else
        {
            push_heap(heap, x);
        }
    }

    return 0;
}