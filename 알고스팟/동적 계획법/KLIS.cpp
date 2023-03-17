#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int S[501]; // 주어지는 정수
int cacheLen[501], cacheCnt[501];

const int MAX = 2000000000 + 1;

// S[start]로 시작하여 만든 부분수열의 길이를 반환
int lis(int start) {
	int& ret = cacheLen[start + 1];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++)
		if (start == -1 || S[next] > S[start])
			ret = max(ret, lis(next) + 1);
	return ret;
}

// 최적해의 개수를 구한다.
int count(int start) {
	if (lis(start) == 1) return 1;  // LIS의 길이가 1인 경우 

	int& ret = cacheCnt[start + 1]; 
	if (ret != -1) return ret; 

	ret = 0;
	for (int next = start + 1; next < n; next++) {
		if ((start == -1 || S[next] > S[start])
			&& lis(start) == lis(next) + 1)
			ret = min<long long>(MAX, (long long)ret + count(next)); 
	}
	return ret; 
}

void reconstruct(int start,  int skip, vector<int>& seq) {
	// S[start]는 항상 lis에 포함된다. 
	if(start != -1) seq.push_back(S[start]);
	
	// S[start] 뒤에 있는 것들 중 추가될 만한 것을 탐색하여 넣는다. 
	// 숫자와 숫자의 위치를 묶어서 저장한다.
	vector<pair<int, int>> followers; 
	for (int next = start + 1; next < n; next++)
		if ((start == -1 || S[next] > S[start])
			&& lis(start) == lis(next) + 1)
			followers.push_back(make_pair(S[next], next));
	sort(followers.begin(), followers.end());

	// K번째 LIS의 다음 숫자를 찾는다. 
	for (int i = 0; i < followers.size(); i++) {
		int idx = followers[i].second;
		int cnt = count(idx);
		if (cnt <= skip)
			skip -= cnt; 
		else {
			reconstruct(idx, skip, seq); 
			break;
		}
	}
}


int main() {
	int cases; cin >> cases;
	while (cases--) {
		memset(cacheLen, -1, sizeof(cacheLen));
		memset(cacheCnt, -1, sizeof(cacheCnt));
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> S[i];
		cout << lis(-1) - 1 << endl; 

		vector<int> seq; 
		reconstruct(-1, k - 1, seq);
		for (int i = 0; i < seq.size(); i++)
			cout << seq[i] << " "; 
		cout << endl;
	}
	return 0; 
}