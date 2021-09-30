#include <stdio.h>
#include <string.h>

int main(void)
{
    const int MAX_SIZE = 1000001;
    char str[MAX_SIZE];
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    int wordCnt = 1;

    for (int i = 0; i < len; ++i)
    {
        wordCnt += str[i] == ' ';
    }

    wordCnt -= str[0] == ' ' || str[0] == '\n';
    wordCnt -= str[len - 2] == ' ';

    printf("%d", wordCnt);

    return 0;
}