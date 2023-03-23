#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int k; // �κ� ���ڿ��� ��
const int MAX_K = 15; 
int cache[MAX_K][1 << MAX_K]; 
int overlap[MAX_K][MAX_K];
string words[MAX_K]; 

/*
void findOverlap(int A, int B) {
	string a = words[A], b = words[B]; 
	int cnt = 0, ret = 0;
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++) {
			if (a[i] == b[j]) cnt++;
			else {
				ret = max(ret, cnt);
				cnt = 0;
			}
		}
	overlap[A][B] = ret; 
}*/

int findOverlap(string& s1, string& s2)
{
	for (int len = min(s1.size(), s2.size()); len > 0; len--) {
		if (s1.substr(s1.size() - len) == s2.substr(0, len)) {
			return len;
		}
	}
	return 0;
}

int restore(int last, int used){
	if (used == (1 << k) - 1) return 0; // ��� ������ ��ȸ�Ͽ��ٸ�
		
	int& ret = cache[last][used];
	if (ret != -1) return ret;

	ret = 0; 
	for (int next = 0; next < k; next++) 
		if ((used & (1 << next)) == 0) {// �湮���� �ʾҴٸ�
			int cand = overlap[last][next] + restore(next, used + (1 << next)); // ���� ��ġ�� �Ͱ� �� ���� ��ġ�� �͵��� ���ؼ� ��ȯ�Ѵ�.
			ret = max(ret, cand);  // ���� ���� ��ġ�� ���� Ž��
		}
	return ret; 
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return ""; // ��� ���� �� ã�� ���

	for (int next = 0; next < k; next++) {
		if (used & (1 << next)) continue; // �̹� �˻��� ���� �н�

		int maybe = overlap[last][next] + restore(next, used + (1 << next)); 
		// next�� ������� ����� ���� ������ restore(last, next)�� ���ٸ� ����Ѵ�.
		if (maybe == restore(last, used))
			// �ߺ��� �κ� ���ĺ��� �ٽ� ���ڿ��� Ž���Ѵ�.
			return (words[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next))); 
	}
	return "oops!"; // ���⿡�� ������ �� ����. 
}


int main() {
	int cases; cin >> cases;
	while (cases--) {
		memset(cache, -1, sizeof(cache)); 
		memset(overlap, -1, sizeof(overlap));
		cin >> k;
		for (int i = 0; i < k; i++) cin >> words[i]; 

		// �� ���ڰ� �ٸ� ���ڿ� ������ ��ġ�� ��츦 �����Ѵ�.
		while (true) {
			bool removed = false; 
			for (int i = 0; i < k && !removed; i++) 
				for (int j = 0; j < k; j++)
					// words[j]�� words[i]�� �ҼӵǴ� ���
					if (i != j && words[i].find(words[j]) != -1) {
						words[j] = words[k - 1]; // Ž�� ���� ������ ����������. 
						k--; 
						removed = true; 
					}
			if (!removed) break; 
		}
		words[k] = ""; 


		for (int i = 0; i <= k; i++)
			for (int j = 0; j <= k; j++) {
				overlap[i][j] = findOverlap(words[i], words[j]);
			}
		cout << reconstruct(k, 0) << endl;
	}
	return 0; 
}