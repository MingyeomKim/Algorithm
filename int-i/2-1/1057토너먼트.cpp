#include <iostream>
using namespace std;

int main() {
	int n;  cin >> n; // 전체 참여자 수
	int p, q; cin >> p >> q;  // 지민과 한수의 번호
	int cnt = 0;
	while (true) {
		cnt++;
		p = p - p / 2;
		q = q - q / 2;
		if (p == q)
			break;
	}
	cout << cnt << endl;
	
	return 0;
}