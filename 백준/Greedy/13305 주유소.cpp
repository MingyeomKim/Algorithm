#include <iostream>
using namespace std;

long long price[100001];
long long length[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> length[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> price[i];
	}

	int current = 0;
	long long dist = 0;
	long long ret = 0;
	for (int next = 1; next < n; next++) {
		dist += length[next - 1];
		if (next == n - 1 || price[current] > price[next]) {
			ret += dist * price[current];
			dist = 0;
			current = next;
		}
	}
	cout << ret << endl;
	return 0;
}

