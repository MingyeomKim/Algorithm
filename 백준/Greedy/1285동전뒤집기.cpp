#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int n; 

char flip(char x) {
	return (x == 'H') ? 'T' : 'H';
}

int main() {
	cin >> n; 
	vector<string> board(n);
	for (int i = 0; i < n; i++)
		cin >> board[i]; 

	int ret = n * n;
	// state : n개의 행에 대해서 바꿀지 말지를 비트마스크로 표현
	for (int state = 0; state < (1 << n); state++) {
		int cand = 0;  // 모든 행의 조합에 대해 T의 최소 갯수

		for (int j = 0; j < n; j++) {
			int cnt = 0; // T의 개수
			for (int i = 0; i < n; i++) { // 행
				char cur = board[i][j]; 
				if (state & (1 << i)) // 현재 행을 뒤집어야 한다면
					cur = flip(cur); 
				if (cur == 'T')
					cnt++; 
			}
			// cnt(T) 가 더 작다면 j열을 뒤집지 않는다. 
			// n - cnt(H)가 더 작다면 j열을 뒤집는다.
			cand += min(cnt, n - cnt); 
		}
		if (ret > cand) ret = cand; 
	}
	cout << ret << endl;
	
	return 0; 
}