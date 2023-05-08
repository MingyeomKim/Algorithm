#include <iostream>
using namespace std; 

int a, b, c, x, y;

int calc(int half) {
	int ret = half * c; 
	int x_ = x - half / 2, y_ = y - half / 2; 
	if (x_ > 0) ret += a * x_; 
	if (y_ > 0) ret += b * y_; 
	return ret; 
}

int main() {
	cin >> a >> b >> c >> x >> y; 
	int max_half = max(x, y)  * 2; // 반반 치킨의 최대 개수
	int ret = -1; 
	for (int half = 0; half <= max_half; half += 2) {
		int cand = calc(half); 
		if (ret == -1 || ret > cand) ret = cand; 
	}
	cout << ret << endl;
	return 0; 
}