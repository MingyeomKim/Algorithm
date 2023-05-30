#include <iostream>
#include <cmath>
using namespace std; 

int calc(int n) {
	int ret = 0; 
	while (n != 0) {
		n /= 10; 
		ret++; 
	}
	return ret; 
}

int main() {
	int n; cin >> n; 
	int k = calc(n); // ÀÚ¸´¼ö
	if (k == 1) cout << n << endl;
	else {
		int ret = 9; 
		for (int i = 2; i < k; i++)
			ret += i * ((pow(10, i) - 1) - (pow(10, i - 1) - 1)); 
		ret += k * (n - (pow(10, k - 1) - 1)); 
		cout << ret << endl;
	}
	return 0; 
}