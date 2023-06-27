#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std; 

int dy[] = { 1, -1, 0, 0 }; 
int dx[] = { 0, 0, 1, -1 }; 

int w, h;
int dist[21][21];
vector<string> v;

bool isOut(int y, int x) {
	return y < 0 || y >= h || x < 0 || x >= w; 
}

void bfs(pair<int, int> src) {
	memset(dist, -1, sizeof(dist)); 
	queue<pair<int, int>> q; 
	int y = src.first, x = src.second; 
	q.push(make_pair(y, x)); 
	dist[y][x] = 0; 
	while (!q.empty()) {
		tie(y, x) = q.front(); q.pop(); 

		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			if (isOut(ny, nx) || dist[ny][nx] != -1 || v[ny][nx] == 'x') continue;
			dist[ny][nx] = dist[y][x] + 1; 
			q.push(make_pair(ny, nx));
		}
	}
}

int main() {
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) break;

		v.clear();  v = vector<string>(h);
		
		int sy, sx; 
		vector<pair<int, int>> target; 
		for (int i = 0; i < h; i++) {
			cin >> v[i];
			for (int j = 0; j < w; j++)
				if (v[i][j] == 'o') {
					sy = i, sx = j; 
					v[i][j] = '.';
				}
				else if (v[i][j] == '*')
					target.emplace_back(i, j); 
		}

		bool flag = true; 

		// initial[i] : (sy, sx)에서 target[i] 점으로 이동할 수 있는 거리
		vector<int> initial(target.size());
		bfs(make_pair(sy, sx));
		for (int i = 0; i < target.size(); i++) {
			int distance = dist[target[i].first][target[i].second];
			if (distance == -1) {
				flag = false; 
				break;
			}
			initial[i] = distance; 
		}
		if (!flag) {
			cout << -1 << endl; 
			continue;
		}

		// map[i][j] : target[i]에서 target[j] 점으로 이동할 수 있는 거리
		vector<vector<int>> map(target.size(),  vector<int>(target.size()));
		for (int i = 0; i < target.size() - 1; i++) {
			bfs(target[i]); 
			for (int j = i + 1; j < target.size(); j++) {
				int distance = dist[target[j].first][target[j].second];
				if (distance == -1) {
					flag = false; 
					break;
				}
				map[i][j] = distance, map[j][i] = distance;
			}
		}
		if (!flag) {
			cout << -1 << endl;
			continue; 
		}

		vector<int> number; 
		for (int i = 0; i < target.size(); i++) 
			number.push_back(i); 

		int ret = -1; 
		do {
			int cand = initial[number[0]]; 
			for (int i = 0; i < number.size() - 1; i++) {
				cand += map[number[i]][number[i + 1]]; 
			}
			if (ret == -1 || ret > cand) ret = cand;
		} while (next_permutation(number.begin(), number.end())); 
		cout << ret << endl;
	}
	return 0;
}