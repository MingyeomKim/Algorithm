#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std; 

int n, m;
int num[500000]; 

bool binarySearch( int target) {
	int left = 0, right = n - 1; 
	
	while (left <= right) {
		int mid = (left + right) / 2; 
		if (num[mid] == target)
			return 1;
		else if (num[mid] > target)
			right = mid - 1;
		else
			left = mid + 1; 
	}
	return 0; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL); 

	cin >> n; // 숫자 카드 수
	for (int i = 0; i < n; i++) cin >> num[i]; 
	sort(num, num + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		int target; cin >> target; 
		cout << binarySearch(target) << " "; 
	}
	cout << endl;
	return 0; 
}