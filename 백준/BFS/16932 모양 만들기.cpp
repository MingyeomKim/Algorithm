#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
using namespace std; 

int board[1001][1001]; 
int group[1001][1001]; 
int group_size[1001 * 1001];  // i번 그룹의 크기 (1의 개수)

int dy[] = { -1, 1, 0, 0 }; 
int dx[] = { 0, 0, 1, -1 };

int n, m;
bool check[1001][1001]; 

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m; 
}

void bfs(int y, int x, int num) {
	int sum = 0; 
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	check[y][x] = true;
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop();
		group[y][x] = num; sum++; 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction];
			if (isOut(ny, nx) || check[ny][nx] || board[ny][nx] == 0) continue;
			check[ny][nx] = true;
			q.push(make_pair(ny, nx));
		}
	}
	group_size[num] = sum; 
}

void calc() {
	int cnt = 0; 
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (check[y][x] || board[y][x] != 1) continue;
			bfs(y, x, cnt); 
			cnt++; 
		}
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];
	
	// group 구하기
	memset(group, -1, sizeof(group)); 
	calc(); 

	int max = 0; 
	for(int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (board[y][x] != 0) continue; 
			set<int> adjacent;
			for (int direction = 0; direction < 4; direction++) {
				int ny = y + dy[direction], nx = x + dx[direction]; 
				if (isOut(ny, nx) || group[ny][nx] == -1) continue;
				adjacent.insert(group[ny][nx]); 
			}

			int sum = 0;
			for (auto g : adjacent) 
				sum += group_size[g]; 
			if (max < sum + 1) max = sum + 1; 
		}
	cout << max << endl;
	return 0; 
}