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

	// ���� ������ ������� ����
	sort(timeTable.begin(), timeTable.end(), cmp);

	int now = 0; // ȸ�ǰ� ���� �ð�
	int ret = 0; 
	for (int i = 0; i < timeTable.size(); i++) {
		if (now <= timeTable[i].begin) { // ȸ�ǰ� ���� �ð��� ���� ȸ���� ���۽ð����� �ռ��ٸ�
			now = timeTable[i].end;
			ret++; 
		}
	}
	cout << ret << endl;
	return 0; 
}