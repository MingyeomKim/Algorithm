#include <iostream>
#include <algorithm>
using namespace std;

/*
* max index를 쉽게 반환할 수 있는 vector를 사용한다
* 
* a = max(list) // 물이 새는 곳 중에 가장 멀리 있는 곳
* for(int i = 0; i <= a; i++)
*	if(list[i] == true) //물이 새는 곳이라면
*		for(int j = i; j < i + (L - 1); j++) //테이프 길이 만큼 돌면서
*			if(list[j] == true)
*				list[j] = false;
*		count++; //테이프 길이만큼 겹치는 부분까지 전부 하나의 테이프로 붙임
*
*/

int main()
{
	bool list[1010] = { false };
	// vector <bool> list = { false };//물이 새는지 여부를 담을 파이프 vector
	int count = 0;
	int L, N;
	cin >> N >> L; //물이 새는 곳의 개수와 테이프의 길이 입력
	int a; int last_index; // 물이 새는 곳의 인덱스와 마지막 물이 새는 곳의 인덱스를 담을 변수 선언
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		list[a] = true; // 물이 새는 곳을 인덱스로 true로 변환해준다. 
		// last_index = a;
	}
	//마지막으로 true인 인덱스를 last_index변수에 담는다. 
	int temp = 0;
	int i = 0;
	while (temp != N)
	{
		if (list[i] == true)
		{
			temp++;
			last_index = i;
		}
		i++;
	}
	//처음부터 물이 새는 곳이 끝나는 곳까지 for문
	for (int i = 1;i <= last_index; i++)
	{
		if (list[i] == true) //물이 새는 부분일 때
		{	//물이 새는 부분에서 테이프의 길이만큼의 영역까지 탐색
			list[i] = false;
			for (int j = i + 1; j <= i + (L - 1); j++)
			{
				if (list[j] == true) // 물이 새는 부분이면
				{
					list[j] = false; // 테이프로 붙인 상황이므로 false로 변환
				}
			}
			count++; // 테이프 길이만큼 겹치는 부분까지 전부 하나의 테이프로 붙임
		}
	}
	cout << count << endl;
	return 0;
}
