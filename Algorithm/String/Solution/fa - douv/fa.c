#include <stdio.h>
#include <string.h>

int main(void)
{
    const int ALPHABET_COUNT = 26;
    int count[ALPHABET_COUNT];
    memset(count, 0, sizeof(count));

    char str[101];
    fgets(str, sizeof(str), stdin);

    {
        int cnt = 0;

        while (str[cnt] != '\0')
        {
            count[str[cnt] - 'a']++;
            cnt++;
        }
    }

    for (int i = 0; i < ALPHABET_COUNT; ++i)
    {
        printf("%c:%d\n", 'a' + i, count[i]);
    }

    return 0;
}