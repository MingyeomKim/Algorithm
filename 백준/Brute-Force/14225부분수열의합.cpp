#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n; 
vector<int> sums; 
void partialSum(vector<int>& S, int index, int sum) {
	if (index == n) {
		sums.push_back(sum);  // 6 3 7 8 5 1 2
		return;
	}
	partialSum(S, index + 1, sum + S[index]);
	partialSum(S, index + 1, sum); 
}

int main() {
	cin >> n; 
	vector<int> S(n); //  5 1 2
	
	for (int i = 0; i < n; i++) cin >> S[i]; 
	partialSum(S, 0, 0);
	sort(sums.begin(), sums.end()); // 오름차순으로 정렬 
	
	if (sums[1] != 1) {
		cout << 1 << endl;
		return 0; 
	}// (맨 앞은 0)

	int index = 2, m = sums.size(); 
	for (index = 2; index < m; index++)
		if (sums[index - 1] + 1 < sums[index]){
			cout << sums[index - 1] + 1; 
			return 0; 
		}
	if (index == m) cout << sums[index - 1] + 1; 
	return 0; 
}