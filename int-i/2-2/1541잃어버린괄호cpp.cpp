#include <iostream>
#include <string>
using namespace std;
// '-' �ڿ� ���� �͵��� ���� ���� ó���ϸ� ���� ������?
// �տ� ���� ���� ���� ���� Num�� sum�� ����������ϴ� ���̹Ƿ� isMinus�� ���� �տ� ���� ��ȣ�� Minus���� �ƴ� �� Ȯ���� ��.

int main() {
	string equation; //�Է����� �־����� ���� ����
	cin >> equation; 

	int sum = 0;
	string num; 

	bool isMinus = false; // �ֱٿ� ���� ��ȣ�� '-'�ΰ�

	for (int i = 0; i <= equation.size(); i++) {

		if (equation[i] == '-' || equation[i] == '+' || i == equation.size()) {
			if (isMinus) {
				sum -= stoi(num);
				num = "";
			}
			else {
				sum += stoi(num); // �� ���� ���̳ʽ� ��ȣ�� ������ ���� ���
				num = "";
			}
		}
		else { // ���ڰ� ���� ���
			num += equation[i];
		}

		if (equation[i] == '-')
			isMinus = true;
	}

	cout << sum << endl;
	return 0; 
}