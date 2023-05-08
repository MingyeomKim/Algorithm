#include <iostream>
#include <vector>
using namespace std; 

long long n, m; 

// mid�б��� ���̱ⱸ�� ź ����� ��
pair<long long, long long> calc(long long mid, vector<int> time) {
	long long cnt = 0; 
	long long interval = 0;
	for (int i = 0; i < m; i++) {
		cnt += 1 + mid / time[i];
		if (mid % time[i] == 0) interval++; 
	}
	return make_pair(cnt, interval);
}

int main() {
	cin >> n >> m; 
	// ���� �ð�
	vector<int> time(m);
	long long left = 0;
	long long right = 0; 
	for (int i = 0; i < m; i++) {
		cin >> time[i];
		if (right < time[i]) right = n * time[i]; 
	}

	if (n <= m) {
		cout << n << endl;
		return 0; 
	}

	// n��° ���̰� ���̱ⱸ�� ź �������� ���̱ⱸ�� ź ������ ��
	long long ret = 0;
	long long minute = 0; 
	while (left <= right) {
		long long mid = (left + right) / 2; 

		auto cnt = calc(mid, time); 
		long long end = cnt.first; 
		long long interval = cnt.second; 
		long long  begin = end - interval + 1; 
		if (end < n)
			left = mid + 1;
		else if (begin > n)
			right = mid - 1; 
		else 
			for (int i = 0; i < m; i++)
				if (mid % time[i] == 0) {
					if (n == begin) {
						cout << i + 1 << endl;
						return 0;
					} begin++; 
				}
	}
	return 0; 
}
