#include <stdio.h>

const int ALPHABET_COUNT = 26;

int main(void)
{
    int cnt = 0;
    int isAppearAt[26];

    for (int i = 0; i < 26; ++i)
    {
        isAppearAt[i] = -1;
    }

    while (1)
    {
        char ch;
        scanf("%c", &ch);

        if (ch == '\n')
        {
            break;
        }

        ch -= 'a';

        if (isAppearAt[ch] == -1)
        {
            isAppearAt[ch] = cnt;
        }

        cnt++;
    }

    for (int i = 0; i < ALPHABET_COUNT; ++i)
    {
        printf("%d ", isAppearAt[i]);
    }
}