#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[12][12];

int ret = 0;
void solve(int position, vector<bool>& isUsed, int sum) {
	if (position == 11) { // 마지막까지 오면
		if (ret < sum) {
			ret = sum; // 대소 비교 후 종료한다.
		}
		return;
	}

	for (int i = 1; i < 12; i++) {
		if (board[i][position + 1] == 0 || isUsed[i]) {
			continue;
		}
		isUsed[i] = true;
		solve(position + 1, isUsed, sum + board[i][position + 1]);
		isUsed[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;
	while (t--) {
		ret = 0;
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				cin >> board[i][j];
			}
		}
		vector<bool> isUsed(12);
		solve(0, isUsed, 0);
		cout << ret << endl;
	}
	return 0;
}
