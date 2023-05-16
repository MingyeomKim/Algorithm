#include <iostream>
#include <cstring>
#include <vector>
using namespace std; 

int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 }; 

int n, m; 
char board[31][31];

bool isOut(int y, int x) {
	return (y < 0 || y >= n || x < 0 || x >= m); 
}

// 몇 번 더 이동해야 모든 빈 칸을 방문할 수 있는지 반환
int solve(int cnt, int y, int x) {
	int ret = -1; 
	if (cnt == 0) return 0; 

	for (int direction = 0; direction < 4; direction++) {
		int ny = y + dy[direction], nx = x + dx[direction]; 
		while (board[ny][nx] == '.' && !isOut(ny, nx)) { 
			board[ny][nx] = '#'; 
			ny += dy[direction], nx += dx[direction];
			cnt--;
		}
		ny -= dy[direction], nx -= dx[direction]; 

		// 이동하지 않은 경우 제외
		if (!(ny == y && nx == x)) {
			int cand = solve(cnt, ny, nx); 
			if (cand != -1)
				if (ret == -1 || ret > cand + 1) 
					ret = cand + 1; 
		}

		// 원상복귀
		while (!(ny == y && nx == x)) {
			board[ny][nx] = '.'; 
			cnt++;
			ny -= dy[direction], nx -= dx[direction];
		}
	}
	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 

	int index = 1; 
	while(cin >> n >> m){
		int blank = 0; 
		for (int i = 0; i < n; i++){
			cin >> board[i];
			for (int j = 0; j < m; j++) 
				if (board[i][j] == '.') 
					blank++; 
		}

		int ret = -1;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '.') {
					board[i][j] = '#'; 
					int cand = solve(blank - 1, i, j); 
					if (cand != -1)
						if (ret == -1 || ret > cand) ret = cand;
					board[i][j] = '.';
				}
			}
		cout << "Case " << index << ": " << ret << endl; 
		index++;
	}
	return 0; 
}