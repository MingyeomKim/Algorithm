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
		// ������� ���� b���� ���� ��� �ִ� ���
		int c = stoi(a);
		if(a[0] != '0' && c < intB)
			if (max < c) max = c; 
	} while (next_permutation(a.begin(), a.end())); 
	if (max == 0) cout << -1 << endl;
	else cout << max << endl;
	return 0; 
}