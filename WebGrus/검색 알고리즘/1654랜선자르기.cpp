#include <iostream>
#include <algorithm>
using namespace std;

int* arr;
int k;

// ���̸� �־��� �� ���� �� �ִ� ������ ���� 
int Count(int length) {
	int cnt = 0;
	for (int i = 0;i < k; i++) {
		cnt += arr[i] / length;
	}
	return cnt;
}

int main()
{
	cin >> k; // �����̰� ������ �ִ� ����
	int n; cin >> n;  // ���� ������ ���� 

	arr = new int[k]; // �����̰� ������ �ִ� ������ ���̸� ���� �迭 
	for (int i = 0;i < k; i++) {
		cin >> arr[i];
	}

	// ����
	sort(arr, arr + k);

	// ó������ ���� ���������� �迭 ����
	int size = arr[k - 1];
	int* ans = new int[size];
	for (int i = 0; i < size; i++) {
		ans[i] = i + 1;
	}

	// �̺� Ž��
	int left = 0;
	int right = size - 1;
	int middle;

	do {
		middle = (left + right) / 2;
		if (Count(middle) < n) // �ʿ��� ������ ������ ������
		{
			right = middle - 1;
		}
		else { // Count(middle)�� 11���� ũ�ų� ���� ��� 
			left = middle + 1;
			// ���Ƶ� �׺��� ū ������ ������ ���� ���� �� �־
		}
	} while (left < right);

	// ��� ���
	cout << right - 1 << endl;

	return 0;
}