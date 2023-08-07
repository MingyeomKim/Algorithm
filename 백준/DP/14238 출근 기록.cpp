#include <iostream>
#include <cstring>
using namespace std; 

char answer[51]; 
int dp[51][51][51][4][4]; 
int length; 
int aa = 0, bb = 0, cc = 0; 

int solve(int a, int b, int c, int p1, int p2) {
	if (a == aa && b == bb && c == cc) return 1; 

	int& ret = dp[a][b][c][p1][p2];
	if (ret != -1) return ret; 

	ret = 1; 

	int len = a + b + c; 
	if (a < aa) {
		answer[len] = 'A'; 
		if (solve(a + 1, b, c, 1, p1) == 1) return 1; 
	}
	if (b < bb) {
		answer[len] = 'B'; 
		if (p1 != 2)
			if (solve(a, b + 1, c, 2, p1) == 1) return 1; 
	}
	if (c < cc) {
		answer[len] = 'C'; 
		if (p1 != 3 && p2 != 3)
			if (solve(a, b, c + 1, 3, p1) == 1) return 1;
	}

	return ret = 0; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 
	string s; cin >> s; 
	int length = s.length(); 

	for (int i = 0; i < length; i++) {
		if (s[i] == 'A') aa++;
		else if (s[i] == 'B') bb++;
		else cc++; 
	}

	memset(dp, -1, sizeof(dp)); 
	if (solve(0, 0, 0, 0, 0) == 1) cout << answer << endl;
	else cout << -1 << endl; 
	return 0; 
}