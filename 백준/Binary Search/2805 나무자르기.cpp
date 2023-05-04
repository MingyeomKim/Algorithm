#include <iostream>
#include <vector>
using namespace std; 

// ������ �� �ִ� ������ ����
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
	long long n, m; cin >> n >> m;  // ������ ��
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
		// ���� �� �ִ� ������ �ʿ��� �ͺ��� ���� ���, �� ���̸� �ʹ� ���� ������ ��� ������ ���� �ݺ��Ѵ�. 
		if (calc(height, mid) < m) right = mid - 1; 
		else {
			left = mid + 1; 
			if (ret < mid) ret = mid; 
		}
	}
	cout << ret << endl;
	return 0; 
}