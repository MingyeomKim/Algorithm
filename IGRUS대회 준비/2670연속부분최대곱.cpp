#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	int N; cin >> N;
	double answer = 0;
	double* array = new double[N];
	for (int i = 0; i < N;i++)
	{
		cin >> array[i];
	}

	// array[i]에서 i을 마지막 인덱스로 하는 연속곱 중 최댓값을 저장한다. 
	for (int i = 0; i < N; ++i)
	{
		if (array[i] * array[i - 1] >= array[i])
		{
			array[i] = array[i - 1] * array[i];
		}
		answer = max(answer, array[i]);
	}
	cout << fixed;
	cout << setprecision(3);
	cout << answer << endl;
	return 0;
}
