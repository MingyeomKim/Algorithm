#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std; 

int n, m; 
int board[9][9]; 
vector<tuple<int,int,int>> cctv; 

// 위, 오른쪽, 아래, 왼쪽
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m);
}

// board를 바탕으로 (y, x)을 시작으로 끝까지 갈 수 있는 곳을 구하고, 그 때의 CCTV 정보를 temp 에 저장한다.
void check(int temp[9][9], int y, int x, int dir) {
	int i = y, j = x; 
	while (true) {
		if (isOut(i, j)|| board[i][j] == 6) break;
		temp[i][j] = board[y][x]; 
		i += dy[dir], j += dx[dir];
	}
}

// (y, x)에 있는 i번 cctv를 탐색한다. 현재까지 설정한 방향으로 볼 수 있는 영역은 sum개이다.
int solve(int index, vector<int> dirs) {
	// 모든 cctv를 다 검색했다면
	if (index == cctv.size()) {
		// 사각지대의 개수를 구한다.
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

	// index번 째 CCTV의 방향
	int ret = 100; 
	for (int i = 0; i < 4; i++) {
		dirs[index] = i; // 몇 번 회전했는가 ?
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
				dirs.push_back(0); // i번 cctv가 몇 번 회전되었는지 ?  
			}
		}
	
	cout << solve(0, dirs) << endl;
	return 0; 
}