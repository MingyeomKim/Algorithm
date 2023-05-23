#include <iostream>
#include <deque>
#include <vector>
#define endl '\n'
using namespace std;

deque<char> q;
bool flag = 1; // 가로 방향이면 1, 세로 방향이면 0
int ball = 0;
int wall = 0;
int isLeft = 1;  // 가로 방향일 때, 뒤 쪽 방향이 왼쪽에 있다면 1, 오른쪽에 있다면 0
int isUpper = 1; // 세로 방향일 때, 뒤 쪽 방향이 위에 있다면 1, 아래에 있다면 0

void query(string s, char c) {
	if (s == "push") {
		if (flag == 1) { // 가로
			q.push_back(c);
			if (c == 'w') wall++;
			else ball++;
		}
		else {  // 세로
			if (c == 'w') {
				q.push_back(c);
				wall++;
			}
			else {
				if (isUpper) { // 뒤가 위에 있는 경우
					if (!q.empty()) {
						char nc = q.front();
						if (nc == 'w') {
							q.push_back(c);
							ball++;
						}
					}
				}
			}
		}
	}
	else if (s == "count") {
		if (c == 'b') {
			cout << ball << endl;
		}
		else
			cout << wall << endl;
	}
	else if (s == "pop") {
		if (!q.empty()) {
			if (flag) {
				char nc = q.front();
				if (nc == 'b') ball--;
				else wall--;
				q.pop_front();
			}
			else { // 세로 방향인 경우
				if (isUpper) {  // 아래에서 꺼내는 경우
					wall--; 
					q.pop_front();
					while (!q.empty()) {
						char nc = q.front(); 
						if (nc == 'w') break;
						q.pop_front(); 
						ball--; 
					} // 가림막 위에 있던 공이 쏟아진다.
				}
				else { // 위에서 꺼내는 경우
					char nc = q.front(); 
					if (nc == 'b') ball--;
					else wall--; 
					q.pop_front(); 
				}
			}
		}
	}
	else if (s == "rotate") {
		flag = 1 - flag;
		if (!flag) { // 세로 방향이 되었다면
			if (c == 'l') { // 반시계 방향 회전
				// 위가 앞, 아래가 뒤가 된 경우
				if (isLeft == 1) {
					if (!q.empty()) {
						char nc = q.back();
						while (!q.empty()) {
							nc = q.back();
							if (nc == 'w') break;
							q.pop_back();
							ball--;
						}
					}
					isUpper = 0;
				}
				else { //  위가 뒤, 아래가 앞이 된 경우
					// 앞에 있는 공들이 쏟아져나온다. 
					if (!q.empty()) {
						char nc = q.front();
						while (!q.empty()) {
							nc = q.front();
							if (nc == 'w') break;
							q.pop_front();
							ball--;
						}
					}
					isUpper = 1;
				}
			}
			else if (c == 'r') { // 시계 방향 회전 
				if (isLeft == 1) {
					if (!q.empty()) {
						char nc = q.front();
						while (!q.empty()) {
							nc = q.front();
							if (nc == 'w') break;
							q.pop_front();
							ball--;
						}
					}
					isUpper = 1;
				}
				else {
					if (!q.empty()) {
						char nc = q.back();
						while (!q.empty()) {
							nc = q.back();
							if (nc == 'w') break;
							q.pop_back();
							ball--;
						}
					}
					isUpper = 0;
				}

			}
		}
		else {  // 가로 방향이 되었다면
			if (c == 'l') { // 반시계 방향 회전
				if (isUpper == 1)
					isLeft = 1;
				else
					isLeft = 0;
			}
			else {
				if (isUpper == 1)
					isLeft = 0;
				else
					isLeft = 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		string s; cin >> s;
		char c;
		if (s != "pop") {
			cin >> c;
		}
		query(s, c);
	}
	return 0;
}