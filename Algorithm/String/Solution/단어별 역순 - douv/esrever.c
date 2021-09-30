#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[81];

    while (scanf("%s", word) != EOF)
    {
        int len = strlen(word);

        for (int i = len - 1; i >= 0; --i)
        {
            printf("%c", word[i]);
        }

        printf(" ");
    }

    return 0;
}