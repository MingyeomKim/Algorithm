#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 

int count(int set, vector<int>& words) {
	int cnt = 0; 
	for (int word : words) // word : i번째 단어를 구성하는 알파벳 집합
		if ((word & ((1 << 26) - 1 - set)) == 0) // 배우지 않은 알파벳이 단어에 있는지 검사
			cnt++; 
	return cnt; 
}

// index : 현재 검사하는 알파벳 
// k : 배워야하는 단어의 개수
// set : 배운 알파벳 집합의 비트마스크
// words : 각 단어에 포함된 알파벳 집합의 비트마스크
int go(int index, int k, int set, vector<int> &words) {

	if (k < 0) return  0; 
	if (index == 26) return count(set, words); 

	int ret = 0; 
	// index번째 알파벳을 선택하는 경우
	int cand = go(index + 1, k - 1, set | (1 << index), words); 
	if (ret < cand) ret = cand;

	// index번째 알파벳을 배우지 않는 경우
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
		cand = go(index + 1, k, set, words);
		if (ret < cand) ret = cand; 
	}
	return ret; 
}

int main() {
	int k;
	cin >> n >> k;
	vector<int> words(n); 
	for (int i = 0; i < n; i++) {
		string s; cin >> s; 
		for (char x : s) words[i] |= (1 << (x - 'a')); 
	}

	cout << go(0, k, 0, words) << endl;
	return 0; 
}