#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

char board[1001][1001];

int w, h;
bool isOut(int y, int x) {
	return y < 0 || y >= h || x < 0 || x >= w;
}

queue<pair<int, int>> sq;
queue<pair<int, int>> fq;

void moveFire() {
	int size = fq.size(); 
	for (int i = 0; i < size; i++) {
		int y, x; 
		tie(y, x) = fq.front(); 
		fq.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir]; 
			int nx = x + dx[dir];
			if (isOut(ny, nx) || board[ny][nx] != '.') {
				continue;
			}
			board[ny][nx] = '*';
			fq.push(make_pair(ny, nx)); 
		}
	}
}

int move() {
	int count = 0;
	while (!sq.empty()) {
		count++; 

		// 불 이동시키기
		moveFire();

		// 상근 이동시키기
		int size = sq.size();
		for (int i = 0; i < size; i++) {
			int y, x;
			tie(y, x) = sq.front();
			sq.pop();
			for (int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (isOut(ny, nx)) {
					return count;
				}
				if (board[ny][nx] != '.') {
					continue;
				}
				board[ny][nx] = '@';
				sq.push(make_pair(ny, nx)); 
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	int t; 
	cin >> t;
	while (t--) {
		while (!sq.empty()) {
			sq.pop(); 
		}
		while (!fq.empty()) {
			fq.pop();
		}
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			string s; cin >> s;
			for (int j = 0; j < w; j++) {
				board[i][j] = s[j];
				if (s[j] == '@') {
					sq.push(make_pair(i, j));
				}
				else if (s[j] == '*') {
					fq.push(make_pair(i, j));
				}
			}
		}

		int count = move();
		if (count == -1) {
			cout << "IMPOSSIBLE" << endl; 
		}
		else {
			cout << count << endl; 
		}
	}
	return 0;
}