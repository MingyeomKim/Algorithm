#include <iostream>
#include <cstring>
#include <vector>
using namespace std; 

int n, m, h; 

int info[31][11];

bool canInput(int y, int x) {
	if (x == n || info[y][x] != 0 || info[y][x + 1] != 0)
		return false;
	return true;
}

int start(int c) {
	int r = 1; 
	while (r <= h) {
		if (info[r][c] == 1)
			c++;
		else if (info[r][c] == 2)
			c--;
		r++;
	}
	return c; 
}

bool check() {
	for (int i = 1; i <= n; i++) {
		int res = start(i); 
		if (res != i) return false; 
	}
	return true; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	cin >> n >> m >> h; 
	
	memset(info, 0, sizeof(info)); 
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		// left : 1, right : 2, none : 0
		info[a][b] = 1;
		info[a][b + 1] = 2;
	}
	
	vector<pair<int, int>> v;
	for (int y = 1; y <= h; y++)
		for (int x = 1; x <= n; x++)
			if (canInput(y, x)) v.emplace_back(y, x);

	int ret = -1; 
	if (check()) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		int y1 = v[i].first, x1 = v[i].second;
		if (!canInput(y1, x1)) continue;
		info[y1][x1] = 1;
		info[y1][x1 + 1] = 2;

		if (check()) {
			if (ret == -1 || ret > 1)
				ret = 1; 
		}

		for (int j = i + 1; j < v.size(); j++) {
			int y2 = v[j].first, x2 = v[j].second;
			if (!canInput(y2, x2)) continue; 

			info[y2][x2] = 1;
			info[y2][x2 + 1] = 2;

			if (check()) {
				if (ret == -1 || ret > 2)
					ret = 2; 
			}
			for (int k = j + 1; k < v.size(); k++) {
				int y3 = v[k].first, x3 = v[k].second; 
				if (i == k || j == k || !canInput(y3, x3)) continue;

				info[y3][x3] = 1;
				info[y3][x3 + 1] = 2;

				if (check()) {
					if (ret == -1 || ret > 3)
						ret = 3; 
				}

				info[y3][x3] = 0;
				info[y3][x3 + 1] = 0;
			}
			info[y2][x2] = 0;
			info[y2][x2 + 1] = 0;
		}
		info[y1][x1] = 0;
		info[y1][x1 + 1] = 0;
	}

	cout << ret << endl;
	return 0; 
}