#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <tuple>
using namespace std; 

int h, w;
int dy[4] = { -1, 1,0, 0 }; 
int dx[4] = { 0, 0, 1, -1 }; 

bool isOut(int y, int x) {
	return y < 0 || y >= h || x < 0 || x >= w; 
}

// 모든 칸으로 가는 문을 여는 최소 횟수를 구한다.
vector<vector<int>> bfs(vector<string> &board, int y, int x) {
	vector <vector<int>> dist(h, vector<int>(w)); 
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			dist[i][j] = -1; 

	deque<pair<int, int>>q;
	q.push_back(make_pair(y, x)); 
	dist[y][x] = 0; 
	while (!q.empty()) {
		int u, v; tie(u, v) = q.front(); q.pop_front(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = u + dy[direction], nx = v + dx[direction]; 
			if (isOut(ny, nx) || board[ny][nx] == '*' || dist[ny][nx] != -1) continue;
			if (board[ny][nx] == '#') {
				dist[ny][nx] = dist[u][v] + 1;
				q.push_back(make_pair(ny, nx)); // 왜 다르게 ? 
			}
			else {
				dist[ny][nx] = dist[u][v];
				q.push_front(make_pair(ny, nx));
			}
		}
	}
	return dist; 
}

int main() {
	int t; cin >> t; 
	while (t--) {
		cin >> h >> w; 
		vector<string> board(h + 2);
		for (int i = 0; i < w + 2; i++) {
			board[0] += ".";
			board[h + 1] += "."; 
		}

		int y1, x1, y2, x2; 
		y1 = x1 = y2 = x2 = -1; 
		for (int i = 1; i <= h; i++) {
			cin >> board[i]; 
			board[i] = "." + board[i] + ".";
			for (int j = 1; j <= w; j++) {
				if (board[i][j] == '$') {
					board[i][j] = '.';
					if (y1 == -1)
						y1 = i, x1 = j;
					else
						y2 = i, x2 = j;
				}
			}
		}
		h += 2, w += 2; 

		vector<vector<int>> stranger = bfs(board, 0, 0); 
		vector<vector<int>> first = bfs(board, y1, x1); 
		vector<vector<int>> second = bfs(board, y2, x2); 

		int ret = -1; 
		for(int i = 0; i < h; i++)
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') continue; 
				if (stranger[i][j] == -1 || first[i][j] == -1 || second[i][j] == -1) continue; 
				int cand = stranger[i][j] + first[i][j] + second[i][j]; 
				if (board[i][j] == '#') cand -= 2; 
				if (ret == -1 || ret > cand) ret = cand; 
			}
		cout << ret << endl;
	}
	return 0; 
}