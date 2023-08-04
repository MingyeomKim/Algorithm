#include <iostream> 
#include <vector>
using namespace std; 

int n;
int input[101]; 
long long dp[101][21]; // dp[i] : i��° ���ڱ��� ������� ��, ���� j�� ���� �� �ִ� ��� ����� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> input[i]; 

	dp[1][input[1]] = 1;
	for (int i = 2; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if(j - input[i] >= 0)
				dp[i][j] += dp[i - 1][j - input[i]];
			if (j + input[i] <= 20)
				dp[i][j] += dp[i - 1][j + input[i]]; 
		}
	}
	cout << dp[n - 1][input[n]] << endl;
	return 0; 
}