#include <iostream>
#define endl '\n'

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);

	double s; cin >> s; // ���� �ٸ� ���鳢�� ���ϸ� S�� �ȴ�. �� ���� ������ ���Ͽ���.
	double cnt = 0;
	int idx = 0;
	while (cnt <= s) {
		cnt += idx + 1;
		idx++;
	}
	cout << idx - 1 << endl; 
	return 0; 
}
