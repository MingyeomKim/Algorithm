#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// �� �� �ִ� �������� ���� ����Ѵ�. 
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
	long long ret = left; // ������ �ּ� �Ÿ��� 
	while (left <= right) {
		long long mid = (left + right) / 2; 
		if (calc(house, mid) >= c) {
			if (ret < mid) ret = mid; 
			left = mid + 1;  // �����ϴٸ� ������ �� ũ���ؼ� �ִ� �Ÿ� ���� ã�´�.
		}
		else
			right = mid - 1; 
	}
	cout << ret << endl;
	return 0; 
}