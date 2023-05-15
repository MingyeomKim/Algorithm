#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std; 

int board[51][51]; 
int n, m; 
int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 }; 
int result = -1; 
vector<pair<int, int>> chickens; // ġŲ��
vector<pair<int, int>> houses; // ��

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= n); 
}

void solve(int index, int sum, vector<int> selected) {
	if (index == chickens.size()) {
		// ������ ġŲ���� ���� m�� ���� ��쿡�� ġŲ �Ÿ��� ���
		if (sum > m || sum == 0) return; 

		int cand = 0; // ������ ġŲ �Ÿ�
		for (auto house : houses) {
			int hy, hx; tie(hy, hx) = house; 
			// �� ������ ���� ����� ġŲ���� ã�´�. 
			int min_dist = -1; 
			for (int i : selected) {
				int y, x; tie(y, x) = chickens[i]; 
				int dist = abs(hy - y) + abs(hx - x); 
				if (min_dist == -1 || min_dist > dist) min_dist = dist; 
			}
			cand += min_dist; 
		}
		if (result == -1 || result > cand) result = cand;
		return; 
	}
	
	selected.push_back(index); 
	solve(index + 1, sum + 1, selected); 
	selected.pop_back(); 
	solve(index + 1, sum, selected); 
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				houses.emplace_back(i, j);
			else if (board[i][j] == 2)
				chickens.emplace_back(i, j); 
		}
	vector<int> selected; 
	solve(0, 0, selected); 
	cout << result << endl;
	
	return 0; 
}