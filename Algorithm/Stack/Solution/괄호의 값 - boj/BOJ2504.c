#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char str[32];
    scanf("%s", str);
    int len = strlen(str);
    char stack[32];
    int size = 0;
    bool isCorrect = true;
    int result = 0;

    {
        int tmp = 1;

        for (int i = 0; i < len; ++i)
        {

            switch ((int)str[i])
            {
            case '(':
                stack[size] = str[i];
                size++;
                tmp *= 2;
                break;

            case '[':
                stack[size] = str[i];
                size++;
                tmp *= 3;
                break;

            case ')':
                if (size < 1 || stack[size - 1] != '(')
                {
                    isCorrect = false;
                    i = len;
                    break;
                }

                if (str[i - 1] == '(')
                {
                    result += tmp;
                }

                tmp /= 2;
                size--;

                break;

            case ']':
                if (size < 1 || stack[size - 1] != '[')
                {
                    isCorrect = false;
                    i = len;
                    break;
                }

                if (str[i - 1] == '[')
                {
                    result += tmp;
                }

                tmp /= 3;
                size--;

                break;
            }
        }
    }

    if (isCorrect && size == 0)
    {
        printf("%d", result);
    }
    else
    {
        printf("%d", 0);
    }
}