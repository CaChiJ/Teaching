#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    scanf("%d ", &N);

    int stack[10000];
    int start = 0;
    int end = 0;

    for (int c = 0; c < N; ++c)
    {
        char command[7];
        scanf("%s", command);

        if (strcmp(command, "push") == 0)
        {
            scanf("%d ", stack + end);
            end++;
        }
        else if (strcmp(command, "pop") == 0)
        {
            if (start == end)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[end - 1]);
                end--;
            }
        }
        else if (strcmp(command, "size") == 0)
        {
            printf("%d\n", end - start);
        }
        else if (strcmp(command, "empty") == 0)
        {
            printf("%d\n", end - start == 0);
        }
        else if (strcmp(command, "top") == 0)
        {
            if (start == end)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", stack[end - 1]);
            }
        }
        else
        {
            printf("??");
        }
    }

    return 0;
}