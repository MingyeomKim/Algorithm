#include <iostream>
#include <algorithm>
using namespace std;

string cache[51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	cache[1] = s;
	for (int i = 2; i <= s.length(); i++) {
		if (cache[i - 1][0] < cache[i - 1][i - 1]) {
			cache[i] = cache[i - 1];
		}
		else {
			reverse(cache[i - 1].begin(), cache[i - 1].begin() + i - 1);
			string temp = cache[i - 1];
			reverse(temp.begin(), temp.begin() + i);
			cache[i] = temp;
		}
	}
	cout << cache[s.length()] << endl;
	return 0;
}