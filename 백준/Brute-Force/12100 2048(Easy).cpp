#include <iostream>
#include <vector>
using namespace std;

int n;
const int LIMIT = 5;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
// 아래, 위, 오, 왼

// 2진수를 4진수로 변환 (네 방면으로 이동하는 경우의 수)
vector<int> generate(int k) {
	vector<int> a(LIMIT);
	for (int i = 0; i < LIMIT; i++) {
		a[i] = (k & 3);
		k >>= 2;
	}
	return a;
}

int check(vector<vector<int>>& board, vector<int>& direction) {
	vector<vector<pair<int, bool>>> info(n, vector<pair<int, bool>>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			info[i][j].first = board[i][j];

	// 한 방향으로 이동
	for (int dir : direction) {
		// first : 그 칸의 숫자 
		// second : 그 칸이 이미 합쳐진 칸인지 (한번의 이동에서 같은 칸이 두 번 합쳐질 수 없음) 
		bool moved = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				info[i][j].second = false;

		while (true) {
			moved = false;
			// 아래로 이동하는 경우
			if (dir == 0) {
				// 아래부터 탐색
				for (int y = n - 2; y >= 0; y--) // 제일 아래 줄은 생략
					for (int x = 0; x < n; x++) {
						if (info[y][x].first == 0) continue;

						int ny = y + dy[dir], nx = x + dx[dir];
						if (info[ny][nx].first == 0) {
							info[ny][nx].first = info[y][x].first;
							info[ny][nx].second = info[y][x].second;
							info[y][x].first = 0;
							moved = true;
						}
						else if (info[ny][nx].first == info[y][x].first)
							if (info[y][x].second == false && info[ny][nx].second == false) { // 둘 다 한번도 합치지 않은 블럭이므로 합칠 수 있다.
								info[ny][nx].first *= 2;
								info[ny][nx].second = true;
								info[y][x].first = 0;
								moved = true;
							}
					}
			}
			// 위로 이동하는 경우
			else if (dir == 1) {
				for (int y = 1; y < n; y++)
					for (int x = 0; x < n; x++) {
						if (info[y][x].first == 0) continue;

						int ny = y + dy[dir], nx = x + dx[dir];
						if (info[ny][nx].first == 0) {
							info[ny][nx].first = info[y][x].first;
							info[ny][nx].second = info[y][x].second;
							info[y][x].first = 0;
							moved = true;
						}
						else if (info[ny][nx].first == info[y][x].first)
							if (info[y][x].second == false && info[ny][nx].second == false) { // 둘 다 한번도 합치지 않은 블럭이므로 합칠 수 있다.
								info[ny][nx].first *= 2;
								info[y][x].first = 0;
								info[ny][nx].second = true;
								moved = true;
							}
					}
			}
			// 오른쪽으로 이동하는 경우
			else if (dir == 2) {
				for (int y = 0; y < n; y++)
					for (int x = n - 2; x >= 0; x--) { // 제일 오른쪽 줄은 생략
						if (info[y][x].first == 0) continue;

						int ny = y + dy[dir], nx = x + dx[dir];
						if (info[ny][nx].first == 0) {
							info[ny][nx].first = info[y][x].first;
							info[ny][nx].second = info[y][x].second;
							info[y][x].first = 0;
							moved = true;
						}
						else if (info[ny][nx].first == info[y][x].first)
							if (info[y][x].second == false && info[ny][nx].second == false) { // 둘 다 한번도 합치지 않은 블럭이므로 합칠 수 있다.
								info[ny][nx].first *= 2;
								info[ny][nx].second = true;
								info[y][x].first = 0;
								moved = true;
							}
					}
			}
			else if (dir == 3) { // 왼쪽으로 이동하는 경우
				for (int y = 0; y < n; y++)
					for (int x = 1; x < n; x++) {
						if (info[y][x].first == 0) continue;

						int ny = y + dy[dir], nx = x + dx[dir];
						if (info[ny][nx].first == 0) {
							info[ny][nx].first = info[y][x].first;
							info[ny][nx].second = info[y][x].second;
							info[y][x].first = 0;
							moved = true;
						}
						else if (info[ny][nx].first == info[y][x].first)
							if (info[y][x].second == false && info[ny][nx].second == false) { // 둘 다 한번도 합치지 않은 블럭이므로 합칠 수 있다.
								info[ny][nx].first *= 2;
								info[y][x].first = 0;
								info[ny][nx].second = true;
								moved = true;
							}
					}
			}
			if (moved == false) break; // 더 이상 움직일 수 없다면
		}
	}
	// 가장 큰 숫자를 반환
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ret < info[i][j].first)
				ret = info[i][j].first;
	return ret;
}

int main() {
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));  // 이차원 벡터
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int ret = 0;
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) { // 모든 경우의 수에 대해
		vector<int> direction = generate(k);
		int cand = check(board, direction);
		if (ret < cand) ret = cand;
	}
	cout << ret << endl;
	return 0;
}
