#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;
string letters = ""; 

int count(int bit) { // 특정 알파벳 조합에서 읽을 수 있는 단어의 개수
	int cnt = 0; 
	for (string word : words) {
		bool canRead = true;
		for (char letter : word) {
			bool know = false;
			int sz = letters.length();
			for (int j = 0; j < sz; j++) {
				// 검증
				if ((bit & (1 << j))&& letters[j] == letter) {
					know = true;
				}

				if (letter == 'a' || letter == 'n' || letter == 't' || letter == 'i' || letter == 'c') {
					know = true;
				}
			}
			if (!know) {
				canRead = false; 
			}
		}
		if (canRead) {
			cnt++;
		}
	}
	return cnt;
}	

int bitCount(int bit) {
	if (bit == 0) {
		return 0;
	}
	return bit % 2 + bitCount(bit / 2);
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 

	int n, k; cin >> n >> k; 
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s; 
		s = s.substr(4, s.length() - 8);
		words.push_back(s);
		for (int j = 0; j < s.length(); j++) {
			char letter = s[j];
			if (letter == 'a' || letter == 'n' || letter == 't' || letter == 'i' || letter == 'c') {
				continue;
			}
			letters.push_back(letter);
		}
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	if (k < 5) {
		cout << 0 << endl;
		return 0;
	}
	k -= 5; // 고정 문자 제거

	int ret = 0;
	int sz = letters.length();
	for (int bit = 0; bit < (1 << sz); bit++) {
		if (bitCount(bit) != k) { // K개 글자를 모두 가르치는 조합의 경우만 검증
			continue;
		}
		int cand = count(bit); 
		if (ret < cand) {
			ret = cand;
		}
	}
	cout << ret << endl; 
	return 0;
}