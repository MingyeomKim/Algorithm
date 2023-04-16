#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std; 

int h, w; 
char board[101][101]; 
int dist[101][101]; 
int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0,0, 1, -1 }; 

bool isOut(int y, int x) {
	return (y < 0 || y >= h || x < 0 || x >= w); 
}

int main() {
	cin >> w >> h;
	int sy, sx, ey, ex; 

	int cnt = 0; 
	for(int i = 0;i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> board[i][j]; 
			if (cnt == 0 && board[i][j] == 'C') {
				cnt++; 
				sy = i, sx = j; 
				board[i][j] = '.';
			}
			else if (board[i][j] == 'C') {
				ey = i, ex = j; 
				board[i][j] = '.';
			}
		}
	memset(dist, -1, sizeof(dist)); 
	queue<pair<int, int>> q; 
	q.push(make_pair(sy, sx)); 
	dist[sy][sx] = 0; 
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			while (!isOut(ny, nx)) {
				if (board[ny][nx] == '*') break;
				if(dist[ny][nx] == -1){
					dist[ny][nx] = dist[y][x] + 1; 
					q.push(make_pair(ny, nx)); 
				}
				ny += dy[direction], nx += dx[direction];
			}
		}
	}
	// 꺾이지 않은 선 하나에 있는 모든 칸들의 dist는 값이 같다. 
	// 총 2번 꺾인 경우에는 dist[ey][ex] = 3이므로, 1을 빼준다.
	cout << dist[ey][ex] - 1 << endl;
	return 0; 
}