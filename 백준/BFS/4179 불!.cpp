#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

char board[1001][1001];
int fire[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int r, c;

void preprocess(queue<pair<int, int>> q) {
	while (!q.empty()) {
		int y, x; tie(y, x) = q.front();
		q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (ny < 0 || ny >= r || nx < 0 || nx >= c || board[ny][nx] == '#') continue;

			if (fire[ny][nx] == 0 || fire[ny][nx] > fire[y][x] + 1) {
				fire[ny][nx] = fire[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;

	pair<int, int> start;
	queue<pair<int, int>> q1;
	for (int i = 0; i < r; i++) {
		string s; cin >> s;
		for (int j = 0; j < c; j++) {
			board[i][j] = s[j];

			if (board[i][j] == 'J') {
				start.first = i;
				start.second = j;
				board[i][j] = '.';
			}

			if (board[i][j] == 'F') {
				q1.push(make_pair(i, j));
				fire[i][j] = 1;
			}
		}
	}

	// 불이 확산된다.

	preprocess(q1);

	// 지훈이가 이동하자.

	queue<pair<int, int>> q;
	q.push(start);
	dist[start.first][start.second] = 1;

	vector<int> result;

	while (!q.empty()) {
		int y, x; tie(y, x) = q.front();
		q.pop();

		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];

			if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
				result.push_back(dist[y][x]);
				continue;
			}

			if (visited[ny][nx]) continue;

			if ((fire[ny][nx] > dist[y][x] + 1 || fire[ny][nx] == 0) && board[ny][nx] == '.') {
				dist[ny][nx] = dist[y][x] + 1;
				q.push(make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}
	if (result.empty()) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		sort(result.begin(), result.end());
		cout << result[0] << endl;
	}

	return 0;
}

/*
* 지훈이의 위치
* 불이 붙은 위치
*
* 탈출할 수 있는 지 여부
* 얼마나 빨리 탈출할 수 있는 지
*
* 1초가 지났을 때 미로의 상태에서 지훈이가 1초 동안 이동할 수 있는 모든 위치중에서 불이 안난 위치가 있는가?
*
* 그런데 여기서 지훈이가 이동할 때 fire[ny][nx] == 0이라는 조건이 없으면 틀린다.
* 만약 불이 모두 확산되어도 벽에 가려져서 지훈이가 안전할 수 있다. 이런 경우에는 벽이 아니더라도 fire의 요소가 0일 수 있다.
*
*/