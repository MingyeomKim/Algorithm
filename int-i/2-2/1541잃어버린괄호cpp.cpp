#include <iostream>
#include <string>
using namespace std;
// '-' 뒤에 오는 것들을 전부 뺄셈 처리하면 되지 않을까?
// 앞에 나온 것을 토대로 뒤의 Num을 sum에 연산해줘야하는 것이므로 isMinus를 제일 앞에 나온 부호가 Minus인지 아닌 지 확인할 것.

int main() {
	string equation; //입력으로 주어지는 식의 길이
	cin >> equation; 

	int sum = 0;
	string num; 

	bool isMinus = false; // 최근에 나온 부호가 '-'인가

	for (int i = 0; i <= equation.size(); i++) {

		if (equation[i] == '-' || equation[i] == '+' || i == equation.size()) {
			if (isMinus) {
				sum -= stoi(num);
				num = "";
			}
			else {
				sum += stoi(num); // 한 번도 마이너스 부호가 나오지 않은 경우
				num = "";
			}
		}
		else { // 숫자가 나온 경우
			num += equation[i];
		}

		if (equation[i] == '-')
			isMinus = true;
	}

	cout << sum << endl;
	return 0; 
}