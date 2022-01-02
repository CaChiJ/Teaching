#include <stdio.h>

int adj[1000][1000];
int visited[1000];

int main(void) {
	int V, E;
	scanf("%d %d", &V, &E);
	
	for (int i = 0; i < E; ++i) {
		int n1, n2;
		scanf("%d %d", &n1, &n2);
		adj[n1][n2] = adj[n2][n1] = 1;
	}
	
	int queue[V];
	queue[0] = 0;
	int front = 0;
	int back = 1;
	
	while (front < back) {
		int node = queue[front];
		front++;
		
		if (visited[node] == 1) {
			continue;
		}
		
		printf("%d ", node);
		visited[node] = 1;
		
		for (int i = 0; i < V; ++i) {
			if (adj[node][i] == 1 && visited[i] == 0) {
				queue[back] = i;
				back++;
			}
		}
	}
	
	return 0;
}
