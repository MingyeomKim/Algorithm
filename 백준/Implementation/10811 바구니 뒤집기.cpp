#include <iostream>
using namespace std;

int arr[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}
	for (int index = 0; index < m; index++) {
		int i, j; cin >> i >> j;
		for (int k = 0; ; k++) {
			int left = i + k;
			int right = j - k;
			if (left >= right) {
				break;
			}
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}