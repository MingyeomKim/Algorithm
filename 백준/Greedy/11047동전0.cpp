#include <iostream>
#include <vector>
using namespace std;

int n, k;

int main() {
	cin >> n >> k;
	vector<int> A(n); 
	for (int i = 0; i < n; i++) {
		cin >> A[i]; 
	}
	
	int ret = 0; 
	for (int i = n - 1; i >= 0; i--) {
		ret += k / A[i]; 
		k %= A[i];
	}
	cout << ret << endl;
	return 0;
}