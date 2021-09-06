#include <iostream>
#include <algorithm>
using namespace std;

/*
* i는 인덱스, Pi는 해당 인덱스의 value이다
* ! 사실상 '누구' 즉 인덱스는 상관이 없다
* 정렬해서
* 새 배열 만들어서
* 맨 처음 인덱스는 그대로
* 두번째는 처음 + 두번째
* 세번쟤는 처음 + 두번째 + 세번째
*/

int main()
{
	int N; cin >> N; //사람 수를 담을 배열
	int list[1000] = { NULL };
	for (int i = 0; i < N; i++)
	{
		cin >> list[i];
	} // list[1000] = { 3, 1, 4, 3, 2, NULL, NULL, .. , NULL }

	sort(list, list + N);
	// list[1000] = { 1, 2, 3, 3, 4, NULL, ... , NULL }

	int answer[1000] = { 0, };
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			answer[i] += list[j];
		}
	}
	//answer[1000] = { 1, 3, 6, 9, 13, 0, ... 0 }

	// 합계 구하기
	int sum = 0;
	for (int i = 0; i < N;i++)
	{
		sum += answer[i];
	}
	cout << sum << endl;
	return 0;

}
