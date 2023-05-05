#include <iostream>
#include <vector>
using namespace std;

int n, m;

// �� ��緹�� ũ�⸦ size��� �� ��, m���� ��緹�̿� ��� ���Ǹ� �� ��� ���� ������ �� ��ȯ
bool check (const vector<int> courses, int size) {
	int sum = 0; // ��緹�̿� ��� ������ ��
	int cnt = 1;  // ��緹�� ����
	for (int i = 0; i < n; i++) {
		if (sum + courses[i] > size) {
			cnt++;
			sum = courses[i];
		}
		else
			sum += courses[i];
	}
	return cnt <= m; 
}

int main() {
	cin >> n >> m; 
	vector<int > course(n);
	int left = 0, right = 0; 
	for (int i = 0; i < n; i++) {
		cin >> course[i];
		if (course[i] > left) left = course[i]; 
		right += course[i]; 
	}
	int ret = 0; 
	while (left <= right) {
		long long mid = (left + right) / 2; 
		if (check(course, mid)) {
			ret = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ret << endl;
	return 0; 
}