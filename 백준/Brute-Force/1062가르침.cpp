#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 

int count(int set, vector<int>& words) {
	int cnt = 0; 
	for (int word : words) // word : i��° �ܾ �����ϴ� ���ĺ� ����
		if ((word & ((1 << 26) - 1 - set)) == 0) // ����� ���� ���ĺ��� �ܾ �ִ��� �˻�
			cnt++; 
	return cnt; 
}

// index : ���� �˻��ϴ� ���ĺ� 
// k : ������ϴ� �ܾ��� ����
// set : ��� ���ĺ� ������ ��Ʈ����ũ
// words : �� �ܾ ���Ե� ���ĺ� ������ ��Ʈ����ũ
int go(int index, int k, int set, vector<int> &words) {

	if (k < 0) return  0; 
	if (index == 26) return count(set, words); 

	int ret = 0; 
	// index��° ���ĺ��� �����ϴ� ���
	int cand = go(index + 1, k - 1, set | (1 << index), words); 
	if (ret < cand) ret = cand;

	// index��° ���ĺ��� ����� �ʴ� ���
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