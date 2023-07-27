#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, k; 
int dp[10001]; // 가치의 합이 i인 동전 조합의 총 개수
int v[101]; 

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> v[i]; 

	dp[0] = 1; 
	for (int i = 1; i <= n; i++) { 
		for (int j = 0; j <= k; j++) {
			if (j - v[i] >= 0)
				dp[j] += dp[j - v[i]]; 
		}
	}
	cout << dp[k] << endl; 
	return 0; 
}