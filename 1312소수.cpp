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

// 소수점 자릿수를 구하는 프로그램을 작성. 근데 왜 자꾸 틀렸다고 뜨냐 하 ㅋㅋ 
*/
