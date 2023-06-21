#include <iostream>
using namespace std; 

int a, b;
long long ret = -2; 
void recursive(long long cnt, long long sum) {
	if (sum == b) {
		if (ret == -2 || ret > cnt) 
			ret = cnt;
		return; 
	}
	else if (sum > b)
		return;
	recursive(cnt + 1, sum * 2); 
	recursive(cnt + 1, sum * 10 + 1); 
}

int main() {
	cin >> a >> b; 
	recursive(0, a); 
	cout << ret + 1 << endl;
	return 0; 
}