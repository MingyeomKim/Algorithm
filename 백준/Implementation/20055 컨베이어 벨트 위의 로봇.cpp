#include <iostream>
#include <vector>
using namespace std;

int n, k;
// �����̾� ��Ʈ�� �κ��� �Բ� �̵���Ų��
void rotate(vector<int>& v, vector<bool>& robots) {
	// ��Ʈ �̵�
	vector<int> temp(2 * n);
	temp[0] = v[2 * n - 1];
	for (int i = 1; i < 2 * n; i++) {
		temp[i] = v[i - 1];
	}
	for (int i = 0; i < 2 * n; i++) {
		v[i] = temp[i];
	}

	// �κ��� �Բ� �̵�
	for (int i = n - 2; i >= 0; i--) {
		if (!robots[i]) continue;
		if (i == n - 2) {
			// ������ ��ġ�� �̵��� �κ��� ���
			robots[i] = false;
		}
		else {
			if (robots[i]) {
				robots[i + 1] = true;
				robots[i] = false;
			}
		}
	}
}

void move(vector<int>& v, vector<bool>& robots) {
	for (int i = n - 2; i >= 0; i--) {
		if (!robots[i]) continue;
		if (i == n - 2 && v[i + 1] > 0) {
			robots[i] = false;
			v[i + 1]--;
		}
		else {
			if (!robots[i + 1] && v[i + 1] > 0) {
				robots[i + 1] = true;
				robots[i] = false;
				v[i + 1]--;
			}
		}
	}
}

void load(vector<int>& belt, vector<bool>& robots) {
	if (belt[0] > 0) {
		belt[0]--;
		robots[0] = true;
	}
}

int countZero(vector<int>& belt) {
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		if (belt[i] == 0) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	vector<int> belt(2 * n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i];
	}
	vector<bool> robots(n, false);
	int ret = 0;
	while (true) {
		ret++;
		rotate(belt, robots);
		move(belt, robots);
		load(belt, robots);
		if (countZero(belt) >= k) {
			break;
		}
	}
	cout << ret << endl;
	return 0;
}

/*
- �����̾� ��Ʈ�� ȸ���ϴ� ���
- �κ��� �̵��ϴ� ��� (�κ��� ���� ���� �� ����)
	- �� �κ��� �̵��� �� �ִ� �� üũ
	- �̵��� �� �ִ� ��� �κ��� �̵���Ű�� ������ 1 ����
	- �̵��� ��ġ�� ������ ��ġ�� �� �κ��� ����
- �ø��� ��ġ�� �ִ� ĭ�� �������� 1 �̻��̸� �ø��� ��ġ�� �κ��� �ø�
	- �ø��� ��ġ�� ������ 1 ����
- ��� ĭ�� �������� Ȯ���ϰ� 0�� ĭ�� ������ K�� �����̸� �н�, �̻��̸� ����
*/