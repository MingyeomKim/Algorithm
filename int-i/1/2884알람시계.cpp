#include <iostream>
using namespace std;

int main() {
	int h, m;
	cin >> h >> m;
	if (m < 45) {
		if (h == 0)
			h = 23;
		else
			h--;
		m = 60 - (45 - m);
	}
	else {
		m = m - 45;
	}
	cout << h << " " << m << endl;

	return 0;
}
