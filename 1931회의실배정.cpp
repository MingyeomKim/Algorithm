/*
#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N; //회의 개수
	int* start = new int[N];
	int* end = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> start[i] >> end[i];
	}
	//회의의 최대 개수
	int count = 0;
	for (int i = 0;i < N;i++)
	{

	}
}
// 따로 배열을 만들려다가 swap할 때 start배열과 end배열의 인덱스가 맞지 않을 경우를 대비해 3*N 배열을 만듦

*/


/*

#include <iostream>
#include <string.h>
using namespace std;

//이른 시간순서대로 정렬 -> 가장 시간 간격이 짧은 회의를 택함
//해당 회의가 끝나는 시간보다 더 늦게 시작하는 회의를 찾아서 이른 순서대로 정렬
// 시간간격이 짧은 회의를 택함 while문(반복)
// 마지막 회의가 끝나고 끝난 시간보다 더 늦게 시작하는 회의가 없으면 break


int find_min(int** info, int start, int end, int index);
void sort(int** info, int size, int index);


int main()
{
	int N; cin >> N;
	int** info = new int* [N];
	for (int i = 0; i < N;i++)
	{
		info[i] = new int[3];
		memset(info[i], 0, sizeof(int) * 3);
	} //3 * N배열 생성

	for (int i = 0;i < N;i++)
	{
		cin >> info[0][i] >> info[1][i];
		//start와 end 시간을 입력
		info[2][i] = info[1][i] - info[0][i];
		//시간간격을 3번째 인덱스에 입력
	}

	int i = 0;
	int min_start = 0;
	int result = 0;
	int end_time = 0;
	int index = -1;

	sort(info, N, 0);

	while (1)
	{
		for (int i = 0; i < N ; i++)
		{
			for(int j = i+1;j < N; j++)
			{
				if (info[2][i] == find_min(info, index + 1,N,2))
				{
					index = i;
					result++;
					end_time = info[1][i];
					break;
				}
			}
		}

		if (end_time > info[0][N-1])
		{
			break;
		}
	}
	cout << result << endl;

	/*
	while (1)
	{
		for (int i = 0;i < N;i++)
		{
			if (info[i][2] == find_min(info, 0, N, 2))
			{
				index = i;
				result++;
				end_time = info[i][1];
				break;
			}
		}

		for (int i = index + 1; i < N; i++)
		{
			if (info[i][2] == find_min(info, index + 1, N, 2))
			{
				index = i;
				result++;
				end_time = info[i][1];
				
			}
			if (end_time <= info[i][0])
			{
				if()
			}
		}
	}
	*/

	//메모리 해제
	for (int i = 0; i < N;i++)
	{
		delete[] info[i];
	}
	delete [] info;

	

	/*
	int N; cin >> N; //회의 개수
	int* start = new int[N];
	int* end = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> start[i] >> end[i];
	}
	//회의의 최대 개수
	int count = 0;

	int* interval = new int[N];
	for (int i = 0; i < N;i++)
	{
		interval[i] = end[i] - start[i];
	}

	int start_min = start[0];
	for (int i = 0; i < N;i++)
	{

	}


	for (int i = 0;i < N;i++)
	{

	}
	*/

}



void sort(int **info, int size, int index)
{
	int min;
	int min_index = 0;
	for (int i = 0; i < size;i++)
	{
		min = info[index][i];
		for (int j = i; j < size;j++)
		{
			if (min > info[index][j])
			{
				min = info[index][j];
				min_index = j;
			}
		}
		int temp = info[index][i];
		info[index][i] = info[index][min_index];
		info[index][min_index] = temp;
		// i번째와 j번째 수 swap하기
	}
	//index는 0,1,2 중에 하나. start와 end, interval를 기준으로 각각 info를 정렬한다. 
}



int find_min(int** info, int start, int end, int index)
{
	int min_index = 0;
	int min = info[index][start];
	for (int i = start; i < end;i++)
	{
		if (min > info[index][i])
		{
			min = info[index][i];
			min_index = i;
		}
	}

	return min;
}


*/ // 알고리즘 틀림. 반례가 있기 때문이다. (시간 간격이 더 길더라도 배정할 수 있는 회의가 있는데,
   // 시간 간격이 min이 아니라는 이유로 건너뛰어버리기 때문)

	
	


	
