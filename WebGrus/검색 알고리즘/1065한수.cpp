#include <iostream>
using namespace std;

int number_of_digits(int n) // 자릿수 계산 함수
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
	int size = number_of_digits(a); // 정수의 자릿수 계산
	if (size == 1 || size == 2)
		return true;

	// 세 자리 수 이상인 경우 
	int* arr = new int[size]; // 정수의 자릿수만큼 동적할당
	for (int i = 0; i < size; i++) // 선형 검색
	{
		int num = a % 10; // 요소의 끝자리 수를 대입
		arr[i] = num;
		a /= 10;
	}

	int gap = arr[0] - arr[1]; // 공차 계산
	for (int i = 1; i < size; i++) {
		if (arr[i] - arr[i + 1] != gap) {
			return false;
		}
		if (i == size - 2) {
			return true;
		}
	}

} //한수인지 판단하는 함수

int main()
{
	int n;
	cin >> n;
	int result = 0; // n보다 작거나 같은 한수의 개수
	for (int i = 1; i <= n; i++) {
		if (isHan(i)) {
			result++;
		}
	}
	cout << result << endl;

	return 0;
}