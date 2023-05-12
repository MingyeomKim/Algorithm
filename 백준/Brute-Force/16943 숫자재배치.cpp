#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

int main() {
	string a, b; cin >> a >> b;
	sort(a.begin(), a.end());

	int max = 0; 
	int intB = stoi(b); 
	do {
		// 만들어진 수가 b보다 작은 경우 최댓값 계산
		int c = stoi(a);
		if(a[0] != '0' && c < intB)
			if (max < c) max = c; 
	} while (next_permutation(a.begin(), a.end())); 
	if (max == 0) cout << -1 << endl;
	else cout << max << endl;
	return 0; 
}