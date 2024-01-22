#include <iostream>
#include <vector>
using namespace std;

int n, k;
// 컨베이어 벨트와 로봇을 함께 이동시킨다
void rotate(vector<int>& v, vector<bool>& robots) {
	// 벨트 이동
	vector<int> temp(2 * n);
	temp[0] = v[2 * n - 1];
	for (int i = 1; i < 2 * n; i++) {
		temp[i] = v[i - 1];
	}
	for (int i = 0; i < 2 * n; i++) {
		v[i] = temp[i];
	}

	// 로봇도 함께 이동
	for (int i = n - 2; i >= 0; i--) {
		if (!robots[i]) continue;
		if (i == n - 2) {
			// 내리는 위치로 이동할 로봇인 경우
			robots[i] = false;
		}
		else {
			if (robots[i]) {
				robots[i + 1] = true;
				robots[i] = false;
			}
		}
	}
}

void move(vector<int>& v, vector<bool>& robots) {
	for (int i = n - 2; i >= 0; i--) {
		if (!robots[i]) continue;
		if (i == n - 2 && v[i + 1] > 0) {
			robots[i] = false;
			v[i + 1]--;
		}
		else {
			if (!robots[i + 1] && v[i + 1] > 0) {
				robots[i + 1] = true;
				robots[i] = false;
				v[i + 1]--;
			}
		}
	}
}

void load(vector<int>& belt, vector<bool>& robots) {
	if (belt[0] > 0) {
		belt[0]--;
		robots[0] = true;
	}
}

int countZero(vector<int>& belt) {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (belt[i] == 0) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vector<int> belt(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i];
	}
	vector<bool> robots(n, false);
	int ret = 0;
	while (true) {
		ret++;
		rotate(belt, robots);
		move(belt, robots);
		load(belt, robots);
		if (countZero(belt) >= k) {
			break;
		}
	}
	cout << ret << endl;
	return 0;
}

/*
- 컨베이어 벨트가 회전하는 기능
- 로봇이 이동하는 기능 (로봇이 여러 개일 수 있음)
	- 각 로봇이 이동할 수 있는 지 체크
	- 이동할 수 있는 모든 로봇을 이동시키고 내구도 1 감소
	- 이동한 위치가 내리는 위치면 그 로봇을 제거
- 올리는 위치에 있는 칸의 내구도가 1 이상이면 올리는 위치에 로봇을 올림
	- 올리는 위치의 내구도 1 감소
- 모든 칸의 내구도를 확인하고 0인 칸의 개수가 K개 이하이면 패스, 이상이면 종료
*/