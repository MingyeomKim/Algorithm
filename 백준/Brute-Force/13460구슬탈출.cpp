#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int LIMIT = 10; 
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 }; 
// �Ʒ�, ��, ������, ����


// k : ���带 ����̴� ����� ���� ���ϴ� �������� ������ ǥ��
// k�� 10���� 4���� ������ ��ȯ�Ͽ� �����Ѵ�. �� 2������ 4������ ��ȯ�Ѵ�. 
vector<int> generate(int k) {
	vector<int> cases(LIMIT); 
	for (int i = 0; i < LIMIT; i++) {
		cases[i] = (k & 3); // 1 1 (2bit)�� AND �����Ͽ� ���� ���� �ִ´�
		k >>= 2; // 2bit �̵��Ѵ�.
	}
	return cases; 
}

// ���� ����, �ݴ� ������ �������� ������ false�� �����Ѵ�.
bool valid(vector<int> &tilts) {
	for (int i = 0; i < (int)tilts.size() - 1; i++) {
		if (tilts[i] == 0 && tilts[i + 1] == 1) return false;
		if (tilts[i] == 1 && tilts[i + 1] == 0) return false;
		if (tilts[i] == 2 && tilts[i + 1] == 3) return false;
		if (tilts[i] == 3 && tilts[i + 1] == 2) return false;
		if (tilts[i] == tilts[i + 1]) return false; 
	}
	return true; 
}

// (������ �̵��Ͽ��°�, ������ ���ۿ� �����°�)
pair<bool, bool> simulation(vector<string> &board, int direction, int& y, int& x) {
	if (board[y][x] == '.') return make_pair(false, false); 

	bool moved = false; 
	while (true) {
		int ny = y + dy[direction], nx = x + dx[direction];

		if (board[ny][nx] == '#') return make_pair(moved, false);
		else if (board[ny][nx] == 'R' || board[ny][nx] == 'B') return make_pair(moved, false);
		else if (board[ny][nx] == '.') {
			swap(board[ny][nx], board[y][x]);
			x = nx, y = ny; 
			moved = true; 
		}
		else if (board[ny][nx] == 'O') {
			board[y][x] = '.'; 
			moved = true; 
			return make_pair(moved, true); 
		}
	}
	return make_pair(false, false); 
}

// board���� �ִ� 10���� tilt��ŭ ����δ�. 
// ���ۿ� ���� ������ ������ ����� Ƚ���� ��ȯ
// ���ۿ� �Ķ� ������ ������ -1�� ��ȯ
int check(vector<string> board, vector<int>& tilts) {
	int hy, hx, ry, rx, by, bx; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			if (board[i][j] == 'O')
				hy = i, hx = j; 
			if (board[i][j] == 'R')
				ry = i, rx = j; 
			if (board[i][j] == 'B')
				by = i, bx = j; 
		}

	int cnt = 0; // �ϳ��� ����̴� ������ ����̸鼭, ����� Ƚ���� ����
	for (int tilt : tilts) {
		cnt++; 
		bool rhole = false, bhole = false; // �� ������ ���ۿ� �������� ����
		while (true) {
			auto rinfo = simulation(board, tilt, ry, rx);
			auto binfo = simulation(board, tilt, by, bx);

			// "�� ��" �������� ���� ��쿡�� ��������.
			// �ϳ��� ������ �� �ִ� ������ ������ �ݺ���
			if (rinfo.first == false && binfo.first == false)
				break;
			if (rinfo.second) rhole = true; 
			if (binfo.second) bhole = true; 
			// rhole = rinfo.second, bhole = binfo.second; 
		}
		if (bhole) return -1; // �Ķ� ������ ������ ���
		if (rhole) return cnt;
	}
	return -1; 
}

int main() {
	cin >> n >> m;
	vector<string> board(n); 
	for (int i = 0; i < n; i++) cin >> board[i];
	
	int ret = -1; 
	// 2�� 20���� = 4�� 10������ŭ�� ����� ���� ����Ѵ�.
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) {
		vector<int> tilts = generate(k); 
		// tilts �˻� : ���� ����, �ݴ� ������ �������� ������ ��츦 �����Ѵ�. 
		if (!valid(tilts)) continue; 
		int cand = check(board, tilts); 
		if (cand == -1) continue;  // �Ķ� ������ ������ ���

		if (ret == -1 || ret > cand) ret = cand;
	}
	cout << ret << endl;
	return 0; 
}