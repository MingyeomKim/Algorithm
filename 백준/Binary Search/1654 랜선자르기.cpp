#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// n의 길이로 잘랐을 때 랜선의 개수를 반환한다. 
int getCount(vector<int> LAN, int len) {
	int ret = 0; 
	for (int i = 0; i < (int)LAN.size(); i++) 
		ret += LAN[i] / len; 
	return ret; 
}

int main() {
	int n, k; 
	cin >> k >> n;

	vector<int> LANs(k); 
	long long max_value = 0; 
	for (int i = 0; i < k; i++){
		cin >> LANs[i]; 
		if (LANs[i] > max_value) max_value = LANs[i]; 
	}

	long long left = 1; 
	long long  right = max_value;
	 vector<long long > candidates; 
	while (left <= right) {
		long long mid = (left + right) / 2; 
		int cnt = getCount(LANs, mid); 
		if (cnt >= n) {
			candidates.push_back(mid); 
			left = mid + 1;
		}
		else
			right = mid - 1; 
	}
	 sort(candidates.begin(), candidates.end(), greater<int>()); 
	 cout << candidates[0] << endl;
	return 0; 
}