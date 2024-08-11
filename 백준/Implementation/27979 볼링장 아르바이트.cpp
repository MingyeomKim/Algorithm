#include <iostream>
using namespace std;

int weight[200001];
bool check[200001];

int main() {
	int n; cin >> n;
	int max = 0;
	int min = -1; // 옮겨야 하는 애 중 가장 작은 애
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
		if (max < weight[i]) {
			max = weight[i];
		}
		else if (max > weight[i]) {
			check[i] = true; // 넌 옮겨야 해
			cnt++;
			if (min == -1 || min > weight[i]) {
				min = weight[i];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!check[i] && min > weight[i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}