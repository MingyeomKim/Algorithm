#include <iostream> 
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end()); 

	int ret = 0;

	for (int i = 0; i < n; i++) { // 같은 것이 있으면  upper bound 설정
		int left = 0;
		int right = n - 1;

		bool flag = false;
		while (true) {
			if (left == i) {
				left++;
			}
			else if (right == i) {
				right--;
			}

			if (left >= right) {
				break;
			}

			if (v[left] + v[right] < v[i]) {
				left++;
			}
			else if (v[left] + v[right] > v[i]) {
				right--;
			}
			else if (v[left] + v[right] == v[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}