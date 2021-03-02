#include <iostream>
using namespace std;


/*
* list에 바이너리 문자열을 넣는다. 
* 
* 0과 1중 무엇을 뒤집는 게 더 나은가?
* 연속된 숫자가 더 많은 것
* ex) 100111101001010 //5
* 숫자는 1이 더 많지만 연속된 숫자는 0이 더 많기 때문에 1을 0으로 바꿔주는 것이 더 낫다. 
* 
* // 연속된 숫자 개수를 세기
* if(처음 숫자 = 1)
*	cnt1 = 1
*	cnt0 = 0
* else if(처음 숫자 = 0)
*	cnt0 = 1
*	cnt1 = 0
* 
* for(i는 0에서 list의 마지막 index까지)
*	list[i]와 list[i+1]이 같으면
*		변화 없음
*	list[i]와 list[i+1]이 다르면
*		if(list[i+1] == 0) // 1에서 0으로 넘어간거
*			cnt0 += 1
*		else if(list[i+1] ==1) // 0에서 1로 넘어간거
*			cnt1 += 1
*	
* cnt1 > cnt0이면
*	cnt0 출력
* cnt < cnt1이면
*	cnt1 출력
*/
001100101001

int main()
{
	int cnt1 = 0, cnt0 = 0;
	char s[1000000];
	cin >> s;
	if (s[0] == '1')
		cnt1++;
	else
		cnt0++;

	int i = 0;
	while (s[i + 1] != NULL)
	{
		if (s[i] == s[i + 1])
		{
			i++;
			continue;
		}
		else
		{
			if (s[i + 1] == '0')
				cnt0++;
			else
				cnt1++;
		}
		i++;
	}

	if (cnt1 >= cnt0)
		cout << cnt0 << endl;
	else
		cout << cnt1 << endl;

	return 0;
}
