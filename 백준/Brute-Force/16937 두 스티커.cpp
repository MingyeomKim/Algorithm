#include <iostream> 
#include <vector>
#include <cstring>
using namespace std; 

int h, w; int n;

// a, b 스티커를 모눈종이에 붙였을 때 넓이. 붙일 수 없는 경우 -1을 반환
int getArea(pair<int, int> a, pair<int,int> b){
	// rotation
	int ret = 0; 
	for (int r1 = 0; r1 < 2; r1++) {
		for (int r2 = 0; r2 < 2; r2++) {
			// 세로로 붙이는 경우 (a, b의 세로 길이의 합이 H보다 작으므로) 
			if (a.first + b.first <= h && max(a.second, b.second) <= w) {
				int cand = a.first * a.second + b.first * b.second;
				if (ret < cand) ret = cand;
			}
			// 가로로 붙이는 경우
			if (a.second + b.second <= w && max(a.first, b.first) <= h) {
				int cand = a.first * a.second + b.first * b.second; 
				if (ret < cand) ret = cand; 
			}
			swap(b.first, b.second);
		}
		swap(a.first, a.second); 
	}
	return ret; 
}

int main() {
	cin >> h >> w >> n; 
	vector<pair<int, int>> sticker;
	for (int i = 0; i < n; i++) {
		int r, c; cin >> r >> c; 
		sticker.emplace_back(r, c); 
	}

	// 두 스티커를 모두 탐색
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cand = getArea(sticker[i], sticker[j]); 
			if (ret < cand) ret = cand; 
		}
	}
	cout << ret << endl;
	return 0; 
}