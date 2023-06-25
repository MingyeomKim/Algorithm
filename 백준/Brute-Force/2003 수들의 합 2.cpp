#include <iostream>
#include <vector>
using namespace std;

int n; long long  m;
long long cache[10001];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;
	cache[0] = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i == 1) cache[i] = x;
		else cache[i] = x + cache[i - 1];
	}

	int ret = 0; 
	for(int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			if (cache[j] - cache[i - 1] == m)
				ret++;
		}
	cout << ret << endl;
	return 0;
}