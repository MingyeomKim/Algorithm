#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

char board[51][51];
int l, w;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int dist[51][51];

bool isOut(int y, int x) {
	return y < 0 || y >= l || x < 0 || x >= w;
}

int bfs(int y, int x) { // (y, x)에서 시작해서 가장 멀리 갈 수 있는 위치를 반환
	int ret = 0;

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	dist[y][x] = 0;

	while (!q.empty()) {
		tie(y, x) = q.front();
		q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || dist[ny][nx] != -1 || board[ny][nx] != 'L') continue;

			dist[ny][nx] = dist[y][x] + 1;
			if (ret < dist[ny][nx]) ret = dist[ny][nx];
			q.push(make_pair(ny, nx));
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> l >> w;
	for (int i = 0; i < l; i++) {
		string s; cin >> s;
		for (int j = 0; j < w; j++) {
			board[i][j] = s[j];
		}
	}

	int ret = 0;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 'L') {
				memset(dist, -1, sizeof(dist));
				int cand = bfs(i, j);
				if (ret < cand) ret = cand;
			}
		}
	}
	cout << ret << endl;
	return 0;
}

/*

< 문제 설명 >
한 칸 이동 시 한 시간이 걸림.
육지를 최단 거리로 이동했을 때 가장 먼 거리에 보물이 묻혀있다.
즉 최단 거리가 가장 긴 두 노드의 거리를 구하면 된다.

< 문제 풀이 >
BFS를 사용해서 각 노드끼리의 최단 거리를 구한다.
이 중에서 가장 큰 것을 선택한다.

*/