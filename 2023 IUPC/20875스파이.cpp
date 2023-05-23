#include <iostream>
using namespace std;

int info[2][3];
int n, m;
int ret = 0;

void solve(int days, int sum, int place) {
	if (days == n) {
		if (sum >= m) ret++;
		return;
	}
	if (days == 0) {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				solve(days + 1, sum + info[i][j], j);
	}
	else {
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				if (j == place)
					solve(days + 1, sum + info[i][j] / 2, j);
				else
					solve(days + 1, sum + info[i][j], j);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			cin >> info[i][j];
	solve(0, 0, 0);
	cout << ret << endl;
	return 0;
}
