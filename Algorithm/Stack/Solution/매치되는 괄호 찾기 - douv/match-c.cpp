#include <stdio.h>
#include <string.h>
#include <stack>
#include <utility>

using namespace std;

int main(void)
{
    char str[51];
    scanf("%s", str);

    stack<pair<int, int>> stk;

    int pairs[25][2];
    int pairCount = 0;

    bool isMatched = true;

    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == '(' || str[i] == '{')
        {
            stk.push({str[i], i});
        }
        else if (str[i] == ')')
        {
            if (!stk.empty() && stk.top().first == '(')
            {
                pairs[pairCount][0] = stk.top().second;
                pairs[pairCount][1] = i;
                pairCount++;
                stk.pop();
            }
            else
            {
                isMatched = false;
                break;
            }
        }
        else if (str[i] == '}')
        {
            if (!stk.empty() && stk.top().first == '{')
            {
                pairs[pairCount][0] = stk.top().second;
                pairs[pairCount][1] = i;
                pairCount++;
                stk.pop();
            }
            else
            {
                isMatched = false;
                break;
            }
        }
    }

    if (isMatched && stk.empty())
    {
        for (int i = 0; i < pairCount; ++i)
        {
            printf("%d %d\n", pairs[i][0], pairs[i][1]);
        }
    }
    else
    {
        printf("not match\n");
    }

    return 0;
}