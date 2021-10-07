#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);

    int prior = -1;
    int i = 0;

    for (i = 0; i < N; ++i)
    {
        int num;
        scanf("%d", &num);

        if (prior > num)
        {
            if (prior != num + 1)
            {
                break;
            }
        }

        prior = num;
    }

    if (i == N)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}