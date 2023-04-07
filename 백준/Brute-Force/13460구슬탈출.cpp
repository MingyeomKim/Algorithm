#include <iostream>
#include <vector>
using namespace std;

int n, m;
const int LIMIT = 10; 
int dx[4] = { 0, 0, 1, -1 }; 
int dy[4] = { 1, -1, 0, 0 }; 
// 아래, 위, 오른쪽, 왼쪽


// k : 보드를 기울이는 방법의 수를 구하는 이진수를 정수로 표현
// k를 10개의 4진법 정수로 변환하여 저장한다. 즉 2진수를 4진수로 변환한다. 
vector<int> generate(int k) {
	vector<int> cases(LIMIT); 
	for (int i = 0; i < LIMIT; i++) {
		cases[i] = (k & 3); // 1 1 (2bit)와 AND 연산하여 구한 값을 넣는다
		k >>= 2; // 2bit 이동한다.
	}
	return cases; 
}

// 같은 방향, 반대 방향이 연속으로 나오면 false를 리턴한다.
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

// (구슬이 이동하였는가, 구슬이 구멍에 빠졌는가)
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

// board에서 최대 10번의 tilt만큼 기울인다. 
// 구멍에 빨간 구슬이 빠지면 기울인 횟수를 반환
// 구멍에 파란 구슬이 빠지면 -1을 반환
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

	int cnt = 0; // 하나의 기울이는 방법대로 기울이면서, 기울인 횟수를 저장
	for (int tilt : tilts) {
		cnt++; 
		bool rhole = false, bhole = false; // 두 구슬이 구멍에 빠졌는지 저장
		while (true) {
			auto rinfo = simulation(board, tilt, ry, rx);
			auto binfo = simulation(board, tilt, by, bx);

			// "둘 다" 움직이지 않은 경우에만 빠져나옴.
			// 하나라도 움직일 수 있는 구슬이 있으면 반복함
			if (rinfo.first == false && binfo.first == false)
				break;
			if (rinfo.second) rhole = true; 
			if (binfo.second) bhole = true; 
			// rhole = rinfo.second, bhole = binfo.second; 
		}
		if (bhole) return -1; // 파란 구슬이 나오는 경우
		if (rhole) return cnt;
	}
	return -1; 
}

int main() {
	cin >> n >> m;
	vector<string> board(n); 
	for (int i = 0; i < n; i++) cin >> board[i];
	
	int ret = -1; 
	// 2의 20제곱 = 4의 10제곱만큼의 경우의 수를 고려한다.
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) {
		vector<int> tilts = generate(k); 
		// tilts 검사 : 같은 방향, 반대 방향이 연속으로 나오는 경우를 제거한다. 
		if (!valid(tilts)) continue; 
		int cand = check(board, tilts); 
		if (cand == -1) continue;  // 파란 구슬이 빠지는 경우

		if (ret == -1 || ret > cand) ret = cand;
	}
	cout << ret << endl;
	return 0; 
}