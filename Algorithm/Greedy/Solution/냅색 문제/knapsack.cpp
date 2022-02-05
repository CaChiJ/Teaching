#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int W;
    int N;
    scanf("%d", &W);
    scanf("%d", &N);
    pair<double, pair<int, int>> jewels[N];

    for (int i = 0; i < N; ++i)
    {
        int w, v;
        scanf("%d %d", &w, &v);
        jewels[i].first = v / (double)w;
        jewels[i].second = {w, v};
    }

    double profit = 0;
    sort(jewels, jewels + N, greater<>());

    for (int i = 0; i < N; ++i)
    {
        if (W <= jewels[i].second.first)
        {
            profit += W * jewels[i].first;
            W = 0;
            break;
        }

        profit += jewels[i].second.second;
        W -= jewels[i].second.first;
    }

    printf("%.2f\n", profit);

    return 0;
}