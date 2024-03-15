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

	if (isOver) { // �����̰� �� ���µ� ���� �ȳ��� ��Ȳ
		return;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == true) { // �긦 �������.
				for (int k = 1; k <= 5; k++) { // ���� ũ��
					if (paper[k] == 0) continue;
					if (isOut(i + k - 1, j + k - 1)) continue; // ���̸� ���� �� ����
					bool possible = true; // k ũ���� ���̸� ���� �� �ֳ�?
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

	vector<int> paper(6);  // �����ִ� ���� ����
	for (int i = 1; i <= 5; i++) {
		paper[i] = 5;
	}
	solve(board, paper);
	cout << ret << endl;
	return 0;
}

/*
* ���� �ּ��� ���ϴ� �� ��ü�����δ� �ּ��� �ƴ� �� �ִ�.
* A �������� ���� �� �ִ� ��� �����̸� �׽�Ʈ�غ����Ѵ�.
*/