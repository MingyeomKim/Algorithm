#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;


	int min_bundle = -1;
	int min_one = -1;
	for (int i = 0; i < m; i++) {
		int bundle, one; cin >> bundle >> one;
		if (min_bundle == -1 || min_bundle > bundle) {
			min_bundle = bundle;
		}
		if (min_one == -1 || min_one > one) {
			min_one = one;
		}
	}

	int ret = -1;

	int max_bundle_size = (n / 6) + 1;
	for (int j = 0; j <= max_bundle_size; j++) {
		int bundle_price = j * min_bundle;
		if (n > j * 6) {
			int one_price = (n - j * 6) * min_one;
			if (ret == -1 || ret > one_price + bundle_price) {
				ret = one_price + bundle_price;
			}
		}
		else {
			if (ret == -1 || ret > bundle_price) {
				ret = bundle_price;
			}
		}
	}

	cout << ret << endl;
	return 0;
}