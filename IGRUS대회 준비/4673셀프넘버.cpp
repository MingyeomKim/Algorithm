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
//시간 초과 에러가 뜬 기존 코드
#include <iostream>
#include <cmath>
using namespace std;

int number_of_constructor(int a);

int main()
{
   for (int i = 0; i < 10000; i++)
   {
      if (number_of_constructor(i) == 0)
      {
         cout << i << endl;
      }
   }

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
//ctime 헤더파일로 프로그램 실행 시간을 측정해보니 17초가 나왔다. 
비효율적인 함수를 사용해 10000번 for문을 돌렸기 때문에 연산 시간이 길어져 시간초과 에러가 뜬 것 같다.

//수정한 코드
#include <iostream>
#include <cmath>
#define SIZE 10001
using namespace std;

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
    
    return 0;
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

/*
int sum(int a)
{
   int temp = a;
   int number = 0; //자릿수
   while (temp != 0)
   {
      temp /= 10;
      number++;
   }

   int sum = a;
   for (int i = 1; i < number; i++)
   {
      sum += a / pow(10, i);
   }
   sum += a % 10;

   return sum;

}
//처음 sum 함수를 만들때 이 로직을 사용하였는데, sum += a/pow(10,i) 부분에서 세자리 수 이상을 넣을 때(ex 535) i = 1인 처음 for문에서 sum값에 53이 더해지게 되어 오류가 생긴다. 따라서 나머지를 더해주는 방식으로 sum 함수를 고쳤다. 

*/
