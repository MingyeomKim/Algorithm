#include <iostream>
using namespace std; 

int r, c;
int visited['Z' - 'A' + 1] = {0,};
char board[21][21]; 
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int ret = 1; 
void move(int y, int x, int cnt) {
	// 다음 칸으로 이동할 수 있는지 여부
	bool flag = false;
	// 현재 칸을 기준으로 다음 칸을 선택한다. 
	for (int direction = 0; direction < 4; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction];
		// 다음 칸에 있는 알파벳이 이미 지난 것인지 검사하고, 그렇지 않다면 방문한다.
		if (!(ny < 0 || ny >= r || nx < 0 || nx >= c) && !visited[board[ny][nx] - 'A']) {
			flag = true;
			visited[board[ny][nx] - 'A'] = true;
			move(ny, nx, cnt + 1);
			visited[board[ny][nx] - 'A'] = false;
		}
	}
	// 이동할 칸이 없거나 모든 칸을 다 탐색한 경우 (모든 칸의 알파벳이 전부 동일)
	if (!flag || cnt == r * c) 
		if (ret < cnt) ret = cnt; 
}

int main() {
	cin >> r >> c; 
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> board[i][j]; 
	visited[board[0][0] - 'A'] = true;
	move(0, 0, 1);
	cout << ret << endl;
	
	return 0; 
}