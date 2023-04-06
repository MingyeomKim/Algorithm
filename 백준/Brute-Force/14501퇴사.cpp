#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int n; // ����� �� �ִ� ��¥ ��

int cache[16]; 
vector<int> T, P;

// day���� �Ǿ���. day�Ͽ� �ִ� ����� ���� ���� �����Ѵ�. 
// ���ݱ��� ���� ������ sum�̴�.
int calc(int day) {
	if (day == n + 1) return 0;
	if (day > n + 1) return -INF;

	int& ret = cache[day];
	if (ret != -1) return ret;

	int t1 = calc(day + 1); 
	int t2 = P[day] + calc(day + T[day]);
	ret = max(ret, max(t1, t2)); 

	return ret; 
}

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	
	memset(cache, -1, sizeof(cache)); 
	cin >> n;
	T.push_back(0); P.push_back(0);
	for (int i = 1; i <= n; i++) {
		int num1, num2; cin >> num1 >> num2;
		T.push_back(num1); P.push_back(num2);
	}
	cout << calc(1) << endl;
	return 0;
}