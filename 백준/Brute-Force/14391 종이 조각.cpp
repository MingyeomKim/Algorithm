#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int board[5][5];
int ret = 0;
int n, m;

// 다음으로 호출할 노드 찾기
pair<int, int> findNext(vector<vector<int>> temp) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == -1) {
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

int dy[2] = { 0, 1 };
int dx[2] = { 1, 0 };

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m;
}

int bfs(vector<vector<int>>& temp, int sy, int sx) {
	int footprint = temp[sy][sx];
	string s = to_string(board[sy][sx]);
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	temp[sy][sx] = -1;
	while (!q.empty()) {
		int y, x; tie(y, x) = q.front();
		q.pop();
		for (int direction = 0; direction < 2; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || temp[ny][nx] == -1) continue;
			if (temp[ny][nx] != footprint) continue;
			s += to_string(board[ny][nx]);
			q.push(make_pair(ny, nx));
			temp[ny][nx] = -1;
		}
	}
	return stoi(s);
}

int sum(vector<vector<int>> temp) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == -1) continue;
			int number = bfs(temp, i, j);
			sum += number;
		}
	}
	return sum;
}

void solve(vector<vector<int>>& temp, int footprint, int y, int x) {
	if (findNext(temp).first == -1) { // 모든 종이를 가득 채운 경우
		int cand = sum(temp);
		if (ret < cand) ret = cand;
		return;
	}

	// 하나만 선택하는 경우
	temp[y][x] = footprint;
	pair<int, int> next = findNext(temp);
	solve(temp, footprint + 1, next.first, next.second);
	temp[y][x] = -1;

	// 세로로 테스트하기
	for (int length = 2; length <= n - y; length++) {
		for (int k = y; k < y + length; k++) {
			temp[k][x] = footprint;
		}
		pair<int, int> next = findNext(temp);
		solve(temp, footprint + 1, next.first, next.second);
		for (int k = y; k < y + length; k++) {
			temp[k][x] = -1;
		}
	}

	// 가로로 테스트하기
	for (int length = 2; length <= m - x; length++) {
		for (int k = x; k < x + length; k++) {
			temp[y][k] = footprint;
		}
		pair<int, int> next = findNext(temp);
		solve(temp, footprint + 1, next.first, next.second);
		for (int k = x; k < x + length; k++) {
			temp[y][k] = -1;
		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	vector<vector<int>> temp(n, vector<int>(m, -1));
	solve(temp, 0, 0, 0);
	cout << ret << endl;
	return 0;
}