#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	double s; cin >> s; // 서로 다른 수들끼리 더하면 S가 된다. 이 수의 개수를 구하여라.
	double cnt = 0;
	int idx = 0;
	while (cnt <= s) {
		cnt += idx + 1;
		idx++;
	}
	cout << idx - 1 << endl; 
	return 0; 
}
