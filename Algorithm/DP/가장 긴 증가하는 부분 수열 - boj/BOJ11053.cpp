#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin>>N;
	int inputs[N];
	int DP[N + 1];
    
    for(int i = 0; i < N; ++i)
    {
        cin>>inputs[i];
        DP[i] = 1;
        int maxV = 0;
        for(int j = 0; j < i; ++j)
        {
            if(inputs[i] > inputs[j]) DP[i] = max(DP[i], DP[j] + 1);
        }
    }
    
    int maxV = 0;
    for(int i = 0; i < N; ++i)
    {
    	maxV = maxV > DP[i] ? maxV : DP[i];
	}
	
	cout<<maxV<<'\n';
    
    return 0;
}
