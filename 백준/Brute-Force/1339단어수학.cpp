#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int n; 
int alpha[256]; 

// 주어진 순열에 해당하는 단어의 합을 구한다.
int calc(vector<string>& input, vector<char>&letters, vector<int> number) {
	int sum = 0; 
	for (int i = 0; i < letters.size(); i++) {
		alpha[letters[i]] = number[i]; 
	}

	for (string s : input) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x]; 
		}
		sum += now; 
	}
	return sum; 
}

int main() {
	cin >> n;
	vector<string> input(n);
	vector<char> letters;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		for (char c : input[i])
			letters.push_back(c);
	}

	// letters 중복 제거
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	vector<int> number;
	int m = letters.size();
	for (int i = 9; i > 9 - m; i--)
		number.push_back(i); 
	sort(number.begin(), number.end()); 

	int ret = 0; 
	do {
		int cand = calc(input, letters, number); 
		if (ret < cand) ret = cand; 
	} while (next_permutation(number.begin(), number.end())); 
	
	cout << ret << endl;
	return 0; 
}