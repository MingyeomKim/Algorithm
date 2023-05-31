#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std; 

int n, m; 
int board[301][301]; 
bool check[301][301]; 

int dy[] = { -1, 1, 0, 0 }; 
int dx[] = { 0, 0, 1, -1 }; 

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m; 
}

void bfs(int y, int x) {
	check[y][x] = true; 
	queue<pair<int, int>> q; 
	q.push(make_pair(y, x)); 
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop(); 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx) || check[ny][nx] || board[ny][nx] == 0) continue;
			q.push(make_pair(ny, nx)); 
			check[ny][nx] = true; 
		}
	}
}

void melt() {
	vector<vector<int>> temp(n, vector<int>(m)); 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = board[i][j]; 
	for(int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (temp[y][x] == 0) continue; 
			int blank = 0;
			for (int direction = 0; direction < 4; direction++) {
				int ny = y + dy[direction], nx = x + dx[direction]; 
				if (temp[ny][nx] == 0) blank++; 
			}
			if (board[y][x] < blank)
				board[y][x] = 0; 
			else 
				board[y][x] -= blank; 
		}
}

int main() {
	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j]; 
	int ret = 0; 
	while (true) {
	
		melt(); 	// ºù»êÀÌ ³ì´Â´Ù.
		int lump = 0;		// µ¢¾î¸® °³¼ö¸¦ °è»êÇÑ´Ù.
		memset(check, false, sizeof(check)); 
		for(int y = 0; y < n; y++)
			for (int x = 0; x < m; x++) {
				if (check[y][x] || board[y][x] == 0) continue; 
				lump++; 
				bfs(y, x); 
			}

		ret++;
		if (lump > 1) {
			cout << ret << endl;
			return 0; 
		}
		if (lump == 0) { // ºù»êÀÌ ´Ù ³ì¾Ò´Ù¸é
			cout << 0 << endl;
			return 0; 
		}
	}
	return 0; 
}