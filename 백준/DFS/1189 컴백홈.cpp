#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

char board[6][6];
bool check[6][6];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0 ,1, -1 };

int r, c, k;
int ret = 0;
void dfs(int y, int x, int dist) {
	if (y < 0 || y >= r || x < 0 || x >= c || board[y][x] == 'T') return;
	if (y == 0 && x == c - 1 && dist == k) ret++;
	for (int direction = 0; direction < 4; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction];
		if (check[ny][nx]) continue;
		check[ny][nx] = true;
		dfs(ny, nx, dist + 1);
		check[ny][nx] = false;
	}
}

int main() {
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++) {
		string line;
		cin >> line;
		for (int j = 0; j < c; j++) {
			board[i][j] = line[j];
		}
	}
	check[r - 1][0] = true;
	dfs(r - 1, 0, 1);
	cout << ret << endl;
	return 0;
}

/*
*
*  cdef  ...f  ..ef  ..gh  cdeh  cdej  ...f
   bT..  .T.e  .Td.  .Tfe  bTfg  bTfi  .Tde
   a...  abcd  abc.  abcd  a...  a.gh  abc.

   브루트포스 - 한수가 집에 도착하는 모든 경우 탐색하여 거리가 K인 개수를 계산한다.
*/