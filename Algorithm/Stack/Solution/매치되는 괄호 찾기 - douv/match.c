#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    char str[51];
    scanf("%s", str);

    char stack[51][2];
    int size = 0;

    int pairs[25][2];
    int pairCount = 0;

    bool isMatched = true;

    for (int i = 0; i < strlen(str); ++i)
    {
        char ch = str[i];

        if (ch == '(' || ch == '{')
        {
            stack[size][0] = ch;
            stack[size][1] = i;
            size++;
        }
        else if (ch == ')')
        {
            if (size > 0 && stack[size - 1][0] == '(')
            {
                pairs[pairCount][0] = stack[size - 1][1];
                pairs[pairCount][1] = i;
                pairCount++;
                size--;
            }
            else
            {
                isMatched = false;
                break;
            }
        }
        else if (ch == '}')
        {
            if (size > 0 && stack[size - 1][0] == '{')
            {
                pairs[pairCount][0] = stack[size - 1][1];
                pairs[pairCount][1] = i;
                pairCount++;
                size--;
            }
            else
            {
                isMatched = false;
                break;
            }
        }
    }

    if (isMatched && size == 0)
    {
        for (int i = 0; i < pairCount; ++i)
        {
            printf("%d %d\n", pairs[i][0], pairs[i][1]);
        }
    }
    else
    {
        printf("not match\n");
    }

    return 0;
}