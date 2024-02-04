#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

bool dragon[102][102]; // �巡�� Ŀ���� ����� �����ϴ� �迭

// �巡�� Ŀ�긦 ������ �׸��� �� ĭ�� �� ������ �߿��� �巡�� Ŀ���� �Ϻο� ���ϴ� �������� ������ �����ϴ� ����
int main() {
	int n; cin >> n;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		int d, g; cin >> d >> g;
		v.push_back(make_pair(x, y));
		int ny = y + dy[d], nx = x + dx[d];
		v.push_back(make_pair(nx, ny)); // 0����

		for (int j = 0; j < g; j++) { // 1 ���� ~ g ����
			auto back = v.back();
			int a = back.first, b = back.second;
			int size = v.size();
			for (int k = size - 2; k >= 0; k--) {
				int c = v[k].first, d = v[k].second;
				v.push_back({ b - d + a, c - a + b });
			}
		}

		for (auto p : v) {
			int x = p.first, y = p.second;
			dragon[y][x] = true;
		}
	}



	int ret = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			int cnt = 0;
			if (dragon[i][j]) {
				cnt++;
			}
			if (dragon[i][j + 1]) {
				cnt++;
			}
			if (dragon[i + 1][j]) {
				cnt++;
			}
			if (dragon[i + 1][j + 1]) {
				cnt++;
			}

			if (cnt == 4) {
				ret++;
			}
		}
	}
	cout << ret << endl;
	return 0;
}