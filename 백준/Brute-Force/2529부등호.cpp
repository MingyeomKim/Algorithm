#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int k;

// input의 부등호 조건과 일치하는 순열인지 검사
bool check(const vector<int> perm, vector<char> input) {
	for (int i = 0; i < k; i++){
		if (input[i] == '<' && perm[i] > perm[i + 1])
			return false;
		if (input[i] == '>' && perm[i] < perm[i + 1])
			return false; 
	}
	return true; 
}

int main() {
	cin >> k;
	vector<char> input(k);
	for (int i = 0; i < k; i++) cin >> input[i];

	vector<int> big(k + 1); // 최댓값 찾는 배열
	vector<int> small(k + 1); // 최솟값 찾는 배열

	for (int i = 0; i <= k; i++) {
		big[i] = 9 - i; 
		small[i] = i; 
	}

	// 최댓값 찾기
	do {
		if (check(big, input))
			break; 
	} while (prev_permutation(big.begin(), big.end()));
	
	// 최솟값 찾기 
	// next_permutation : 인자에 나오는 vector에 속한 모든 순열을 만들어준다. 
	do {
		if (check(small, input))
			break;
	} while (next_permutation(small.begin(), small.end()));

	for (int i = 0; i < k + 1; i++) cout << big[i]; 
	cout << endl;
	for (int i = 0; i < k + 1; i++) cout << small[i]; 
	cout << endl;

	return 0;
}