#include <iostream>
#include <string>
#define hash hash_
using namespace std; 

// 라빈-카프 알고리즘
int mod = 127; // 소수
int base = 256; // 진법
int hash(string s) {
	int ret = 0; 
	for (char c : s)
		ret = (ret * base + c) % mod; 
	return ret; 
}

int match(string& s, string& p) {
	int n = s.length(); 
	int m = p.length(); 
	if (n < m) return 0; 

	int hash_p = hash(p); 
	int hash_s = hash(s.substr(0, m)); 

	int first = 1; // 제일 첫번째 문자에 몇을 곱하는 지 저장
	for (int i = 0; i < m - 1; i++)
		first = (first * base) % mod; 
	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) // 해시값이 같으면 비교
			if (s.substr(i, m) == p) return 1; 
		if (i + m < n) { 
			hash_s = hash_s - (s[i] * first) % mod; 
			hash_s = (hash_s + mod) % mod;  // 음수가 나오는경우를 처리
			hash_s = ((hash_s * base) % mod + s[i + m]) % mod; 
		}
	}
	return 0; 
}

int main() {
	string s, p; cin >> s >> p;
	cout << match(s, p) << endl;
	return 0; 
}