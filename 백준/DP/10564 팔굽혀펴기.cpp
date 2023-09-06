#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std; 

int dp[5001][5001]; // i�� �ȱ�����⸦ ���� ��, j ������ ���� �����Ѱ� ?
int scores[11]; 
int n, m;

int solve(int count, int score) {
	int& ret = dp[count][score]; 
	if (ret != -1) return ret; 

	ret = 1; 
	for (int j = 0; j < m; j++) {
		int jump = score + scores[j]; 
		if (count + jump > n) continue; 
		solve(count + jump, jump); 
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL);

	int t; cin >> t; 
	while (t--) {
		cin >> n >> m; 
		for (int i = 0; i < m; i++)
			cin >> scores[i]; 

		memset(dp, -1, sizeof(dp)); 
		solve(0, 0); 

		// find max
		int i = 5000; 
		for (; i >= 0; i--) {
			if (dp[n][i] == 1) {
				cout << i << endl;
				break;
			}
		}
		if (i <= 0) cout << -1 << endl;
	}
	return 0; 
}

// �ִ��� �ƴ� ��쿡�� �ٸ� ��츦 Ž���� �� �ֵ��� �ؾ��Ѵ�.