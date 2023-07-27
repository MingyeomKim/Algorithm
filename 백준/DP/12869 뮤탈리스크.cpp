#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dp3[540][540][61];
int dp2[540][61];
int dp1[540];
int scv[3];

int sum; 
int solve(int a, int b, int i) {
	int c = sum - (13 * i) - (a + b); 
	if (a <= 540 && b <= 540 && c <= 0) return 0;

	int& ret = dp3[a][b][i];
	if (ret != -1) return ret;

	vector<int> candidates;
	candidates.push_back(solve(a - 9, b - 3, i + 1) + 1);
	candidates.push_back(solve(a - 9, b - 1, i + 1) + 1);
	candidates.push_back(solve(a - 3, b - 9, i + 1) + 1);
	candidates.push_back(solve(a - 3, b - 1, i + 1) + 1);
	candidates.push_back(solve(a - 1, b - 9, i + 1) + 1);
	candidates.push_back(solve(a - 1, b - 3, i + 1) + 1);
	sort(candidates.begin(), candidates.end());
	return dp3[a][b][i] = candidates[0];
}

int solve(int a, int i) {
	int b = sum - (13 * i) - (a - 540); 
	if (a <= 540 && b <= 0) return 0;
	int& ret = dp2[a][i];
	if (ret != -1) return ret;

	vector<int> candidates;
	candidates.push_back(solve(a - 9, i + 1) + 1);
	candidates.push_back(solve(a - 3, i + 1) + 1);
	sort(candidates.begin(), candidates.end());
	return dp2[a][i] = candidates[0];
}

int solve(int a) {
	if (a <= 540) return 0;
	int& ret = dp1[a];
	if (ret != -1) return ret;

	vector<int> candidates;
	candidates.push_back(solve(a - 9) + 1);
	return dp1[a] = candidates[0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	memset(dp1, -1, sizeof(dp1));
	memset(dp2, -1, sizeof(dp2));
	memset(dp3, -1, sizeof(dp3));
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> scv[i];

	if (n == 1)
		cout << solve(scv[0] + 540) << endl;
	else if (n == 2) {
		sum = scv[0] + scv[1]; 
		cout << solve(scv[0] + 540, 0) << endl;
	}
	else {
		sum = scv[0] + scv[1] + scv[2]; 
		cout << solve(scv[0] + 540, scv[1] + 540, 0) << endl;
	}
	return 0;
}