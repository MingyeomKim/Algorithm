#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std; 

int ret = -1; 

/*
0 1 2 
3 4 5
6 7 8
*/

bool isMagicSquare(const vector<int> v) {
	int target = v[0] + v[3] + v[6];
	return (target == v[1] + v[4] + v[7]
		&& target == v[2] + v[5] + v[8]
		&& target == v[0] + v[1] + v[2]
		&& target == v[3] + v[4] + v[5]
		&& target == v[6] + v[7] + v[8]
		&& target == v[0] + v[4] + v[8]
		&& target == v[2] + v[4] + v[6]); 
}

int calcCost(vector<int> origin, vector< int > temp) {
	int sum = 0; 
	for (int i = 0; i < origin.size(); i++)
		sum += abs(origin[i] - temp[i]); 
	return sum;
}

int main() {
	vector<int> origin(9);
	for (int i = 0; i < 9; i++) cin >> origin[i]; 
	vector<int> temp = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	do {
		if (isMagicSquare(temp)) {
			int cand = calcCost(origin, temp); 
			if (ret == -1 || ret > cand) ret = cand;
		}
	} while (next_permutation(temp.begin(), temp.end())); 
	cout << ret << endl;
	return 0; 
}