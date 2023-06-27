#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };

int n;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= n;
}

int main() {
	cin >> n;
	vector<string> board(n);
	vector<vector<int>> num(n, vector<int>(n)); // point to number
	vector<pair<int, int>> point; // number to point
	
	int start = -1, end = -1; 
	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < n; j++) { // check visiting point
			if (board[i][j] == '#') {
				if (start == -1) start = point.size();
				else end = point.size(); 
				num[i][j] = point.size();
				point.emplace_back(i, j);
			}
			else if (board[i][j] == '!') {
				num[i][j] = point.size();
				point.emplace_back(i, j);
			}
		}
	}

	int p = point.size(); 
	// check[i][j] = 점 i에서 점 j로 갈 수 있는지 저장
	vector<vector<bool>> canGo(p, vector<bool>(p, false)); 
	for (int i = 0; i < p; i++) {
		for (int direction = 0; direction < 4; direction++) {
			int y = point[i].first + dy[direction]; 
			int x = point[i].second + dx[direction]; 
			while (!isOut(y, x) && board[y][x] != '*') {
				if (board[y][x] == '!' || board[y][x] == '#') 
					canGo[i][num[y][x]] = true;
				y += dy[direction], x += dx[direction]; 
			}
		}
	}

	queue<int> q; 
	vector<int> dist(p, -1); // dist of all points from 'start'
	q.push(start);
	dist[start] = 0; 
	while (!q.empty()) {
		int here = q.front(); q.pop(); 
		for(int there= 0; there < p; there++)
			if (canGo[here][there] && dist[there] == -1) {
				dist[there] = dist[here] + 1; 
				q.push(there); 
			}
	}
	cout << dist[end] - 1 << endl;
	return 0; 
}