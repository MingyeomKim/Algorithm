#include <iostream> 
#include <algorithm>
#include <vector>
#define MAX 1000000000
using namespace std;

/*
반례 : -1 -1 -2
반례 : -5 -4 -1 1 2 5
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		long long number; cin >> number;
		v[i] = number;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		v[i] = v[i] + MAX;
	}

	int ret = 0;
	for (int i = 0; i < n; i++) { // 같은 것이 있으면  upper bound 설정
		int k = i;
		if (i != n - 1) {
			for (int j = i + 1; j < n; j++) {
				if (v[i] == v[j]) {
					k = j;
				}
				else {
					break;
				}
			}
		}
		int left = 0;
		int right = k - 1;

		bool flag = false;
		while (left < right) {
			if (v[left] + v[right] < v[k] + MAX) {
				left++;
			}
			else if (v[left] + v[right] > v[k] + MAX) {
				right--;
			}
			else if (v[left] + v[right] == v[k] + MAX) {
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