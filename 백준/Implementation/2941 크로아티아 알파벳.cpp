#include <iostream>
using namespace std; 

string check[] = { 
	"c=", "c-", "lj", "nj", "s=", "z="
};

int main() {
	string s; cin >> s;
	int index = 0; 
	int ret = 0; 
	while (index < s.length()) {
		if (s[index] == 'd') {
			if (s[index + 1] == 'z' && s[index + 2] == '=')
				index = index + 3;
			else if (s[index + 1] == '-')
				index = index + 2;
			else
				index = index + 1;
		}
		else {
			// 주어진 알파벳인지 확인
			bool isOk = false;
			if (index < s.length() - 1) {
				string target = s.substr(index, 2);
				for (string cand : check)
					if (cand == target) isOk = true;
			}
			if (isOk) 
				index = index + 2;
			else
				index = index + 1; 
		}
		ret++; 
	}
	cout << ret << endl; 
	return 0; 
}