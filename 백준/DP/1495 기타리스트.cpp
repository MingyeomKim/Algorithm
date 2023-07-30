#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, s, m; 
int dp[51][1001]; // i��° ���� ������ �� j �������� �����ϴ� ���� �����ϸ� 1, �������� ������ 0, ���� �˻����� �ʾҴٸ� -1
int volume[51]; 

bool solve(int i, int j) {
	if (i == 0) return j == s;
	int& ret = dp[i][j]; 
	if (ret != -1) return ret;

	int m1 = 0, m2 = 0; 
	if (j - volume[i] >= 0)
		m1 = solve(i - 1, j - volume[i]); 
	if (j + volume[i] <= m)
		m2 = solve(i - 1, j + volume[i]); 
	return dp[i][j] = max(m1, m2); 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	memset(dp, -1, sizeof(dp)); 
	cin >> n >> s >> m; 
	for (int i = 1; i <= n; i++)
		cin >> volume[i]; 
	int j;
	bool isPossible = false;
	for (j = m; j >= 0; j--) {
		if (solve(n, j) == 1) {
			isPossible = true;
			break;
		}
	}
	if (isPossible) cout << j << endl;
	else cout << -1 << endl; 
	return 0; 
}