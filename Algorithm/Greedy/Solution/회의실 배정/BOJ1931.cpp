#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d", &N);

    pair<int, int> meetings[N];

    for (int i = 0; i < N; ++i)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        meetings[i] = {end, start};
    }

    sort(meetings, meetings + N);
    int last = -1;
    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        if (meetings[i].second >= last)
        {
            last = meetings[i].first;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}