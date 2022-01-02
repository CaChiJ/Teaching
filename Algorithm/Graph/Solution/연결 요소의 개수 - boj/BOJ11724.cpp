#include <iostream>
#include <stack>

using namespace std;

int adj[1000][1000];
int visited[1000];

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < M; ++i) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		n1--;
		n2--;
		adj[n1][n2] = adj[n2][n1] = 1;
	}
	
	stack<int> stk;
	int count = 0;
	
	for (int i = 0; i < N; ++i) {
		if (visited[i] == 0) {
			count++;
			stk.push(i);
			
			while (!stk.empty()) {
				int node = stk.top();
				stk.pop();
				
				if(visited[node] == 1) {
					continue;
				}
				
				visited[node] = 1;
				
				for (int j = 0; j < N; ++j) {
					if (adj[node][j] == 1 && visited[j] == 0) {
						stk.push(j);
					}
				}
			}
		}
	}
	
	printf("%d\n", count);
	return 0;
}
