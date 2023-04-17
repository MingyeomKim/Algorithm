#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int n;

struct Meeting {
	int begin, end; 
};

bool cmp(const Meeting& a, const Meeting& b) {
	if (a.end == b.end) return a.begin < b.begin;
	else return a.end < b.end;
}

int main() {
	cin >> n;
	vector<Meeting> timeTable(n);
	for (int i = 0; i < n; i++) 
		cin >> timeTable[i].begin >> timeTable[i].end; 

	// 빨리 끝나는 순서대로 정렬
	sort(timeTable.begin(), timeTable.end(), cmp);

	int now = 0; // 회의가 끝난 시간
	int ret = 0; 
	for (int i = 0; i < timeTable.size(); i++) {
		if (now <= timeTable[i].begin) { // 회의가 끝난 시간이 다음 회의의 시작시간보다 앞선다면
			now = timeTable[i].end;
			ret++; 
		}
	}
	cout << ret << endl;
	return 0; 
}