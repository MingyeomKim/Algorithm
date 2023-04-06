#include <iostream>
using namespace std; 

int n; 
int S[21];
bool exists[20 * 100000 + 10];  // 부분수열을 비트마스크로 저장, 부분수열의 합이 sum인 부분수열이 있으면 true 

// 모든 부분수열을 확인하고 exists에 표시한다.
void solve() {
	// 모든 상태를 확인
	for (int i = 1; i < (1 << n); i++) { 
		int sum = 0; 
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) // 현재 탐색하고 있는 부분수열에 j번째 원소가 속해있다면
				sum += S[j]; 
		}
		exists[sum] = true; 
	}
	
	for (int i = 1;; i++)
		if (exists[i] == false) {
			cout << i << endl;
			break;
		}
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++)
		cin >> S[i]; 
	solve(); 
}