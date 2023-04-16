#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int dist[10000];  // ���� n�� �湮�ߴ� �� ����

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}

// here�� index �ڸ��� ��ȭ��Ű�� �Ҽ��� �͸��� vector�� �����Ͽ� ��ȯ
vector<int> nextPrime(int index, int here) {
	vector<int> ret;
	string number = to_string(here);
	// ���� ���ڸ���� 0�� ���� �ȵȴ�.
	if (index == 0) {
		for (int i = 1; i <= 9; i++) {
			number[0] = i + '0';
			int cand = stoi(number);
			if (isPrime(cand))
				ret.push_back(cand);
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			number[index] = i + '0';
			int cand = stoi(number);
			if (isPrime(cand))
				ret.push_back(cand);
		}
	}
	return ret;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int start, end;
		cin >> start >> end;

		memset(dist, -1, sizeof(dist));
		queue<int> q;
		q.push(start);
		dist[start] = 0;

		while (!q.empty()) {
			int here = q.front(); q.pop();
			for (int index = 0; index < 4; index++) {
				// index �ڸ����� �����Ͽ� �Ҽ��� ���ڵ��� ���Ѵ�.
				vector<int> there = nextPrime(index, here);

				for (int next = 0; next < (int)there.size(); next++)
					if (dist[there[next]] == -1) {
						q.push(there[next]);
						dist[there[next]] = dist[here] + 1;
					}
			}
		}

		cout << dist[end] << endl;
	}
}