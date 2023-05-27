#include <iostream>
using namespace std; 

int n;

void print(int k) {
	for (int i = 0; i < k; i++)
		cout << "_"; 
}

void solve(int k) {
	if (k == n) {
		print(4 * k); cout << "\"����Լ��� ������?\"" << endl;
		print(4 * k); cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << endl;
		print(4 * k); cout << "��� �亯�Ͽ���." << endl;
		return; 
	}
	print(4 * k);  cout << "\"����Լ��� ������?\"" << endl;
	print(4 * k);  cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << endl;
	print(4 * k);  cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << endl;
	print(4 * k);  cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << endl;
	solve(k + 1); 
	print(4 * k); cout << "��� �亯�Ͽ���." << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << endl;
	solve(0);
}