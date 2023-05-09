#include <iostream>
#include <vector>
#include <set>
using namespace std; 

int num[4] = { 1, 5, 10, 50 };
int n;


// index : temp 배열의 index
// temp : 현재 위치에서 숫자를 추가하고 있는 배열
// result : 모든 숫자 조합 배열
// sum : temp의 모든 숫자의 합
void calc(int index, int sum, vector<int> &temp, vector<vector<int>> & result) {
	if (sum == n && temp.size() == 4) {
		result.push_back(temp); 
		return;
	}
	if (index == 4) return; // 합이 n이 되지 않은 경우

	calc(index + 1, sum, temp, result); 
	for (int i = 0; i <= n; i++) {
		temp.push_back(i); 
		calc(index + 1, sum + i, temp, result); 
		temp.pop_back(); 
	}
}

int main() {
	 cin >> n; // 문자의 개수
	 vector<vector<int>>  candidates; 
	 vector<int> temp; 
	 calc(0, 0, temp, candidates); 
	 set<int> numbers;
	 for (vector<int> combinations : candidates) {
		 int sum = 0; 
		 for (int i = 0; i < 4; i++) {
			 sum += combinations[i] * num[i];
		 }
		 numbers.insert(sum);
	 }
	 cout << numbers.size() << endl;

	 return 0; 
}