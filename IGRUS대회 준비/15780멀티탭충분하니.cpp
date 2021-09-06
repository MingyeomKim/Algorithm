#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N; //사람의 수
	int K; cin >> K; //멀티탭의 수 
	int* multitab = new int[K];
	for (int i = 0;i < K;i++)
	{
		cin >> multitab[i];
	}
	int sum = 0;
	for (int i = 0; i < K; i++)
	{
		switch (multitab[i])
		{
		case 3:
		case 4:
			sum += 2;
			break;
		case 5:
		case 6:
			sum += 3;
			break;
		case 7:
		case 8:
			sum += 4;
			break;
		}
	}

	if (sum >= N)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}

	return 0;
} 
