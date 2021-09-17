#include <iostream>
using namespace std;

int number_of_digits(int n) // �ڸ��� ��� �Լ�
{
	int count = 0;
	if (n == 0)
	{
		return 0;
	}
	while (n != 0)
	{
		count++;
		n /= 10;
	} return count;
}

bool isHan(int a) {
	int size = number_of_digits(a); // ������ �ڸ��� ���
	if (size == 1 || size == 2)
		return true;

	// �� �ڸ� �� �̻��� ��� 
	int* arr = new int[size]; // ������ �ڸ�����ŭ �����Ҵ�
	for (int i = 0; i < size; i++) // ���� �˻�
	{
		int num = a % 10; // ����� ���ڸ� ���� ����
		arr[i] = num;
		a /= 10;
	}

	int gap = arr[0] - arr[1]; // ���� ���
	for (int i = 1; i < size; i++) {
		if (arr[i] - arr[i + 1] != gap) {
			return false;
		}
		if (i == size - 2) {
			return true;
		}
	}

} //�Ѽ����� �Ǵ��ϴ� �Լ�

int main()
{
	int n;
	cin >> n;
	int result = 0; // n���� �۰ų� ���� �Ѽ��� ����
	for (int i = 1; i <= n; i++) {
		if (isHan(i)) {
			result++;
		}
	}
	cout << result << endl;

	return 0;
}