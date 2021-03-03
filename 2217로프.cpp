#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int list[100000]; //로프의 정보를 담을 배열
	int k; // 로프의 개수
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> list[i];
	}
	sort(list, list + k); // 정렬
	int* compare = new int[k]; //메모리 크기가 k인 compare 배열 동적할당
	int temp = k; // temp = 3
	for (int i = 0; i < temp; i++) // 3번 반복
	{
		compare[k - 1] = list[i] * k; 
		//compare[2] = list[0] * 3 = 50 * 3 = 150
		//compare[1] = list[1] * 2 = 90 * 2 = 180
		//compare[0] = list[2] * 1 = 100 * 1 = 100
		k--;
	}
	cout << *max_element(compare, compare + temp) << endl;

	return 0;
}
