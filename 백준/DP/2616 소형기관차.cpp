#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std; 

vector<int> people;
vector<int> sum; 

int dp[3][50001]; // dp[i][s] : 사용한 소형기관차 개수가 i일 때, s번째 객차를 선택할 지 고려하고 있다. 이 선택지에서 최대 손님 수를 담는다. 
int n; // 총 객차 수
int s;  // 끌 수 있는 최대 객차 수

int solve(int index, int start) {
	if (index == 3 || start > n) return 0; 
	// if (start == n) return sum[n] - sum[n - 1]; 

	int& ret = dp[index][start]; 
	if (ret != -1) return ret; 

	int cand1 = solve(index, start + 1);
	int cand2 = solve(index + 1, start + s); 
	if (start + s <= n) cand2 += sum[start + s - 1] - sum[start - 1];
	else cand2 += sum[n] - sum[start - 1]; 
	return ret = max(cand1, cand2);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 

	cin >> n; 
	people = vector<int>(n + 1); 
	sum = vector<int>(n + 1, 0);
	sum[0] = 0; 
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
		sum[i] = sum[i - 1] + people[i]; 
	}
	cin >> s; 

	memset(dp, -1, sizeof(dp));

	cout << solve(0, 1) << endl;
	return 0; 
}