#include <iostream>
#include <vector>
#include <cstring>
using namespace std; 

int check['z' - 'a' + 1]; // 마지막으로 이 문자가 나온 인덱스 저장 
int main() {
	int n; cin >> n;
	int ret = 0; 
	for (int i = 0; i < n; i++) {
		memset(check, -1, sizeof(check)); 
		string s; cin >> s; 
		bool isOk = true; 
		for (int j = 0; j < s.length(); j++) {
			if (check[s[j] - 'a'] != -1 && check[s[j] - 'a'] != j - 1)
				isOk = false; 
			check[s[j] - 'a'] = j; 
		}
		if (isOk) ret++; 
	}
	cout << ret << endl;
	return 0; 
}