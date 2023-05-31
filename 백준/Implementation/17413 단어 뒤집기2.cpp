#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std; 

int word[100001]; // 1이면 단어 시작, -1이면 단어 끝, 나머지는 0
int main() {
	memset(word, 0, sizeof(word)); 
	string s; getline(cin, s); 
	int index = 0; 
	while (index < s.length()) {
		if (s[index] == '<') { // 태그 시작
			while (true) {
				index++;
				if (s[index] == '>') {
					break;
				}
			}
			index++;
		}
		else if ((s[index] >= 'a' && s[index] <= 'z')
			|| (s[index] >= '0' && s[index] <= '9')) { // 단어 시작
			word[index] = 1; 
			while (true) {
				index++; 
				if (s[index] == ' ' ) {
					word[index] = -1; 
					index++; 
					break;
				}
				if (s[index] == '<') {
					word[index] = -1; 
					break; 
				}
				if (index == s.length() - 1 || s[index + 1] == '<') {
					word[index + 1] = -1; 
					index++; 
					break;
				}
			}
		}
	}

	//reverse
	index = 0; 
	while (index <= s.length()) {
		if (word[index] == 1) {
			int i = index; 
			int j; 
			while (true) {
				index++; 
				if (word[index] == -1){
					j = index; 
					break;
				}
			}
			reverse(s.begin() + i, s.begin() + j); 
		}
		index++; 
	}
	cout << s << endl;
	return 0; 
}