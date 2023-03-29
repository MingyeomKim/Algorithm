#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int k;

// input�� �ε�ȣ ���ǰ� ��ġ�ϴ� �������� �˻�
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

	vector<int> big(k + 1); // �ִ� ã�� �迭
	vector<int> small(k + 1); // �ּڰ� ã�� �迭

	for (int i = 0; i <= k; i++) {
		big[i] = 9 - i; 
		small[i] = i; 
	}

	// �ִ� ã��
	do {
		if (check(big, input))
			break; 
	} while (prev_permutation(big.begin(), big.end()));
	
	// �ּڰ� ã�� 
	// next_permutation : ���ڿ� ������ vector�� ���� ��� ������ ������ش�. 
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