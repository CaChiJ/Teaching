#include <stdio.h>

int main(void)
{
    int d, r;
    scanf("%d %d", &d, &r);

    char result[14]; // 2^14 = 16384
    int cnt = 0;

    do
    {
        int mod = d % r;
        result[cnt] = mod < 10 ? mod + '0' : (mod - 10) + 'A';
        d /= r;
        cnt++;
    } while (d != 0);

    for (int i = cnt - 1; i >= 0; --i)
    {
        printf("%c", result[i]);
    }

    return 0;
}