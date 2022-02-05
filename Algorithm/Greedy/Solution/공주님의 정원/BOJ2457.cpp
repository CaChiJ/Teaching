#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    scanf("%d", &N);

    pair<int, int> flowers[N];

    for (int i = 0; i < N; ++i)
    {
        int startMonth, startDay;
        int endMonth, endDay;
        scanf("%d %d %d %d", &startMonth, &startDay, &endMonth, &endDay);

        flowers[i] = {startMonth * 100 + startDay, endMonth * 100 + endDay};
    }

    sort(flowers, flowers + N);
    int lastEnd = 301;
    int maxEnd = -1;
    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        if (flowers[i].first <= lastEnd)
        {
            maxEnd = max(maxEnd, flowers[i].second);

            if (maxEnd > 1130)
            {
                break;
            }
        }
        else
        {
            if (maxEnd == -1)
            {
                break;
            }

            lastEnd = maxEnd;
            maxEnd = -1;
            count++;
            i--;
        }
    }

    lastEnd = maxEnd;
    count++;

    if (lastEnd <= 1130)
    {
        printf("0\n");
    }
    else
    {
        printf("%d", count);
    }

    return 0;
}