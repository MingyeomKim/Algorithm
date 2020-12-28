#include <iostream>
#define SIZE 10001
using namespace std;

int number_of_constructor(int a);
int sum(int a);

int main()
{
	bool N[SIZE] = { 0 };

	for (int i = 0; i < SIZE; i++)
	{
		if (sum(i) < SIZE)
		{
			N[sum(i)] = 1;
		}
	}

	//출력
	for (int i = 0; i < SIZE; i++)
	{
		if (N[i] == 0)
		{
			cout << i << endl;
		}
	} 
}

int sum(int a)
{
	int sum = a;
	while (1)
	{
		if (a == 0)
			break;
		sum += a % 10;
		a = a / 10;
	}

	return sum;

}

int number_of_constructor(int a)
{
	int temp = a;
	//자릿수 구하기
	int number = 0;
	while (temp != 0)
	{
		temp /= 10;
		number += 1;
	}

	//a의 생성자 개수 구하기
	int count = 0;
	for (int i = 0; i < a;i++)
	{
		int sum = 0;
		sum += i;
		for (int j = 1; j < number + 1;j++)
		{
			sum += i / pow(10, j);
		}
		sum += i % 10;
		if (sum == a)
		{
			count++;
		}
	}

	return count;
}


