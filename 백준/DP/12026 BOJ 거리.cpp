#include <iostream>
#include <cstring>
using namespace std;

int n; string s;
int dp[1001]; // dp[i] : i��° ��ġ�� �����ϴ� ���� ����� �������� �ּڰ�

char get_prev(char x) {
	if (x == 'B')
		return 'J';
	else if (x == 'O')
		return 'B';
	else if (x == 'J')
		return 'O'; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	cin >> n >> s; 
	memset(dp, -1, sizeof(dp)); 

	dp[0] = 0; 
	for (int i = 1; i < n; i++) {
		char now = s[i]; 
		char prev = get_prev(now); 
		for (int j = 0; j < i; j++) {
			if (dp[j] == -1) continue; // s[j]���� ������ �� ����. 
			if (s[j] != prev) continue; 
			int cand = dp[j] + (i - j) * (i - j); 
			if (dp[i] == -1 || dp[i] > cand)
				dp[i] = cand; 
		}
	}
	cout << dp[n - 1] << endl; 
	return 0; 
}