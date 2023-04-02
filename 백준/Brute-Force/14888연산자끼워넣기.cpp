#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
#define PLUS 0
#define MINUS 1
#define MULTI 2
#define DIVDE 3

const int INF = 1000000001; 

// ���� ������ ���տ��� ������ �����Ͽ� �ᱣ���� ��ȯ�ϴ� �Լ�
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

	// ��ȣ�� ���� ����
	vector<int> sign; 
	for (int i = 0; i < 4; i++) {
		int remain; cin >> remain; 
		while (remain--)
			sign.push_back(i); 
	} // sign : 0 0 1 2 3
	
	vector<int> candidates; 
	do {
		int temp = calc(number, sign);
		candidates.push_back(temp); 
	} while (next_permutation(sign.begin(), sign.end())); 
	auto ret = minmax_element(candidates.begin(), candidates.end());
	cout << *ret.second << endl; // �ִ�
	cout << *ret.first << endl; // �ּڰ�

	return 0; 
}