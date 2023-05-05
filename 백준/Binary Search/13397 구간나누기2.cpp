#include <iostream>
#include <vector>
using namespace std; 

int n, m; 

// ���� ������ �ִ��� K�� ��� �� �� ���� ������ �������� ? 
int calc(vector<int> num, int k) {
	int min = num[0], max = num[0]; 
	int ret = 1; // ������ ����
	for (int i = 1; i < n; i++) {
		if (min > num[i]) min = num[i]; 
		if (max < num[i]) max = num[i]; 
		if (max - min > k) { // ������ �����ش�. 
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
		if (calc(numbers, mid) <= m) { // ���� ������ �� �۴ٸ�, ���� ������ �ִ��� �۰��Ͽ� ������ �� �÷��� ��!
			right = mid - 1;
			// if (ret > mid) ret = mid;  // �ּڰ����� ����
			ret = mid; 
		}
		else
			left = mid + 1; 
	}
	cout << ret << endl;
	return 0; 
}