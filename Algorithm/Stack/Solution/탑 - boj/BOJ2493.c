#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int h[N];

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", h + i);
    }

    int stack[500000]; // 탑의 번호가 저장됨. 탑의 번호를 h(높이 배열)의 인덱스로 하여 각 탑의 높이를 구할 수 있음.
    int size = 0;

    for (int i = 0; i < N; ++i)
    {
        while (size > 0 && h[stack[size - 1]] < h[i])
        {
            size--;
        }

        if (size == 0)
        {
            printf("%d ", 0);
        }
        else
        {
            printf("%d ", stack[size - 1] + 1);
        }

        stack[size] = i;
        size++;
    }

    return 0;
}