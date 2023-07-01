#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

int main() {
	while (true) {
		int n; cin >> n; 
		if (n == 0) break;

		vector<long long> h(n); 
		for (int i = 0; i < n; i++)
			cin >> h[i]; 

		stack<long long> st; 
		long long ret = 0; 
		for (int i = 0; i < n; i++) {
			int left = i; 
			while (!st.empty() && h[st.top()] > h[i]) {
				int height = h[st.top()]; 
				st.pop(); 
				long long width = i; 
				if (!st.empty()) width = (i - st.top() - 1);
				if (ret < width * height)
					ret = width * height; 
			}
			st.push(i); 
		}

		while (!st.empty()) {
			long long height = h[st.top()]; 
			st.pop(); 
			long long width = n; 
			if (!st.empty())
				width = n - st.top() - 1; 
			if (ret < width * height) ret = width * height; 
		}
		cout << ret << endl; 
	}
	return 0; 
}