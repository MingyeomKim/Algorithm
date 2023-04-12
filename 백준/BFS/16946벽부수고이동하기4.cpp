#include <iostream>
#include <queue> 
#include <cstring>
#include <tuple>
#include <set>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std; 

int n, m; 
int board[1001][1001]; 
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
bool dist[1001][1001]; 
int group[1001][1001]; // 칸 (i, j)의 그룹의 번호를 저장한다.
vector<int> group_size; 
int countFor[1001][1001]; 

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

// 빈 칸들을 같은 그룹으로 묶는다.
void bfs(int sy, int sx) {
	int g = group_size.size(); 

	queue<pair<int, int>> q; 
	q.push(make_pair(sy, sx)); 
	dist[sy][sx] = true; 
	group[sy][sx] = g; 

	int cnt = 1; // g 그룹에 포함된 빈 칸의 개수
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx)) continue; 
			if (board[ny][nx] == 0 && dist[ny][nx] == false) {
				dist[ny][nx] = true;
				cnt++; 
				group[ny][nx] = group[y][x]; 
				q.push(make_pair(ny, nx));
			}
		}
	}
	group_size.push_back(cnt); 
}


int main() {
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
			dist[i][j] = false;
			group[i][j] = -1;
		}

	// 모든 빈 칸에 대한 그룹 번호를 지정
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			// 빈 칸이고, 방문하지 않았다면
			if (board[i][j] == 0 && dist[i][j] == false)
				bfs(i, j); 
		}

	// 그룹에 따라 벽을 마주쳤을 때 몇 개의 빈 칸을 지날 수 있는지 검사한다
	for(int y = 0; y < n; y++){
		for (int x = 0; x < m; x++) {
			if (board[y][x] == 0)
				cout << 0; 
			else { // 벽이 발견되면
				set<int> near; 
				for (int direction = 0; direction < 4; direction++) {
					int ny = y + dy[direction], nx = x + dx[direction]; 
					if (isOut(ny, nx)) continue; 
					if (board[ny][nx] == 0)
						near.insert(group[ny][nx]); // 이 벽을 부수어서 방문할 수 있는 그룹을 담는다. 
				}

				// near 그룹들을 방문하며 방문할 수 있는 모든 칸의 개수 저장
				int ret = 1; 
				for (int g : near)
					ret += group_size[g]; 
				cout << ret % 10; 
			}
		}
		cout << endl;
	}


	return 0; 
}