#include <iostream>
#include <queue> 
#include <cstring>
#include <tuple>
#include <set>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std; 

int n, m; 
int board[1001][1001]; 
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
bool dist[1001][1001]; 
int group[1001][1001]; // ĭ (i, j)�� �׷��� ��ȣ�� �����Ѵ�.
vector<int> group_size; 
int countFor[1001][1001]; 

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

// �� ĭ���� ���� �׷����� ���´�.
void bfs(int sy, int sx) {
	int g = group_size.size(); 

	queue<pair<int, int>> q; 
	q.push(make_pair(sy, sx)); 
	dist[sy][sx] = true; 
	group[sy][sx] = g; 

	int cnt = 1; // g �׷쿡 ���Ե� �� ĭ�� ����
	while (!q.empty()) {
		int y, x;
		tie(y, x) = q.front(); q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx)) continue; 
			if (board[ny][nx] == 0 && dist[ny][nx] == false) {
				dist[ny][nx] = true;
				cnt++; 
				group[ny][nx] = group[y][x]; 
				q.push(make_pair(ny, nx));
			}
		}
	}
	group_size.push_back(cnt); 
}


int main() {
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
			dist[i][j] = false;
			group[i][j] = -1;
		}

	// ��� �� ĭ�� ���� �׷� ��ȣ�� ����
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			// �� ĭ�̰�, �湮���� �ʾҴٸ�
			if (board[i][j] == 0 && dist[i][j] == false)
				bfs(i, j); 
		}

	// �׷쿡 ���� ���� �������� �� �� ���� �� ĭ�� ���� �� �ִ��� �˻��Ѵ�
	for(int y = 0; y < n; y++){
		for (int x = 0; x < m; x++) {
			if (board[y][x] == 0)
				cout << 0; 
			else { // ���� �߰ߵǸ�
				set<int> near; 
				for (int direction = 0; direction < 4; direction++) {
					int ny = y + dy[direction], nx = x + dx[direction]; 
					if (isOut(ny, nx)) continue; 
					if (board[ny][nx] == 0)
						near.insert(group[ny][nx]); // �� ���� �μ�� �湮�� �� �ִ� �׷��� ��´�. 
				}

				// near �׷���� �湮�ϸ� �湮�� �� �ִ� ��� ĭ�� ���� ����
				int ret = 1; 
				for (int g : near)
					ret += group_size[g]; 
				cout << ret % 10; 
			}
		}
		cout << endl;
	}


	return 0; 
}