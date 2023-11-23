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

	// ���� Ȯ��ȴ�.

	preprocess(q1);

	// �����̰� �̵�����.

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
* �������� ��ġ
* ���� ���� ��ġ
*
* Ż���� �� �ִ� �� ����
* �󸶳� ���� Ż���� �� �ִ� ��
*
* 1�ʰ� ������ �� �̷��� ���¿��� �����̰� 1�� ���� �̵��� �� �ִ� ��� ��ġ�߿��� ���� �ȳ� ��ġ�� �ִ°�?
*
* �׷��� ���⼭ �����̰� �̵��� �� fire[ny][nx] == 0�̶�� ������ ������ Ʋ����.
* ���� ���� ��� Ȯ��Ǿ ���� �������� �����̰� ������ �� �ִ�. �̷� ��쿡�� ���� �ƴϴ��� fire�� ��Ұ� 0�� �� �ִ�.
*
*/