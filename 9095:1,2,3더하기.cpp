#include <iostream>
using namespace std;

int facto(int a)
{
	int result = 0;
	for (int i = 1; i <= a; i++)
	{
		result *= i;
	}

	return result;
}

int find_permut(int a, int b)
{
	return facto(a + b) / (facto(a) * facto(b));
}


int main()
{
	int T; cin >> T;
	for (int i = 0; i < T;i++)
	{
		int count = 0;
		int n; cin >> n;
		int temp = n;
		// 1로만 이루어짐
		count += 1;

		int index = 0;
		//1과 2로만 이루어짐

		while (temp != n % 2)
		{
			temp -= 2; //남아있는 1의 개수
			index++; // 생성된 2의 개수
			count += find_permut(temp, index);
		}

		temp = n;//다시 초기화
		index = 0;
		//1과 3으로만 이루어짐
		while (temp != n % 3)
		{
			temp -= 3; //남아있는 1의 개수
			index++; // 생성된 3의 개수
			count += find_permut(temp, index);
		}

		temp = n;
		index = 0;

		//1과 2와 3으로 이루어짐
		if (n >= 6)
		{
			temp -= 5; // 2,3 하나씩 있고 남아있는 1의 개수
			count += facto(temp + inde)
		}
		for (int i = 1; i < n;i++) //n은 6이상
		{


		}
	}
}

