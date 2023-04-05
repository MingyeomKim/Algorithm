#include <iostream>
using namespace std; 

int r, c;
int visited['Z' - 'A' + 1] = {0,};
char board[21][21]; 
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int ret = 1; 
void move(int y, int x, int cnt) {
	// ���� ĭ���� �̵��� �� �ִ��� ����
	bool flag = false;
	// ���� ĭ�� �������� ���� ĭ�� �����Ѵ�. 
	for (int direction = 0; direction < 4; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction];
		// ���� ĭ�� �ִ� ���ĺ��� �̹� ���� ������ �˻��ϰ�, �׷��� �ʴٸ� �湮�Ѵ�.
		if (!(ny < 0 || ny >= r || nx < 0 || nx >= c) && !visited[board[ny][nx] - 'A']) {
			flag = true;
			visited[board[ny][nx] - 'A'] = true;
			move(ny, nx, cnt + 1);
			visited[board[ny][nx] - 'A'] = false;
		}
	}
	// �̵��� ĭ�� ���ų� ��� ĭ�� �� Ž���� ��� (��� ĭ�� ���ĺ��� ���� ����)
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