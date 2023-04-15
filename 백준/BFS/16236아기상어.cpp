#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std; 

int n, m; 
int board[21][21];

int dy[4] = { -1, 0, 0, 1 }; 
int dx[4] = { 0, -1, 1, 0 };

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= n); 
}

// �� �� ������ ������ ���� �� �ִ� ���� ����� ����⸦ ã�� �̵��Ѵ�.
// �Ÿ�, ��ǥ�� tuple�� ���� ��ȯ
tuple<int, int, int> decideNext(int y, int x, int size) {
	vector<tuple<int, int, int>> ret;
	vector<vector<int>> dist(n, vector<int>(n, -1));
	queue<pair<int, int>> q;

	q.push(make_pair(y, x));
	dist[y][x] = 0;

	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx)) continue;
			if (dist[ny][nx] == -1) {  // �湮���� ���� ĭ�̶��
				bool ok = false;  // ���� �� �ִ°� ? 
				bool eat = false;  // ���� �� �ִ°� ? 

				if (board[ny][nx] == 0) ok = true;
				else if (board[ny][nx] < size) ok = eat = true;
				else if (board[ny][nx] == size) ok = true;

				if (ok) { // ���� �� �ִ� ĭ�̸� 
					q.push(make_pair(ny, nx)); // ������ !

					dist[ny][nx] = dist[y][x] + 1;
					if (eat) // ���� �� �ִ� ����Ⱑ �ִٸ�
						ret.push_back(make_tuple(dist[ny][nx], ny, nx)); // �ĺ��� �߰��Ѵ�. 
				}
			}
		}
	}
	if (ret.empty())
		return make_tuple(-1, -1, -1);
	sort(ret.begin(), ret.end());
	return ret[0]; // �Ÿ��� ���� ª�� ���� ��ȯ
}

int main() {
	cin >> n; 
	int y, x;  
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			cin >> board[i][j]; 
			if (board[i][j] == 9) {
				y = i, x = j;
				board[i][j] = 0;
			}
		}
	
	// DFS
	int ret = 0; 
	int size = 2; 
	int cnt = 0;
	while (true) {
		int ny, nx, dist; 
		tie(dist, ny, nx) = decideNext(y, x, size); 
		if (dist == -1) break;

		board[ny][nx] = 0; 
		ret += dist; 
		cnt++; 
		if (size == cnt) {
			size++; 
			cnt = 0; 
		}
		tie(y, x) = make_pair(ny, nx); 
	}
	cout << ret << endl;
	return 0; 
}