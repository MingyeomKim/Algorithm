#include <iostream>
using namespace std;

int main() {
	int n;  cin >> n; // ��ü ������ ��
	int p, q; cin >> p >> q;  // ���ΰ� �Ѽ��� ��ȣ
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