#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

bool check[101][101];
int dy[4] = { -1, 1 ,0, 0 };
int dx[4] = { 0, 0,1, -1 };
vector<int> answer;
int m, n, k;

bool isOut(int y, int x) {
	return y < 0 || y >= m || x < 0 || x >= n;
}

int bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));
	check[sy][sx] = true;

	int size = 1;
	while (!q.empty()) {
		int y, x; tie(y, x) = q.front();
		q.pop();
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || check[ny][nx]) continue;
			q.push(make_pair(ny, nx));
			size++;
			check[ny][nx] = true;
		}
	}
	return size;
}

int main() {
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int sy = m - y1 - 1;
		int sx = x1;
		int ey = m - y2;
		int ex = x2 - 1;
		for (int y = ey; y <= sy; y++) {
			for (int x = sx; x <= ex; x++) {
				check[y][x] = true;
			}
		}
	}
	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (check[y][x]) continue;
			int size = bfs(y, x);
			answer.push_back(size);
		}
	}

	cout << answer.size() << endl;
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	} cout << endl;
	return 0;
}

/*

	주어진 모눈 종이 안의 직사각형을 배치하였을 때
	분리되어 나누어지는 영역의 개수와 넓이를 출력하기

*/