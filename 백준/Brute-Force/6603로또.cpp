#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

vector<int> numbers; // �� ���� �����Ѵ�.
void go(vector<int>& S, int index, int cnt) {
	if (cnt == 6) {
		for (int num : numbers)
			cout << num << " "; 
		cout << endl;
		return; 
	}
	if (index == (int) S.size()) return; 

	// ���� ���ڸ� ������ ��� 
	numbers.push_back(S[index]); 
	go(S, index + 1, cnt + 1); 
	numbers.pop_back(); 
	
	// ���� ���ڸ� �������� ���� ���
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