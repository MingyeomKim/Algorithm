#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;

int add[11][11];
vector<int> trees[11][11];
int board[11][11]; // 양분

int dy[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
int dx[8] = { 0, -1, 1, 0, -1, 1, -1, 1 };
int n, m, k;

void spring(vector<tuple<int, int, int>>& die) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			vector<int> changed;
			for (int tree : trees[i][j]) {
				if (board[i][j] >= tree) {
					board[i][j] -= tree;
					changed.push_back(tree + 1);
				}
				else {
					die.push_back(make_tuple(i, j, tree));
				}
			}
			sort(changed.begin(), changed.end());
			// copy
			trees[i][j].clear();
			for (int newTree : changed) {
				trees[i][j].push_back(newTree);
			}
		}
	}
}

void fall() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			for (int tree : trees[y][x]) {
				if (tree % 5 == 0) {
					for (int d = 0; d < 8; d++) {
						int ny = y + dy[d], nx = x + dx[d];
						if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
						trees[ny][nx].push_back(1);
						sort(trees[ny][nx].begin(), trees[ny][nx].end());
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] += add[i][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 5;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> add[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		x--; y--;
		trees[y][x].push_back(z);
		sort(trees[y][x].begin(), trees[y][x].end());
	}

	for (int i = 0; i < k; i++) {
		// 봄
		vector<tuple<int, int, int>> die;
		spring(die);
		// 여름
		for (auto t : die) {
			int y, x, age; tie(y, x, age) = t;
			board[y][x] += (age / 2);
		}

		// 가을
		fall();

		// 겨울
		winter();

	}
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ret += trees[i][j].size();
		}
	}
	cout << ret << endl;
	return 0;
}

