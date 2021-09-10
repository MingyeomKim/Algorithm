#include <iostream>
#include <algorithm>
using namespace std;


int n; // �־��� ������ ����
int IsNumber(int *arr, int num) {
	int left = 0; // arr 0��° �ε��� 
	int right = n - 1; // arr ������ �ε���
	int middle;
	// ���� �˻��� �̿��� search
	do {
		middle = (left + right) / 2;
		if (arr[middle] > num) {
			right = middle - 1;
		} // ã�� ���� �߰� ������ �� ���� ��
		else if (arr[middle] == num)
			return 1; // ��ġ�ϴ� ���� ã���� ��
		else { // ã�� ���� �߰� ������ �� Ŭ ��
			left = middle + 1;
		}
	} while (left <= right);
	return 0; 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n; 
	int* arr = new int[n]; // ���� �迭
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int m; cin >> m; // arr�迭 �ȿ��� Ž���� ������ ����
	int* findNum = new int[m];
	for (int i = 0; i < m; i++) {
		cin >> findNum[i];
		cout << IsNumber(arr, findNum[i]) << "\n";
	}

	return 0;
}