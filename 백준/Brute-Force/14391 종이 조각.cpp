#include <iostream>
#include <string>
using namespace std; 

char board[5][5];

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s; 
		for (int j = 0; j < m; j++) {
			board[i][j] = s[j];
		}
	}
	
	int ret = 0;
	for (int k = 0; k < (1 << (n * m)); k++) {
		if (k == (1 << (n * m)) - 1) {
			int a = 1;
		}
		int cand = 0;
		// 가로로 놓인 숫자를 계산
		for (int y = 0; y < n; y++) {
			string sum = "";
			for (int x = 0; x < m; x++) {
				int p = y * m + x;
				if (!(k & (1 << p))) { // 현재 위치가 0
					sum += board[y][x];
				}
				else {
					if (!sum.empty()) {
						cand += stoi(sum);
					}
					sum = "";
				}
			}
			if (!sum.empty()) {
				cand += stoi(sum);
			}
		}

		// 세로로 놓인 숫자를 계산
		for (int x = 0; x < m; x++) {
			string sum = "";
			for (int y = 0; y < n; y++) {
				int p = y * m + x;
				if (k & (1 << p)) { // 현재 위치가 1
					sum += board[y][x];
				}
				else {
					if (!sum.empty()) {
						cand += stoi(sum);
					}
					sum = "";
				}
			}
			if (!sum.empty()) {
				cand += stoi(sum);
			}
		}
		if (ret < cand) ret = cand;
	}
	
	cout << ret << endl; 
	return 0;
}