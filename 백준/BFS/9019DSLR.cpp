#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std; 

bool check[10000]; 
int dist[10000]; // dist[i] : ���������� i���� ���� �Ÿ�
int from[10000]; // from[i] : i ���� ���ϱ� ������ ����
char how[10000]; // how[i] : from[i]���� i ���ڸ� ���ϱ� ���� D, S, L, R �� � ��ɾ ����ߴ���
char comm[4] = { 'D', 'S','L', 'R' };

int transform(int flag, int n) {
	if (flag == 0) // D
		return (n * 2) % 10000;
	else if (flag == 1) { // S
		if (n == 0) return 9999;
		return n - 1;
	}
	else if (flag == 2) // L
		return (n % 1000) * 10 + n / 1000;
	else if (flag == 3) // R
		return (n / 10) + (n % 10) * 1000;
	else return -1; 
}

int main() {
	int cases; cin >> cases;
	while (cases--) {
		int a, b; cin >> a >> b; 
		
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist)); 
		memset(from, 0, sizeof(from)); 
		memset(how, '\0', sizeof(how)); 

		queue<int> q; 
		q.push(a); 

		// ���� ���� ����
		check[a] = true;
		dist[a] = 0; 
		from[a] = -1; 

		while (!q.empty()) {
			int here = q.front(); q.pop(); 
			
			for (int command = 0; command < 4; command++) {
				int there = transform(command, here); 
				if (check[there] == false) {
					q.push(there);
					dist[there] = dist[here] + 1;
					from[there] = here;
					how[there] = comm[command];
					check[there] = true;
				}
			}
		}

		string ret = "";
		while (b != a) {
			ret += how[b]; 
			b = from[b]; 
		}
		/*
		int prev = from[b]; 
		string ret = ""; 
		ret += how[b]; 
		while (prev != a) {
			ret += how[prev]; 
			prev = from[prev]; 
		}
		*/
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
	return 0;
}