#include <iostream>
#include <vector>
using namespace std; 

// 가져갈 수 있는 나무의 길이
long long calc(const vector<long long>& height, long long h) {
	long long ret = 0;
	int size = height.size(); 
	for (int i = 0; i < size; i++) {
		if (height[i] > h)
			ret += height[i] - h; 
	}
	return ret; 
}

int main() {
	long long n, m; cin >> n >> m;  // 나무의 수
	vector<long long> height(n);
	long long max_value = 0; 
	for (int i = 0; i < n; i++) {
		cin >> height[i];
		if (height[i] > max_value) max_value = height[i]; 
	}
	long long left = 1;
	long long right = max_value; 
	long long ret = 0; 
	while (left <= right) {
		long long mid = (left + right) / 2; 
		// 얻을 수 있는 나무가 필요한 것보다 적은 경우, 즉 높이를 너무 높게 설정한 경우 왼쪽을 택해 반복한다. 
		if (calc(height, mid) < m) right = mid - 1; 
		else {
			left = mid + 1; 
			if (ret < mid) ret = mid; 
		}
	}
	cout << ret << endl;
	return 0; 
}