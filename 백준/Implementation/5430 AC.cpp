#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std; 

int main() {
	int t; cin >> t; 
	while (t--) {
		string p; cin >> p; // RDD
		int n; cin >> n; // 4
		deque<int> q; 
		string s; cin >> s; // [1,2,3,4]
		bool isError = false; 
		for (int i = 1; i < s.size();) {
			string num = ""; 
			while (s[i] != ',' && s[i] != ']') {
				num += s[i]; 
				i++; 
			}
			if (num != "")
				q.push_back(stoi(num)); 
			else
				i++;
		}
		bool isFlipped = false; 
		for(char c : p){
			if (c == 'R') 
				isFlipped = (isFlipped == true) ? false : true; 
			else if (c == 'D') {
				if (q.size() > 0) {
					if (isFlipped) 
						q.pop_back(); 
					else
						q.pop_front(); 
				}
				else {
					cout << "error" << endl;
					isError = true; 
					break; 
				}
			}
		}

		if (!isError) {
			cout << "[";
			if(isFlipped){
				for (auto iter = q.rbegin(); iter != q.rend();){ // 뒤집어서 출력
					cout << *iter;
					iter++; 
					if (iter != q.rend())
						cout << ","; 
				}
			}
			else {
				while (!q.empty()) {
					cout << q.front(); q.pop_front();
					if (!q.empty())
						cout << ","; 
				}
			}
			cout << "]"; 
			cout << endl;
		}
	}
	return 0; 
}