#include <iostream>
#include <vector>
#include <cstring>
#include <deque>
using namespace std; 

bool removed[101];

int main() {
	int t; cin >> t; 
	while (t--) {
		int n, target; cin >> n >> target; // 문서의 중요도
		vector<int> priority(n);
		deque<int> q;
		for (int i = 0; i < n; i++) {
			cin >> priority[i];
			q.push_back(i); // 0 1 2 3
		}

		int index = 0; // 제일 앞에 있는 문서의 인덱스
		int ret = 0; 
		memset(removed, false, sizeof(removed));
		while(!q.empty()) {
			bool isOk = true; 
			bool isFound = false;
			for (int j = 0; j < n; j++) {
				if (index == j || removed[j]) continue;
				if (priority[index] < priority[j]) {
					isOk = false; 
					break;
				}
			}
			if (isOk) {
				if (q.front() == target) {
					isFound = true; 
					cout << ret + 1 << endl;
					break;
				}
				else {
					int c = q.front(); 
					removed[c] = true; 
					q.pop_front(); 
					ret++; 
					index = q.front(); 
				}
			}
			else {
				q.push_back(q.front()); 
				q.pop_front();
				index = q.front(); 
			}
			if (isFound)
				break;
		}
	}
}