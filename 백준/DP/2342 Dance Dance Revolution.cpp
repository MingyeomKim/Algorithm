#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

int dp[5][5][100001];
vector<int> v;

int getEnergy(int from, int to) {
	if (from == to) {
		return 1;
	}

	if (from == 0 || to == 0) {
		return 2;
	}

	int interval = abs(from - to);
	if (interval == 1 || interval == 3) {
		return 3;
	}

	if (interval == 2) {
		return 4;
	}
}

int solve(int left, int right, int index) {
	if (index == v.size()) return 0;
	int& ret = dp[left][right][index];
	if (ret != -1) return ret;

	int next = v[index];
	int moveLeft = -1;
	int moveRight = -1;
	// 왼쪽 발을 이동
	if (right != next) { // 이미 오른쪽 발이 next에 있지 않다면 왼쪽 발 이동 가능
		moveLeft = solve(next, right, index + 1) + getEnergy(left, next);
	}
	// 오른쪽 발을 이동
	if (left != next) {
		moveRight = solve(left, next, index + 1) + getEnergy(right, next);
	}

	if (moveLeft == -1) {
		ret = moveRight;
	}
	else if (moveRight == -1) {
		ret = moveLeft;
	}
	else {
		ret = min(moveLeft, moveRight);
	}
	return ret;
}

int main() {
	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		v.push_back(n);
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0) << endl;
	return 0;
}