#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int ability[21][21];
const int INF = 18001;

int main() {
	int n; cin >> n; 
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> ability[i][j]; 

	vector<int> binary(n);  // 0으로 n개 채워져있음
	for (int i = n / 2; i < n; i++)
		binary[i] = 1; 

	int ret = INF; 
	do {
		vector<int> left, right; 
		for (int i = 0; i < n; i++) {
			if (binary[i] == 0) // 스타트팀이면
				left.push_back(i);
			else
				right.push_back(i); // 링크팀이면
		}

		int leftSum = 0, rightSum = 0; 
		for (int i : left) for (int j : left)
			leftSum += ability[i][j];
		for (int i : right) for (int j : right)
			rightSum += ability[i][j];

		int cand = abs(leftSum - rightSum); 
		if (ret > cand) ret = cand; 
	} while (next_permutation(binary.begin(), binary.end()));

	cout << ret << endl;
	return 0; 
}