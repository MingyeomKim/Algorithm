#include <iostream>
#include <cstring>
using namespace std;

int n, k; 
int v[101]; 
int dp[100001]; // dp[i] : ��ġ i�� ����� �� �ʿ��� ������ ����

int main() {
	memset(dp, -1, sizeof(dp)); 
	cin >> n >> k; 
	for (int i = 0; i < n; i++)
		cin >> v[i]; 
	dp[0] = 0; // �ʱ갪
	for (int i = 0; i < n; i++) { // ����
		for (int j = 0; j <= k; j++) { // ��ġ
			if (j - v[i] >= 0 && dp[j - v[i]] != -1) {
				if (dp[j] == -1 || dp[j] > dp[j - v[i]] + 1)
					dp[j] = (dp[j - v[i]] + 1);
			}
		}
	}
	cout << dp[k] << endl;
	return 0; 
}