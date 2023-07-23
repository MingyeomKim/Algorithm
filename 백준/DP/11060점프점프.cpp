#include <iostream>
#include <cstring>
using namespace std; 

/*

int a[1001]; 
int ret[1001]; 


int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i]; 
	memset(ret, -1, sizeof(ret)); 
	ret[0] = 0; 
	for (int i = 0; i < n - 1; i++) {
		if (ret[i] == -1) continue; 
		for (int j = 1; j <= a[i]; j++) {
			if (i + j >= n) break; 
			if (ret[i + j] == -1 || ret[i + j] > ret[i] + 1)
				ret[i + j] = ret[i] + 1; 
		}
	}
	cout << ret[n -1] << endl;
	return 0; 
}

*/


int board[1001];
int cache[1001]; // i번째 위치에서 n위치까지 가는 데 점프해야하는 최소 횟수
int n;

int solve(int index) {
	if (index >= n) return INF;
	if (index == n - 1) return 0;
	if (cache[index] != -1) return cache[index];

	cache[index] = INF;
	for (int jump = 1; jump <= board[index]; jump++) {
		if (index + jump >= n) break;
		cache[index] = min(cache[index], solve(index + jump) + 1);
	}
	return cache[index];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	memset(cache, -1, sizeof(cache));
	int ret = solve(0);
	if (ret == INF) cout << -1 << endl;
	else cout << ret << endl;
	return 0;
}