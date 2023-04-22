#include <iostream>
#include <vector>
using namespace std; 

int n, k;

int main() {
	cin >> n >> k;
	// A의 개수를 바꿔가며 입력 조건과 일치 (k개의 쌍, n길이의 문자열) 하는 A, B 조합을 찾는다. 
	for(int a = 0; a <= n; a++){
		int b = n - a; 
		if (a * b < k) continue; 

		vector<int> cnt(b + 1); 
		for (int i = 0; i < a; i++) {
			int pos = min(b, k); 
			cnt[pos]++; 
			k -= pos; 
		}

		for (int i = b; i >= 0; i--) {
			for (int j = 0; j < cnt[i]; j++)
				cout << 'A'; 
			if(i > 0)
				cout << 'B'; 
		}
		cout << endl;
		return 0; 
	}
	cout << -1 << endl;
	return 0; 
}