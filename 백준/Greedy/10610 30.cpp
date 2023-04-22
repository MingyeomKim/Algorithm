#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

bool cmp(int n1, int n2) {
	return n1 > n2; 
}

int main() {
	string input; cin >> input;
	int sum = 0; 
	bool areZeroExists = false; 
	for (char s : input) {
		sum += s - '0'; 
		if (s == '0')
			areZeroExists = true; 
	}
	
	sort(input.begin(), input.end(), cmp);
	if (!areZeroExists || sum % 3 != 0) cout << -1 << endl;
	else cout << input << endl;
	return 0;
}
