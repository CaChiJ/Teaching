#include <iostream>

using namespace std;

int main(void)
{
    int N, K;
    scanf("%d %d", &N, &K);

    int A[N] = {0};

    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }

    int count = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        count += K / A[i];
        K %= A[i];
    }

    printf("%d\n", count);

    return 0;
}