/* #include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int* info = new int[N]; 
	for (int i = 0; i < N; i++) 
	{
		cin >> info[i];
	}
	int* line = new int[N] {0,};
	//line = {0};  // 오류 원인 1

	line[info[0]] = 1; 
	line[0] = N; //오류 원인 2
	int count = 0;
	for (int i = 1; i < N -1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (line[j] == 0)
			{
				count = 0; //오류 원인3
				count++;
				if (count == info[i])
				{
					line[j] = i + 1;
					break;
				}
			}
			
		}
	}

	for (int i = 0;i < N;i++)
	{
		cout << line[i] << " ";
	}
	return 0;
}

*/
#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N;
	int* info = new int[N]; //왼쪽에 큰 사람이 몇명이 있었는지 배열
	for (int i = 0; i < N; i++) //N명의 사람의 키
	{
		cin >> info[i];
	}
	int* line = new int[N] {0, };
	//line = {0}; 이렇게 초기화해주니 에러뜸

	line[info[0]] = 1; //info[0]+1을 인덱스로 넣음
	//line[0] = N; 
	int count = 0;
	for (int i = 1; i < N; i++)
	{
		count = 0; 
		for (int j = 0; j < N; j++)
		{
			if (line[j] == 0)
			{
				count++;
				if (count == info[i] + 1)
				{
					line[j] = i + 1;
					break;
				}
			}

		}
	}

	for (int i = 0;i < N;i++)
	{
		cout << line[i] << " ";
	}
	return 0;
}

