#include <stdio.h>

int main(void)
{
    int stack[10000];
    int top = -1;

    int N;
    scanf("%d", &N);
    int i = 0;
    for (i = 0; i < N; ++i)
    {
        int input;
        scanf("%d", &input);
        if (stack[top] > input)
        {
            if (stack[top] - 1 != input)
            {
                break;
            }

            top = -1;
            stack[++top] = input;
        }
        else
        {
            stack[++top] = input;
        }
    }

    if (i != N)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }

    return 0;
}
