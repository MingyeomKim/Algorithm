#include <iostream>
using namespace std;

int loss[21];
int happy[21];
int n;

int ret = -1;
void solve(int index, int health, int pleasure) {
	if (index == n) {
		if (ret == -1 || ret < pleasure) {
			ret = pleasure;
		}
		return;
	}
	if (health - loss[index] > 0) {
		solve(index + 1, health - loss[index], pleasure + happy[index]);
	}
	solve(index + 1, health, pleasure);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> loss[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> happy[i];
	}
	solve(0, 100, 0);
	cout << ret << endl;
	return 0;
}