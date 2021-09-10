#include <iostream>
using namespace std;

void swap(int*, int* b);

int main()
{
	int N;
	cin >> N;
	int* a = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	//오름차순 정렬
	int min;
	int index;
	for (int i = 0; i < N;i++)
	{
		min = a[i];
		for (int j = i; j < N;j++)
		{
			if (a[j] < min)
			{
				min = a[j];
				index = j;
				swap(&a[index], &a[i]);
			}
		}

	}

	for (int i = 0; i < N;i++)
	{
		cout << a[i] << endl;
	}


}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
