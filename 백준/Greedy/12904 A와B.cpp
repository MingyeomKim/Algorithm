#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

string t, s; 

int main() {
	cin >> s >> t; 

	// t를 이전 연산으로 바꿔가며 s와 일치하는 지 조사한다.
	while (t.size() > 0) {
		if (t == s) {
			cout << 1 << endl;
			return 0; 
		}

		int u = t.size(); 
		if (t[u - 1] == 'A')
			t.erase(u - 1, 1); // 'A' 제거
		else {
			t.erase(u - 1, 1); // 'B' 제거
			reverse(t.begin(), t.end());
		}
	}
	cout << 0 << endl; 
	return 0; 
}