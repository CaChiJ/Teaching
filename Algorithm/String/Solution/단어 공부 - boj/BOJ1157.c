#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    const int MAX_SIZE = 1000001;
    const int ALPHABET_COUNT = 26;

    char str[MAX_SIZE];
    fgets(str, MAX_SIZE, stdin);
    int count[ALPHABET_COUNT];
    memset(count, 0, sizeof(count));

    {
        int cnt = 0;
        while (str[cnt] != '\0')
        {
            if (isupper(str[cnt]))
            {
                count[str[cnt] - 'A']++;
            }
            else
            {
                count[str[cnt] - 'a']++;
            }

            cnt++;
        }
    }

    int maxCount = 0;
    char maxChar = '?';

    for (int i = 0; i < ALPHABET_COUNT; ++i)
    {
        if (maxCount < count[i])
        {
            maxCount = count[i];
            maxChar = 'A' + i;
        }
        else if (maxCount == count[i])
        {
            maxChar = '?';
        }
    }

    printf("%c", maxChar);

    return 0;
}