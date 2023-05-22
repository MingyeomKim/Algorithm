#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
#define endl '\n'
using namespace std; 

char board[16][16]; 
bool check[16][16]; 
int dy[4] = { -1, 1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 }; 

int n, m;

bool isOut(int y, int x) {
	return y < 0 || y >= n || x < 0 || x >= m; 
}

bool cmp(tuple<int, int, int>& t1, tuple<int, int, int>& t2) {
	return get<0>(t1) > get<0>(t2);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	cin >> n >> m; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> board[i][j];

	int ret = 1; // 최소 넓이의 곱 (1, 1)
	vector<tuple<int,int,int>> cand;  // (size, y, x) : (y, x)에서 시작해서 size만큼의 십자가 (size >= 1인 것만 저장)
	for(int y = 1; y < n - 1;y ++)
		for (int x = 1; x < m - 1; x++) {
			if (board[y][x] == '#') {
				int min_dist = -1; 
				for (int direction = 0; direction < 4; direction++) {
					int ny = y + dy[direction], nx = x + dx[direction]; 
					int dist = 0; 
					while (!isOut(ny, nx) && board[ny][nx] != '.') {
						dist++; 
						ny += dy[direction], nx += dx[direction]; 
					}
					if (min_dist == -1 || min_dist > dist) min_dist = dist; 
				}
				while (min_dist >= 1) {
					cand.emplace_back(min_dist--, y, x); 
				}
				/*if (min_dist >= 1) {
					cand.emplace_back(min_dist, y, x); 
				}
				*/
			}
		}
	
	/*
	for (int i = 0; i < cand.size(); i++) {
		int size, y, x; tie(size, y, x) = cand[i]; 
		cout << size << "  " << y << " " << x << endl;
	}
	*/
	
	if (cand.size() == 0)
		cout << 1 << endl;
	else if (cand.size() == 1) {
		// 나올 수 있는 십자가가 이거 하나인 경우에는 1을 출력해야함
		memset(check, false, sizeof(check)); 
		int size, y, x; tie(size, y, x) = cand[0]; 
		check[y][x] = true; 
		for (int direction = 0; direction < 4; direction++) {
			int ny = y + dy[direction], nx = x + dx[direction]; 
			for (int k = 0; k < size; k++) {
				check[ny][nx] = true; 
				ny += dy[direction], nx += dx[direction]; 
			}
		}

		bool isOk = false; 
		for(int i =0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '#' && !check[i][j])
					isOk = true;
			}
		if (isOk) cout << 1 + size * 4 << endl;
		else cout << 1 << endl;
	}
	else {
		sort(cand.begin(), cand.end(), cmp);

		int ret = 0; 
		// 겹치지 않는 최댓값을 찾아 반환
		for (int i = 0; i < cand.size(); i++){
			int size1, y1, x1; 
			tie(size1, y1, x1) = cand[i];
			memset(check, false, sizeof(check)); 
			check[y1][x1] = true; 
			for (int direction = 0; direction < 4; direction++) {
				int ny = y1 + dy[direction], nx = x1 + dx[direction]; 
				for (int k = 0; k < size1; k++) {
					check[ny][nx] = true; 
					ny += dy[direction], nx += dx[direction]; 
				}
			}

			for (int j = i + 1; j < cand.size(); j++) {
				bool isOk = true;
				
				int size2, y2, x2;
				tie(size2, y2, x2) = cand[j];
				if (y1 == y2 && x1 == x2) continue; 

				for (int direction = 0; direction < 4; direction++) {
					int ny = y2 + dy[direction], nx = x2 + dx[direction];
					for (int k = 0; k < size2; k++) {
						if (check[ny][nx]) isOk = false; 
						ny += dy[direction], nx += dx[direction]; 
					}
				}
				if (isOk) {
					int cand = (1 + size1 * 4) * (1 + size2 * 4); 
					if (ret < cand) ret = cand; 
				}
			}
			int cand = (1 + size1 * 4); 
			if (ret < cand) ret = cand; 
		}
		cout << ret << endl;
	}
	return 0; 
}