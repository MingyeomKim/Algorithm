#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char lefts[11];
char rights[11];

bool check[11]; // i번째 자리의 수 포함 앞에 있는 수들이 모두 같은지 체크

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int l, r;
	cin >> l >> r;

	string sl = to_string(l);
	string sr = to_string(r);

	memset(lefts, '0', sizeof(lefts));
	memset(rights, '0', sizeof(rights));

	for (int i = 10 - sl.size(); i <= 9; i++) {
		int index = i - (10 - sl.size());
		lefts[i] = sl[index];
	}
	for (int i = 10 - sr.size(); i <= 9; i++) {
		int index = i - (10 - sr.size());
		rights[i] = sr[index];
	}

	for (int i = 0; i <= 9; i++) {
		if (lefts[i] == rights[i]) {
			check[i] = true;
		}
		else {
			break;
		}
	}

	// 8의 개수 찾기
	int ret = 0;
	for (int i = 0; i <= 9; i++) {
		if (check[i] && lefts[i] == '8' && rights[i] == '8') {
			ret++;
		}
	}

	cout << ret << endl;
	return 0;
}