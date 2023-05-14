#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 

int n, m; 
int board[9][9]; 
vector<tuple<int,int,int>> cctv; 

// ��, ������, �Ʒ�, ����
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m);
}

// board�� �������� (y, x)�� �������� ������ �� �� �ִ� ���� ���ϰ�, �� ���� CCTV ������ temp �� �����Ѵ�.
void check(int temp[9][9], int y, int x, int dir) {
	int i = y, j = x; 
	while (true) {
		if (isOut(i, j)|| board[i][j] == 6) break;
		temp[i][j] = board[y][x]; 
		i += dy[dir], j += dx[dir];
	}
}

// (y, x)�� �ִ� i�� cctv�� Ž���Ѵ�. ������� ������ �������� �� �� �ִ� ������ sum���̴�.
int solve(int index, vector<int> dirs) {
	// ��� cctv�� �� �˻��ߴٸ�
	if (index == cctv.size()) {
		// �簢������ ������ ���Ѵ�.
		int temp[9][9]; 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				temp[i][j] = board[i][j]; 

		for (int i = 0; i < cctv.size(); i++) {
			int u, v, s; tie(u, v, s) = cctv[i]; 
			if (s == 1)
				check(temp, u, v, dirs[i]); 
			else if (s == 2) {
				check(temp, u, v, dirs[i]); 
				check(temp, u, v, (dirs[i] + 2) % 4); 
			}
			else if (s == 3) {
				check(temp, u, v, dirs[i]); 
				check(temp, u, v, (dirs[i] + 1) % 4); 
			}
			else if (s == 4) {
				check(temp, u, v, dirs[i]); 
				check(temp, u, v, (dirs[i] + 1) % 4); 
				check(temp, u, v, (dirs[i] + 2) % 4); 
			}
			else if (s == 5) {
				check(temp, u, v, dirs[i]); 
				check(temp, u, v, (dirs[i] + 1) % 4); 
				check(temp, u, v, (dirs[i] + 2) % 4);
				check(temp, u, v, (dirs[i] + 3) % 4);
			}
		}

		int cnt = 0; 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (temp[i][j] == 0) cnt++; 
		return cnt; 
	}

	// index�� ° CCTV�� ����
	int ret = 100; 
	for (int i = 0; i < 4; i++) {
		dirs[index] = i; // �� �� ȸ���ߴ°� ?
		int cand = solve(index + 1, dirs); 
		if (ret > cand) ret = cand;
	}
	return ret; 
}

int main() {
	cin >> n >> m;
	vector<int> dirs;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x; cin >> x; 
			board[i][j] = x; 
			if (x >= 1 && x <= 5){
				cctv.push_back(make_tuple(i, j, x)); 
				dirs.push_back(0); // i�� cctv�� �� �� ȸ���Ǿ����� ?  
			}
		}
	
	cout << solve(0, dirs) << endl;
	return 0; 
}