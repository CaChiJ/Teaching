#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int q[N];
    int front = 0;
    int size = 0;

    for (int i = 0; i < N; ++i)
    {
        char command[16];
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            int num;
            scanf("%d", &num);
            q[front + size] = num;
            size++;
        }
        else if (strcmp(command, "pop") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q[front]);
                size--;
                front++;
            }
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", size);
        }
        else if (strcmp(command, "empty") == 0)
        {
            printf("%d\n", size == 0);
        }
        else if (strcmp(command, "front") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q[front]);
            }
        }
        else if (strcmp(command, "back") == 0)
        {
            if (size == 0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", q[front + size - 1]);
            }
        }
    }
}