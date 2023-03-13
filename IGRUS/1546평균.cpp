#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	float* score_now = new float[N]; //float형식이 아닌 int 형식으로 하면 score_now의 값을 바꾸는 과정에서 버그가 생긴다. 
	for (int i = 0; i < N; i++)
	{
		cin >> score_now[i];
	}

	float max = score_now[0];
	for (int i = 0; i < N;i++)
	{
		if (max < score_now[i])
		{
			max = score_now[i];
		}
	}
	
	float sum = 0;
	for (int i = 0; i < N;i++)
	{
		score_now[i] = (score_now[i] / max) * 100;
		sum += score_now[i];
	}
	float average = sum / N;
	cout << average << endl;

	return 0;

}
