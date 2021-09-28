#include <stdio.h>

int gcd(int a, int b)
{
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    if (a % b == 0)
    {
        return b;
    }

    return gcd(b, a % b);
}

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    int g = gcd(a, b);
    printf("%d %lld\n", g, (long long)a * b / g);
    return 0;
}