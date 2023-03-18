#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, p, l;
const int MAX = 1000000000 + 1; // p의 최댓값 + 1

int length[51]; // n세대 드래곤 커브 문자열의 총 길이

void precalc() {
	length[0] = 1; 
	for (int i = 1; i <= 50; i++)
		length[i] = min(MAX, length[i - 1] * 2 + 2) ; 
}

const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y"; 

char expand(const string& seed, int generations, int skip) {
	if (generations == 0) {
		if (skip > seed.size()) exit(-1);
		return seed[skip];
	}
	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X' || seed[i] == 'Y') {
			// 현재 세대의 총 길이보다 skip이 더 크다면
			// 한 세대만큼 건너뛰고 탐색한다.
			if (skip >= length[generations])
				skip -= length[generations];
			else if (seed[i] == 'X')
				return expand(EXPAND_X, generations - 1, skip);
			else
				return expand(EXPAND_Y, generations - 1, skip);
		}
		else if (skip > 0)
			--skip;
		else // F나 +, -가 오는 경우 그대로 출력한다.
			return seed[i];
	}
	return '#'; 
}

int main() {
	int cases; cin >> cases;
	precalc();
	while (cases--) {
		cin >> n >> p >> l;
		for (int i = 0; i < l; i++)
			cout << expand("FX", n, p + i - 1);
		cout << endl;
	}
	return 0; 
}