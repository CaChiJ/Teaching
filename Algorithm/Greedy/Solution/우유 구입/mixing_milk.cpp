#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);

    pair<int, int> sellers[M];

    for (int i = 0; i < M; ++i)
    {
        int P, A;
        scanf("%d %d", &P, &A);
        sellers[i] = {P, A};
    }

    sort(sellers, sellers + M);
    int price = 0;

    for (int i = 0; i < M; ++i)
    {
        if (N <= sellers[i].second)
        {
            price += sellers[i].first * N;
            break;
        }

        price += sellers[i].first * sellers[i].second;
        N -= sellers[i].second;
    }

    printf("%d\n", price);

    return 0;
}