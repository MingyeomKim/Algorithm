#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N; cin >> N; 
	vector<pair<int,int>> A(N); 
	for (int i = 0; i < N; i++) {
		cin >> A[i].first; 
		A[i].second = i; // 정렬 전 위치 저장
	}
	sort(A.begin(), A.end()); 

	int ret = 0; 
	for (int i = 0; i < N; i++) {
		int cand = A[i].second - i; 
		if (cand > ret) ret = cand; 
	}
	cout << ret + 1<< endl;
	return 0; 
}