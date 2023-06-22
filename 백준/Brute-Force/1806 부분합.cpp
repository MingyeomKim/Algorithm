#include <iostream>
#include <vector>
using namespace std; 

int main() {
	int n, s; cin >> n >> s; 
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i]; 

	long long sum = v[0];
	int left = 0, right = 0; 
	int ret = 0;
	while (left <= right && right < n) {
		if (sum > s) {
			if (ret == 0 || ret > right - left + 1)
				ret = right - left + 1;
			sum -= v[left];
			left++;
		}
		else if (sum < s) {
			right++;
			if(right < n) sum += v[right]; 
		}
		else {
			if (ret == 0 || ret > right - left + 1)
				ret = right - left + 1;
			right++; 
			sum += v[right]; 
		}
	}
	cout << ret << endl;
	return 0; 
}