#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
#define PLUS 0
#define MINUS 1
#define MULTI 2
#define DIVDE 3

const int INF = 1000000001; 

// 현재 연산자 조합에서 연산을 수행하여 결괏값을 반환하는 함수
int calc(vector<int> number, vector<int> sign) {
	int cand = number[0];
	int m = sign.size(); 

	for (int i = 0; i < m; i++) {
		if (sign[i] == PLUS)
			cand += number[i + 1]; 
		if (sign[i] == MINUS)
			cand -= number[i + 1]; 
		if (sign[i] == MULTI)
			cand *= number[i + 1]; 
		if (sign[i] == DIVDE)
			cand /= number[i + 1]; 
	}

	return cand; 
}

int main() {
	int n; cin >> n;
	vector<int> number(n);
	for (int i = 0; i < n; i++) cin >> number[i]; 

	// 부호의 순열 생성
	vector<int> sign; 
	for (int i = 0; i < 4; i++) {
		int remain; cin >> remain; 
		while (remain--)
			sign.push_back(i); 
	} // sign : 0 0 1 2 3
	
	// 최댓값
	int ret = -INF; 
	do {
		int cand = calc(number, sign); 
		if (ret < cand) ret = cand; 
	} while (next_permutation(sign.begin(), sign.end())); 
	cout << ret << endl;

	sort(sign.begin(), sign.end()); 

	// 최솟값
	ret = INF;
	do {
		int cand = calc(number, sign);
		if (ret > cand) ret = cand; 
	} while (next_permutation(sign.begin(), sign.end())); 
	cout << ret << endl;

	return 0; 
}