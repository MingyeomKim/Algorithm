#include <iostream>
#include <algorithm>
using namespace std;


long long k;

// ���̸� �־��� �� ���� �� �ִ� ������ ���� 
int Count(long long *arr, long long length) {
	int cnt = 0;
	for (int i = 0;i < k; i++) {
		cnt += arr[i] / length;
	}
	return cnt;
}

int main()
{
	cin >> k; // �����̰� ������ �ִ� ����
	long long n; cin >> n;  // ���� ������ ���� 
	long long* arr;
	arr = new long long[k]; // �����̰� ������ �ִ� ������ ���̸� ���� �迭 
	for (int i = 0;i < k; i++) {
		cin >> arr[i];
	}

	// ����
	sort(arr, arr + k);

	// ó������ ���� ���������� �迭 ����
	long long size = arr[k - 1];
	long long ans[1000001];
	for (int i = 0; i < size; i++) {
		ans[i] = (long long)i + 1;
	}
	
	// �̺� Ž��
	long long left = 1;
	long long right = size;
	long long middle;

	do {
		middle = (left + right) / 2;
		if (Count(arr, middle) < n) // �ʿ��� ������ ������ ������
		{
			right = middle - 1;
		}
		else { // Count(middle)�� 11���� ũ�ų� ���� ��� 
			left = middle + 1;
			// ���Ƶ� �׺��� ū ������ ������ ���� ���� �� �־
		}
	} while (left <= right);

	// ��� ���
	cout << right << endl;
	delete arr;
	return 0;
}