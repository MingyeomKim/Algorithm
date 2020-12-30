#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n; //지불할 돈
	int a = 1000 - n; //거스름 돈
	int count = 0; //동전의 개수
	//500 100 50 10 5 1
	while(1)
	{
		if (a >= 500)
		{
			a -= 500;
			count++; //500원 동전 하나 추가
		}
		else if (a < 500 && a >=100)
		{
			a -= 100;
			count++; // 100원 동전 하나 추가
		}
		else if (a < 100 && a >= 50)
		{
			a -= 50;
			count++; // 50원 추가
		}
		else if (a < 50 && a >= 10)
		{
			a -= 10;
			count++;
		}
		else if (a < 10 && a >5)
		{
			a -= 5;
			count++;
		}
		else if (a < 5 && a >= 1)
		{
			a -= 1;
			count++;
		}
		else if( a== 0)
		{
			break;
		}
	}
	cout << count << endl;

	return 0;
}
