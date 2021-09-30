#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char key[26];

    for (int i = 0; i < 26; ++i)
    {
        char ch;
        scanf("%c ", &ch);
        key[i] = tolower(ch) - 'a';
    }

    char text[82];
    fgets(text, sizeof(text), stdin);
    int len = strlen(text);
    text[len - 1] = '\0';
    len--;

    for (int i = 0; i < len; ++i)
    {
        if (islower(text[i]))
        {
            printf("%c", key[text[i] - 'a'] + 'a');
        }
        else if (isupper(text[i]))
        {
            printf("%c", key[text[i] - 'A'] + 'A');
        }
        else
        {
            printf("%c", text[i]);
        }
    }

    return 0;
}