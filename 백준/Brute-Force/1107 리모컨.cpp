#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool broken[10];

int length(int channel) {
	return to_string(channel).length();
}

bool check(int channel) {
	string channels = to_string(channel);
	for (char channel : channels) {
		if (broken[channel - '0']) {
			return false;
		}
	}
	return true;
}

int main() {
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		broken[num] = true;
	}

	int ret = abs(n - 100); // +, -만 눌러서 채널 이동
	for (int i = 0; i < n + abs(n - 100); i++) {
		if (check(i)) {
			int cand = length(i) + abs(n - i);
			if (ret > cand) {
				ret = cand;
			}
		}
	}
	cout << ret << endl;
	return 0;
}