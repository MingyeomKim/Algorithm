#include <iostream>
#include <vector>
#define MAX 100000
using namespace std;

int main() {
	int n; // ������ ����
	int s; // �ּ� ����
	cin >> n >> s;
	int arr[MAX]; // ������ ���� �迭
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int count = 0;
	int sum = 0; // ���� ������ ������ ���� ��
	int end = 0;
	int min = 0; // �ּڰ��� ������ ����

	for (int start = 0; start < n; start++) {
		while (sum < s && end < n) { // ���� �κ����� s���� �۰�, ������ ������ �������� �ʾ�����
			sum += arr[end];
			end++;
		}
		if (sum >= s) { // �κ����� s �̻��� ���
			if (start == 0)
				min = end - start;
			else {
				if (end - start < min)
					min = end - start;
			}
		}
		sum -= arr[start]; // ���� ��ġ�� Ž���ϱ� ���� �κ��տ��� ���� ��ġ�� ���� ���ش�.
	}
	
	cout << min << endl;
	return 0; 
}