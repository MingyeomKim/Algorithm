#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 
#define endl '\n'

int check[2001][2001];  // i부터 j까지가 팰린드롬인지 저장 (-1이면 아직 검사하지 않은 것)ㄴ
int board[2001]; 
int n;

int solve(int i, int j) {
	if (i == j) return 1;  // 길이 1
	else if (i + 1 == j) { // 길이 2
		if (board[i] == board[j]) return 1;
		else return 0; 
	}
	if (check[i][j] >= 0) return check[i][j];  // 메모이제이션
	if (board[i] != board[j]) return check[i][j] = 0; // 같지 않다면 팰린드롬이 아님
	else return check[i][j] = solve(i + 1, j - 1);  // 그 사이에 있는 것이 팰린드롬 부분수열인지 재귀적으로 확인
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	memset(check, -1, sizeof(check)); 
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> board[i]; 
	int m; cin >> m; 
	while (m--) {
		int s, e; cin >> s >> e;
		if (solve(s, e) == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
	return 0; 
}