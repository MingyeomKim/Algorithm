#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int n, m;
char board[21][21]; 

int dx[4] = {1, -1, 0, 0}; 
int dy[4] = {0, 0, 1, -1};

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

// 두 동전의 위치를 받아 이동함을 표현한다. 
int play(int y1, int x1, int y2, int x2, int cnt) {
	if (isOut(y1, x1) ^ isOut(y2, x2)) return cnt; // 둘 중 하나만 떨어졌다면
	if (isOut(y1, x1) && isOut(y2, x2)) return -1; // 둘다 떨어졌다면
	if (cnt > 10)
		return -1; 

	int ret = -1; 
	for (int direction = 0; direction < 4; direction++) {
		int nextY1 = y1 + dy[direction];
		int nextX1 = x1 + dx[direction];
		int nextY2 = y2 + dy[direction];
		int nextX2 = x2 + dx[direction];

		// 다음 좌표가 벽이라면
		if (!isOut(nextY1, nextX1) && board[nextY1][nextX1] == '#') {
			nextY1 = y1; 
			nextX1 = x1;
		}
		if (!isOut(nextY2, nextX2) && board[nextY2][nextX2] == '#') {
			nextY2 = y2;
			nextX2 = x2; 
		}

		int cand = play(nextY1, nextX1, nextY2, nextX2, cnt + 1);
		if (cand == -1) continue; 
		if (ret == -1 || ret > cand) ret = cand; 
	}
	return ret; 
}

int main() {
	cin >> n >> m;
	pair<int, int> coin[2]; int cnt = 0; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> board[i][j]; 
			if (board[i][j] == 'o'){
				coin[cnt] = make_pair(i, j); 
				cnt++; 
			}
		}
	cout << play(coin[0].first, coin[0].second, coin[1].first, coin[1].second, 0) << endl;
	return 0; 
}

