#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


int main() {
	string s; cin >> s;
	vector<int> num, sign;
	bool isMinus = false; 
	int cur = 0; 
	sign.push_back(1); 

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			if (s[i] == '+')
				sign.push_back(1);
			else
				sign.push_back(-1); 
			num.push_back(cur);
			cur = 0; 
		}
		else {
			cur = cur * 10 + (s[i] - '0'); 
		}
	}
	num.push_back(cur); 

	int ret = 0; 
	for (int i = 0; i < num.size(); i++) {
		if (sign[i] == -1)
			isMinus= true;
		if (isMinus)
			ret -= num[i];
		else
			ret += num[i];
	}
	cout << ret << endl;
	return 0; 
 }