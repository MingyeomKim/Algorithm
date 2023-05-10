#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

char board[101][101]; 
bool check[101][101]; 

int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 }; 

// (y, x)가 십자가의 중앙일 때 만들 수 있는 십자가의 최대 길이
int count(int y, int x) {
	int ret = -1; // 최소 십자가의 길이
	for (int direction = 0; direction < 4; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction];
		if (board[ny][nx] == '.') return -1; // 십자가를 만들 수 없다면
		int cnt = 0; // 이 방향으로 십자가의 길이
		while (board[ny][nx] == '*') {
			cnt++;
			ny += dy[direction]; nx += dx[direction];
		}
		if (ret == -1 || ret > cnt) ret = cnt; 
	}
	return ret; 
}

int main() {
	int n, m; cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j]; // 격자판의 상태
	memset(check, false, sizeof(check)); 

	
	vector<pair<pair<int, int>, int>> ret; 
	for (int i = 1; i < n -1 ; i++)
		for (int j = 1; j < m - 1; j++) {
			if (board[i][j] == '*') {
				int k = count(i, j); 
				if (k != -1) {
					ret.emplace_back(make_pair(i, j), k); 
					check[i][j] = true; 
					for (int direction = 0; direction < 4; direction++) {
						int ni = i + dy[direction], nj = j + dx[direction];
						for (int i = 0; i < k; i++) {
							check[ni][nj] = true; 
							ni += dy[direction], nj += dx[direction]; 
						}
					}
				}
			}
		}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '*' && !check[i][j]) {
				cout << -1 << endl;
				return 0; 
			}
			if (board[i][j] == '.' && check[i][j]) {
				cout << -1 << endl;
				return 0; 
			}
		}
	}
	cout << ret.size() << endl;
	for (auto & a: ret) {
		cout << a.first.first + 1 << " " << a.first.second  + 1 << " " << a.second << " " << endl;
	}
	return 0; 
}