#include <iostream>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std; 

int main() {
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); cin.tie(NULL); 

	int n; cin >> n; 
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x; 
		if (left.empty()) left.push(x); 
		else {
			if (left.size() == right.size()) {
				if (left.top() > x)
					left.push(x); 
				else {
					right.push(x); 
					left.push(right.top()); 
					right.pop(); 
				}
			}
			else {
				if (left.top() > x) {
					left.push(x);
					right.push(left.top());
					left.pop();
				}
				else
					right.push(x); 
			}
		}
		cout << left.top() << endl;
	}
	return 0; 
}