#include <iostream>
#include <cstring>
using namespace std; 

long long dp[46]; 

long long fivo(int n) {

	long long& ret = dp[n]; 
	if (ret != -1) return ret; 

	if (n == 0) return ret = 0;
	else if (n == 1) return ret = 1; 
	return ret = fivo(n - 1) + fivo(n - 2); 
}

int main() {
	int n; cin >> n;

	memset(dp, -1, sizeof(dp)); 
	cout << fivo(n) << endl; 
	return 0; 
}