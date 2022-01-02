#include <iostream>
#include <utility>

using namespace std;

int cache[41][2];

pair<int, int> fibo(int n)
{
    if(cache[n][0] != 0 || cache[n][1] != 0)
    {
        return make_pair(cache[n][0], cache[n][1]);
    }
    
    pair<int, int> result1 = fibo(n - 2);
    pair<int, int> result2 = fibo(n - 1);
    
    cache[n][0] = result1.first + result2.first;
    cache[n][1] = result1.second + result2.second;
    
    return make_pair(cache[n][0], cache[n][1]);
}

int main(void)
{
    int T, N;
    cin>>T;
    
    cache[0][0] = 1;
    cache[1][1] = 1;
    
    for(int i = 0; i < T; ++i)
    {
        cin>>N;
        pair<int, int> result = fibo(N);
        cout<<result.first<<' '<<result.second<<'\n';
    }
    
    return 0;
}
