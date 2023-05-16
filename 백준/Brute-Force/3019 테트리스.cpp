#include <iostream>
#include <string> 
using namespace std; 

int c, p;
int a[101];

int calc(int i, string s) {
	if (i + s.length() > c) return 0; 
	int base = a[i] - (s[0] - '0'); 
	for (int j = 0; j < s.length(); j++) {
		if (base != a[i + j] - (s[j] - '0'))
			return 0; 
	}
	return 1; 
}

int main() {
	// 열의 개수, 블록의 번호
	 cin >> c >> p;
	for (int i = 0; i < c; i++)
		cin >> a[i]; 

	int ret = 0; 
	for (int i = 0; i < c; i++) {
		if (p == 1)
			ret += calc(i, "0") + calc(i, "0000");
		else if (p == 2)
			ret += calc(i, "00");
		else if (p == 3)
			ret += calc(i, "001") + calc(i, "10");
		else if (p == 4)
			ret += calc(i, "100") + calc(i, "01");
		else if (p == 5)
			ret += calc(i, "000") + calc(i, "01") + calc(i, "101") + calc(i, "10");
		else if (p == 6)
			ret += calc(i, "000") + calc(i, "00") + calc(i, "011") + calc(i, "20");
		else if (p == 7)
			ret += calc(i, "000") + calc(i, "02") + calc(i, "110") + calc(i, "00");
	}

	cout << ret << endl;
	return 0; 
}