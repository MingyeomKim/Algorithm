#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std; 
#define endl '\n'

int n, m, k; 

// target를 (r, c, s)로 회전 연산한 결과를 temp에 저장한다.
void rotate(int r, int c, int s, vector<vector<int>> &temp,  vector<vector<int>> target) {

	for (int size = 1; size <= s; size++) {
		for (int i = -size; i < size; i++)
			temp[r - size][c + i + 1] = target[r - size][c + i];
		for (int i = -size; i < size; i++)
			temp[r + i + 1][c + size] = target[r + i][c + size];
		for (int i = size; i > -size; i--)
			temp[r + size][c + i - 1] = target[r + size][c + i];
		for (int i = size; i > -size; i--)
			temp[r + i - 1][c - size] = target[r + i][c - size];
	}
}

// 배열의 값 계산
int calc(vector<vector<int>> temp) {
	int ret = -1; 
	for (int i = 0; i < n; i++) {
		int cand = 0; 
		for (int j = 0; j < m; j++)
			cand += temp[i][j]; 
		if (ret == -1 || ret > cand) ret = cand; 
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 

	cin >> n >> m >> k;
	vector<vector<int>> board(n, vector<int>(m)); 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j]; 
	vector<tuple<int, int, int>> rot; 
	for (int i = 0; i < k; i++) {
		int r, c, s; cin >> r >> c >> s; 
		rot.emplace_back(r, c, s); 
	}

	vector<int> order(k); 
	for (int i = 0; i < k; i++)
		order[i] = i; 
	int ret = -1; 
	do {
		auto temp = board; 
		for (int index : order) {
			int r, c, s; tie(r, c, s) = rot[index]; 
			rotate(r - 1, c - 1, s, temp, temp); 
		}

		int cand = calc(temp); 
		if (ret == -1 || ret > cand) ret = cand; 
	} while (next_permutation(order.begin(), order.end())); 

	cout << ret << endl;
	return 0; 
}