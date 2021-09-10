#include <iostream>
using namespace std;

int main()
{
	int N, M; cin >> N >> M;
	int count = 1;
	if (N == 1 || M ==1)
	{
	}
	else if (N == 2)
	{
		if (M == 3 || M == 4)count += 1;
		else if (M == 5 || M == 6) count += 2;
		else if (M >= 7) count += 3;
	}
	else //N이 3이상이면 N을 고려할 필요가 없다. 
	{
		if (M == 2) count += 1;
		else if (M == 3) count += 2;
		else if (M == 4 || M == 5 || M == 6) count += 3;
		else if(M >=7)// 4가지 방향 모두 다 쓸 수 있게 됨
			count += M - 3;
	}

	cout << count << endl;
	return 0;
}
// 마지막 else if문을 모두 else로 처리했어서 틀렸다. 
