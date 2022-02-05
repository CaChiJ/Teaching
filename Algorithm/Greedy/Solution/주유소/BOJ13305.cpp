#include <iostream>
#include <climits>

using namespace std;

int main(void)
{
    int N;
    scanf("%d", &N);

    long long road[N - 1];
    int minCost = INT_MAX;
    long long costSum = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        scanf("%lld", road + i);
    }

    for (int i = 0; i < N - 1; ++i)
    {
        int cost;
        scanf("%d", &cost);
        minCost = min(minCost, cost);

        costSum += minCost * road[i];
    }

    printf("%lld\n", costSum);

    return 0;
}