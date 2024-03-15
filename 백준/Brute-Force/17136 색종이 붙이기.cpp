#include <iostream>
#include <vector>
using namespace std;

bool isOut(int y, int x) {
	return y < 0 || y >= 10 || x < 0 || x >= 10;
}

int ret = -1;
void solve(vector<vector<bool>>& board, vector<int>& paper) {
	bool isOver = true;
	for (int i = 1; i <= 5; i++) {
		if (paper[i] > 0) {
			isOver = false;
		}
	}

	bool isCompleted = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == 1) {
				isCompleted = false;
			}
		}
	}
	if (isCompleted) {
		int count = 0;
		for (int i = 1; i <= 5; i++) {
			count += (5 - paper[i]);
		}
		if (ret == -1 || ret > count) {
			ret = count;
		}
		return;
	}

	if (isOver) { // 색종이가 더 없는데 아직 안끝난 상황
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == true) { // 얘를 덮어야해.
				for (int k = 1; k <= 5; k++) { // 종이 크기
					if (paper[k] == 0) continue;
					if (isOut(i + k - 1, j + k - 1)) continue; // 종이를 놓을 수 없음
					bool possible = true; // k 크기의 종이를 놓을 수 있나?
					for (int y = i; y < i + k; y++) {
						for (int x = j; x < j + k; x++) {
							if (!board[y][x]) {
								possible = false;
							}
						}
					}
					if (possible) {
						for (int y = i; y < i + k; y++) {
							for (int x = j; x < j + k; x++) {
								board[y][x] = false;
							}
						}
						paper[k]--;
						solve(board, paper);

						for (int y = i; y < i + k; y++) {
							for (int x = j; x < j + k; x++) {
								board[y][x] = true;
							}
						}
						paper[k]++;
					}
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<bool>> board(10);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			bool flag; cin >> flag;
			board[i].push_back(flag);
		}
	}

	vector<int> paper(6);  // 남아있는 종이 개수
	for (int i = 1; i <= 5; i++) {
		paper[i] = 5;
	}
	solve(board, paper);
	cout << ret << endl;
	return 0;
}

/*
* 현재 최선을 다하는 게 전체적으로는 최선이 아닐 수 있다.
* A 지점에서 놓을 수 있는 모든 색종이를 테스트해봐야한다.
*/