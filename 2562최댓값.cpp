#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int a[9];
	for (int i = 0; i < 9;i++)
	{
		cin >> a[i];
		if (a[i] <= 0)
		{
			exit(1);
		}
		for (int j = 0; j < i; j++)
		{
			if (a[i] == a[j])
			{
				exit(1);
			}
		}
	}
	int max = a[0];
	int index = 1; //a[0]가 가장 큰 값인 경우를 따지지 않아서 계속 틀림..
	for (int i = 0;i < 9;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			index = i + 1;
		}
		else
		{
			continue;
		}
	}
	cout << max << endl;
	cout << index << endl;

	return 0;
}
