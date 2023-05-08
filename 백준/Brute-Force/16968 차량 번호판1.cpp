#include <iostream>
#define D 10
#define C 26
using namespace std; 

int main() {
	string a; cin >> a; 
	int ret = 0; 
	if (a[0] == 'c') ret += C;
	else ret += D; 

	for (int i = 1; i < a.size(); i++) {
		if (a[i] == a[i - 1]) {
			if (a[i] == 'c') ret  *= (C - 1);
			else ret *= (D - 1);
		}
		else {
			if (a[i] == 'c') ret *= C;
			else ret *= D;
		}
	}
	cout << ret << endl; 
	return 0; 
}