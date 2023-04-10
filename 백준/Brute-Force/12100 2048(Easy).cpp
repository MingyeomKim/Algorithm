#include <iostream>
#include <vector>
using namespace std;

int n;
const int LIMIT = 5;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
// �Ʒ�, ��, ��, ��

// 2������ 4������ ��ȯ (�� ������� �̵��ϴ� ����� ��)
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

	// �� �������� �̵�
	for (int dir : direction) {
		// first : �� ĭ�� ���� 
		// second : �� ĭ�� �̹� ������ ĭ���� (�ѹ��� �̵����� ���� ĭ�� �� �� ������ �� ����) 
		bool moved = false;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				info[i][j].second = false;

		while (true) {
			moved = false;
			// �Ʒ��� �̵��ϴ� ���
			if (dir == 0) {
				// �Ʒ����� Ž��
				for (int y = n - 2; y >= 0; y--) // ���� �Ʒ� ���� ����
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
							if (info[y][x].second == false && info[ny][nx].second == false) { // �� �� �ѹ��� ��ġ�� ���� ���̹Ƿ� ��ĥ �� �ִ�.
								info[ny][nx].first *= 2;
								info[ny][nx].second = true;
								info[y][x].first = 0;
								moved = true;
							}
					}
			}
			// ���� �̵��ϴ� ���
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
							if (info[y][x].second == false && info[ny][nx].second == false) { // �� �� �ѹ��� ��ġ�� ���� ���̹Ƿ� ��ĥ �� �ִ�.
								info[ny][nx].first *= 2;
								info[y][x].first = 0;
								info[ny][nx].second = true;
								moved = true;
							}
					}
			}
			// ���������� �̵��ϴ� ���
			else if (dir == 2) {
				for (int y = 0; y < n; y++)
					for (int x = n - 2; x >= 0; x--) { // ���� ������ ���� ����
						if (info[y][x].first == 0) continue;

						int ny = y + dy[dir], nx = x + dx[dir];
						if (info[ny][nx].first == 0) {
							info[ny][nx].first = info[y][x].first;
							info[ny][nx].second = info[y][x].second;
							info[y][x].first = 0;
							moved = true;
						}
						else if (info[ny][nx].first == info[y][x].first)
							if (info[y][x].second == false && info[ny][nx].second == false) { // �� �� �ѹ��� ��ġ�� ���� ���̹Ƿ� ��ĥ �� �ִ�.
								info[ny][nx].first *= 2;
								info[ny][nx].second = true;
								info[y][x].first = 0;
								moved = true;
							}
					}
			}
			else if (dir == 3) { // �������� �̵��ϴ� ���
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
							if (info[y][x].second == false && info[ny][nx].second == false) { // �� �� �ѹ��� ��ġ�� ���� ���̹Ƿ� ��ĥ �� �ִ�.
								info[ny][nx].first *= 2;
								info[y][x].first = 0;
								info[ny][nx].second = true;
								moved = true;
							}
					}
			}
			if (moved == false) break; // �� �̻� ������ �� ���ٸ�
		}
	}
	// ���� ū ���ڸ� ��ȯ
	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (ret < info[i][j].first)
				ret = info[i][j].first;
	return ret;
}

int main() {
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n));  // ������ ����
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	int ret = 0;
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) { // ��� ����� ���� ����
		vector<int> direction = generate(k);
		int cand = check(board, direction);
		if (ret < cand) ret = cand;
	}
	cout << ret << endl;
	return 0;
}
