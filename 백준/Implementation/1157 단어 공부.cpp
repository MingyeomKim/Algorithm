#include <iostream>
using namespace std;

int COUNT[200];

char to_uppercase(char c) {
	if (c >= 'a') {
		return c - ('a' - 'A');
	}
	return c;
}

int main() {
	int ret = 0;
	string s; cin >> s;

	char max;
	for (char c : s) {
		c = to_uppercase(c);
		COUNT[(int)c]++;
		if (ret < COUNT[(int)c]) {
			ret = COUNT[(int)c];
			max = c;
		}
	}

	for (char c : s) {
		c = to_uppercase(c);
		if (ret == COUNT[(int)c] && max != c) {
			cout << "?" << endl;
			return 0;
		}
	}
	cout << max << endl;
	return 0;
}