#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int board[11][11];

int dy[12] = { -1,1, 0, 0, -2, 2,  0, 0, 1, -1, 1, -1 };
int dx[12] = { 0, 0, 1, -1 , 0, 0, -2, 2, -1, -1, 1, 1 };

bool check(vector<tuple<int, int, int>> v, int i, int j) {
	int expense1, y1, x1;  tie(expense1, y1, x1) = v[i];
	int expense2, y2, x2; tie(expense2, y2, x2) = v[j];

	for (int direction = 0; direction < 12; direction++) {
		int ny = y1 + dy[direction], nx = x1 + dx[direction];
		if (ny == y2 && nx == x2) return false;
	}
	return true;
}

int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	vector<tuple<int, int, int>> v;
	for (int y = 1; y < n - 1; y++) {
		for (int x = 1; x < n - 1; x++) {
			int temp = board[y][x];
			for (int direction = 0; direction < 4; direction++) {
				int ny = y + dy[direction], nx = x + dx[direction];
				temp += board[ny][nx];
			}
			v.emplace_back(temp, y, x);
		}
	}

	int size = v.size();
	int ret = -1;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			for (int k = j + 1; k < size; k++) {
				if (!check(v, i, j) || !check(v, i, k) || !check(v, j, k)) continue;

				int expense1, y1, x1;  tie(expense1, y1, x1) = v[i];
				int expense2, y2, x2; tie(expense2, y2, x2) = v[j];
				int expense3, y3, x3; tie(expense3, y3, x3) = v[k];

				int cand = expense1 + expense2 + expense3;
				if (ret == -1 || ret > cand) ret = cand;
			}
		}
	}
	cout << ret << endl;

	return 0;
}
