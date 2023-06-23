#include <vector>
#include <iostream>
using namespace std; 

bool isPrime(int n) {
	if (n <= 1) return false; 
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false; 

	return true; 
}

int main() {
	int n; cin >> n;
	if (n == 1) {
		int x; cin >> x; 
		if (x == n) cout << 1 << endl;
		else cout << 0 << endl;
		return 0; 
	}

	vector<int> v; 
	for (int i = 2; i <= n; i++) {
		if (isPrime(i))
			v.push_back(i); 
	}

	int left = 0, right = 0; 
	long long sum = v[0]; 
	int ret = 0; 
	while (left <= right && right < v.size()) {
		if (sum < n) {
			right++; 
			if (right < v.size()) sum += v[right]; 
		}
		else if (sum > n) {
			sum -= v[left]; 
			left++; 
		}
		else {
			ret++; 
			right++; 
			if (right < v.size()) sum += v[right];
		}
	}
	cout << ret << endl;
	return 0; 
}