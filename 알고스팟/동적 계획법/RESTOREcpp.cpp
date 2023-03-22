#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int k; // 부분 문자열의 수
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
	if (used == (1 << k) - 1) return 0; // 모든 조각을 순회하였다면
		
	int& ret = cache[last][used];
	if (ret != -1) return ret;

	ret = 0; 
	for (int next = 0; next < k; next++) 
		if ((used & (1 << next)) == 0) {// 방문하지 않았다면
			int cand = overlap[last][next] + restore(next, used + (1 << next)); // 현재 겹치는 것과 그 다음 겹치는 것들을 더해서 반환한다.
			ret = max(ret, cand);  // 제일 많이 겹치는 것을 탐색
		}
	return ret; 
}

string reconstruct(int last, int used) {
	if (used == (1 << k) - 1) return ""; // 모든 것을 다 찾은 경우

	for (int next = 0; next < k; next++) {
		if (used & (1 << next)) continue; // 이미 검사한 것은 패스

		int maybe = overlap[last][next] + restore(next, used + (1 << next)); 
		// next를 사용했을 경우의 답이 최적해 restore(last, next)와 같다면 사용한다.
		if (maybe == restore(last, used))
			// 중복된 부분 이후부터 다시 문자열을 탐색한다.
			return (words[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next))); 
	}
	return "oops!"; // 여기에는 도달할 수 없다. 
}


int main() {
	int cases; cin >> cases;
	while (cases--) {
		memset(cache, -1, sizeof(cache)); 
		memset(overlap, -1, sizeof(overlap));
		cin >> k;
		for (int i = 0; i < k; i++) cin >> words[i]; 

		// 한 문자가 다른 문자에 완전히 겹치는 경우를 제외한다.
		while (true) {
			bool removed = false; 
			for (int i = 0; i < k && !removed; i++) 
				for (int j = 0; j < k; j++)
					// words[j]가 words[i]에 소속되는 경우
					if (i != j && words[i].find(words[j]) != -1) {
						words[j] = words[k - 1]; // 탐색 범위 밖으로 보내버린다. 
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