#include <iostream>
using namespace std; 

int n; 
int S[21];
bool exists[20 * 100000 + 10];  // �κм����� ��Ʈ����ũ�� ����, �κм����� ���� sum�� �κм����� ������ true 

// ��� �κм����� Ȯ���ϰ� exists�� ǥ���Ѵ�.
void solve() {
	// ��� ���¸� Ȯ��
	for (int i = 1; i < (1 << n); i++) { 
		int sum = 0; 
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) // ���� Ž���ϰ� �ִ� �κм����� j��° ���Ұ� �����ִٸ�
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