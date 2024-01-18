#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void rotate(string& wheel, int direction) {
	if (direction == 1) { // 시계 방향
		char last = wheel[wheel.size() - 1];
		wheel = wheel.substr(0, wheel.size() - 1);
		wheel = last + wheel;
	}
	else { // 반시계 방향
		char first = wheel[0];
		wheel = wheel.substr(1, wheel.size() - 1);
		wheel = wheel + first;
	}
}

bool check[1001];

void rotate(vector<string>& wheels, int number, int direction) {
	if (check[number]) return;
	check[number] = true;
	if (number == 0) {
		string wheel = wheels[number];
		string next = wheels[number + 1];
		if (wheel[2] != next[6]) { // 옆의 것도 반대방향으로 같이 돌아감
			rotate(wheels, number + 1, -1 * direction);
		}
	}
	else if (number == wheels.size() - 1) {
		string wheel = wheels[number];
		string next = wheels[number - 1];
		if (wheel[6] != next[2]) {
			rotate(wheels, number - 1, -1 * direction);
		}
	}
	else {
		string wheel = wheels[number];
		string left = wheels[number - 1];
		string right = wheels[number + 1];
		if (wheel[6] != left[2]) {
			rotate(wheels, number - 1, -1 * direction);
		}
		if (wheel[2] != right[6]) {
			rotate(wheels, number + 1, -1 * direction);
		}
	}
	rotate(wheels[number], direction);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	vector<string> wheels(t);
	for (int i = 0; i < t; i++) {
		cin >> wheels[i];
	}

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int number, direction;
		cin >> number >> direction;
		memset(check, false, sizeof(check));
		rotate(wheels, number - 1, direction);
	}

	int ret = 0;
	for (int i = 0; i < t; i++) {
		if (wheels[i][0] == '1') {
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}