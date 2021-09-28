#include <iostream>

int gcd(int a, int b)
{
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int mod = a % b;

    if (mod == 0)
    {
        return b;
    }

    return gcd(b, mod);
}

int main(void)
{
    int a, b;
    std::cin >> a >> b;
    int g = gcd(a, b);
    std::cout << g << ' ' << (long long)a * b / g << std::endl;
    return 0;
}