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

/*
#include <iostream>
using namespace std;
#include <ctime>
#include <cmath>

int number_of_constructor(int a);

int main()
{
	time_t start = time(NULL);
	for (int i = 0; i < 10001; i++)
	{
		if (number_of_constructor(1) == 0)
		{
			cout << i << endl;
		}
	}
	time_t end = time(NULL);
	double result = (double)(end - start); 

	cout << result << endl; //17s

	return 0;
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

*/
//처음 작성했던 코드. 비효율적인 함수를 써서 연산 시간이 17초가 나왔다. 
