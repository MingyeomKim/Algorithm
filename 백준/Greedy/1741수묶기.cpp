#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int n;

bool cmp(int n1, int n2) {
	return n1 > n2; 
}

int main() {
	cin >> n; 
	vector<int> pos, neg;
	for (int i = 0; i < n; i++) {
		int num; cin >> num; 
		if (num > 0) pos.push_back(num);
		else neg.push_back(num);
	}

	vector<int> tied; 
	// 양수
	int index_pos = 0; 
	sort(pos.begin(), pos.end(), cmp); // 내림차순 정렬
	int u = pos.size(); 
	while (index_pos <  u - 1 && pos[index_pos + 1] > 1) {
		tied.push_back(pos[index_pos] * pos[index_pos + 1]); 
		index_pos += 2;
	}	
	for (int i = index_pos; i < pos.size(); i++)
		tied.push_back(pos[i]); 

	// 음수
	int index_neg = 0; 
	int v = neg.size(); 
	sort(neg.begin(), neg.end());  // -3, -2, -1 // 오름차순 정렬
	while (index_neg < v - 1) {
		tied.push_back(neg[index_neg] * neg[index_neg + 1]); 
		index_neg += 2; 
	}
	for (int i = index_neg; i < neg.size(); i++)
		tied.push_back(neg[i]); 

	int ret = 0;
	for (int i = 0; i < tied.size(); i++)
		ret += tied[i]; 
	cout << ret << endl;
	return 0;
}