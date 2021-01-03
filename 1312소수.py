/*#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a; double b; int N;
	cin >> a >> b >> N;
	double c = a / b;
	c = c * pow(10, N);
	cout << int(c) % 10 << endl;



	return 0;
}*/

/*
import sys
a,b,N = map(float,sys.stdin.readline().split())
c = (str)(a/b)
result = c.split('.')[1]
print(result[(int(N)-1):(int(N))])
*/

// 두 코드 다 백준에서 런타임 에러가 뜨는 것을 확인할 수 있다. 왜 안되냐면 나눗셈을 하는 과정에서 오차가 발생. 나눗셈 하는 과정 자체를 구현해줘야한다. 

/* 
import sys
a,b,N = map(int,sys.stdin.readline().split())
count = 0
if(int(a/b) == 0):
    count +=1

while(1):
    # while(int(a / b) != 0):
    #     a *= 10
    while(1):
        if(int(a / b) == 0):
            a *= 10
        else:
            break
    c = int(a / b)
    d = int(a - int(c * b)) #나머지
    a = d
    count+=1
    if(count == N + 1):
        print(c)
        break
    if(b == 0):
    	exit()

// 소수점 자릿수를 구하는 프로그램을 작성. 근데 왜 자꾸 틀렸다고 뜨냐 하 ㅋㅋ 
*/

// 나머지 연산자를 쓰면 안되는건가..?


/*
import sys
a,b,N = map(int, sys.stdin.readline().split(' '))
c = a / b
count = 0
while(1):
    c *= 10
    count+=1
    if(N == count):
        print(int(c % 10))
        break
*/ //런타임 에러가 뜬다. break가 작동되지 않는 케이스가 있다는 뜻인데.. 모르겠다.

/*
#include <iostream>
using namespace std;

int main()
{
	int a, b, N;
	cin >> a >> b >> N;
	int count = 0;
	int answer; //소수점 N번째자리의 수

	while (1)
	{
		int c = a / b;
		int d = a % b;
		
		while (d != 0)
		{
			while (1)
			{
				if (d / b == 0)
				{
					d *= 10;
				}
				else break;
			}
			answer = d / b;
			d = d - (answer * b);
			count++;
			if (count == N)
			{
				break;
			}
		}
		if (count == N)
		{
			break;
		}
	}

	cout << answer << endl;

	return 0;

	
}
이 코드는 n번째 자리 숫자를 직접 구하는 코드. 1 99 1을 입력했을 때 1이 나오는 반례를 찾을 수 있다. 
*/


def result():
    a,b,n = map(int, input().split(' '))
    a %= b
    for i in range(n -1):
        a = (a * 10) % b
    return ((a * 10) // b)

print(result())
#최종 제출하여 맞은 코드는 이것...

