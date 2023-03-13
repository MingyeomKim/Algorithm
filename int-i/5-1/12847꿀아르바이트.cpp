#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001

int main() {
	int n; cin >> n; // ���� ������� ���� �� ��	
	int m; cin >> m; // �ִ� ���� �� �ִ� �� ��
	long long arr[MAX] = {0,}; // �ϱ�
	for (int i = 1; i < n + 1 ; i++) { // 1���� n�ϱ����� �ϱ� ����
		cin >> arr[i]; 
		arr[i] = arr[i - 1] + arr[i]; // �ش� �ε��������� ������ ���� ����Ѵ�. 
	}

	// 5 3 
	// 10 20 30 20 10

	// arr : 10 30 60 80 90

	long long max = 0;  // �κ���

	// �κ����� �ִ밡 �Ǵ� ��� 
	for (int i = 0; i < n - m + 1; i++) {
		long long sum = arr[i + m] - arr[i]; 
		if (sum > max)
			max = sum;
	}
	cout << max << endl;

	return 0;
}