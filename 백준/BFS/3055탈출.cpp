#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>
using namespace std; 

int r, c;
int water[51][51]; // �� ĭ�� ���� ��п� ������ ����Ѵ�.
int dist[51][51]; // �� ĭ�� ����ġ�� �� �п� �����ϴ� �� ����Ѵ�. 
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

	// �� ĭ�� �� �� �ڿ� ���� ���� �� ���
	while (!q.empty()) {
		int y, x; 
		tie(y, x) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx)) continue; 
			if (water[ny][nx] != -1) continue; // �̹� ���� ������
			if (board[ny][nx] == 'D' || board[ny][nx] == 'X') continue; 
			water[ny][nx] = water[y][x] + 1; 
			q.push(make_pair(ny, nx)); 
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q2; 
	dist[start.first][start.second] = 0; // ����� : S
	q2.push(make_pair(start.first, start.second)); 

	while (!q2.empty()) {
		int y, x;
		tie(y, x) = q2.front(); q2.pop(); 
		
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 

			// �̵��� �� ���� ��� : �� �ٱ�, ��, ��
			if (isOut(ny, nx) || board[ny][nx] == 'X')  continue;
			// ������  ���� ���� ĭ�̶��, �� �ð��� ����, �׸��� 1�� �Ŀ��� �� �Ͼ�� �̵��� �� �ִ�
			if (dist[ny][nx] != -1) continue; // �̹� �湮�� ��
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