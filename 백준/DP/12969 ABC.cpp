#include <iostream>
#include <cstring>
using namespace std; 

int dp[31][31][31][450]; 
char ans[31];
int n, k;

int solve(int length, int a, int b, int p) {
	if (length == n) {
		if (p == k) return 1;
		else return 0; 
	}
	int& ret = dp[length][a][b][p]; 
	if (ret != -1) return ret; 

	ret = 1;

	ans[length] = 'A';
	if (solve(length + 1, a + 1, b, p) == 1) return 1; 

	ans[length] = 'B'; 
	if (solve(length + 1, a, b + 1, p + a) == 1) return 1; 

	ans[length] = 'C'; 
	if (solve(length + 1, a, b, p + a + b) == 1) return 1; 

	ret = 0; 
	return ret; 
}


int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); 

	memset(dp, -1, sizeof(dp)); 
	cin >> n >> k; 
	if (solve(0, 0, 0, 0) == 1)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0; 
}