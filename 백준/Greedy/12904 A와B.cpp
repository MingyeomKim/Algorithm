#include <iostream>
#include <algorithm>
#include <string>
using namespace std; 

string t, s; 

int main() {
	cin >> s >> t; 

	// t�� ���� �������� �ٲ㰡�� s�� ��ġ�ϴ� �� �����Ѵ�.
	while (t.size() > 0) {
		if (t == s) {
			cout << 1 << endl;
			return 0; 
		}

		int u = t.size(); 
		if (t[u - 1] == 'A')
			t.erase(u - 1, 1); // 'A' ����
		else {
			t.erase(u - 1, 1); // 'B' ����
			reverse(t.begin(), t.end());
		}
	}
	cout << 0 << endl; 
	return 0; 
}