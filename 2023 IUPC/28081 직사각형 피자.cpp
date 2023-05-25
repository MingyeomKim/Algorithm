#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

long long w, h, k;

bool check(long long height, long long wide) {
	return height * wide <= k; 
}

int main() {
	cin >> w >> h >> k;
	int n; cin >> n;  // 가로 방향 커팅 개수
	vector<long long > height(n); // 커팅의 세로 위치
	vector<long long > block_h;
	for (int i = 0; i < n; i++) {
		cin >> height[i]; 
		if (i != 0) block_h.push_back(height[i] - height[i - 1]);
		else block_h.push_back(height[i]); 
	}
	block_h.push_back(h - height.back());
	
	int m; cin >> m;  // 세로 방향 커팅 개수
	vector<long long > wide(m);
	vector<long long > block_w;
	for (int i = 0; i < m; i++) {
		cin >> wide[i]; 
		if (i != 0) block_w.push_back(wide[i] - wide[i - 1]);
		else block_w.push_back(wide[i]); 
	}
	block_w.push_back(w - wide.back()); 

	long long ret = 0; 
	sort(block_w.begin(), block_w.end());
	for (int i = 0; i < block_h.size() ; i++) { // height
		long long  left = 0;  //  block_w의 인덱스를 저장
		long long  right = block_w.size() - 1;
		while(left <= right){ // wide
			long long  mid = (left + right) / 2;
			if (check(block_h[i], block_w[mid])) { 
				left = mid + 1; 
			}
			else {
				right = mid - 1; 
			}
		}
		ret += left; 
	}
	cout << ret << endl;
	return 0; 
}