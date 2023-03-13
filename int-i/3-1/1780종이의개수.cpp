#include <iostream>
#define MAX 2187
#include <cmath>
using namespace std;

int map[MAX][MAX] = { 0, }; // ���
int cnt0 = 0; // 0�� ä���� ������ ����
int cnt1 = 0; // 1�� ä���� ������ ����
int cnt2 = 0; // -1�� ä���� ������ ����


bool check(int p, int q, int n) { // p, q���� �����ؼ� num ũ�⿡ �ش��ϴ� ���簢�� ���� ĭ���� ��� ������ Ȯ���ϴ� �Լ�
	// ������
	if (n == 1)
		return true;
	else {
		int flag = map[p][q]; // ���� ó�� ���� ���� �������� Ž��
		for (int i = p; i < p + n; i++) {
			for (int j = q; j < q + n; j++) {
				if (flag != map[i][j]) // �ٸ� �� �ϳ��� ������
					return false;
			}
		}
	}
	return true;
}

void count(int p, int q) {
	if (map[p][q] == 0) {
		cnt0++;
	}
	else if (map[p][q] == 1) {
		cnt1++;
	}
	else {
		cnt2++;
	}
}

// 9���ҷ� ������ �Լ�
void divide(int p, int q, int n) { // ���� Point(p, q), ������ ���� ����(n)

	if (check(p, q, n)) {
		count(p, q); // ���� ���� count
		return; // n�� 1�̸� ���̸� �ٷ� ����Ѵ�. 
	}
	else {
		int size = n / 3; // ������ �ݺ��� ������ ���Ӱ� ���簢���� ����� �ʱ�ȭ�Ѵ�.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(p + size * i, q + size * j, size); // 
			}
		}
		return;
	}
}

int main() {
	
	int init_size; // �ʱ� ����� ũ��
	cin >> init_size; 

	for (int i = 0; i < init_size; i++) {
		for (int j = 0; j < init_size; j++) {
			cin >> map[i][j];
		}
	}

	divide(0, 0, init_size);

	cout << cnt2 << endl << cnt0 << endl << cnt1 << endl;

	return 0;
}