#include <iostream>
#include <deque>
#include <set>
using namespace std;

deque<int> board[51];
// 1 1 2 3 
// 3 1 1 2
// 시계 방향 회전 = 제일 뒤의 요소를 제일 앞으로 
// 1 2 3 1
// 반시계 방향 회전 = 제일 앞의 요소를 제일 뒤로

int n, m, t;

void clockwise(int i) {
	int back = board[i].back();
	board[i].pop_back();
	board[i].push_front(back);
}

void counterclockwise(int i) {
	int front = board[i].front();
	board[i].pop_front();
	board[i].push_back(front);
}

int previous(int j) {
	if (j > 0) {
		return j - 1;
	}
	return m - 1;
}

int next(int j) {
	if (j < m - 1) {
		return j + 1;
	}
	return 0;
}

bool check(int a, int b) {
	return a != 0 && b != 0 && a == b;
}

bool doesNotHaveAdjacent() {
	auto q = board[1];
	set<pair<int, int>> changed;
	for (int j = 0; j < m; j++) {
		bool flag = false;
		if (check(q[j], board[2][j])) {
			changed.insert(make_pair(2, j));
			flag = true;
		}
		if (check(q[j], q[next(j)])) {
			changed.insert(make_pair(1, next(j)));
			flag = true;
		}
		if (check(q[j], q[previous(j)])) {
			changed.insert(make_pair(1, previous(j)));
			flag = true;
		}

		if (flag) {
			changed.insert(make_pair(1, j));
		}
	}


	// 중간 원판에 대해 지우기
	// (i, j) -> (i, prev(j)), (i, next(j)), (i + 1, j), (I - 1, j)
	for (int i = 2; i < n; i++) {
		auto q = board[i];
		for (int j = 0; j < m; j++) {
			bool flag = false;
			if (check(q[previous(j)], q[j])) {
				changed.insert(make_pair(i, previous(j)));
				flag = true;
			}
			if (check(q[next(j)], q[j])) {
				changed.insert(make_pair(i, next(j)));
				flag = true;
			}
			if (check(board[i + 1][j], q[j])) {
				changed.insert(make_pair(i + 1, j));
				flag = true;
			}
			if (check(board[i - 1][j], q[j])) {
				changed.insert(make_pair(i - 1, j));
				flag = true;
			}

			if (flag) {
				changed.insert(make_pair(i, j));
			}
		}
	}

	// 마지막 원판에 대해 지우기
	q = board[n];
	for (int j = 0; j < m; j++) {
		bool flag = false;
		if (check(q[j], board[n - 1][j])) {
			changed.insert(make_pair(n - 1, j));
			flag = true;
		}
		if (check(q[j], q[next(j)])) {
			changed.insert(make_pair(n, next(j)));
			flag = true;
		}
		if (check(q[j], q[previous(j)])) {
			changed.insert(make_pair(n, previous(j)));
			flag = true;
		}

		if (flag) {
			changed.insert(make_pair(n, j));
		}
	}
	return changed.empty();
}

void solve(int x, int d, int k) {
	// rotate
	if (d == 0) { // 시계 방향
		for (int i = 1; i <= n; i++) {
			if (i % x == 0) { // i 번 원판을 시계 방향으로 회전
				for (int j = 0; j < k; j++) { // k번 회전
					clockwise(i);
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (i % x == 0) { // i 번 원판을 반시계 방향으로 회전
				for (int j = 0; j < k; j++) {
					counterclockwise(i);
				}
			}
		}
	}

	// 첫 번째 원판에 대해 지우기
	auto q = board[1];
	set<pair<int, int>> changed;
	for (int j = 0; j < m; j++) {
		bool flag = false;
		if (check(q[j], board[2][j])) {
			changed.insert(make_pair(2, j));
			flag = true;
		}
		if (check(q[j], q[next(j)])) {
			changed.insert(make_pair(1, next(j)));
			flag = true;
		}
		if (check(q[j], q[previous(j)])) {
			changed.insert(make_pair(1, previous(j)));
			flag = true;
		}

		if (flag) {
			changed.insert(make_pair(1, j));
		}
	}


	// 중간 원판에 대해 지우기
	// (i, j) -> (i, prev(j)), (i, next(j)), (i + 1, j), (I - 1, j)
	for (int i = 2; i < n; i++) {
		auto q = board[i];
		for (int j = 0; j < m; j++) {
			bool flag = false;
			if (check(q[previous(j)], q[j])) {
				changed.insert(make_pair(i, previous(j)));
				flag = true;
			}
			if (check(q[next(j)], q[j])) {
				changed.insert(make_pair(i, next(j)));
				flag = true;
			}
			if (check(board[i + 1][j], q[j])) {
				changed.insert(make_pair(i + 1, j));
				flag = true;
			}
			if (check(board[i - 1][j], q[j])) {
				changed.insert(make_pair(i - 1, j));
				flag = true;
			}

			if (flag) {
				changed.insert(make_pair(i, j));
			}
		}
	}

	// 마지막 원판에 대해 지우기
	q = board[n];
	for (int j = 0; j < m; j++) {
		bool flag = false;
		if (check(q[j], board[n - 1][j])) {
			changed.insert(make_pair(n - 1, j));
			flag = true;
		}
		if (check(q[j], q[next(j)])) {
			changed.insert(make_pair(n, next(j)));
			flag = true;
		}
		if (check(q[j], q[previous(j)])) {
			changed.insert(make_pair(n, previous(j)));
			flag = true;
		}

		if (flag) {
			changed.insert(make_pair(n, j));
		}
	}

	for (auto p : changed) {
		board[p.first][p.second] = 0;
	}

	if (changed.empty()) {
		double sum = 0;
		double cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] != 0) {
					cnt += 1; 
					sum += board[i][j];
				}
			}
		}
		double avg = sum / cnt;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] > avg) {
					board[i][j]--;
				}
				else if (board[i][j] != 0 && board[i][j] < avg) {
					board[i][j]++;
				}
			}
		}
	}

	changed.clear();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> t; // 4 4 1
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int number; cin >> number;
			board[i].push_back(number);
		}
	}
	while (t--) {
		int x, d, k; cin >> x >> d >> k;
		solve(x, d, k);
	}

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			ret += board[i][j];
		}
	}
	cout << ret << endl;
	return 0;
}