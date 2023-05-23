#include <iostream>
#include <deque>
#include <vector>
#define endl '\n'
using namespace std;

deque<char> q;
bool flag = 1; // ���� �����̸� 1, ���� �����̸� 0
int ball = 0;
int wall = 0;
int isLeft = 1;  // ���� ������ ��, �� �� ������ ���ʿ� �ִٸ� 1, �����ʿ� �ִٸ� 0
int isUpper = 1; // ���� ������ ��, �� �� ������ ���� �ִٸ� 1, �Ʒ��� �ִٸ� 0

void query(string s, char c) {
	if (s == "push") {
		if (flag == 1) { // ����
			q.push_back(c);
			if (c == 'w') wall++;
			else ball++;
		}
		else {  // ����
			if (c == 'w') {
				q.push_back(c);
				wall++;
			}
			else {
				if (isUpper) { // �ڰ� ���� �ִ� ���
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
			else { // ���� ������ ���
				if (isUpper) {  // �Ʒ����� ������ ���
					wall--; 
					q.pop_front();
					while (!q.empty()) {
						char nc = q.front(); 
						if (nc == 'w') break;
						q.pop_front(); 
						ball--; 
					} // ������ ���� �ִ� ���� �������.
				}
				else { // ������ ������ ���
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
		if (!flag) { // ���� ������ �Ǿ��ٸ�
			if (c == 'l') { // �ݽð� ���� ȸ��
				// ���� ��, �Ʒ��� �ڰ� �� ���
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
				else { //  ���� ��, �Ʒ��� ���� �� ���
					// �տ� �ִ� ������ ��������´�. 
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
			else if (c == 'r') { // �ð� ���� ȸ�� 
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
		else {  // ���� ������ �Ǿ��ٸ�
			if (c == 'l') { // �ݽð� ���� ȸ��
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