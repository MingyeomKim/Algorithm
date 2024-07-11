#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> dq; // (이동, 현재 번호)

// 2 1 -3 -1 (times = 3)
// 1 -3 -1 2 (i = 1)
// -3 -1 2 1 (i = 2)
pair<int, int> go_right(int times) {
	for (int i = 1; i < times; i++) {
		auto p = dq.front();
		dq.pop_front();
		dq.push_back(p);
	}
	return dq.front();
}

// -1 2 1  (times = -3)
// 1 -1 2 (i = -3)
// 2 1 -1 (i = -2) 
// -1 2 1 (i = -1)
pair<int, int> go_left(int times) {
	for (int i = times; i < 0; i++) {
		auto p = dq.back();
		dq.pop_back();
		dq.push_front(p);
	}
	return dq.front();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		dq.push_back({ x, i });
	}

	int next_step = dq.front().first;
	dq.pop_front();
	cout << 1 << " ";
	while (!dq.empty()) {
		if (next_step >= 0) {
			auto p = go_right(next_step);
			cout << p.second << " ";
		}
		else {
			auto p = go_left(next_step);
			cout << p.second << " ";
		}
		auto n_p = dq.front();
		next_step = n_p.first;
		dq.pop_front();
	}
	return 0;
}