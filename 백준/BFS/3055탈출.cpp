#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>
using namespace std; 

int r, c;
int water[51][51]; // 각 칸에 물이 몇분에 차는지 기록한다.
int dist[51][51]; // 각 칸에 고슴도치가 몇 분에 도착하는 지 기록한다. 
int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0, -1, 1 };

bool isOut(int y, int x) {
	return (y < 0 || y >= r || x < 0 || x >= c); 
}

int main() {
	cin >> r >> c; 
	vector<string> board(r);
	for (int i = 0; i < r; i++)
		cin >> board[i]; 

	memset(water, -1, sizeof(water));
	pair<int, int> start, end;
	queue<pair<int, int>>q; 
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++){
			if (board[i][j] == '*') {
				water[i][j] = 0;
				q.push(make_pair(i, j)); 
			}
			if (board[i][j] == 'S')
				start.first = i, start.second = j; 
			if (board[i][j] == 'D')
				end.first = i, end.second = j; 
		}

	// 각 칸이 몇 분 뒤에 물에 차는 지 기록
	while (!q.empty()) {
		int y, x; 
		tie(y, x) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx)) continue; 
			if (water[ny][nx] != -1) continue; // 이미 물이 차있음
			if (board[ny][nx] == 'D' || board[ny][nx] == 'X') continue; 
			water[ny][nx] = water[y][x] + 1; 
			q.push(make_pair(ny, nx)); 
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q2; 
	dist[start.first][start.second] = 0; // 출발점 : S
	q2.push(make_pair(start.first, start.second)); 

	while (!q2.empty()) {
		int y, x;
		tie(y, x) = q2.front(); q2.pop(); 
		
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 

			// 이동할 수 없는 경우 : 숲 바깥, 돌, 물
			if (isOut(ny, nx) || board[ny][nx] == 'X')  continue;
			// 언젠가  물이 닿을 칸이라면, 그 시간이 지금, 그리고 1분 후에만 안 일어나면 이동할 수 있다
			if (dist[ny][nx] != -1) continue; // 이미 방문한 곳
			if (water[ny][nx] != -1 && water[ny][nx] <= dist[y][x] + 1) continue;
			dist[ny][nx] = dist[y][x] + 1; 
			q2.push(make_pair(ny, nx));
		}
	}
	
	if (dist[end.first][end.second] == -1) 
		cout << "KAKTUS" << endl;
	else 
		cout << dist[end.first][end.second] << endl;
	return 0;
}