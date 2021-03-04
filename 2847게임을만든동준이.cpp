#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int list[101] = { NULL };
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	}
	for (int i = N - 1; i > 0; i--)
	{
		while (true)
		{
			if (list[i] > list[i - 1]) 
				//높은 레벨의 점수가 더 크면
				break; // 넘어가고
			else //낮은 레벨의 점수가 더 크거나 같으면 
			{
				list[i - 1]--;
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
/*
* 어떻게 푸냐면
* 레벨 난이도를 담을 list[100]을 만든다
* int i =0;
* while(list[i+1] != NULL)
	if(list[i] > list[i+1])
		넘어가
	else
		count+=(list[i + 1] - list[i] + 1)
		list[i+1] = list[i] - 1;
	i++;
*cout << cnt << endl;
*/
/*
int main()
{
	int count = 0;
	int list[100] = { NULL };
	int N;
	cin >> N; //4 
	for (int i = 0; i < N;i++)
	{
		cin >> list[N - i - 1];
		//list[4 - 0 - 1] = list[3] = 5
		//list[4 - 1 - 1] = list[2] = 3
		//list[1] = 7
		//list[0] = 5
	}
	int i = 0;
	while (list[i + 1] != NULL)
	{
		if (list[i] <= list[i + 1])
		{
			count += (list[i + 1] - list[i] + 1);
			list[i + 1] = list[i] - 1;
		}
		i++;
	}

	cout << count << endl;

	return 0;
}
*/
