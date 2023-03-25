#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 

int n; 
int price[51]; 
int cache[51][51]; 

int diff(int left, int right) {
	if (left > right) return 0; 

	int& ret = cache[left][right]; 
	if (ret != -1) return ret; 

	int minValue = 0; 
	ret = max(price[left] - diff(left + 1, right),
			  price[right] - diff(left, right - 1)); 
	if (right - left + 1 >= 2) {
		ret = max(ret, -diff(left + 2, right)); 
		ret = max(ret, -diff(left, right - 2)); 
	}

	return ret; 
}

int main() {
	int cases; cin >> cases;
	while (cases--) {
		memset(cache, -1, sizeof(cache));
		cin >> n; 
		for (int i = 0; i < n; i++) cin >> price[i]; 
		cout << diff(0, n - 1) << endl;
	}
	return 0; 
}