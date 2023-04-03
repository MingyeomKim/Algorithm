#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

vector<int> numbers; // 고른 수를 저장한다.
void go(vector<int>& S, int index, int cnt) {
	if (cnt == 6) {
		for (int num : numbers)
			cout << num << " "; 
		cout << endl;
		return; 
	}
	if (index == (int) S.size()) return; 

	// 현재 숫자를 선택할 경우 
	numbers.push_back(S[index]); 
	go(S, index + 1, cnt + 1); 
	numbers.pop_back(); 
	
	// 현재 숫자를 선택하지 않을 경우
	go(S, index + 1, cnt); 
}

int main() {
	while (true) {
		int k; cin >> k;
		if (k == 0) break; 

		vector<int> S(k); 
		for (int i = 0; i < k; i++) cin >> S[i]; 

		go(S, 0, 0); 
		cout << endl;
	}
	return 0; 
}