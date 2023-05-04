#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// 둘 수 있는 공유기의 수를 계산한다. 
int calc(vector<long long> house, int x) {
	int ret = 1; 
	int size = house.size(); 
	int last = house[0]; 
	for (int i = 0; i < size; i++) {
		int dist = house[i] - last;
		if (dist >= x) {
			ret++; 
			last = house[i];
		}
	}
	return ret; 
}

int main() {
	int n, c; cin >> n >> c; 
	vector<long long> house(n);
	for (int i = 0; i < n; i++)
		cin >> house[i]; 
	sort(house.begin(), house.end());

	long long left = 1; 
	long long right = house[n-1] - house[0];
	long long ret = left; // 인접한 최소 거리의 
	while (left <= right) {
		long long mid = (left + right) / 2; 
		if (calc(house, mid) >= c) {
			if (ret < mid) ret = mid; 
			left = mid + 1;  // 가능하다면 정답을 더 크게해서 최대 거리 차를 찾는다.
		}
		else
			right = mid - 1; 
	}
	cout << ret << endl;
	return 0; 
}