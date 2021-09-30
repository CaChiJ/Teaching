#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101];
    scanf("%s", str);
    int len = strlen(str);

    printf("%c", str[0]);

    for (int i = 1; i < len; ++i)
    {
        if ((len - i) % 3 == 0)
        {
            printf(",");
        }

        printf("%c", str[i]);
    }

    return 0;
}