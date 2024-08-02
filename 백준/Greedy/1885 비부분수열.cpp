#include <iostream>
#include <set>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k; cin >> n >> k; 
	int cnt = 0;
	set<int> check;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		check.insert(x);
		if (check.size() == k) { // 모든 숫자를 다 방문
			check.clear();
			cnt++;
		}
	}
	cout << cnt + 1 << endl; 
	return 0;
}