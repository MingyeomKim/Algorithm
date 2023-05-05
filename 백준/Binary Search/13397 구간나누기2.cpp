#include <iostream>
#include <vector>
using namespace std; 

int n, m; 

// 구간 점수의 최댓값이 K인 경우 총 몇 개의 구간이 나오는지 ? 
int calc(vector<int> num, int k) {
	int min = num[0], max = num[0]; 
	int ret = 1; // 구간의 개수
	for (int i = 1; i < n; i++) {
		if (min > num[i]) min = num[i]; 
		if (max < num[i]) max = num[i]; 
		if (max - min > k) { // 구간을 나눠준다. 
			ret++; 
			min = num[i]; 
			max = num[i]; 
		}
	}
	return ret; 
}

int main() {
	cin >> n >> m;
	vector<int> numbers(n);
	int left = 0;
	int right = 0;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		if (right < numbers[i]) right = numbers[i]; 
	}
	// int ret = right; 
	int ret = 0; 
	while (left <= right) {
		int mid = (left + right) / 2; 
		if (calc(numbers, mid) <= m) { // 구간 갯수가 더 작다면, 구간 점수의 최댓값을 작게하여 구간을 더 늘려도 됨!
			right = mid - 1;
			// if (ret > mid) ret = mid;  // 최솟값으로 결정
			ret = mid; 
		}
		else
			left = mid + 1; 
	}
	cout << ret << endl;
	return 0; 
}