#include <iostream>
#include <queue>
using namespace std;

int board[9][9]; 
int n, m;

int dy[4] = { 0, 0, -1, 1 }; 
int dx[4] = { -1, 1, 0, 0 }; 

bool isOut(pair<int, int>& p) {
	int y = p.first, x = p.second; 
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

int bfs() {
	queue<pair<int, int>> q;
	int info[9][9]; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			info[i][j] = board[i][j]; 
			if (info[i][j] == 2) q.push(make_pair(i, j)); 
		}

	// BFS로 바이러스가 퍼진 영역의 개수를 구한다.
	while (!q.empty()) {
		pair<int, int> here = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			pair<int, int> there = make_pair(here.first + dy[direction], here.second + dx[direction]);
			// 다음 칸이 빈칸이면 바이러스가 전염된다.
			if (!isOut(there)) {
				if(info[there.first][there.second] == 0){
					q.push(there);
					info[there.first][there.second] = 2;
				}
			}
		}
	}

	int cnt = 0; // 안전 영역의 수 계산
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (info[i][j] == 0) cnt++;
	return cnt; 
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j]; 

	int ret = 0; 
	// 세 개의 벽을 세우는 모든 경우를 탐색한다.
	for(int y1 = 0; y1 < n; y1++)
		for (int x1 = 0; x1 < m; x1++) {
			if (board[y1][x1] != 0) continue;  // 빈 칸이 아니면 패스
			for(int y2 = 0; y2 < n; y2++)
				for (int x2 = 0; x2 < m; x2++) {
					if (board[y2][x2] != 0) continue; 
					for(int y3 = 0; y3 < n; y3++)
						for (int x3 = 0; x3 < m; x3++) {
							if (board[y3][x3] != 0) continue; 
							if (y1 == y2 && x1 == x2) continue; 
							if (y1 == y3 && x1 == x3) continue; 
							if (y2 == y3 && x2 == x3) continue; 
							board[y1][x1] = 1;
							board[y2][x2] = 1;
							board[y3][x3] = 1;
							int cand = bfs();
							if (ret < cand) ret = cand; 
							board[y1][x1] = 0;
							board[y2][x2] = 0;
							board[y3][x3] = 0;
						}
				}
		}
	cout << ret << endl;

	return 0; 
}