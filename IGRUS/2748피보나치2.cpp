#include <cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n; cin >> n;
	if (n < 0)
		exit(1);

	long long* array = new long long[n + 1]; // 0 ~ n인덱스의 배열 생성(총 n+1개)
	array[0] = 0;
	array[1] = 1;
	for (int i = 2;i < n + 1;i++) //2 ~ n 인덱스에 값 할당
	{
		array[i] = array[i - 1] + array[i - 2]; // i = n일때 n-1 + n-2
	}

	
	printf("%lld", array[n]);

	return 0;
}

