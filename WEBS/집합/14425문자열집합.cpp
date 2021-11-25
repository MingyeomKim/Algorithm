#include <iostream>
using namespace std;


int isInclude(string* a, int a_size, string b) { // 집합 a 내에 string b를 포함하는 원소가 있는지 체크하는 함수 
	for (int i = 0; i < a_size; i++) {
		if (!a[i].compare(b))
			return 1;
	}
	return 0;
}


int main() {
	int n; cin >> n; // 집합 S에 포함되어있는 문자열 나열
	int m; cin >> m; // 주어지는 문자열

	string* set = new string[n];
	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		set[i] = a;
	} // 집합
	int count = 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (isInclude(set, n, a)) {
			count++;
		}
	}
	cout << count << endl;
	
	return 0;
}