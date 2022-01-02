#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int map[1000][1000];
int visited[1000][1000][2];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%1d", &(map[i][j]));
		}
	}
	
	int dist = 0;
	queue<pair<pair<int, int>, int> > q;
	q.push({{0, 0}, 0});
	
	while (!q.empty()) {
		dist++;
		int qSize = q.size();
		
		for (int qCnt = 0; qCnt < qSize; ++qCnt) {
			pair<pair<int, int>, int> node = q.front();
			q.pop();
			
			int x = node.first.first;
			int y = node.first.second;
			int z = node.second;
			
			if(x == M-1 && y == N-1) {
				printf("%d\n", dist);
				return 0;
			}
			
			if (visited[x][y][z] == 1) {
				continue;
			}
			
			visited[x][y][z] = 1;
			for (int d = 0; d < 4; ++d) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				
				if (0 <= nx && nx < M && 0 <= ny && ny < N && visited[nx][ny][z] == 0) {
					if (map[ny][nx] == 0) {
						q.push({{nx, ny}, z});
					} else if (z == 0 && visited[nx][ny][1] == 0) {
						q.push({{nx, ny}, 1});
					}
				}
			}
		}
	}
	
	printf("-1\n");
	return 0;
}
